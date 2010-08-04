#include "SysUtil.h"
#include "lib/mace.h"
#include "lib/SysUtil.h"

#include "services/Mencius/Mencius-init.h"
#include "services/Mencius/CoordinatedPaxos-init.h"
#include "TcpTransport.h"
#include "TcpTransport-init.h"


/* Variables */
MaceKey myip;  //This is always the IP address

/* Calculate moving average of latency */
int gotten = 0;		// number of messages received
int state = -1;		// 0 = ready-to-commit, 1 = waiting
int myid = -1;
int myid_start = -1;
int mymsg = -1;
int period_start = 0;
int period_end = 0;
int max_rounds = 0;
int total_rounds = 0;
class CoordinatedConsensusReceiveHandler : public CoordinatedConsensusHandler {
	/* upcall onCommit */

	void onCommit(const mace::string& msg, registration_uid_t serviceUid)
	{

		int id = boost::lexical_cast<int>(msg);

		if( myid_start <= id && id < myid_start + max_rounds )
		{
			std::cout << "* My message received" << std::endl;
			gotten++;
			assert(period_end>=period_start);
			usleep(RandomUtil::randInt() % (period_end-period_start)+period_start);
			state = 0;
		}
		else
		{
			std::cout << "* Else message received" << std::endl;
		}

		total_rounds--;

		std::cout << "* RECEIVED["<<serviceUid<<"] : " << msg << "  total_recvd = " << gotten << "  total_left = " << total_rounds << std::endl;

		return;
	}

	void onReady(registration_uid_t serviceUid)
	{
		std::cout << "onReady() called." << std::endl;
		state = 0;
		return;
	}

	const MaceKey& getLocalAddress(registration_uid_t serviceUid)
	{
		myip = MaceKey(ipv4, Util::getMaceAddr());
		return myip;
	}

};


int main(int argc, char* argv[]) {

	/* Add required params */
	params::addRequired("MACE_PORT", "Port to use for connections.");
	params::addRequired("ALL_NODES", "Addresses of nodes to add. e.g. IPV4/1.1.1.1:port IPV4/2.2.2.2 ... (be aware of uppercases!)");
	params::addRequired("MAX_ROUNDS", "Number of messages sent by each client.");
	//params::addRequired("ALPHA", "Number of outstanding messages.");
	//params::addRequired("BETA", "Interval of instance.");
	//params::addRequired("TAU", "One-way delay.");
	//params::addRequired("PERIOD_START", "Pause time for committing a new value.");
	//params::addRequired("PERIOD_END", "Pause time for committing a new value.");

	params::loadparams(argc, argv);

	/* Get parameters */
	myip = MaceKey(ipv4, Util::getMaceAddr());

	max_rounds = params::get("MAX_ROUNDS", 1);
	int alpha = params::get("ALPHA", 20);
	int beta = params::get("BETA", 100000);
	int tau = params::get("TAU", 50*1000);
	int check_period = params::get("CHECK_PERIOD", 10*1000);
	int default_id = params::get("DEFAULT_ID", -1);
	period_start = params::get("PERIOD_START", 0);
	period_end = params::get("PERIOD_END", 1);
	double current_time = params::get<double>("CURRENT", 0);

	printf("* myip: %s\n", myip.toString().c_str());
	printf("* max_rounds: %d\n", max_rounds);
	printf("* alpha: %d\n", alpha);
	printf("* beta: %d\n", beta);
	printf("* tau: %d\n", tau);
	printf("* period_start: %d\n", period_start);
	printf("* period_end: %d\n", period_end);
	printf("* current_time: %.4f\n", current_time);

	/* Get nodeset and create subgroups */
	NodeSet allNodes = params::get<NodeSet>("ALL_NODES");	// ipv4

	std::list<ServiceClass*> thingsToExit;

	/* Create services */

	TransportServiceClass *tcp = &(TcpTransport_namespace::new_TcpTransport_Transport());	// 1
	thingsToExit.push_back(tcp);

	BasicConsensusServiceClass *cp = &(CoordinatedPaxos_namespace::new_CoordinatedPaxos_BasicConsensus(*tcp));
	thingsToExit.push_back(cp);

	CoordinatedConsensusServiceClass *mencius = &(Mencius_namespace::new_Mencius_CoordinatedConsensus(*cp, tau, alpha, beta));
	thingsToExit.push_back(mencius);

	CoordinatedConsensusReceiveHandler h;
	mencius->registerUniqueHandler(h);


	/* Now handle groups */
	ASSERT(!allNodes.empty());

	total_rounds = allNodes.size() * max_rounds;

	/* Joining overlay */
	std::cout << "* AllNodes listed are : " << std::endl;;

	int t = 0;
	for (NodeSet::const_iterator j = allNodes.begin(); j != allNodes.end(); j++, t++) {
		std::cout << (*j) << std::endl;
		if (*j == myip.toString()) {
			myid = t;
			myid_start = 10 + t * allNodes.size() * max_rounds;
		}
	}

	if( myid == -1 )
	{
		myid = default_id;
	}

	assert(myid != -1);

	mymsg = myid_start;


	/* Now start service */
	mencius->maceInit();

	usleep(5*1000*1000);

	while( state == -1 )
	{
		mencius->joinGroup(allNodes);
		usleep(1*1000*1000);
	}
	

	std::cout << "Done in joining" << std::endl;

	// Deserialize nodes
	// To maximize the effect, sending time will be SYNCHRONIZED.

//	std::cout << "current_time + 5 : " << (current_time + 5) << std::endl;
//	std::cout << "TimeUtil::timeu() : " << TimeUtil::timeu() << std::endl;
//	while(current_time + 5 > TimeUtil::timeu() / 1000000.0 )
//	{
//		usleep(check_period);
//	}

	std::cout << "Starting messaging..." << std::endl;


	/* Basically, it will keep sending to their groups. */
	while(total_rounds > 0)
	{
		if( state == 0 ) /* Ready to commit */
		{
			std::ostringstream ss;
			//ss << "[" << myip << "]-" << msgId++;
			ss << boost::lexical_cast<std::string>(mymsg++);
			//total_rounds--;
			mencius->onClientRequest(ss.str());
			std::cout << "Sending " << ss.str() << std::endl;
			state = 1;
		}
		else if(state == 1 || state == -1)	// state == 1 /* Waiting */
		{
			usleep(check_period);
		}
		std::cout << "..." << std::endl;
	}

	std::cout << "DONE!!!" << std::endl;

	mencius->finishCommit();

	std::cout << "FINISHED!!!" << std::endl;

	usleep(5*1000*1000);

	return 0;

	// All done.
//	for(std::list<ServiceClass*>::iterator ex = thingsToExit.begin(); ex != thingsToExit.end(); ex++) {
//		(*ex)->maceExit();
//	}
//	Scheduler::haltScheduler();

	// return 0;

}
