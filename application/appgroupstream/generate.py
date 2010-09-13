# Name : generate.py
# Description : It generates run_xx script.
import sys

#machine = "128.210.18.91"
machine = "augustus"
# machine = "ruapehu"
#macedir = '/home/vision82/mace-project'
macedir = '/homes/ckillian/hg/mace-project'
ip_start = 10000
node = int(sys.argv[1])
num_transport = int(sys.argv[2])
num_messages = int(sys.argv[3])
current = sys.argv[4]
ip_interval = 5
allgroup = ""
bootgroup = ""
#gdb_cmd = "gdb --command=/homes/yoo7/scratch/mace-project/mace/application/appgroupstream/gdb_cmd.txt --args "
gdb_cmd = ""
logging_para = ""
if int(sys.argv[5]) == 1:
  logging_para = " -MACE_LOG_LEVEL 1 -MACE_LOG_AUTO_ALL 1 "

for i in range(0,node):
	if allgroup == "":
		allgroup = "IPV4/"+machine+":"+str(ip_start + i*(num_transport*ip_interval))
	else:
		allgroup += " IPV4/"+machine+":"+str(ip_start + i*(num_transport*ip_interval))

for i in range(0,node):
	if bootgroup == "":
		bootgroup = "IPV4/"+machine+":"+str(ip_start + i*(num_transport*ip_interval))
	else:
		bootgroup += " IPV4/"+machine+":"+str(ip_start + i*(num_transport*ip_interval))

	if i == node-1:
		#print 'cd '+macedir+'/build/mace/application/appgroupstream; ./groupstream -ALL_NODES "' + allgroup + '"  -MACE_ADDRESS_ALLOW_LOOPBACK 1 -MACE_PORT '+str(ip_start + i*(num_transport*ip_interval)) + " -NUM_MESSAGES "+str(num_messages)+" -NUM_NODES "+str(node)+" -NUM_TRANSPORT "+str(num_transport)+" -IP_INTERVAL "+str(ip_interval)+" -DELAY $1 -PERIOD $2 -CURRENT "+str(current)+" 2>&1 | tee log_"+str(node)+"_"+str(num_transport)+"_$1_$2_" + str(i) + ".txt \n"
		print 'mkdir '+macedir+'/build/mace/application/appgroupstream/'+str(i)+'; cd '+macedir+'/build/mace/application/appgroupstream/'+str(i)+'; '+gdb_cmd+'../groupstream -BOOTSTRAP_NODES "' + bootgroup + '" -ALL_NODES "' +allgroup + '" ' + logging_para + ' -MACE_ADDRESS_ALLOW_LOOPBACK 1 -MACE_PORT '+str(ip_start + i*(num_transport*ip_interval)) + " -NUM_MESSAGES "+str(num_messages)+" -NUM_NODES "+str(node)+" -NUM_TRANSPORT "+str(num_transport)+" -IP_INTERVAL "+str(ip_interval)+" -DELAY $1 -PERIOD $2 -CURRENT "+str(current)+" 2>&1 | tee ../log_"+str(node)+"_"+str(num_transport)+"_$1_$2_" + str(i) + ".txt | egrep -v \"TRACE|ServiceStack|demux|routine|ThreadPool|DeliveryTransport|BaseTransport|TcpTransport|UdpTransport|SNAPSHOT|TcpConnection|expire_printer|AgentLock|Ticket\" \n"
	else:
		print 'mkdir '+macedir+'/build/mace/application/appgroupstream/'+str(i)+'; cd '+macedir+'/build/mace/application/appgroupstream/'+str(i)+'; '+gdb_cmd+'../groupstream -BOOTSTRAP_NODES "' + bootgroup + '" -ALL_NODES "' + allgroup + '" ' + logging_para + ' -MACE_ADDRESS_ALLOW_LOOPBACK 1 -MACE_PORT '+str(ip_start + i*(num_transport*ip_interval)) + " -NUM_MESSAGES "+str(num_messages)+" -NUM_NODES "+str(node)+" -NUM_TRANSPORT "+str(num_transport)+" -IP_INTERVAL "+str(ip_interval)+" -DELAY $1 -PERIOD $2 -CURRENT "+str(current)+" > ../log_"+str(node)+"_"+str(num_transport)+"_$1_$2_" + str(i) + ".txt 2>&1 &\n"

