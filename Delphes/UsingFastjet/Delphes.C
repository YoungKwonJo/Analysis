#define Delphes_cxx
#include "Delphes.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLorentzVector.h"
#include "fastjet/ClusterSequence.hh"

#include "Particle.h"

using namespace fastjet;
using namespace std;

typedef std::vector<Particle> Particles;
typedef Particles* ParticlesP;
bool GreaterByPtParticle(Particle a, Particle b){ return a.Pt() > b.Pt(); };

void Delphes::Loop()
{
///////////
  typedef fastjet::JetDefinition JetDef;
  std::shared_ptr<JetDef> fjLepDef_, fjJetDef_;
  const double leptonMinPt_ = 20., leptonMaxEta_ = 2.4, jetMinPt_ = 20., jetMaxEta_ = 2.4;
  const double leptonConeSize = 0.1, jetConeSize = 0.4, wMass_ = 80.2, tMass_ = 172.5;

  fjLepDef_ = std::shared_ptr<JetDef>(new JetDef(fastjet::antikt_algorithm, leptonConeSize));
  fjJetDef_ = std::shared_ptr<JetDef>(new JetDef(fastjet::antikt_algorithm, jetConeSize));


  //vector<PseudoJet> particles;
  ParticlesP neutrinos;
  ParticlesP lepJet;
  ParticlesP Jet;
 // ParticlesP leptons_;

  neutrinos = new Particles;
  lepJet = new Particles;
  Jet = new Particles;

const bool debug=true;
if(debug) cout<< "start" << endl;
////////////////
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   int iii = 0;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if(iii>2) break;  iii++;
      // if (Cut(ientry) < 0) continue;
///////////////////
      //particles.clear();
      neutrinos->clear();
      lepJet->clear();
//break;
      std::set<size_t> bHadronIdxs;
      // Collect unstable B-hadrons
      for(int i=0;i<Particle_size;i++ )
      {
        const int status = Particle_Status[i];
        if ( status == 1 ) continue;

        // Collect B-hadrons, to be used in b tagging
        if ( isBHadron(i) ) bHadronIdxs.insert(i);
      }
 //break;
if(debug) cout<< "finish bHadronIdxs.." << endl;
/////////////
      // Collect stable leptons and neutrinos
      size_t nStables = 0;
      std::vector<size_t> leptonIdxs;
      std::set<size_t> neutrinoIdxs;
      for ( size_t i=0, n=Particle_size; i<n; ++i )
      {
        const int absPdgId = abs(Particle_PID[i]);
        const int status = Particle_Status[i];
        if ( status != 1 ) continue;
      
        ++nStables;
        if ( Particle_M1[i] == -1 ) continue; // Skip orphans (if exists)
        if ( Particle_Status[Particle_M1[i]] == 4 ) continue; // Treat particle as hadronic if directly from the incident beam (protect orphans in MINIAOD)
        if ( Particle_Status[Particle_M2[i]] == 4 ) continue; // Treat particle as hadronic if directly from the incident beam (protect orphans in MINIAOD)
 
       if ( isFromHadron(i) ) continue;
        switch ( absPdgId )
        {
          case 11: case 13: // Leptons
          case 22: // Photons
            leptonIdxs.push_back(i);
            break;
          case 12: case 14: case 16:
            neutrinoIdxs.insert(i);
            Particle nu_(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
            neutrinos->push_back(nu_);//Particle(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]));
            break;
        }
      }
      
      // Sort neutrinos by pT.
      std::sort(neutrinos->begin(), neutrinos->end(), GreaterByPtParticle);
if(debug) cout<< "finish neutrinoIdxs.." << endl;
      
      // Make dressed leptons with anti-kt(0.1) algorithm
      //// Prepare input particle list
      std::vector<fastjet::PseudoJet> fjLepInputs;
      fjLepInputs.reserve(leptonIdxs.size());
      for ( auto index : leptonIdxs )
      {
        const TLorentzVector p(Particle_Px[index],Particle_Py[index],Particle_Pz[index],Particle_E[index]);
        if ( std::isnan(p.Pt()) or p.Pt() <= 0 ) continue;
      
        fjLepInputs.push_back(fastjet::PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy()));
        fjLepInputs.back().set_user_index(index);
      }

if(debug) cout<< "finish leptonIdxs.." << endl;
      
      //// Run the jet algorithm
      fastjet::ClusterSequence fjLepClusterSeq(fjLepInputs, *fjLepDef_);
      std::vector<fastjet::PseudoJet> fjLepJets = fastjet::sorted_by_pt(fjLepClusterSeq.inclusive_jets(leptonMinPt_));
      
      //// Build dressed lepton objects from the FJ output
      //leptons->reserve(fjLepJets.size());
      std::set<size_t> lepDauIdxs; // keep lepton constituents to remove from GenJet construction
      for ( auto& fjJet : fjLepJets )
      {
        if ( abs(fjJet.eta()) > leptonMaxEta_ ) continue;
      
        // Get jet constituents from fastJet
        const std::vector<fastjet::PseudoJet> fjConstituents = fastjet::sorted_by_pt(fjJet.constituents());
        // Convert to CandidatePtr
        std::vector<Particle> constituents;
        Particle lepCand(true);
        for ( auto& fjConstituent : fjConstituents )
        {
          const size_t index = fjConstituent.user_index();
          Particle cand(Particle_Px[index],Particle_Py[index],Particle_Pz[index],Particle_E[index]);    
          cand.setPdgId(Particle_PID[index]);
          cand.setCharge(Particle_Charge[index]);

          //reco::CandidatePtr cand = finalStateHandle->ptrAt(index);
          const int absPdgId = abs(Particle_PID[index]);
          if ( absPdgId == 11 || absPdgId == 13 )
          {
            if ( lepCand.isNotnull()) if(lepCand.Pt() > cand.Pt() ) continue; // Choose one with highest pt
            lepCand = cand;
          }
          constituents.push_back(cand);
        }
        if ( lepCand.isNull() ) continue;
        if ( lepCand.Pt() < fjJet.pt()/2 ) continue; // Central lepton must be the major component
      
        Particle jetP4(fjJet.px(), fjJet.py(), fjJet.pz(), fjJet.E());
        jetP4.setPdgId(lepCand.pdgId());
        jetP4.setCharge(lepCand.charge());
        const double jetArea = fjJet.has_area() ? fjJet.area() : 0;
        jetP4.setJetArea(jetArea);
        lepJet->push_back(jetP4);
      
        // Keep constituent indices to be used in the next step.
        for ( auto& fjConstituent : fjConstituents )
        {
          lepDauIdxs.insert(fjConstituent.user_index());
        }
      }
if(debug) cout<< "finish lepJet.." << endl;

/////////////
      std::vector<fastjet::PseudoJet> fjJetInputs;
      for ( size_t i=0, n=Particle_size; i<n; ++i )
      {
        const TLorentzVector p(Particle_Px[i],Particle_Py[i],Particle_Pz[i],Particle_E[i]);
        if ( Particle_Status[i] != 1 ) continue;
        if ( std::isnan(p.Pt()) or p.Pt() <= 0 ) continue;
    
        if ( neutrinoIdxs.find(i) != neutrinoIdxs.end() ) continue;
        if ( lepDauIdxs.find(i) != lepDauIdxs.end() ) continue;
    
        fjJetInputs.push_back(fastjet::PseudoJet(p.Px(), p.Py(), p.Pz(), p.Energy()));
        fjJetInputs.back().set_user_index(i);
      }
      for ( auto index : bHadronIdxs )
      {
        const TLorentzVector p(Particle_Px[index],Particle_Py[index],Particle_Pz[index],Particle_E[index]);
        if ( std::isnan(p.Pt()) or p.Pt() <= 0 ) continue;
      
        const double scale = 1e-20/p.P();
        fjJetInputs.push_back(fastjet::PseudoJet(p.Px()*scale, p.Py()*scale, p.Pz()*scale, p.Energy()*scale));
        fjJetInputs.back().set_user_index(index);
      }

      // run the clustering, extract the jets
      fastjet::ClusterSequence fjJetClusterSeq(fjJetInputs, *fjJetDef_);
      std::vector<fastjet::PseudoJet> fjJets = fastjet::sorted_by_pt(fjJetClusterSeq.inclusive_jets(jetMinPt_));

if(debug) cout<< "finish fJets.." << endl;      
// https://github.com/vallot/CATTools/blob/cat72x/CatProducer/plugins/PseudoTopProducer.cc:#L260
// I have to update it.

      // print out some infos
      cout << "Clustering with " << fjJetDef_->description() << endl;
      
      // print the jets
      cout <<   "        pt y phi" << endl;
      for (unsigned i = 0; i < fjJets.size(); i++) 
      {
        cout << "jet " << i << ": "<< fjJets[i].pt() << " "
                       << fjJets[i].rap() << " " << fjJets[i].phi() << endl;
        vector<PseudoJet> constituents = fjJets[i].constituents();
        for (unsigned j = 0; j < constituents.size(); j++) {
          cout << "    constituent " << j << "'s pt: " << constituents[j].pt()
               << endl;
        }
      }


/////////////////
   }
}

bool Delphes::isBHadron(const int idx_ ) const
{
  const unsigned int absPdgId = abs(Particle_PID[idx_]);
  if ( !isBHadronC(absPdgId) ) return false;

  // Do not consider this particle if it has B hadron daughter
  // For example, B* -> B0 + photon; then we drop B* and take B0 only
  if( isBHadronC(abs(Particle_PID[Particle_D1[idx_]])) ) return false;
  if( isBHadronC(abs(Particle_PID[Particle_D2[idx_]])) ) return false;

  return true;
}

bool Delphes::isBHadronC(const unsigned int absPdgId) const
{
  if ( absPdgId <= 100 ) return false; // Fundamental particles and MC internals
  if ( absPdgId >= 1000000000 ) return false; // Nuclei, +-10LZZZAAAI

  // General form of PDG ID is 7 digit form
  // +- n nr nL nq1 nq2 nq3 nJ
  //const int nJ = absPdgId % 10; // Spin
  const int nq3 = (absPdgId / 10) % 10;
  const int nq2 = (absPdgId / 100) % 10;
  const int nq1 = (absPdgId / 1000) % 10;

  if ( nq3 == 0 ) return false; // Diquarks
  if ( nq1 == 0 and nq2 == 5 ) return true; // B mesons
  if ( nq1 == 5 ) return true; // B baryons

  return false;
}

bool Delphes::isFromHadron(const int idx_) const
{
  const int idx_M1 = Particle_M1[idx_], idx_M2 = Particle_M2[idx_];
  if( idx_M1 !=-1)
  {
       const int idx_M11 = Particle_M1[idx_M1], idx_M12 = Particle_M2[idx_M1];
       if(!(idx_M11==-1 && idx_M12==-1))
       {
           const int pdgId = abs(Particle_PID[idx_M1]);
          
           if ( pdgId > 100 ) return true;
           else if ( idx_M11 !=-1 &&  isFromHadron(idx_M11) ) return true;
           else if ( idx_M12 !=-1 &&  isFromHadron(idx_M12) ) return true;
       }
  }
  if( idx_M2 !=-1)
  {
       const int idx_M21 = Particle_M1[idx_M2], idx_M22 = Particle_M2[idx_M2];
       if(!(idx_M21==-1 && idx_M22==-1)) 
       {
           const int pdgId = abs(Particle_PID[idx_M2]);
          
           if ( pdgId > 100 ) return true;
           else if ( idx_M21 !=-1 &&  isFromHadron(idx_M21) ) return true;
           else if ( idx_M22 !=-1 &&  isFromHadron(idx_M22) ) return true;
       }
  }
  return false;
}



