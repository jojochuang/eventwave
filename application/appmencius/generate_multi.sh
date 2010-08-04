if [ $# -gt 8 ]
then
  names=( cloud03 cloud04 cloud05 cloud06 cloud07 cloud08 cloud09 cloud10 cloud11 )

  pkill mencius

  for (( i = 0 ; i < ${#names[@]} ; i++ ))
  do
    /scratch/yoo7/mace-project/mace/application/appmencius/sshdo.exp r3530t71bb ${names[$i]} pkill mencius
  done

  for (( i = 0 ; i < ${#names[@]} && i < $2 - 1; i++ ))
  do
    echo "Working on $i th server - ${names[$i]}"
    python generate_multi.py $1 $2 $i $3 $4 $5 $6 $7 $8 $9 `date "+%s.%N"` > ../../../build/mace/application/appmencius/run_$1_$i.sh
    chmod 777 ../../../build/mace/application/appmencius/run_$1_$i.sh
    echo "==================="
    cat ../../../build/mace/application/appmencius/run_$1_$i.sh
    echo "==================="
    /scratch/yoo7/mace-project/mace/application/appmencius/scpdo.exp r3530t71bb ${names[$i]} /scratch/yoo7/mace-project/build/mace/application/appmencius/run_$1_$i.sh
    /scratch/yoo7/mace-project/mace/application/appmencius/sshdo.exp r3530t71bb ${names[$i]} /scratch/yoo7/mace-project/build/mace/application/appmencius/run_$1_$i.sh &
  done

 echo "Creating monitor"
 python generate_multi.py $1 $2 -1 $3 $4 $5 $6 $7 $8 $9 `date "+%s.%N"` > ../../../build/mace/application/appmencius/run_$1.sh
 chmod 777 ../../../build/mace/application/appmencius/run_$1.sh
 echo "==================="
 cat ../../../build/mace/application/appmencius/run_$1.sh
 echo "==================="
 cd /scratch/yoo7/mace-project/build/mace/application/appmencius
 ./run_$1.sh

#pkill mencius
else
echo "Usage : ./generate_multi.sh [job_name] [num_nodes] [max_rounds] [alpha] [beta] [tau] [check_period] [period_start] [period_end]"
fi
