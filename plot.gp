#!/usr/bin/gnuplot -c
set grid
set style data point
set style function line
set style line 1 lc 3 pt 7 ps 0.3
set boxwidth 1
set xtics
set xrange [64:4500]
set xlabel  "N (bytes)"

set logscale x
# set logscale y

## set datafile separator {whitespace | tab | comma | "<chars>"}
set datafile separator comma

#
# TEMPO
#
#ARQ=ARG1."/Tempos.csv"
#set key left top
#set logscale y
#set ylabel  "Tempo (ms)"
#set title   "Tempo"
#set terminal qt 0 title "Tempos"
#plot ARQ every 4::0 using 1:2 title "MatVet" lc rgb "green" with linespoints, \
     ARQ every 4::1 using 1:2 title "MatVetOptimizado" lc rgb "blue" with linespoints, \
     ARQ every 4::2 using 1:2 title "MatMat" lc rgb "magenta" with linespoints, \
     ARQ every 4::3 using 1:2 title "MatMatOtimizado" lc rgb "orange" with linespoints

# pause -1

#
# FLOPS_DP
#
ARQ=ARG1."/FLOPS_DP.csv"
set key right top
unset logscale y
set ylabel  "FLOPS DP [MFlops/s]"
set title   "FLOPS DP"
set terminal qt 1 title "FLOPS DP"
plot ARQ using 1:2 title "MatVet" lc rgb "green" with linespoints, \
     '' using 1:3 title "MatVetOptimizado" lc rgb "blue" with linespoints, \
     '' using 1:4 title "MatMat" lc rgb "magenta" with linespoints, \
     '' using 1:5 title "MatMatOptimizado" lc rgb "orange" with linespoints

# pause -1

#
# L3
#
ARQ=ARG1."/L3.csv"
set key left top
unset logscale y
set ylabel  "L3 [MBytes/s]"
set title   "L3"
set terminal qt 3 title "L3"
plot ARQ using 1:2 title "MatVet" lc rgb "green" with linespoints, \
     '' using 1:3 title "MatVetOptimizado" lc rgb "blue" with linespoints, \
     '' using 1:4 title "MatMat" lc rgb "magenta" with linespoints, \
     '' using 1:5 title "MatMatOptimizado" lc rgb "orange" with linespoints

# pause -1

#
# L2CACHE
#
ARQ=ARG1."/L2CACHE.csv"
set key right bottom
unset logscale y
set ylabel  "L2 miss ratio"
set title   "L2 miss ratio"
set terminal qt 4 title "L2 miss ratio"
plot ARQ using 1:2 title "MatVet" lc rgb "green" with linespoints, \
     '' using 1:3 title "MatVetOptimizado" lc rgb "blue" with linespoints, \
     '' using 1:4 title "MatMat" lc rgb "magenta" with linespoints, \
     '' using 1:5 title "MatMatOptimizado" lc rgb "orange" with linespoints

pause -1


# ENERGY
#
ARQ=ARG1."/ENERGY.csv"
set key center top
unset logscale y
set ylabel  "Energia [J]"
set title   "Energia"
set terminal qt 2 title "Energia"

plot ARQ using 1:2 title "MatVet" lc rgb "green" with linespoints, \
     '' using 1:3 title "MatVetOtimizado" lc rgb "blue" with linespoints, \
     '' using 1:4 title "MatMat" lc rgb "magenta" with linespoints, \
     '' using 1:5 title "MatMatOtimizado" lc rgb "orange" with linespoints

pause -1
