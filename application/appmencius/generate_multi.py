# Name : generate_multi.py
# Description : It generates run_xx script.
import sys

#python generate.py $2 $3 $4 $5 $6 $7 $8 `date "+%s.%N"` > ../../../build/mace/application/appmencius/run_$1.sh
#echo "Usage : ./test.sh [job_name] [max_rounds] [alpha] [beta] [tau] [check_period] [period_start] [period_end]"

#machine = ["128.10.4.173", "128.10.4.174", "128.10.4.175", "128.10.4.176", "128.10.4.177", "128.10.4.178", "128.10.4.179", "128.10.4.180", "128.10.4.181"]
machine = ["128.10.4.173", "128.10.4.174", "128.10.4.175", "128.10.4.176", "128.10.4.177", "128.10.4.178", "128.10.4.179", "128.10.4.180", "128.10.4.181"]
monitor_machine = "128.10.4.172"  #cloud02
ip_start = 10000
#node = int(sys.argv[1])
#num_transport = int(sys.argv[2])
#num_messages = int(sys.argv[3])
#current = sys.argv[4]

description = sys.argv[1]
node = int(sys.argv[2])			# number of programs...
server_id = int(sys.argv[3])
max_rounds = int(sys.argv[4])
alpha = int(sys.argv[5])
beta = int(sys.argv[6])
tau = int(sys.argv[7])
check_period = int(sys.argv[8])
period_start = int(sys.argv[9])
period_end = int(sys.argv[10])
current = sys.argv[11]

ip_interval = 2
allgroup = ""
cur_server = 0

# Add monitor
allgroup = "IPV4/"+monitor_machine+":10000"

for i in range(0,node-1):
	if allgroup == "":
		allgroup = "IPV4/"+machine[i%len(machine)]+":"+str(ip_start + i*ip_interval)
	else:
		allgroup += " IPV4/"+machine[i%len(machine)]+":"+str(ip_start + i*ip_interval)

if server_id == -1:  # Case for monitor machine.
	print 'cd /scratch/yoo7/mace-project/build/mace/application/appmencius; (time -p ./mencius -ALL_NODES "' + allgroup + '"  -MACE_PORT 10000' + " -MAX_ROUNDS " + str(max_rounds) + " -ALPHA " + str(alpha) + " -BETA " + str(beta) + " -TAU " + str(tau) + " -DEFAULT_ID 0 -CHECK_PERIOD " + str(check_period) + " -PERIOD_START " + str(period_start) + " -PERIOD_END " + str(period_end) + " -CURRENT "+str(current)+" | tee log_"+str(description)+".txt) 2> time_"+str(description)+".txt\n"
else:
	for i in range(0,node-1):
		if (i % len(machine)) == server_id:		# Non-monitor machine.
			print '(time -p /scratch/yoo7/mace-project/build/mace/application/appmencius/mencius -ALL_NODES "' + allgroup + '"  -MACE_PORT '+str(ip_start + i*ip_interval) + " -MAX_ROUNDS " + str(max_rounds) + " -ALPHA " + str(alpha) + " -BETA " + str(beta) + " -TAU " + str(tau) + " -DEFAULT_ID " + str(i+1) + " -CHECK_PERIOD " + str(check_period) + " -PERIOD_START " + str(period_start) + " -PERIOD_END " + str(period_end) + " -CURRENT "+str(current)+" > /dev/null) 2> /scratch/yoo7/mace-project/build/mace/application/appmencius/time_"+str(description)+"_"+str(i)+".txt &\n"
