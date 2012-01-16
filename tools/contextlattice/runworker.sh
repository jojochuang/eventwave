#!/bin/bash

#for i in {1..$2}
BASE=0
for (( i=1+BASE; i<= $1+BASE ; i++))
do
    #echo $i
    ./heartbeat -isworker 1 -pid $i -TRACE_ALL 0 -TRACE_SUBST "SpawnProcess UpdateContextMapping  ReportJobMigration NotifySignal" &> /tmp/unit_app$i.log &
done
