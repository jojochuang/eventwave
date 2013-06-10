

#include "InternalMessage.h"

const uint8_t mace::InternalMessage::messageType;

int mace::InternalMessage::deserializeEvent( std::istream& in ){
    BaseMaceService* serviceInstance = BaseMaceService::getInstance( sid );
    mace::Message* ptr;
    int count = serviceInstance->deserializeMethod( in, ptr );
    helper = InternalMessageHelperPtr( static_cast< InternalMessageHelper* >( ptr ) );

    return count;
}
int mace::InternalMessage::deserializeUpcall( std::istream& in ){
    BaseMaceService* serviceInstance = BaseMaceService::getInstance( sid );
    mace::Message* ptr;
    int count = serviceInstance->deserializeMethod( in, ptr );
    helper = InternalMessageHelperPtr( static_cast< InternalMessageHelper* >( ptr ) );

    return count;
}
int mace::InternalMessage::deserializeRoutine( std::istream& in ){
    BaseMaceService* serviceInstance = BaseMaceService::getInstance( sid );
    mace::Message* ptr;
    int count = serviceInstance->deserializeMethod( in, ptr );
    helper = InternalMessageHelperPtr( static_cast< InternalMessageHelper* >( ptr ) );

    return count;
}
