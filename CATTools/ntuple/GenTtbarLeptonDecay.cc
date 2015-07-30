#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/Association.h"
#include "DataFormats/Common/interface/RefToPtr.h"

#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"

using namespace edm;
using namespace std;

namespace cat {

  class GenTtbarLeptonDecay : public edm::EDProducer {
  public:
    explicit GenTtbarLeptonDecay(const edm::ParameterSet & iConfig);
    virtual ~GenTtbarLeptonDecay() { }

    virtual void produce(edm::Event & iEvent, const edm::EventSetup & iSetup);
    virtual bool isLastP( const reco::GenParticle& p);
    virtual const reco::Candidate* getLast( const reco::Candidate& p );

  private:
    edm::EDGetTokenT<reco::GenParticleCollection> GenParticlesLabel_;
    edm::EDGetTokenT<reco::GenJetCollection> GenJetsLabel_;
    const double pt_;
    const double eta_;

  };

} // namespace

cat::GenTtbarLeptonDecay::GenTtbarLeptonDecay(const edm::ParameterSet & iConfig) :
  GenParticlesLabel_(consumes<reco::GenParticleCollection>(iConfig.getParameter<edm::InputTag>("GenParticles"))),
  GenJetsLabel_(consumes<reco::GenJetCollection>(iConfig.getParameter<edm::InputTag>("GenJets"))),
  pt_(iConfig.getParameter<double>("pt")),
  eta_(iConfig.getParameter<double>("eta"))
{
    produces<int>("genTtbarLeptonDecayId");
    produces<int>("NgenJet");

}
void cat::GenTtbarLeptonDecay::produce(edm::Event & iEvent, const edm::EventSetup & iSetup) 
{

  Handle<reco::GenParticleCollection> genParticles;
  iEvent.getByToken(GenParticlesLabel_, genParticles);

  unsigned int nParticles = genParticles->size();
  int ntop = 0,nW=0, n_W2muonic=0, n_W2electronic=0, n_W2taunic=0, nW2hadronic=0, n_Welse=0;

  for ( unsigned int ip=0; ip<nParticles; ++ip ) { 
    const reco::GenParticle& p = (*genParticles)[ip];

    if ( ntop == 2 ) continue;
    if ( abs(p.pdgId()) != 6 ) continue;

    bool isLast = isLastP(p);
    if(isLast != true) continue;

    unsigned int nDaughters = p.numberOfDaughters();
    for ( unsigned iDaughter=0; iDaughter<nDaughters; ++iDaughter ) {
      const reco::Candidate* daughTemp = p.daughter(iDaughter);
      if ( nW == 1 ) break;
      if ( abs(daughTemp->pdgId()) != 24 ) continue;
      const reco::Candidate* daugh = getLast( *daughTemp );
      unsigned int nWDaughters = daugh->numberOfDaughters();

      for ( unsigned iWDaughter=0; iWDaughter<nWDaughters; ++iWDaughter ) {
	const reco::Candidate* decay = daugh->daughter(iWDaughter);
	int decayId = abs(decay->pdgId());
	if ( decayId == 11 || decayId == 12 ) {  
              ++n_W2electronic;
	} else if ( decayId == 13 || decayId == 14 ) {  
              ++n_W2muonic;
	} else if ( decayId == 15 || decayId == 16 ) {  
              ++n_W2taunic;
	} else if( decayId < 6 ){
              ++nW2hadronic;
        } else {  
          ++n_Welse;
        }
      }

      ++nW;
    }
    ++ntop;
  }

  Handle<reco::GenJetCollection> genJets;
  iEvent.getByToken(GenJetsLabel_, genJets);
  int nJet = 0;
  for (const reco::GenJet & aGenJet : *genJets) 
  {
    if ( aGenJet.pt() < pt_ || fabs(aGenJet.eta()) > eta_ ) continue;
    nJet++;
  }
  std::auto_ptr<int> nJet_(new int);
  *nJet_ = nJet;
  iEvent.put(nJet_, "NgenJet");

  std::auto_ptr<int> ttbarId(new int);
  //*ttbarId = ntop*10000000+nW*10 00 00+
  *ttbarId = n_W2taunic*10000+n_W2electronic*100+n_W2muonic+nW2hadronic*1000000;
  iEvent.put(ttbarId, "genTtbarLeptonDecayId");  

}
/*
void cat::GenTtbarLeptonDecay::beginJob()
{}
void cat::GenTtbarLeptonDecay::endJob()
{}
void cat::GenTtbarLeptonDecay::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
*/
bool cat::GenTtbarLeptonDecay::isLastP( const reco::GenParticle& p){

   bool out = true;

   int id = abs( p.pdgId() );

   unsigned int nDaughters = p.numberOfDaughters();
   for ( unsigned iDaughter=0; iDaughter<nDaughters; ++iDaughter ) {
     const reco::Candidate* daugh = p.daughter(iDaughter);
     if( abs(daugh->pdgId()) == id) {
       out = false;
       break;
     }
   }

   return out;
}
const reco::Candidate* cat::GenTtbarLeptonDecay::getLast( const reco::Candidate& p ){

   const reco::Candidate* last = 0;
   int id = abs( p.pdgId() );
   unsigned int nDaughters = p.numberOfDaughters();
   if( nDaughters == 1) {
     const reco::Candidate* daugh = p.daughter(0);
     if( abs( daugh->pdgId() ) == id ){ 
       last = getLast( *daugh );
     }else{
       last = &p;
     }
   }else{
     last = &p;
   }

   return last;

}

#include "FWCore/Framework/interface/MakerMacros.h"
using namespace cat;
DEFINE_FWK_MODULE(GenTtbarLeptonDecay);

