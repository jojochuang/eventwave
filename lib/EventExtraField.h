#ifndef _EVENTEXTRAFIELD_H
#define _EVENTEXTRAFIELD_H

#include "Printable.h"
#include "Serializable.h"
#include "mstring.h"
#include "mset.h"
#include "Event.h"

namespace mace{
  struct Temporary_type {};
  class __asyncExtraField : public mace::PrintPrintable, public mace::Serializable {
    private:
    bool storePointerOnly;
    public:


      class helperInterface: public Serializable, virtual public PrintPrintable{
      public:
        virtual size_t getSerializedSize() const =0;
        virtual mace::string const& getTargetContextID() const = 0;
        virtual void setTargetContextID( mace::string const& targetContextID){}

        virtual mace::set<mace::string> const& getSnapshotContextIDs() const = 0;
        virtual void setSnapshotContextIDs( mace::set<mace::string> const& snapshotContextIDs) {}

        virtual mace::Event const& getEvent() const = 0;
        virtual void setEvent( mace::Event const& event ){}

        virtual bool getIsRequest() const = 0;
        virtual void setIsRequest( bool const isRequest ){}
      };

      class StoreCopy_helper: public helperInterface{
          mutable size_t serializedByteSize;
          mace::string targetContextID;
          mace::set<mace::string> snapshotContextIDs;
          mace::Event event;
          bool isRequest;
        public:
          StoreCopy_helper(): targetContextID(), snapshotContextIDs(), event(), isRequest() {}
          StoreCopy_helper(mace::string const & _targetContextID, mace::set<mace::string> const & _snapshotContextIDs, mace::Event const & _event, bool const & _isRequest) : serializedByteSize(0), targetContextID(_targetContextID), snapshotContextIDs(_snapshotContextIDs), event(_event), isRequest(_isRequest) {}
        void printNode(mace::PrintNode& __pr, const std::string& __name) const {
          mace::PrintNode ____asyncExtraFieldPrinter(__name, "__asyncExtraField");
          mace::printItem(____asyncExtraFieldPrinter, "targetContextID", &(targetContextID));;
          mace::printItem(____asyncExtraFieldPrinter, "snapshotContextIDs", &(snapshotContextIDs));;
          mace::printItem(____asyncExtraFieldPrinter, "event", &(event));;
          mace::printItem(____asyncExtraFieldPrinter, "isRequest", &(isRequest));
          __pr.addChild(____asyncExtraFieldPrinter);
        }
        mace::string const& getTargetContextID() const { return targetContextID; }
        void setTargetContextID( mace::string const& _targetContextID){ targetContextID = _targetContextID; }

        mace::set<mace::string> const& getSnapshotContextIDs() const { return snapshotContextIDs; }
        void setSnapshotContextIDs( mace::set<mace::string> const& _snapshotContextIDs) { snapshotContextIDs = _snapshotContextIDs; }

        mace::Event const& getEvent() const { return event; }
        void setEvent( mace::Event const& _event ){ event = _event;}

        bool getIsRequest() const { return isRequest; }
        void setIsRequest( bool const _isRequest ){ isRequest = _isRequest; }
        void print(std::ostream& __out) const {
          __out << "__asyncExtraField("  ;
              __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
              __out << ", ";
              __out << "snapshotContextIDs=";  mace::printItem(__out, &(snapshotContextIDs));
              __out << ", ";
              __out << "event=";  mace::printItem(__out, &(event));
              __out << ", ";
              __out << "isRequest=";  mace::printItem(__out, &(isRequest));
              __out << ")";
        }
        void printState(std::ostream& __out) const {
          __out << "__asyncExtraField(" ;
              __out << "targetContextID=";  mace::printState(__out, &(targetContextID), (targetContextID));
              __out << ", ";
              __out << "snapshotContextIDs=";  mace::printState(__out, &(snapshotContextIDs), (snapshotContextIDs));
              __out << ", ";
              __out << "event=";  mace::printState(__out, &(event), (event));
              __out << ", ";
              __out << "isRequest=";  mace::printState(__out, &(isRequest), (isRequest));
              __out << ")";
        }
        void serialize(std::string& str) const {
          serializedByteSize = str.size();
          mace::serialize(str, &targetContextID);
          mace::serialize(str, &snapshotContextIDs);
          mace::serialize(str, &event);
          mace::serialize(str, &isRequest);
          serializedByteSize = str.size() - serializedByteSize;
        }
        int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
          serializedByteSize = 0;
          serializedByteSize +=  mace::deserialize(__mace_in, &targetContextID);
          serializedByteSize +=  mace::deserialize(__mace_in, &snapshotContextIDs);
          serializedByteSize +=  mace::deserialize(__mace_in, &event);
          serializedByteSize +=  mace::deserialize(__mace_in, &isRequest);
          return serializedByteSize;
        }
        size_t getSerializedSize() const {
          return serializedByteSize;
        }
      };

      class StorePointer_helper: public helperInterface{
          mutable size_t serializedByteSize;
          mace::string const& targetContextID;
          mace::set<mace::string> const& snapshotContextIDs;
          mace::Event const& event;
          bool const& isRequest;
        public:
        StorePointer_helper( mace::string const & _targetContextID, mace::set<mace::string> const & _snapshotContextIDs, mace::Event const & _event, bool const & _isRequest) : serializedByteSize(0), targetContextID(_targetContextID), snapshotContextIDs(_snapshotContextIDs), event(_event), isRequest(_isRequest) { }

        mace::string const& getTargetContextID() const { return targetContextID; }

        mace::set<mace::string> const& getSnapshotContextIDs() const { return snapshotContextIDs; }

        mace::Event const& getEvent() const { return event; }

        bool getIsRequest() const { return isRequest; }

        void printNode(mace::PrintNode& __pr, const std::string& __name) const {
          mace::PrintNode ____asyncExtraFieldPrinter(__name, "__asyncExtraField");
          mace::printItem(____asyncExtraFieldPrinter, "targetContextID", &(targetContextID));;
          mace::printItem(____asyncExtraFieldPrinter, "snapshotContextIDs", &(snapshotContextIDs));;
          mace::printItem(____asyncExtraFieldPrinter, "event", &(event));;
          mace::printItem(____asyncExtraFieldPrinter, "isRequest", &(isRequest));
          __pr.addChild(____asyncExtraFieldPrinter);
        }
        void print(std::ostream& __out) const {
          __out << "__asyncExtraField("  ;
              __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
              __out << ", ";
              __out << "snapshotContextIDs=";  mace::printItem(__out, &(snapshotContextIDs));
              __out << ", ";
              __out << "event=";  mace::printItem(__out, &(event));
              __out << ", ";
              __out << "isRequest=";  mace::printItem(__out, &(isRequest));
              __out << ")";
        }
        void printState(std::ostream& __out) const {
          __out << "__asyncExtraField(" ;
              __out << "targetContextID=";  mace::printState(__out, &(targetContextID), (targetContextID));
              __out << ", ";
              __out << "snapshotContextIDs=";  mace::printState(__out, &(snapshotContextIDs), (snapshotContextIDs));
              __out << ", ";
              __out << "event=";  mace::printState(__out, &(event), (event));
              __out << ", ";
              __out << "isRequest=";  mace::printState(__out, &(isRequest), (isRequest));
              __out << ")";
        }
        void serialize(std::string& str) const {
          serializedByteSize = str.size();
          mace::serialize(str, &targetContextID);
          mace::serialize(str, &snapshotContextIDs);
          mace::serialize(str, &event);
          mace::serialize(str, &isRequest);
          serializedByteSize = str.size() - serializedByteSize;
        }
        int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
          serializedByteSize = 0;
          ABORT("this function will never be called");
          return serializedByteSize;
        }
        size_t getSerializedSize() const {
          return serializedByteSize;
        }
      };

      helperInterface *helper;
      __asyncExtraField(): helper(new StoreCopy_helper()) { }
      __asyncExtraField(mace::string const & _targetContextID, mace::set<mace::string> const & _snapshotContextIDs, mace::Event const & _event, bool const & _isRequest) : helper(new StoreCopy_helper(_targetContextID, _snapshotContextIDs, _event, _isRequest )){ }
      __asyncExtraField(Temporary_type t, mace::string const & _targetContextID, mace::set<mace::string> const & _snapshotContextIDs, mace::Event const & _event, bool const & _isRequest) : helper(new StorePointer_helper( _targetContextID, _snapshotContextIDs, _event, _isRequest) ) { }

      virtual ~__asyncExtraField() {
        delete helper;
      }
    
      void print(std::ostream& __out) const {
        mace::printItem(__out, helper);
      }
      void printState(std::ostream& __out) const {
        mace::printState( __out, helper, *helper );
      }
      void serialize(std::string& str) const {
        return helper->serialize( str );
      }
      int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
        return helper->deserialize( __mace_in );
      }
      size_t getSerializedSize() const {
        return helper->getSerializedSize();
      }
    
      mace::string const& getTargetContextID() const { return helper->getTargetContextID(); }
      void setTargetContextID( mace::string const& targetContextID) { helper->setTargetContextID(targetContextID); }

      mace::set<mace::string> const& getSnapshotContextIDs() const { return helper->getSnapshotContextIDs(); }
      void setSnapshotContextIDs( mace::set<mace::string> const& snapshotContextIDs) { helper->setSnapshotContextIDs( snapshotContextIDs ); }

      mace::Event const& getEvent() const { return helper->getEvent(); }
      void setEvent( mace::Event const& event ) { helper->setEvent( event ); }

      bool getIsRequest() const{ return helper->getIsRequest(); }
      void setIsRequest( bool const isRequest ) { helper->setIsRequest( isRequest ); }
    
      __asyncExtraField& operator=(const __asyncExtraField& orig){
        // XXX: not tested.
        ASSERTMSG( this != &orig, "Self assignment is forbidden!" );

        helper->setTargetContextID(  orig.getTargetContextID() );
        helper->setSnapshotContextIDs(  orig.getSnapshotContextIDs() );
        helper->setEvent(  orig.getEvent() );
        helper->setIsRequest(  orig.getIsRequest() );
        return *this;
      }
    /*void sqlize(mace::LogNode* __node) const {
      int _index = __node->nextIndex();
      if (_index == 0) {
        std::ostringstream __out;
        __out << "CREATE TABLE " << __node->logName << " (_id INT PRIMARY KEY, targetContextID TEXT, snapshotContextIDs INT, event INT, isRequest INT);" << std::endl;
        __node->children = new mace::LogNode*[2];
        mace::LogNode* __child0 = new mace::LogNode(__node->logName + "_snapshotContextIDs", Log::sqlEventsLog);
        __node->children[0] = __child0;
        mace::LogNode* __child1 = new mace::LogNode(__node->logName + "_event", Log::sqlEventsLog);
        __node->children[1] = __child1;
        Log::logSqlCreate(__out.str(), __node);
      }
      int _snapshotContextIDsIndex = __node->children[0]->nextId;
      int _eventIndex = __node->children[1]->nextId;
      std::ostringstream __out;
      __out << __node->logId << "\t" << _index;
      __out << "\t";
      if (Base64::isPrintable(targetContextID)) {
        __out << targetContextID;
      }
      else {
        __out << HashString::hash(targetContextID);
      }
      __out << "\t" << _snapshotContextIDsIndex;
      __out << "\t" << _eventIndex;
      __out << "\t" << isRequest;
      __out << std::endl;
      ASSERT(fwrite(__out.str().c_str(), __out.str().size(), 1, __node->file) > 0);
      mace::sqlize(&snapshotContextIDs, __node->children[0]);
      mace::sqlize(&event, __node->children[1]);
      
    }
    
    int deserializeXML_RPC(std::istream& __mace_in) throw(mace::SerializationException) {
      int __fields = 0;
      std::istream::pos_type __m_offset = __mace_in.tellg();
      mace::SerializationUtil::expectTag(__mace_in, "<struct>");
      
      std::string tag = mace::SerializationUtil::getTag(__mace_in);
      while (tag == "<member>") {
        __fields++;
        mace::SerializationUtil::expectTag(__mace_in, "<name>");
        std::string __var = mace::KeyTraits<mace::string>::extract(__mace_in);
        mace::SerializationUtil::expectTag(__mace_in, "</name>");
        mace::SerializationUtil::expectTag(__mace_in, "<value>");
        
        if (__var == "targetContextID") {
          mace::deserializeXML_RPC(__mace_in, & targetContextID, targetContextID);
        } else
        if (__var == "snapshotContextIDs") {
          mace::deserializeXML_RPC(__mace_in, & snapshotContextIDs, snapshotContextIDs);
        } else
        if (__var == "event") {
          mace::deserializeXML_RPC(__mace_in, & event, event);
        } else
        if (__var == "isRequest") {
          mace::deserializeXML_RPC(__mace_in, & isRequest, isRequest);
        } else
        {
          throw(new mace::SerializationException("deserializing __asyncExtraField: unknown field " + __var + " found"));
        }
        mace::SerializationUtil::expectTag(__mace_in, "</value>");
        mace::SerializationUtil::expectTag(__mace_in, "</member>");
        tag = mace::SerializationUtil::getTag(__mace_in);
      }
      if (__fields != 4) {
        throw(new mace::SerializationException("deserializing __asyncExtraField: incorrect number of fields found"));
      }
      if (tag != "</struct>") {
        throw mace::SerializationException("error parsing tag: expected </struct>, parsed " + tag);
      }
      
      //   __mace_in >> skipws;
      return __mace_in.tellg() - __m_offset;
    }
    
    void serializeXML_RPC(std::string& str) const throw(mace::SerializationException) {
      str.append("<struct>");
      
      str.append("<member><name>targetContextID</name><value>");
      mace::serializeXML_RPC(str, &(targetContextID), targetContextID);
      str.append("</value></member>");
      str.append("<member><name>snapshotContextIDs</name><value>");
      mace::serializeXML_RPC(str, &(snapshotContextIDs), snapshotContextIDs);
      str.append("</value></member>");
      str.append("<member><name>event</name><value>");
      mace::serializeXML_RPC(str, &(event), event);
      str.append("</value></member>");
      str.append("<member><name>isRequest</name><value>");
      mace::serializeXML_RPC(str, &(isRequest), isRequest);
      str.append("</value></member>");
      
      str.append("</struct>");
    }
    */
  };

}
const mace::Temporary_type PointerOnly = mace::Temporary_type();
#endif
