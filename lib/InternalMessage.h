#ifndef _INTERNAL_MESSAGE_H
#define _INTERNAL_MESSAGE_H

#include "Serializable.h"
#include "Printable.h"
#include "m_map.h"
#include "ContextMapping.h"
namespace mace {
  class InternalMessageHelper : public Serializable, virtual public Printable  {
    
  };

  class AllocateContextObject_Message: public InternalMessageHelper, virtual public PrintPrintable{
  private:
  struct AllocateContextObject_struct{
    MaceAddr destNode;
    mace::map< uint32_t, mace::string > ContextID;
    uint64_t eventID;
    mace::ContextMapping contextMapping;
    int8_t eventType;
  };
  AllocateContextObject_struct* _data_store_;
  mutable size_t serializedByteSize;
  mutable std::string serializedCache;
  public:
    AllocateContextObject_Message( ): _data_store_( new AllocateContextObject_struct() ), 
      serializedByteSize(0) , 
      destNode(_data_store_->destNode), 
      ContextID( _data_store_->ContextID ), 
      eventID( _data_store_->eventID ), 
      contextMapping( _data_store_->contextMapping ), 
      eventType( _data_store_->eventType ){ }

    AllocateContextObject_Message( MaceAddr const & destNode, mace::map< uint32_t, mace::string > const & ContextID, uint64_t const & eventID, mace::ContextMapping const & contextMapping, int8_t const & eventType): _data_store_( NULL ), serializedByteSize(0) , destNode(destNode), ContextID( ContextID ), eventID( eventID ), contextMapping( contextMapping ), eventType( eventType ){ }
    ~AllocateContextObject_Message(){ delete _data_store_; _data_store_ = NULL; }
 
    void print(std::ostream& __out) const {
      __out << "AllocateContextObject(";
          __out << "destNode=";  mace::printItem(__out, &(destNode));
          __out << ", ";
          __out << "ContextID=";  mace::printItem(__out, &(ContextID));
          __out << ", ";
          __out << "eventID=";  mace::printItem(__out, &(eventID));
          __out << ", ";
          __out << "contextMapping=";  mace::printItem(__out, &(contextMapping));
          __out << ", ";
          __out << "eventType=";  mace::printItem(__out, &(eventType));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &destNode);
      mace::serialize(str, &ContextID);
      mace::serialize(str, &eventID);
      mace::serialize(str, &contextMapping);
      mace::serialize(str, &eventType);
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->destNode);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->contextMapping);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventType);
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    MaceAddr const & destNode;
    mace::map< uint32_t, mace::string > const & ContextID;
    uint64_t const & eventID;
    mace::ContextMapping const & contextMapping;
    int8_t const & eventType;
  };
  class AllocateContextObjectResponse_Message: public InternalMessageHelper, virtual public PrintPrintable{
  private:
  struct AllocateContextObjectResponse_struct{
    MaceAddr destNode;
    uint64_t eventID;
  };
  AllocateContextObjectResponse_struct* _data_store_;
  mutable size_t serializedByteSize;
  mutable std::string serializedCache;
  public:
    AllocateContextObjectResponse_Message() : _data_store_(new AllocateContextObjectResponse_struct()), serializedByteSize(0) , destNode(_data_store_->destNode), eventID(_data_store_->eventID) {}
    AllocateContextObjectResponse_Message(MaceAddr const & my_destNode, uint64_t const & my_eventID) : _data_store_(NULL), serializedByteSize(0), destNode(my_destNode), eventID(my_eventID) {}
    void print(std::ostream& __out) const {
      __out << "AllocateContextObjectResponse(";
          __out << "destNode=";  mace::printItem(__out, &(destNode));
          __out << ", ";
          __out << "eventID=";  mace::printItem(__out, &(eventID));
          __out << ")";
    }
    void serialize(std::string& str) const { 
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &destNode);
      mace::serialize(str, &eventID);
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { 
      serializedByteSize = 0;
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->destNode);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventID);
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }

    MaceAddr const & destNode;
    uint64_t const & eventID;
  };
  class ContextMigrationRequest_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct ContextMigrationRequest_struct {
      uint32_t ctxId ;
      MaceAddr dest ;
      bool rootOnly ;
      mace::Event event;
      uint64_t prevContextMapVersion;
      mace::vector< uint32_t > nextHops;
    };
    ContextMigrationRequest_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    ContextMigrationRequest_Message() : _data_store_(new ContextMigrationRequest_struct()), serializedByteSize(0) , ctxId(_data_store_->ctxId), dest(_data_store_->dest), rootOnly(_data_store_->rootOnly), event(_data_store_->event), prevContextMapVersion(_data_store_->prevContextMapVersion), nextHops(_data_store_->nextHops) {}
    ContextMigrationRequest_Message(uint32_t const & my_ctxId, MaceAddr const & my_dest, bool const & my_rootOnly, mace::Event const & my_event, uint64_t const & my_prevContextMapVersion, mace::vector< uint32_t > const & my_nextHops) : _data_store_(NULL), serializedByteSize(0), ctxId(my_ctxId), dest(my_dest), rootOnly(my_rootOnly), event(my_event), prevContextMapVersion(my_prevContextMapVersion), nextHops(my_nextHops) {}
    virtual ~ContextMigrationRequest_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "ContextMigrationRequest(";
          __out << "ctxId=";  mace::printItem(__out, &(ctxId));
          __out << ", ";
          __out << "dest=";  mace::printItem(__out, &(dest));
          __out << ", ";
          __out << "rootOnly=";  mace::printItem(__out, &(rootOnly));
          __out << ", ";
          __out << "event=";  mace::printItem(__out, &(event));
          __out << ", ";
          __out << "prevContextMapVersion=";  mace::printItem(__out, &(prevContextMapVersion));
          __out << ", ";
          __out << "nextHops=";  mace::printItem(__out, &(nextHops));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &ctxId);
      mace::serialize(str, &dest);
      mace::serialize(str, &rootOnly);
      mace::serialize(str, &event);
      mace::serialize(str, &prevContextMapVersion);
      mace::serialize(str, &nextHops);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { 
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ctxId);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->dest);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->rootOnly);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->event);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->prevContextMapVersion);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->nextHops);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }

    uint32_t const & ctxId;
    MaceAddr const & dest;
    bool const & rootOnly;
    mace::Event const & event;
    uint64_t const & prevContextMapVersion;
    mace::vector< uint32_t > const & nextHops;
  };
  class TransferContext_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct __event_TransferContext_struct {
      uint32_t rootContextID ;
      mace::string ctxId;
      uint32_t ctxNId ;
      mace::string checkpoint ;
      uint64_t eventId ;
      MaceAddr parentContextNode ;
      bool isresponse ;
    };
    TransferContext_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~TransferContext() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "TransferContext(";
          __out << "rootContextID=";  mace::printItem(__out, &(rootContextID));
          __out << ", ";
          __out << "ctxId=";  mace::printItem(__out, &(ctxId));
          __out << ", ";
          __out << "ctxNId=";  mace::printItem(__out, &(ctxNId));
          __out << ", ";
          __out << "checkpoint=";  mace::printItem(__out, &(checkpoint));
          __out << ", ";
          __out << "eventId=";  mace::printItem(__out, &(eventId));
          __out << ", ";
          __out << "parentContextNode=";  mace::printItem(__out, &(parentContextNode));
          __out << ", ";
          __out << "isresponse=";  mace::printItem(__out, &(isresponse));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      mace::serialize(str, &rootContextID);
      mace::serialize(str, &ctxId);
      mace::serialize(str, &ctxNId);
      mace::serialize(str, &checkpoint);
      mace::serialize(str, &eventId);
      mace::serialize(str, &parentContextNode);
      mace::serialize(str, &isresponse);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { 
    
      serializedByteSize = 0;
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->rootContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ctxId);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ctxNId);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->checkpoint);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventId);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->parentContextNode);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->isresponse);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
  };
  class create_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct create_struct {
      __asyncExtraField extra ;
      uint64_t counter;
    };
    create_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~create() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "create(";
          __out << "extra=";  mace::printItem(__out, &(extra));
          __out << ", ";
          __out << "counter=";  mace::printItem(__out, &(counter));
          __out << ")";
    }
    void serialize(std::string& str) const { 
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      mace::serialize(str, &extra);
      mace::serialize(str, &counter);
      mace::serialize(str, &extra.isRequest );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
    
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->extra);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->counter);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    
    __asyncExtraField const & extra;
    uint64_t const & counter;
  };
  class create_head_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct create_head_struct {
      __asyncExtraField extra ;
      uint64_t counter ;
      MaceAddr src ;
    };
  public:
    virtual ~create_head() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "create_head(";
          __out << "extra=";  mace::printItem(__out, &(extra));
          __out << ", ";
          __out << "counter=";  mace::printItem(__out, &(counter));
          __out << ", ";
          __out << "src=";  mace::printItem(__out, &(src));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &extra);
      mace::serialize(str, &counter);
      mace::serialize(str, &src);
      
      mace::serialize(str, &extra.isRequest );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->extra);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->counter);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->src);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
  };
  class create_response_Message: public InternalMessageHelper, virtual public PrintPrintable{
  struct create_response_struct {
    mace::Event event ;
    uint32_t counter ;
    MaceAddr targetAddress ;
  };
    create_response_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~create_response() { delete _data_store_; _data_store_ = NULL; }
    
    void print(std::ostream& __out) const {
      __out << "create_response(";
          __out << "event=";  mace::printItem(__out, &(event));
          __out << ", ";
          __out << "counter=";  mace::printItem(__out, &(counter));
          __out << ", ";
          __out << "targetAddress=";  mace::printItem(__out, &(targetAddress));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &event);
      mace::serialize(str, &counter);
      mace::serialize(str, &targetAddress);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->event);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->counter);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->targetAddress);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }

    mace::Event const & event;
    uint32_t const & counter;
    MaceAddr const & targetAddress;
  };
  class exit_committed_Message: public InternalMessageHelper, virtual public PrintPrintable{
  struct exit_committed_struct {  };
    exit_committed_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~exit_committed() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "exit_committed()";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
  };
  class enter_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
  struct __event_enter_context_struct {
    mace::Event event ;
    mace::vector< uint32_t > contextIDs ;
  };
    enter_context_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~enter_context() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "__event_enter_context(";
          __out << "event=";  mace::printItem(__out, &(event));
          __out << ", ";
          __out << "contextIDs=";  mace::printItem(__out, &(contextIDs));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &event);
      mace::serialize(str, &contextIDs);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->event);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->contextIDs);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    
    mace::Event const & event;
    mace::vector< uint32_t > const & contextIDs;
  };
  class commit_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct commit_struct {
      mace::Event event ;
    };
    commit_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~commit_Message() { delete _data_store_; _data_store_ = NULL; }
    
    void print(std::ostream& __out) const {
      __out << "__event_commit(";
          __out << "event=";  mace::printItem(__out, &(event));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      mace::serialize(str, &event);
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->event);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    
    mace::Event const & event;
  };
  class commit_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct commit_context_struct {
      mace::vector< uint32_t > nextHops ;
      uint64_t eventID ;
      int8_t eventType ;
      uint64_t eventContextMappingVersion ;
      mace::map< uint8_t, mace::map< uint32_t, uint64_t> > eventSkipID ;
      bool isresponse ;
      bool hasException ;
      uint32_t exceptionContextID ;
    };
    __event_commit_context_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~commit_context_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "__event_commit_context(";
          __out << "nextHops=";  mace::printItem(__out, &(nextHops));
          __out << ", ";
          __out << "eventID=";  mace::printItem(__out, &(eventID));
          __out << ", ";
          __out << "eventType=";  mace::printItem(__out, &(eventType));
          __out << ", ";
          __out << "eventContextMappingVersion=";  mace::printItem(__out, &(eventContextMappingVersion));
          __out << ", ";
          __out << "eventSkipID=";  mace::printItem(__out, &(eventSkipID));
          __out << ", ";
          __out << "isresponse=";  mace::printItem(__out, &(isresponse));
          __out << ", ";
          __out << "hasException=";  mace::printItem(__out, &(hasException));
          __out << ", ";
          __out << "exceptionContextID=";  mace::printItem(__out, &(exceptionContextID));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &nextHops);
      mace::serialize(str, &eventID);
      mace::serialize(str, &eventType);
      mace::serialize(str, &eventContextMappingVersion);
      mace::serialize(str, &eventSkipID);
      mace::serialize(str, &isresponse);
      mace::serialize(str, &hasException);
      mace::serialize(str, &exceptionContextID);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->nextHops);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventType);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventContextMappingVersion);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventSkipID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->isresponse);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->hasException);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->exceptionContextID);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    
    mace::vector< uint32_t > const & nextHops;
    uint64_t const & eventID;
    int8_t const & eventType;
    uint64_t const & eventContextMappingVersion;
    mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const & eventSkipID;
    bool const & isresponse;
    bool const & hasException;
    uint32_t const & exceptionContextID;
  };
  class snapshot_Message: public InternalMessageHelper, virtual public PrintPrintable{
  struct snapshot_struct {
    mace::Event event ;
    mace::string ctxID ;
    mace::string snapshotContextID ;
    mace::string snapshot ;
  };
    snapshot_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~snapshot_Message() { delete _data_store_; _data_store_ = NULL; }
    
    void print(std::ostream& __out) const {
      __out << "__event_snapshot(";
          __out << "event=";  mace::printItem(__out, &(event));
          __out << ", ";
          __out << "ctxID=";  mace::printItem(__out, &(ctxID));
          __out << ", ";
          __out << "snapshotContextID=";  mace::printItem(__out, &(snapshotContextID));
          __out << ", ";
          __out << "snapshot=";  mace::printItem(__out, &(snapshot));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &event);
      mace::serialize(str, &ctxID);
      mace::serialize(str, &snapshotContextID);
      mace::serialize(str, &snapshot);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->event);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ctxID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshotContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->snapshot);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    
    mace::Event const & event;
    mace::string const & ctxID;
    mace::string const & snapshotContextID;
    mace::string const & snapshot;
  };
  class downgrade_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct downgrade_context_struct {
      uint32_t contextID ;
      uint64_t eventID ;
      bool isresponse ;
    };
    downgrade_context_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~downgrade_context() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "__event_downgrade_context(";
          __out << "contextID=";  mace::printItem(__out, &(contextID));
          __out << ", ";
          __out << "eventID=";  mace::printItem(__out, &(eventID));
          __out << ", ";
          __out << "isresponse=";  mace::printItem(__out, &(isresponse));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &contextID);
      mace::serialize(str, &eventID);
      mace::serialize(str, &isresponse);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->contextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->isresponse);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    
    uint32_t const & contextID;
    uint64_t const & eventID;
    bool const & isresponse;
  };
  class evict_Message: public InternalMessageHelper, virtual public PrintPrintable{
  struct evict_struct {  };
    evict_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~evict() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "__event_evict()";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
  };
  class migrate_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct migrate_context_struct {
      mace::MaceAddr newNode ;
      mace::string contextName ;
      uint64_t delay ;
    };
    migrate_context_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
    virtual ~migrate_context_Message() { delete _data_store_; _data_store_ = NULL; }
    
    mace::MaceAddr const & newNode;
    mace::string const & contextName;
    uint64_t const & delay;
  public:
    void print(std::ostream& __out) const {
      __out << "__event_migrate_context(";
          __out << "newNode=";  mace::printItem(__out, &(newNode));
          __out << ", ";
          __out << "contextName=";  mace::printItem(__out, &(contextName));
          __out << ", ";
          __out << "delay=";  mace::printItem(__out, &(delay));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &newNode);
      mace::serialize(str, &contextName);
      mace::serialize(str, &delay);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->newNode);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->contextName);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->delay);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
  };
  class migrate_param_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct migrate_param_struct {
      mace::string paramid;
    };
    migrate_param_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~migrate_param_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "__event_migrate_param(";
          __out << "paramid=";  mace::printItem(__out, &(paramid));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &paramid);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->paramid);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    
    mace::string const & paramid;

  };
  class RemoveContextObject_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct RemoveContextObject_struct {
      uint64_t eventID ;
      mace::ContextMapping ctxmapCopy ;
      MaceAddr dest ;
      uint32_t contextID ;
    };
    RemoveContextObject_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:

    virtual ~RemoveContextObject_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "__event_RemoveContextObject(";
          __out << "eventID=";  mace::printItem(__out, &(eventID));
          __out << ", ";
          __out << "ctxmapCopy=";  mace::printItem(__out, &(ctxmapCopy));
          __out << ", ";
          __out << "dest=";  mace::printItem(__out, &(dest));
          __out << ", ";
          __out << "contextID=";  mace::printItem(__out, &(contextID));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();

      mace::serialize(str, &eventID);
      mace::serialize(str, &ctxmapCopy);
      mace::serialize(str, &dest);
      mace::serialize(str, &contextID);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->eventID);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->ctxmapCopy);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->dest);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->contextID);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    
    uint64_t const & eventID;
    mace::ContextMapping const & ctxmapCopy;
    MaceAddr const & dest;
    uint32_t const & contextID;
    
  };
  class delete_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct delete_context_struct {
      mace::string contextName ;
    };
    delete_context_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~delete_context_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "__event_delete_context(";
          __out << "contextName=";  mace::printItem(__out, &(contextName));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      mace::serialize(str, &contextName);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->contextName);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }

  };
  class new_head_ready_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct new_head_ready_struct {  };
    new_head_ready_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~new_head_ready_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "__event_new_head_ready(";
          
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
    
  };
  class routine_return_Message: public InternalMessageHelper, virtual public PrintPrintable{
  struct routine_return_struct {
    mace::string returnValue ;
    mace::Event event ;
  };
    routine_return_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    virtual ~routine_return() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & returnValue;
    mace::Event const & event;

    void print(std::ostream& __out) const {
      __out << "__event_routine_return(";
          __out << "returnValue=";  mace::printItem(__out, &(returnValue));
          __out << ", ";
          __out << "event=";  mace::printItem(__out, &(event));
          __out << ")";
    }
    void serialize(std::string& str) const {
      if (!serializedCache.empty()) {
        str.append(serializedCache);
        return;
      }
      size_t initsize = str.size();
      mace::serialize(str, &returnValue);
      mace::serialize(str, &event);
      
      bool __false = false;
      mace::serialize(str, &__false );
      
      if (initsize == 0) {
        serializedCache = str;
      }
      serializedByteSize = str.size() - initsize;
    }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->returnValue);
      serializedByteSize +=  mace::deserialize(__mace_in, &_data_store_->event);
      
      bool __unused;
      serializedByteSize += mace::deserialize( __mace_in, &__unused );
      
      return serializedByteSize;
    }
  };
  class InternalMessage : public Serializable, virtual public Printable{
  private:
    uint8_t msgType;
    InternalMessageHelper* helper;
  public:
    InternalMessageHelper* getHelper()const { return helper; }
    uint8_t getMessageType() const{ return msgType; }

    struct AllocateContextObject_type{};
    struct AllocateContextObjectResponse_type{};
    struct ContextMigrationRequest_type{}; // TODO: WC: change to a better name
    struct TransferContext_type{};
    struct create_type{};
    struct create_head_type{};
    struct create_response_type{};
    struct exit_committed_type{};
    struct enter_context_type{};
    struct commit_type{};
    struct commit_context_type{}; // TODO: WC: rename it. it should be renamed to downgrade
    struct snapshot_type{};
    struct downgrade_context_type{}; // TODO: may be this is a duplicate of commit_context?
    struct evict_type{};
    struct migrate_context_type{};
    struct migrate_param_type{};
    struct RemoveContextObject_type{};
    struct delete_context_type{};
    struct new_head_ready_type{};
    struct routine_return_type{};

  const static uint8_t UNKNOWN = 0;
  const static uint8_t ALLOCATE_CONTEXT_OBJECT = 1;
  const static uint8_t ALLOCATE_CONTEXT_OBJECT_RESPONSE = 2;
  const static uint8_t CONTEXT_MIGRATION_REQUEST = 3;
  const static uint8_t TRANSFER_CONTEXT = 4;
  const static uint8_t CREATE = 5;
  const static uint8_t CREATE_HEAD = 6;
  const static uint8_t CREATE_RESPONSE = 7;
  const static uint8_t EXIT_COMMITTED = 8;
  const static uint8_t ENTER_CONTEXT = 9;
  const static uint8_t COMMIT = 10;
  const static uint8_t COMMIT_CONTEXT = 11;
  const static uint8_t SNAPSHOT = 12;
  const static uint8_t DOWNGRADE_CONTEXT = 13;
  const static uint8_t EVICT = 14;
  const static uint8_t MIGRATE_CONTEXT = 15;
  const static uint8_t MIGRATE_PARAM = 16;
  const static uint8_t REMOVE_CONTEXT_OBJECT = 17;
  const static uint8_t DELETE_CONTEXT = 18;
  const static uint8_t NEW_HEAD_READY = 19;
  const static uint8_t ROUTINE_RETURN = 20;
    InternalMessage( AllocateContextObject_type t, MaceAddr const & destNode, mace::map< uint32_t, mace::string > const & ContextID, uint64_t const & eventID, mace::ContextMapping const & contextMapping, int8_t const & eventType): msgType( ALLOCATE_CONTEXT_OBJECT ), helper(new AllocateContextObject_Message(destNode, ContextID, eventID, contextMapping, eventType) ) {}
    InternalMessage( AllocateContextObjectResponse_type t): helper(new AllocateContextObjectResponse_Message() ) {}
    InternalMessage( ContextMigrationRequest_type t): helper(new ContextMigrationRequest_Message() ) {} // TODO: WC: change to a better name
    InternalMessage( TransferContext_type t): helper(new TransferContext_Message() ) {}
    InternalMessage( create_type t): helper(new create_Message() ) {}
    InternalMessage( create_head_type t): helper(new create_head_Message() ) {}
    InternalMessage( create_response_type t): helper(new create_response_Message() ) {}
    InternalMessage( exit_committed_type t): helper(new exit_committed_Message() ) {}
    InternalMessage( enter_context_type t): helper(new enter_context_Message() ) {}
    InternalMessage( commit_type t): helper(new commit_Message() ) {}
    InternalMessage( commit_context_type t): helper(new commit_context_Message() ) {} // TODO: WC: rename it. it should be renamed to downgrade
    InternalMessage( snapshot_type t): helper(new snapshot_Message() ) {}
    InternalMessage( downgrade_context_type t): helper(new downgrade_context_Message() ) {} // TODO: may be this is a duplicate of commit_context?
    InternalMessage( evict_type t): helper(new evict_Message() ) {}
    InternalMessage( migrate_context_type t): helper(new migrate_context_Message() ) {}
    InternalMessage( migrate_param_type t): helper(new migrate_param_Message() ) {}
    InternalMessage( RemoveContextObject_type t): helper(new RemoveContextObject_Message() ) {}
    InternalMessage( delete_context_type t): helper(new delete_context_Message() ) {}
    InternalMessage( new_head_ready_type t): helper(new new_head_ready_Message() ) {}
    InternalMessage( routine_return_type t): helper(new routine_return_Message() ) {}

    void print(std::ostream& out) const {
      if( helper != NULL ){
        out << (*helper);
      }
    }
    virtual void serialize(std::string& str) const {
      mace::serialize(str, &msgType);
      if(msgType != UNKNOWN && helper != NULL) {
        helper->serialize(str);
      }
    }
    virtual int deserialize(std::istream& in) throw(SerializationException) {
      int count = 0;
      count += mace::deserialize(in, &msgType);

      switch( msgType ){
  case UNKNOWN: return count; break;
  case ALLOCATE_CONTEXT_OBJECT: helper = new AllocateContextObject_Message(); break;
  case ALLOCATE_CONTEXT_OBJECT_RESPONSE: helper = new AllocateContextObjectResponse_Message(); break;
  case CONTEXT_MIGRATION_REQUEST: helper = new ContextMigrationRequest_Message(); break;
  case TRANSFER_CONTEXT: helper = new TransferContext_Message(); break;
  case CREATE: helper = new create_Message(); break;
  case CREATE_HEAD: helper = new create_head_Message(); break; 
  case CREATE_RESPONSE: helper = new create_response_Message(); break;
  case EXIT_COMMITTED: helper = new exit_committed_Message(); break;
  case ENTER_CONTEXT: helper = new enter_context_Message(); break;
  case COMMIT: helper = new commit_Message(); break;
  case COMMIT_CONTEXT: helper = new commit_context_Message(); break;
  case SNAPSHOT: helper = new snapshot_Message(); break;
  case DOWNGRADE_CONTEXT: helper = new downgrade_context_Message(); break;
  case EVICT: helper = new evict_Message(); break;
  case MIGRATE_CONTEXT: helper = new migrate_context_Message(); break;
  case MIGRATE_PARAM: helper = new migrate_param_Message(); break;
  case REMOVE_CONTEXT_OBJECT: helper = new RemoveContextObject_Message(); break;
  case DELETE_CONTEXT: helper = new delete_context_Message(); break;
  case NEW_HEAD_READY: helper = new new_head_ready_Message(); break;
  case ROUTINE_RETURN: helper = new routine_return_Message(); break;
  default: throw(InvalidMaceKeyException("Deserializing bad internal message type "+boost::lexical_cast<std::string>(msgType)+"!"));
    
      }
      count += helper->deserialize(in); 
      return count;
    }
    virtual ~InternalMessage() { 
//#ifndef MACE_KEY_USE_SHARED_PTR
      delete helper; 
//#endif
    }
  };

 const mace::InternalMessage::AllocateContextObject_type AllocateContextObject = mace::InternalMessage::AllocateContextObject_type();
 const mace::InternalMessage::AllocateContextObjectResponse_type AllocateContextObjectResponse = mace::InternalMessage::AllocateContextObjectResponse_type();
 const mace::InternalMessage::ContextMigrationRequest_type ContextMigrationRequest = mace::InternalMessage::ContextMigrationRequest_type(); // TODO: WC: change to a better name
 const mace::InternalMessage::TransferContext_type TransferContext = mace::InternalMessage::TransferContext_type();
 const mace::InternalMessage::create_type create = mace::InternalMessage::create_type();
 const mace::InternalMessage::create_head_type create_head = mace::InternalMessage::create_head_type();
 const mace::InternalMessage::create_response_type create_response = mace::InternalMessage::create_response_type();
 const mace::InternalMessage::exit_committed_type exit_committed = mace::InternalMessage::exit_committed_type();
 const mace::InternalMessage::enter_context_type enter_context = mace::InternalMessage::enter_context_type();
 const mace::InternalMessage::commit_type commit = mace::InternalMessage::commit_type();
 const mace::InternalMessage::commit_context_type commit_context = mace::InternalMessage::commit_context_type(); // TODO: WC: rename it. it should be renamed to downgrade
 const mace::InternalMessage::snapshot_type snapshot = mace::InternalMessage::snapshot_type();
 const mace::InternalMessage::downgrade_context_type downgrade_context = mace::InternalMessage::downgrade_context_type(); // TODO: may be this is a duplicate of commit_context?
 const mace::InternalMessage::evict_type evict = mace::InternalMessage::evict_type();
 const mace::InternalMessage::migrate_context_type migrate_context = mace::InternalMessage::migrate_context_type();
 const mace::InternalMessage::migrate_param_type migrate_param = mace::InternalMessage::migrate_param_type();
 const mace::InternalMessage::RemoveContextObject_type RemoveContextObject = mace::InternalMessage::RemoveContextObject_type();
 const mace::InternalMessage::delete_context_type delete_context = mace::InternalMessage::delete_context_type();
 const mace::InternalMessage::new_head_ready_type new_head_ready = mace::InternalMessage::new_head_ready_type();
 const mace::InternalMessage::routine_return_type routine_return = mace::InternalMessage::routine_return_type();
}
#endif
