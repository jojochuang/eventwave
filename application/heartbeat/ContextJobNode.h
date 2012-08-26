
class ContextJobNode: public JobManagerDataHandler{
public:
    ContextJobNode() { }

    virtual void installSignalHandlers(){ }
    virtual void start(){
        master = MaceKey(ipv4, params::get<std::string>("MACE_AUTO_BOOTSTRAP_PEERS") );
        tcp = &( TcpTransport_namespace::new_TcpTransport_Transport() );
        me = tcp->localAddress();
        heartbeatApp = &(CondorHeartBeat_namespace::new_CondorHeartBeat_HeartBeat(*tcp)) ;
        heartbeatApp->registerUniqueHandler(*this);
        heartbeatApp->maceInit();
        std::cout<<"me="<<me<<",master="<<master<<std::endl;
    }
    virtual void stop(){
        std::cout<<"sleep finished"<<std::endl;
        heartbeatApp->maceExit();
        std::cout<<"maceExit() called"<<std::endl;
        SysUtil::sleepm(1000);
        mace::Shutdown();
        std::cout<<"scheduler halt"<<std::endl;
        delete tcp;
        delete heartbeatApp;
    }
protected:
    MaceKey me;
    MaceKey master;

    static HeartBeatServiceClass  *heartbeatApp;
private:
    TransportServiceClass* tcp;

};
typedef mace::map<MaceAddr, mace::set<mace::string> > ContextMapping;
HeartBeatServiceClass* ContextJobNode::heartbeatApp = NULL;
