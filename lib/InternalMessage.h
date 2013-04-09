#ifndef _INTERNAL_MESSAGE_H
#define _INTERNAL_MESSAGE_H

#include "Serializable.h"
#include "Printable.h"
#include "m_map.h"
#include "ContextMapping.h"
namespace mace {
  class InternalMessageHelper : public Serializable, virtual public Printable  {
    
  };
  const uint8_t UNKNOWN = 0;
  const uint8_t ALLOCATE_CONTEXT_OBJECT = 1;
  const uint8_t ALLOCATE_CONTEXT_OBJECT_RESPONSE = 2;
  const uint8_t CONTEXT_MIGRATION_REQUEST = 3;
  const uint8_t TRANSFER_CONTEXT = 4;
  const uint8_t CREATE = 5;
  const uint8_t CREATE_HEAD = 6;
  const uint8_t CREATE_RESPONSE = 7;
  const uint8_t EXIT_COMMITTED = 8;
  const uint8_t ENTER_CONTEXT = 9;
  const uint8_t COMMIT = 10;
  const uint8_t COMMIT_CONTEXT = 11;
  const uint8_t SNAPSHOT = 12;
  const uint8_t DOWNGRADE_CONTEXT = 13;
  const uint8_t EVICT = 14;
  const uint8_t MIGRATE_CONTEXT = 15;
  const uint8_t MIGRATE_PARAM = 16;
  const uint8_t REMOVE_CONTEXT_OBJECT = 17;
  const uint8_t DELETE_CONTEXT = 18;
  const uint8_t NEW_HEAD_READY = 19;
  const uint8_t ROUTINE_RETURN = 20;

  struct AllocateContextObject_struct{
    MaceAddr destNode;
    mace::map< uint32_t, mace::string > ContextID;
    uint64_t eventID;
    mace::ContextMapping contextMapping;
    int8_t eventType;
  };
  class AllocateContextObject_Message: public InternalMessageHelper, virtual public PrintPrintable{
  private:
  AllocateContextObject_struct* _data_store_;
  public:
    AllocateContextObject_Message( ): _data_store_( new AllocateContextObject_struct() ), 
      destNode(_data_store_->destNode), 
      ContextID( _data_store_->ContextID ), 
      eventID( _data_store_->eventID ), 
      contextMapping( _data_store_->contextMapping ), 
      eventType( _data_store_->eventType ){ }

    AllocateContextObject_Message( MaceAddr const & destNode, mace::map< uint32_t, mace::string > const & ContextID, uint64_t const & eventID, mace::ContextMapping const & contextMapping, int8_t const & eventType): destNode(destNode), ContextID( ContextID ), eventID( eventID ), contextMapping( contextMapping ), eventType( eventType ){ }
    ~AllocateContextObject_Message(){ delete _data_store_; _data_store_ = NULL; }
 
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
    MaceAddr const & destNode;
    mace::map< uint32_t, mace::string > const & ContextID;
    uint64_t const & eventID;
    mace::ContextMapping const & contextMapping;
    int8_t const & eventType;
  };
  class AllocateContextObjectResponse_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class ContextMigrationRequest_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class TransferContext_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class create_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class create_head_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class create_response_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class exit_committed_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class enter_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class commit_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class commit_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class snapshot_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class downgrade_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class evict_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class migrate_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class migrate_param_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class RemoveContextObject_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class delete_context_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class new_head_ready_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class routine_return_Message: public InternalMessageHelper, virtual public PrintPrintable{
    void print(std::ostream& __out) const { }
    void serialize(std::string& str) const { }
    int deserialize(std::istream& __mace_in) throw (mace::SerializationException) { return 0; }
  };
  class InternalMessage : public Serializable, virtual public Printable{
  private:
    uint8_t msgType;
    InternalMessageHelper* helper;
  public:
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

}
#endif
