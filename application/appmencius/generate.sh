if [ $# -gt 8 ]
then
python generate.py $1 $2 $3 $4 $5 $6 $7 $8 $9 `date "+%s.%N"` > ../../../build/mace/application/appmencius/run_$1.sh
chmod 777 ../../../build/mace/application/appmencius/run_$1.sh
cd /scratch/yoo7/mace-project/build/mace/application/appmencius
./run_$1.sh
#pkill mencius
else
echo "Usage : ./generate.sh [job_name] [num_nodes] [max_rounds] [alpha] [beta] [tau] [check_period] [period_start] [period_end]"
fi
