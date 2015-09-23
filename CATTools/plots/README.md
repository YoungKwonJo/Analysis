result.root to plots 
========

## command for running code
```
python run.py # make root-files with histograms
# after all process finish
hadd hist_all.root hist_mon*
python hist2plot.py -b # please, check the line 45~47. 1st run with  comment, 2nd run without comment.
```
