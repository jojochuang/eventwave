#!/bin/bash

USERNAME="arasmuss"
NODEFILE="nodes.txt.${1}"
MODELCHECKER_BINARY="~/build/mace/mace/application/parallelmc/modelchecker"

x=`wc -l ${NODEFILE} | awk '{print $1}'`

for node in `tac ${NODEFILE}`
do
  (ssh ${USERNAME}@${node} "killall modelchecker")
  let "x -= 1"
done
