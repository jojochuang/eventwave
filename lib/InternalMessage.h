#ifndef _INTERNAL_MESSAGE_H
#define _INTERNAL_MESSAGE_H

#include "Serializable.h"
#include "Printable.h"
#include "m_map.h"
#include "ContextMapping.h"
#include "Message.h"
#include "SpecialMessage.h"
#include <limits>
namespace mace {
  typedef  AsyncEvent_Message ApplicationUpcall;
  class InvalidInternalMessageException : public SerializationException {
  public:
    InvalidInternalMessageException(const std::string& m) : SerializationException(m) { }
    virtual ~InvalidInternalMessageException() throw() {}
    void rethrow() const { throw *this; }
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
    // WC: C++03 forbids calling a constructor from another constructor.
    AllocateContextObject_Message( InternalMessageHelper const* o): _data_store_( new AllocateContextObject_struct() ), 
      serializedByteSize(0) , 
      destNode(_data_store_->destNode), 
      ContextID( _data_store_->ContextID ), 
      eventID( _data_store_->eventID ), 
      contextMapping( _data_store_->contextMapping ), 
      eventType( _data_store_->eventType ) {
     AllocateContextObject_Message const* orig_helper = static_cast< AllocateContextObject_Message const* >( o );
      _data_store_->destNode = orig_helper->destNode;
      _data_store_->ContextID = orig_helper->ContextID;
      _data_store_->eventID = orig_helper->eventID;
      _data_store_->contextMapping = orig_helper->contextMapping;
      _data_store_->eventType = orig_helper->eventType;
    }
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
    ContextMigrationRequest_Message( InternalMessageHelper const* o): _data_store_( new ContextMigrationRequest_struct() ), 
      serializedByteSize(0) , ctxId(_data_store_->ctxId), dest(_data_store_->dest), rootOnly(_data_store_->rootOnly), event(_data_store_->event), prevContextMapVersion(_data_store_->prevContextMapVersion), nextHops(_data_store_->nextHops)
      {
     ContextMigrationRequest_Message const* orig_helper = static_cast< ContextMigrationRequest_Message const* >( o );
      _data_store_->ctxId = orig_helper->ctxId;
      _data_store_->dest = orig_helper->dest;
      _data_store_->rootOnly = orig_helper->rootOnly;
      _data_store_->event = orig_helper->event;
      _data_store_->prevContextMapVersion = orig_helper->prevContextMapVersion;
      _data_store_->nextHops = orig_helper->nextHops;

    }
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
    struct TransferContext_struct {
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
    TransferContext_Message() : _data_store_(new TransferContext_struct()), serializedByteSize(0) , rootContextID(_data_store_->rootContextID), ctxId(_data_store_->ctxId), ctxNId(_data_store_->ctxNId), checkpoint(_data_store_->checkpoint), eventId(_data_store_->eventId), parentContextNode(_data_store_->parentContextNode), isresponse(_data_store_->isresponse) {}
    TransferContext_Message(uint32_t const & my_rootContextID, mace::string const & my_ctxId, uint32_t const & my_ctxNId, mace::string const & my_checkpoint, uint64_t const & my_eventId, MaceAddr const & my_parentContextNode, bool const & my_isresponse) : _data_store_(NULL), serializedByteSize(0), rootContextID(my_rootContextID), ctxId(my_ctxId), ctxNId(my_ctxNId), checkpoint(my_checkpoint), eventId(my_eventId), parentContextNode(my_parentContextNode), isresponse(my_isresponse) {}
    TransferContext_Message(InternalMessageHelper const* o) : _data_store_(new TransferContext_struct()), serializedByteSize(0) , rootContextID(_data_store_->rootContextID), ctxId(_data_store_->ctxId), ctxNId(_data_store_->ctxNId), checkpoint(_data_store_->checkpoint), eventId(_data_store_->eventId), parentContextNode(_data_store_->parentContextNode), isresponse(_data_store_->isresponse) {
     TransferContext_Message const* orig_helper = static_cast< TransferContext_Message const* >( o );
      _data_store_->rootContextID = orig_helper->rootContextID;
      _data_store_->ctxId = orig_helper->ctxId;
      _data_store_->ctxNId = orig_helper->ctxNId;
      _data_store_->checkpoint = orig_helper->checkpoint;
      _data_store_->eventId = orig_helper->eventId;
      _data_store_->parentContextNode = orig_helper->parentContextNode;
      _data_store_->isresponse = orig_helper->isresponse;
    }
    virtual ~TransferContext_Message() { delete _data_store_; _data_store_ = NULL; }
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
    uint32_t const& rootContextID ;
    mace::string const& ctxId;
    uint32_t const& ctxNId ;
    mace::string const& checkpoint ;
    uint64_t const& eventId ;
    MaceAddr const& parentContextNode ;
    bool const& isresponse ;
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
    create_Message() : _data_store_(new create_struct()), serializedByteSize(0) , extra(_data_store_->extra), counter(_data_store_->counter) {}
    create_Message(__asyncExtraField const & my_extra, uint64_t const & my_counter) : _data_store_(NULL), serializedByteSize(0), extra(my_extra), counter(my_counter) {}
    create_Message(InternalMessageHelper const* o) : _data_store_(new create_struct()), serializedByteSize(0) , extra(_data_store_->extra), counter(_data_store_->counter) {
     create_Message const* orig_helper = static_cast< create_Message const* >( o );
      _data_store_->extra = orig_helper->extra;
      _data_store_->counter = orig_helper->counter;
    }
    virtual ~create_Message() { delete _data_store_; _data_store_ = NULL; }
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
    create_head_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    create_head_Message() : _data_store_(new create_head_struct()), serializedByteSize(0) , extra(_data_store_->extra), counter(_data_store_->counter), src(_data_store_->src) {}
    create_head_Message(__asyncExtraField const & my_extra, uint64_t const & my_counter, MaceAddr const & my_src) : _data_store_(NULL), serializedByteSize(0), extra(my_extra), counter(my_counter), src(my_src) {}
    create_head_Message(InternalMessageHelper const* o) : _data_store_(new create_head_struct()), serializedByteSize(0) , extra(_data_store_->extra), counter(_data_store_->counter), src(_data_store_->src) {
    
     create_head_Message const* orig_helper = static_cast< create_head_Message const* >( o );
      _data_store_->extra = orig_helper->extra;
      _data_store_->counter = orig_helper->counter;
      _data_store_->src = orig_helper->src;
    }


    virtual ~create_head_Message() { delete _data_store_; _data_store_ = NULL; }
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
    __asyncExtraField const& extra;
    uint64_t const& counter;
    MaceAddr const& src;
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
    create_response_Message() : _data_store_(new create_response_struct()), serializedByteSize(0) , event(_data_store_->event), counter(_data_store_->counter), targetAddress(_data_store_->targetAddress) {}
    create_response_Message(mace::Event const & my_event, uint32_t const & my_counter, MaceAddr const & my_targetAddress) : _data_store_(NULL), serializedByteSize(0), event(my_event), counter(my_counter), targetAddress(my_targetAddress) {}
    create_response_Message(InternalMessageHelper const* o) : _data_store_(new create_response_struct()), serializedByteSize(0) , event(_data_store_->event), counter(_data_store_->counter), targetAddress(_data_store_->targetAddress) {
     create_response_Message const* orig_helper = static_cast< create_response_Message const* >( o );
      _data_store_->event = orig_helper->event;
      _data_store_->counter = orig_helper->counter;
      _data_store_->targetAddress = orig_helper->targetAddress;
    
    
    }
    virtual ~create_response_Message() { delete _data_store_; _data_store_ = NULL; }
    
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
    exit_committed_Message() : _data_store_(new exit_committed_struct()), serializedByteSize(0)  {}
    exit_committed_Message(InternalMessageHelper const* o) : _data_store_(new exit_committed_struct()), serializedByteSize(0)  {
    }
    virtual ~exit_committed_Message() { delete _data_store_; _data_store_ = NULL; }
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
  struct enter_context_struct {
    mace::Event event ;
    mace::vector< uint32_t > contextIDs ;
  };
    enter_context_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    enter_context_Message() : _data_store_(new enter_context_struct()), serializedByteSize(0) , event(_data_store_->event), contextIDs(_data_store_->contextIDs) {}
    enter_context_Message(mace::Event const & my_event, mace::vector< uint32_t > const & my_contextIDs) : _data_store_(NULL), serializedByteSize(0), event(my_event), contextIDs(my_contextIDs) {}
    enter_context_Message(InternalMessageHelper const* o ) : _data_store_(new enter_context_struct()), serializedByteSize(0) , event(_data_store_->event), contextIDs(_data_store_->contextIDs) {
     enter_context_Message const* orig_helper = static_cast< enter_context_Message const* >( o );
      _data_store_->event = orig_helper->event;
      _data_store_->contextIDs = orig_helper->contextIDs;
    
    }
    virtual ~enter_context_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "enter_context(";
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
    commit_Message() : _data_store_(new commit_struct()), serializedByteSize(0) , event(_data_store_->event) {}
    commit_Message(mace::Event const & my_event) : _data_store_(NULL), serializedByteSize(0), event(my_event) {}
    commit_Message(InternalMessageHelper const* o) : _data_store_(new commit_struct()), serializedByteSize(0) , event(_data_store_->event) {
     commit_Message const* orig_helper = static_cast< commit_Message const* >( o );
      _data_store_->event = orig_helper->event;
    }
    virtual ~commit_Message() { delete _data_store_; _data_store_ = NULL; }
    
    void print(std::ostream& __out) const {
      __out << "commit(";
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
      //mace::map< uint8_t, mace::Event::EventSkipRecordType > eventSkipID ;
      mace::Event::SkipRecordType eventSkipID ;
      bool isresponse ;
      bool hasException ;
      uint32_t exceptionContextID ;
    };
    commit_context_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    commit_context_Message() : _data_store_(new commit_context_struct()), serializedByteSize(0) , nextHops(_data_store_->nextHops), eventID(_data_store_->eventID), eventType(_data_store_->eventType), eventContextMappingVersion(_data_store_->eventContextMappingVersion), eventSkipID(_data_store_->eventSkipID), isresponse(_data_store_->isresponse), hasException(_data_store_->hasException), exceptionContextID(_data_store_->exceptionContextID) {}

    commit_context_Message(mace::vector< uint32_t > const & my_nextHops, uint64_t const & my_eventID, int8_t const & my_eventType, uint64_t const & my_eventContextMappingVersion, mace::Event::SkipRecordType const & my_eventSkipID, bool const & my_isresponse, bool const & my_hasException, uint32_t const & my_exceptionContextID) : _data_store_(NULL), serializedByteSize(0), nextHops(my_nextHops), eventID(my_eventID), eventType(my_eventType), eventContextMappingVersion(my_eventContextMappingVersion), eventSkipID(my_eventSkipID), isresponse(my_isresponse), hasException(my_hasException), exceptionContextID(my_exceptionContextID) {}

    /*commit_context_Message(mace::vector< uint32_t > const & my_nextHops, uint64_t const & my_eventID, int8_t const & my_eventType, uint64_t const & my_eventContextMappingVersion, mace::map< uint8_t, mace::map< uint32_t, uint64_t> > const & my_eventSkipID, bool const & my_isresponse, bool const & my_hasException, uint32_t const & my_exceptionContextID) : 
      _data_store_(new commit_context_struct()), serializedByteSize(0) , nextHops(_data_store_->nextHops), eventID(_data_store_->eventID), eventType(_data_store_->eventType), eventContextMappingVersion(_data_store_->eventContextMappingVersion), eventSkipID(_data_store_->eventSkipID), isresponse(_data_store_->isresponse), hasException(_data_store_->hasException), exceptionContextID(_data_store_->exceptionContextID) {

      _data_store_->nextHops = my_nextHops;
      _data_store_->eventID = my_eventID;
      _data_store_->eventType = my_eventType;
      _data_store_->eventContextMappingVersion = my_eventContextMappingVersion;
      _data_store_->eventSkipID = my_eventSkipID;
      _data_store_->isresponse = my_isresponse;
      _data_store_->hasException = my_hasException;
      _data_store_->exceptionContextID = my_exceptionContextID;
      
    }*/



    commit_context_Message(InternalMessageHelper const* o) : _data_store_(new commit_context_struct()), serializedByteSize(0) , nextHops(_data_store_->nextHops), eventID(_data_store_->eventID), eventType(_data_store_->eventType), eventContextMappingVersion(_data_store_->eventContextMappingVersion), eventSkipID(_data_store_->eventSkipID), isresponse(_data_store_->isresponse), hasException(_data_store_->hasException), exceptionContextID(_data_store_->exceptionContextID) {
    
     commit_context_Message const* orig_helper = static_cast< commit_context_Message const* >( o );
      _data_store_->nextHops = orig_helper->nextHops;
      _data_store_->eventID = orig_helper->eventID;
      _data_store_->eventType = orig_helper->eventType;
      _data_store_->eventContextMappingVersion = orig_helper->eventContextMappingVersion;
      _data_store_->eventSkipID = orig_helper->eventSkipID;
      _data_store_->isresponse = orig_helper->isresponse;
      _data_store_->hasException = orig_helper->hasException;
      _data_store_->exceptionContextID = orig_helper->exceptionContextID;
    
    }
    virtual ~commit_context_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "commit_context(";
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
    mace::Event::SkipRecordType const & eventSkipID;
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
    snapshot_Message() : _data_store_(new snapshot_struct()), serializedByteSize(0) , event(_data_store_->event), ctxID(_data_store_->ctxID), snapshotContextID(_data_store_->snapshotContextID), snapshot(_data_store_->snapshot) {}
    snapshot_Message(mace::Event const & my_event, mace::string const & my_ctxID, mace::string const & my_snapshotContextID, mace::string const & my_snapshot) : _data_store_(NULL), serializedByteSize(0), event(my_event), ctxID(my_ctxID), snapshotContextID(my_snapshotContextID), snapshot(my_snapshot) {}
    snapshot_Message(InternalMessageHelper const* o) : _data_store_(new snapshot_struct()), serializedByteSize(0) , event(_data_store_->event), ctxID(_data_store_->ctxID), snapshotContextID(_data_store_->snapshotContextID), snapshot(_data_store_->snapshot) {
    
     snapshot_Message const* orig_helper = static_cast< snapshot_Message const* >( o );
      _data_store_->event = orig_helper->event;
      _data_store_->ctxID = orig_helper->ctxID;
      _data_store_->snapshotContextID = orig_helper->snapshotContextID;
      _data_store_->snapshot = orig_helper->snapshot;
    
    }
    virtual ~snapshot_Message() { delete _data_store_; _data_store_ = NULL; }
    
    void print(std::ostream& __out) const {
      __out << "snapshot(";
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
    downgrade_context_Message() : _data_store_(new downgrade_context_struct()), serializedByteSize(0) , contextID(_data_store_->contextID), eventID(_data_store_->eventID), isresponse(_data_store_->isresponse) {}
    downgrade_context_Message(uint32_t const & my_contextID, uint64_t const & my_eventID, bool const & my_isresponse) : _data_store_(NULL), serializedByteSize(0), contextID(my_contextID), eventID(my_eventID), isresponse(my_isresponse) {}
    downgrade_context_Message(InternalMessageHelper const* o) : _data_store_(new downgrade_context_struct()), serializedByteSize(0) , contextID(_data_store_->contextID), eventID(_data_store_->eventID), isresponse(_data_store_->isresponse) {
    
     downgrade_context_Message const* orig_helper = static_cast< downgrade_context_Message const* >( o );
      _data_store_->contextID = orig_helper->contextID;
      _data_store_->eventID = orig_helper->eventID;
      _data_store_->isresponse = orig_helper->isresponse;
    
    }
    virtual ~downgrade_context_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "downgrade_context(";
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
    evict_Message() : _data_store_(new evict_struct()), serializedByteSize(0)  {}
    
    evict_Message(const evict_Message& _orig) : _data_store_(new evict_struct()), serializedByteSize(0)  {
      
    }
    evict_Message(InternalMessageHelper const* o) : _data_store_(new evict_struct()), serializedByteSize(0)  {
    }
    virtual ~evict_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "evict()";
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
    
  public:
    migrate_context_Message() : _data_store_(new migrate_context_struct()), serializedByteSize(0) , newNode(_data_store_->newNode), contextName(_data_store_->contextName), delay(_data_store_->delay) {}
    migrate_context_Message(mace::MaceAddr const & my_newNode, mace::string const & my_contextName, uint64_t const & my_delay) : _data_store_(NULL), serializedByteSize(0), newNode(my_newNode), contextName(my_contextName), delay(my_delay) {}
    migrate_context_Message(InternalMessageHelper const* o) : _data_store_(new migrate_context_struct()), serializedByteSize(0) , newNode(_data_store_->newNode), contextName(_data_store_->contextName), delay(_data_store_->delay) {
     migrate_context_Message const* orig_helper = static_cast< migrate_context_Message const* >( o );
      _data_store_->newNode = orig_helper->newNode;
      _data_store_->contextName = orig_helper->contextName;
      _data_store_->delay = orig_helper->delay;
    }
    virtual ~migrate_context_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "migrate_context(";
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
    mace::MaceAddr const & newNode;
    mace::string const & contextName;
    uint64_t const & delay;
  };
  class migrate_param_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct migrate_param_struct {
      mace::string paramid;
    };
    migrate_param_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    migrate_param_Message() : _data_store_(new migrate_param_struct()), serializedByteSize(0) , paramid(_data_store_->paramid) {}
    migrate_param_Message(mace::string const & my_paramid) : _data_store_(NULL), serializedByteSize(0), paramid(my_paramid) {}
    migrate_param_Message(InternalMessageHelper const* o ) : _data_store_(new migrate_param_struct()), serializedByteSize(0) , paramid(_data_store_->paramid) {
     migrate_param_Message const* orig_helper = static_cast< migrate_param_Message const* >( o );
      _data_store_->paramid = orig_helper->paramid;
    }
    virtual ~migrate_param_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "migrate_param(";
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
    RemoveContextObject_Message() : _data_store_(new RemoveContextObject_struct()), serializedByteSize(0) , eventID(_data_store_->eventID), ctxmapCopy(_data_store_->ctxmapCopy), dest(_data_store_->dest), contextID(_data_store_->contextID) {}
    RemoveContextObject_Message(uint64_t const & my_eventID, mace::ContextMapping const & my_ctxmapCopy, MaceAddr const & my_dest, uint32_t const & my_contextID) : _data_store_(NULL), serializedByteSize(0), eventID(my_eventID), ctxmapCopy(my_ctxmapCopy), dest(my_dest), contextID(my_contextID) {}
    RemoveContextObject_Message(InternalMessageHelper const* o ) : _data_store_(new RemoveContextObject_struct()), serializedByteSize(0) , eventID(_data_store_->eventID), ctxmapCopy(_data_store_->ctxmapCopy), dest(_data_store_->dest), contextID(_data_store_->contextID) {
     RemoveContextObject_Message const* orig_helper = static_cast< RemoveContextObject_Message const* >( o );
      _data_store_->eventID = orig_helper->eventID;
      _data_store_->ctxmapCopy = orig_helper->ctxmapCopy;
      _data_store_->dest = orig_helper->dest;
      _data_store_->contextID = orig_helper->contextID;
    }

    virtual ~RemoveContextObject_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "RemoveContextObject(";
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
    delete_context_Message() : _data_store_(new delete_context_struct()), serializedByteSize(0) , contextName(_data_store_->contextName) {}
    delete_context_Message(mace::string const & my_contextName) : _data_store_(NULL), serializedByteSize(0), contextName(my_contextName) {}
    delete_context_Message(InternalMessageHelper const* o) : _data_store_(new delete_context_struct()), serializedByteSize(0) , contextName(_data_store_->contextName) {
     delete_context_Message const* orig_helper = static_cast< delete_context_Message const* >( o );
      _data_store_->contextName = orig_helper->contextName;
    }
    virtual ~delete_context_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "delete_context(";
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
      mace::string const& contextName ;

  };
  class new_head_ready_Message: public InternalMessageHelper, virtual public PrintPrintable{
    struct new_head_ready_struct {  };
    new_head_ready_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    new_head_ready_Message() : _data_store_(new new_head_ready_struct()), serializedByteSize(0)  {}
    
    
    new_head_ready_Message(InternalMessageHelper const* o) : _data_store_(new new_head_ready_struct()), serializedByteSize(0)  {
    }
    virtual ~new_head_ready_Message() { delete _data_store_; _data_store_ = NULL; }
    void print(std::ostream& __out) const {
      __out << "new_head_ready(";
          
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
    routine_return_Message() : _data_store_(new routine_return_struct()), serializedByteSize(0) , returnValue(_data_store_->returnValue), event(_data_store_->event) {}
    routine_return_Message(mace::string const & my_returnValue, mace::Event const & my_event) : _data_store_(NULL), serializedByteSize(0), returnValue(my_returnValue), event(my_event) {}
    routine_return_Message(InternalMessageHelper const* o) : _data_store_(new routine_return_struct()), serializedByteSize(0) , returnValue(_data_store_->returnValue), event(_data_store_->event) {
     routine_return_Message const* orig_helper = static_cast< routine_return_Message const* >( o );
      _data_store_->returnValue = orig_helper->returnValue;
      _data_store_->event = orig_helper->event;
    }
    virtual ~routine_return_Message() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & returnValue;
    mace::Event const & event;

    void print(std::ostream& __out) const {
      __out << "routine_return(";
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
  class appupcall_return_Message: public InternalMessageHelper, virtual public PrintPrintable{
  struct appupcall_return_struct {
    mace::string returnValue ;
    mace::Event event ;
  };
    appupcall_return_struct* _data_store_;
    mutable size_t serializedByteSize;
    mutable std::string serializedCache;
  public:
    appupcall_return_Message() : _data_store_(new appupcall_return_struct()), serializedByteSize(0) , returnValue(_data_store_->returnValue), event(_data_store_->event) {}
    appupcall_return_Message(mace::string const & my_returnValue, mace::Event const & my_event) : _data_store_(NULL), serializedByteSize(0), returnValue(my_returnValue), event(my_event) {}
    appupcall_return_Message(InternalMessageHelper const* o) : _data_store_(new appupcall_return_struct()), serializedByteSize(0) , returnValue(_data_store_->returnValue), event(_data_store_->event) {
     appupcall_return_Message const* orig_helper = static_cast< appupcall_return_Message const* >( o );
      _data_store_->returnValue = orig_helper->returnValue;
      _data_store_->event = orig_helper->event;
    }
    virtual ~appupcall_return_Message() { delete _data_store_; _data_store_ = NULL; }
    
    mace::string const & returnValue;
    mace::Event const & event;

    void print(std::ostream& __out) const {
      __out << "appupcall_return(";
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

  class InternalMessage : public Message, virtual public PrintPrintable{
  private:
    uint8_t msgType;
    uint8_t sid;
    mutable InternalMessageHelperPtr helper;
  public:

    static const uint8_t messageType = 255;
    static uint8_t getMsgType() { return messageType; }
    uint8_t getType() const { return InternalMessage::getMsgType(); }

    InternalMessageHelperPtr const& getHelper()const { 
      return helper;
    }
    void unlinkHelper() const{
      //helper = InternalMessageHelperPtr( NULL );
      helper = NULL;
    }
    uint8_t getMessageType() const{ return msgType; }
    int deserializeEvent( std::istream& in );
    int deserializeUpcall( std::istream& in );
    int deserializeRoutine( std::istream& in );

    struct AllocateContextObject_type{};
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
    struct appupcall_return_type{};
    struct routine_type{};
    struct new_event_request_type{};

  const static uint8_t UNKNOWN = 0;
  const static uint8_t ALLOCATE_CONTEXT_OBJECT = 1;
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
  const static uint8_t ASYNC_EVENT = 21;
  const static uint8_t APPUPCALL = 22;
  const static uint8_t APPUPCALL_RETURN = 23;
  const static uint8_t ROUTINE = 24;
  const static uint8_t TRANSITION_CALL = 25;
  const static uint8_t NEW_EVENT_REQUEST = 26;

    InternalMessage() {}
    InternalMessage( AllocateContextObject_type t, MaceAddr const & destNode, mace::map< uint32_t, mace::string > const & ContextID, uint64_t const & eventID, mace::ContextMapping const & contextMapping, int8_t const & eventType): msgType( ALLOCATE_CONTEXT_OBJECT ), helper(new AllocateContextObject_Message(destNode, ContextID, eventID, contextMapping, eventType) ) {}
    InternalMessage( ContextMigrationRequest_type t, uint32_t const & my_ctxId, MaceAddr const & my_dest, bool const & my_rootOnly, mace::Event const & my_event, uint64_t const & my_prevContextMapVersion, mace::vector< uint32_t > const & my_nextHops): msgType( CONTEXT_MIGRATION_REQUEST), helper(new ContextMigrationRequest_Message(my_ctxId, my_dest, my_rootOnly, my_event, my_prevContextMapVersion, my_nextHops) ) {} // TODO: WC: change to a better name
    InternalMessage( TransferContext_type t, uint32_t const & my_rootContextID, mace::string const & my_ctxId, uint32_t const & my_ctxNId, mace::string const & my_checkpoint, uint64_t const & my_eventId, MaceAddr const & my_parentContextNode, bool const & my_isresponse ): msgType( TRANSFER_CONTEXT), helper(new TransferContext_Message( my_rootContextID, my_ctxId, my_ctxNId, my_checkpoint, my_eventId, my_parentContextNode, my_isresponse ) ) {}
    InternalMessage( create_type t, __asyncExtraField const & my_extra, uint64_t const & my_counter): msgType( CREATE), helper(new create_Message( my_extra, my_counter) ) {}
    InternalMessage( create_head_type t, __asyncExtraField const & my_extra, uint64_t const & my_counter, MaceAddr const & my_src): msgType( CREATE_HEAD), helper(new create_head_Message( my_extra, my_counter, my_src) ) {}
    InternalMessage( create_response_type t, mace::Event const & my_event, uint32_t const & my_counter, MaceAddr const & my_targetAddress): msgType( CREATE_RESPONSE ), helper(new create_response_Message( my_event, my_counter, my_targetAddress) ) {}
    InternalMessage( exit_committed_type t ): msgType( EXIT_COMMITTED), helper(new exit_committed_Message() ) {}
    InternalMessage( enter_context_type t, mace::Event const & my_event, mace::vector< uint32_t > const & my_contextIDs): msgType( ENTER_CONTEXT), helper(new enter_context_Message( my_event, my_contextIDs) ) {}
    InternalMessage( commit_type t, mace::Event const & my_event): msgType( COMMIT), helper(new commit_Message( my_event ) ) {}
    InternalMessage( commit_context_type t, mace::vector< uint32_t > const & my_nextHops, uint64_t const & my_eventID, int8_t const & my_eventType, uint64_t const & my_eventContextMappingVersion, mace::Event::SkipRecordType const & my_eventSkipID, bool const & my_isresponse, bool const & my_hasException, uint32_t const & my_exceptionContextID): msgType( COMMIT_CONTEXT), helper(new commit_context_Message( my_nextHops, my_eventID, my_eventType, my_eventContextMappingVersion, my_eventSkipID, my_isresponse, my_hasException, my_exceptionContextID ) ) {} // TODO: WC: rename it. it should be renamed to downgrade
    InternalMessage( snapshot_type t, mace::Event const & my_event, mace::string const & my_ctxID, mace::string const & my_snapshotContextID, mace::string const & my_snapshot): msgType( SNAPSHOT), helper(new snapshot_Message( my_event, my_ctxID, my_snapshotContextID, my_snapshot) ) {}
    InternalMessage( downgrade_context_type t, uint32_t const & my_contextID, uint64_t const & my_eventID, bool const & my_isresponse): msgType( DOWNGRADE_CONTEXT ), helper(new downgrade_context_Message( my_contextID, my_eventID, my_isresponse) ) {} // TODO: may be this is a duplicate of commit_context?
    InternalMessage( evict_type t ): msgType( EVICT ), helper(new evict_Message( ) ) {}
    InternalMessage( migrate_context_type t, mace::MaceAddr const & my_newNode, mace::string const & my_contextName, uint64_t const & my_delay): msgType( MIGRATE_CONTEXT), helper(new migrate_context_Message( my_newNode, my_contextName, my_delay ) ) {}
    InternalMessage( migrate_param_type t, mace::string const & my_paramid): msgType( MIGRATE_PARAM ), helper(new migrate_param_Message(my_paramid) ) {}
    InternalMessage( RemoveContextObject_type t, uint64_t const & my_eventID, mace::ContextMapping const & my_ctxmapCopy, MaceAddr const & my_dest, uint32_t const & my_contextID): msgType( REMOVE_CONTEXT_OBJECT), helper(new RemoveContextObject_Message( my_eventID, my_ctxmapCopy, my_dest, my_contextID) ) {}
    InternalMessage( delete_context_type t, mace::string const & my_contextName): msgType( DELETE_CONTEXT), helper(new delete_context_Message( my_contextName ) ) {}
    InternalMessage( new_head_ready_type t): msgType( NEW_HEAD_READY), helper(new new_head_ready_Message() ) {}
    InternalMessage( routine_return_type t, mace::string const & my_returnValue, mace::Event const & my_event): msgType( ROUTINE_RETURN), helper(new routine_return_Message( my_returnValue, my_event) ) {}
    InternalMessage( appupcall_return_type t, mace::string const & my_returnValue, mace::Event const & my_event): msgType( APPUPCALL_RETURN), helper(new appupcall_return_Message( my_returnValue, my_event) ) {}


    InternalMessage( mace::AsyncEvent_Message* m, uint8_t sid): msgType( ASYNC_EVENT ), sid(sid), helper(m ) {}

    InternalMessage( mace::ApplicationUpcall_Message* m, uint8_t sid): msgType( APPUPCALL ), sid(sid), helper(m ) {}

    InternalMessage( mace::Routine_Message* m, uint8_t sid): msgType( ROUTINE ), sid(sid), helper(m ) {}

    InternalMessage( mace::Transition_Message* m, uint8_t sid): msgType( TRANSITION_CALL ), sid(sid), helper(m ) {}


    InternalMessage( new_event_request_type t, mace::AsyncEvent_Message* m, uint8_t sid): msgType( NEW_EVENT_REQUEST ), sid(sid), helper(m ) {}

    /// copy constructor
    InternalMessage( InternalMessage const& orig ){
      msgType = orig.msgType;
      switch( orig.msgType ){

  case UNKNOWN: break;
  case ALLOCATE_CONTEXT_OBJECT: helper = InternalMessageHelperPtr( new AllocateContextObject_Message(orig.getHelper() ) ); break;
  case CONTEXT_MIGRATION_REQUEST: helper = InternalMessageHelperPtr( new ContextMigrationRequest_Message(orig.getHelper()) ); break;
  case TRANSFER_CONTEXT: helper = InternalMessageHelperPtr( new TransferContext_Message(orig.getHelper()) ); break;
  case CREATE: helper = InternalMessageHelperPtr( new create_Message(orig.getHelper()) ); break;
  case CREATE_HEAD: helper = InternalMessageHelperPtr( new create_head_Message(orig.getHelper()) ); break; 
  case CREATE_RESPONSE: helper = InternalMessageHelperPtr( new create_response_Message(orig.getHelper()) ); break;
  case EXIT_COMMITTED: helper = InternalMessageHelperPtr( new exit_committed_Message(orig.getHelper()) ); break;
  case ENTER_CONTEXT: helper = InternalMessageHelperPtr( new enter_context_Message(orig.getHelper()) ); break;
  case COMMIT: helper = InternalMessageHelperPtr( new commit_Message(orig.getHelper()) ); break;
  case COMMIT_CONTEXT: helper = InternalMessageHelperPtr( new commit_context_Message(orig.getHelper()) ); break;
  case SNAPSHOT: helper = InternalMessageHelperPtr( new snapshot_Message(orig.getHelper()) ); break;
  case DOWNGRADE_CONTEXT: helper = InternalMessageHelperPtr( new downgrade_context_Message(orig.getHelper()) ); break;
  case EVICT: helper = InternalMessageHelperPtr( new evict_Message(orig.getHelper()) ); break;
  case MIGRATE_CONTEXT: helper = InternalMessageHelperPtr( new migrate_context_Message(orig.getHelper()) ); break;
  case MIGRATE_PARAM: helper = InternalMessageHelperPtr( new migrate_param_Message(orig.getHelper()) ); break;
  case REMOVE_CONTEXT_OBJECT: helper = InternalMessageHelperPtr( new RemoveContextObject_Message(orig.getHelper()) ); break;
  case DELETE_CONTEXT: helper = InternalMessageHelperPtr( new delete_context_Message(orig.getHelper()) ); break;
  case NEW_HEAD_READY: helper = InternalMessageHelperPtr( new new_head_ready_Message(orig.getHelper()) ); break;
  case ROUTINE_RETURN: helper = InternalMessageHelperPtr( new routine_return_Message(orig.getHelper()) ); break;
  case APPUPCALL_RETURN: helper = InternalMessageHelperPtr( new appupcall_return_Message(orig.getHelper())); break;

  default:
      helper = orig.helper;
  } 


      switch( orig.msgType ){

        case ASYNC_EVENT: 
        case APPUPCALL: 
        case ROUTINE: 
        case TRANSITION_CALL: 
        case NEW_EVENT_REQUEST:
          sid = orig.sid;
          break;
      }
    }

    void print(std::ostream& out) const {
      if( helper != NULL ){
        out << (*helper);
      }
    }
    virtual void serialize(std::string& str) const {
      mace::serialize(str, &messageType);
      mace::serialize(str, &msgType);
      if(msgType != UNKNOWN && helper != NULL) {
        switch( msgType ){
          case ASYNC_EVENT:
            mace::serialize(str, &sid);
            break;
          case APPUPCALL:
            mace::serialize(str, &(ThreadStructure::myEvent() ) );
            mace::serialize(str, &sid);
            break;
          case ROUTINE:
            mace::serialize(str, &sid);
            break;
          case TRANSITION_CALL:
            mace::serialize(str, &sid);
            break;
          case NEW_EVENT_REQUEST:
            mace::serialize(str, &sid);
            break;
        }
        helper->serialize(str);
      }
    }
    virtual int deserialize(std::istream& in) throw(SerializationException) {
      int count = 0;
      uint8_t t;
      count = mace::deserialize(in, &t);
      ASSERT( t == messageType );
      count += mace::deserialize(in, &msgType);

      switch( msgType ){
  case UNKNOWN: return count; break;
  case ALLOCATE_CONTEXT_OBJECT: helper = InternalMessageHelperPtr( new AllocateContextObject_Message() ); break;
  case CONTEXT_MIGRATION_REQUEST: helper = InternalMessageHelperPtr( new ContextMigrationRequest_Message() ); break;
  case TRANSFER_CONTEXT: helper = InternalMessageHelperPtr( new TransferContext_Message() ); break;
  case CREATE: helper = InternalMessageHelperPtr( new create_Message() ); break;
  case CREATE_HEAD: helper = InternalMessageHelperPtr( new create_head_Message() ); break; 
  case CREATE_RESPONSE: helper = InternalMessageHelperPtr( new create_response_Message() ); break;
  case EXIT_COMMITTED: helper = InternalMessageHelperPtr( new exit_committed_Message() ); break;
  case ENTER_CONTEXT: helper = InternalMessageHelperPtr( new enter_context_Message() ); break;
  case COMMIT: helper = InternalMessageHelperPtr( new commit_Message() ); break;
  case COMMIT_CONTEXT: helper = InternalMessageHelperPtr( new commit_context_Message() ); break;
  case SNAPSHOT: helper = InternalMessageHelperPtr( new snapshot_Message() ); break;
  case DOWNGRADE_CONTEXT: helper = InternalMessageHelperPtr( new downgrade_context_Message() ); break;
  case EVICT: helper = InternalMessageHelperPtr( new evict_Message() ); break;
  case MIGRATE_CONTEXT: helper = InternalMessageHelperPtr( new migrate_context_Message() ); break;
  case MIGRATE_PARAM: helper = InternalMessageHelperPtr( new migrate_param_Message() ); break;
  case REMOVE_CONTEXT_OBJECT: helper = InternalMessageHelperPtr( new RemoveContextObject_Message() ); break;
  case DELETE_CONTEXT: helper = InternalMessageHelperPtr( new delete_context_Message() ); break;
  case NEW_HEAD_READY: helper = InternalMessageHelperPtr( new new_head_ready_Message() ); break;
  case ROUTINE_RETURN: helper = InternalMessageHelperPtr( new routine_return_Message() ); break;
  case APPUPCALL_RETURN: helper = InternalMessageHelperPtr( new appupcall_return_Message()); break;

  case ASYNC_EVENT: {
    count += mace::deserialize(in, &sid );
    count += deserializeEvent( in );
    return count;
  }
  case APPUPCALL: {
    // these are the application upcalls that return a value (either have a return value, or have non-const reference parameter )
    // this internal message updates the current event
    count += mace::deserialize(in, &(ThreadStructure::myEvent() ) );
    count += mace::deserialize(in, &sid );
    count += deserializeUpcall( in );
    return count;
  }
  case ROUTINE: {
    count += mace::deserialize(in, &sid );
    count += deserializeRoutine( in );
    return count;
  }
  case TRANSITION_CALL: {
    count += mace::deserialize(in, &sid );
    count += deserializeRoutine( in );
    return count;
  }
  case NEW_EVENT_REQUEST: {
    count += mace::deserialize(in, &sid );
    count += deserializeEvent( in );
    return count;
  }
  default: throw(InvalidInternalMessageException("Deserializing bad internal message type "+boost::lexical_cast<std::string>(msgType)+"!"));
    
      }
      count += helper->deserialize(in); 
      return count;
    }
    virtual ~InternalMessage() { 
#ifndef INTERNALMESSAGE_USE_SHARED_PTR
      delete helper; 
#endif
    }
  };

 const mace::InternalMessage::AllocateContextObject_type AllocateContextObject = mace::InternalMessage::AllocateContextObject_type();
 //const mace::InternalMessage::AllocateContextObjectResponse_type AllocateContextObjectResponse = mace::InternalMessage::AllocateContextObjectResponse_type();
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
 const mace::InternalMessage::appupcall_return_type appupcall_return = mace::InternalMessage::appupcall_return_type();
 const mace::InternalMessage::new_event_request_type new_event_request = mace::InternalMessage::new_event_request_type();
}
#endif
