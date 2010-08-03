#!/bin/bash

USERNAME="arasmuss"
NODEFILE="nodes.txt"
#MODELCHECKER_BINARY="~/build/mace/mace/application/parallelmc/modelchecker"
MODELCHECKER_BINARY="~/build/mace/mace-internal/application/pmacemc/modelchecker"

x=`wc -l ${NODEFILE}.${1} | awk '{print $1 - 1}'`

for node in `tac ${NODEFILE}.${1}`
do
  echo "Starting process at node ${node} (rank ${x})"
  (ssh ${USERNAME}@${node} "ulimit -c unlimited && cd experiment/google_cluster_runs/${1} && mkdir node_${x} && cd node_${x} && ln -s ../../../nodes.txt.${1} nodes.txt && ln -s ../../../params.default . && ${MODELCHECKER_BINARY} -NODE_RANK ${x}" &>${1}/output_${x} &)
  sleep 2
  let "x -= 1"
done
