# Name : generate.py
# Description : It generates run_xx script.
import sys

#python generate.py $2 $3 $4 $5 $6 $7 $8 `date "+%s.%N"` > ../../../build/mace/application/appmencius/run_$1.sh
#echo "Usage : ./test.sh [job_name] [max_rounds] [alpha] [beta] [tau] [check_period] [period_start] [period_end]"

machine="cloud02"
ip_start = 10000
#node = int(sys.argv[1])
#num_transport = int(sys.argv[2])
#num_messages = int(sys.argv[3])
#current = sys.argv[4]

description = sys.argv[1]
node = int(sys.argv[2])
max_rounds = int(sys.argv[3])
alpha = int(sys.argv[4])
beta = int(sys.argv[5])
tau = int(sys.argv[6])
check_period = int(sys.argv[7])
period_start = int(sys.argv[8])
period_end = int(sys.argv[9])
current = sys.argv[10]

ip_interval = 2
allgroup = ""

for i in range(0,node):
	if allgroup == "":
		allgroup = "IPV4/"+machine+":"+str(ip_start + i*ip_interval)
	else:
		allgroup += " IPV4/"+machine+":"+str(ip_start + i*ip_interval)
for i in range(0,node):
	if i == node-1:
		print 'cd /scratch/yoo7/mace-project/build/mace/application/appmencius; (time -p ./mencius -ALL_NODES "' + allgroup + '"  -MACE_PORT '+str(ip_start + i*ip_interval) + " -MAX_ROUNDS " + str(max_rounds) + " -ALPHA " + str(alpha) + " -BETA " + str(beta) + " -TAU " + str(tau) + " -CHECK_PERIOD " + str(check_period) + " -PERIOD_START " + str(period_start) + " -PERIOD_END " + str(period_end) + " -CURRENT "+str(current)+" | tee log_"+str(description)+".txt) 2> time_"+str(description)+".txt\n"
		#print 'cd /scratch/yoo7/mace-project/build/mace/application/appmencius; ./mencius -ALL_NODES "' + allgroup + '"  -MACE_PORT '+str(ip_start + i*ip_interval) + " -MAX_ROUNDS " + str(max_rounds) + " -ALPHA " + str(alpha) + " -BETA " + str(beta) + " -TAU " + str(tau) + " -CHECK_PERIOD " + str(check_period) + " -PERIOD_START " + str(period_start) + " -PERIOD_END " + str(period_end) + " -CURRENT "+str(current)+"&\n"
		#print 'cd /scratch/yoo7/mace-project/build/mace/application/appmencius; ./mencius -ALL_NODES "' + allgroup + '"  -MACE_PORT '+str(ip_start + i*ip_interval) + " -MAX_ROUNDS " + str(max_rounds) + " -ALPHA " + str(alpha) + " -BETA " + str(beta) + " -TAU " + str(tau) + " -CHECK_PERIOD " + str(check_period) + " -PERIOD_START " + str(period_start) + " -PERIOD_END " + str(period_end) + " -CURRENT "+str(current)+" | tee log_"+str(description)+".txt\n"
	else:
		print 'cd /scratch/yoo7/mace-project/build/mace/application/appmencius; (time -p ./mencius -ALL_NODES "' + allgroup + '"  -MACE_PORT '+str(ip_start + i*ip_interval) + " -MAX_ROUNDS " + str(max_rounds) + " -ALPHA " + str(alpha) + " -BETA " + str(beta) + " -TAU " + str(tau) + " -CHECK_PERIOD " + str(check_period) + " -PERIOD_START " + str(period_start) + " -PERIOD_END " + str(period_end) + " -CURRENT "+str(current)+" > /dev/null) 2> time_"+str(description)+"_"+str(i)+".txt &\n"
		#print 'cd /scratch/yoo7/mace-project/build/mace/application/appmencius; ./mencius -ALL_NODES "' + allgroup + '"  -MACE_PORT '+str(ip_start + i*ip_interval) + " -MAX_ROUNDS " + str(max_rounds) + " -ALPHA " + str(alpha) + " -BETA " + str(beta) + " -TAU " + str(tau) + " -CHECK_PERIOD " + str(check_period) + " -PERIOD_START " + str(period_start) + " -PERIOD_END " + str(period_end) + " -CURRENT "+str(current)+"&\n"
		#print 'cd /scratch/yoo7/mace-project/build/mace/application/appmencius; ./mencius -ALL_NODES "' + allgroup + '"  -MACE_PORT '+str(ip_start + i*ip_interval) + " -MAX_ROUNDS " + str(max_rounds) + " -ALPHA " + str(alpha) + " -BETA " + str(beta) + " -TAU " + str(tau) + " -CHECK_PERIOD " + str(check_period) + " -PERIOD_START " + str(period_start) + " -PERIOD_END " + str(period_end) + " -CURRENT "+str(current)+"> /dev/null &\n"

