#include "ContextJobApplication.h"
#include "HeadEventDispatch.h"
template<class T, class Handler>
void mace::ContextJobApplication<T, Handler>::migrateOnCondition(){
    StringList paramset;
    paramset = StrUtil::split(" ", params::get<std::string>("lib.ContextJobApplication.conditional_migration"));
    std::vector< ConditionalMigrationItem > migrateCondition;
    uint32_t sample_period = 0;
    for (StringList::const_iterator i = paramset.begin(); i != paramset.end(); i++) {
      std::string const& param_id = *i;
      std::cout<<"conditional migrate parameter set id: "<< param_id << std::endl;
      if( !params::containsKey( param_id + ".condition" )  ){
        std::cerr<<"Missing "<< param_id << ".condition parameter"<<std::endl;
        continue;
      }else if(  !params::containsKey( param_id + ".dest" ) ){
        std::cerr<<"Missing "<< param_id << ".dest parameter"<<std::endl;
        continue;
      }else if( !params::containsKey( param_id + ".service" ) ){
        std::cerr<<"Missing "<< param_id << ".service parameter"<<std::endl;
        continue;
      }else if( !params::containsKey( param_id + ".contexts" ) ){
        std::cerr<<"Missing "<< param_id << ".contexts parameter"<<std::endl;
        continue;
      }else if( !params::containsKey( param_id + ".sample_period" ) ){
        std::cerr<<"Missing "<< param_id << ".sample_period parameter"<<std::endl;
        continue;
      }
      StringList condition_param = StrUtil::split(" ", params::get<std::string>( param_id + ".condition" ));
      uint8_t condition;
      if( condition_param[0].compare("ON_EVENT_LATENCY") == 0 ){
        HeadEventDispatch::sampleLatency(true);
        condition = ConditionalMigrationItem::ON_EVENT_LATENCY;
      }

      MaceAddr dest = MaceKey(ipv4, params::get<std::string>( param_id + ".dest" ) ).getMaceAddr();
      uint8_t service = static_cast<uint8_t>(params::get<uint32_t>( param_id + ".service" ));
      StringVector mapping = split(params::get<mace::string>( param_id + ".contexts" ), '\n');
      sample_period = params::get<uint32_t>( param_id + ".sample_period" );
      migrateCondition.push_back( ConditionalMigrationItem( condition, dest, service, mapping ) );

    }
    if( params::get("lib.ContextJobApplication.debug",false )==true){
      std::cout<< migrateCondition.size() << " conditional migration requests"<< std::endl;
    }
    while(true ){
      // sleep for some time until same_period
      SysUtil::sleepu( sample_period );

      // read sampling data
      for( std::vector< ConditionalMigrationItem >::const_iterator mcIt = migrateCondition.begin(); mcIt != migrateCondition.end(); mcIt++ ){
        switch( mcIt->condition ){
          case ConditionalMigrationItem::ON_EVENT_LATENCY:{
            double avgLatency = HeadEventDispatch::getAverageLatency();
            migrateOnLatencyCondition( avgLatency, *mcIt );
          }
        }
      }
    }
}
template<class T, class Handler>
void mace::ContextJobApplication<T, Handler>::migrateOnLatencyCondition( double avgLatency, ConditionalMigrationItem const& condition ){
  
}
