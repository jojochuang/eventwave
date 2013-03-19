#ifndef _EVENTEXTRAFIELD_H
#define _EVENTEXTRAFIELD_H

#include "Printable.h"
#include "Serializable.h"
#include "mstring.h"
#include "mset.h"
//#include "Event.h"

namespace mace{
  class __asyncExtraField : public mace::PrintPrintable, public mace::Serializable {
    private:
    mutable size_t serializedByteSize;
    public:
    mace::string targetContextID;
    mace::string get_targetContextID() const { return targetContextID; }
    mace::set<mace::string> snapshotContextIDs;
    mace::set<mace::string> get_snapshotContextIDs() const { return snapshotContextIDs; }
    /*mace::Event event;
    mace::Event get_event() const { return event; }*/
    bool isRequest;
    bool get_isRequest() const { return isRequest; }
    __asyncExtraField() : targetContextID(), snapshotContextIDs(), /*event(), */isRequest() {}
    __asyncExtraField(mace::string const & _targetContextID, mace::set<mace::string> const & _snapshotContextIDs, /*mace::Event const & _event,*/ bool const & _isRequest) : serializedByteSize(0), targetContextID(_targetContextID), snapshotContextIDs(_snapshotContextIDs), /*event(_event),*/ isRequest(_isRequest) {}
    virtual ~__asyncExtraField() {}
    
    void printNode(mace::PrintNode& __pr, const std::string& __name) const {
      mace::PrintNode ____asyncExtraFieldPrinter(__name, "__asyncExtraField");
      mace::printItem(____asyncExtraFieldPrinter, "targetContextID", &(targetContextID));;
      mace::printItem(____asyncExtraFieldPrinter, "snapshotContextIDs", &(snapshotContextIDs));;
      //mace::printItem(____asyncExtraFieldPrinter, "event", &(event));;
      mace::printItem(____asyncExtraFieldPrinter, "isRequest", &(isRequest));
      __pr.addChild(____asyncExtraFieldPrinter);
    }
    void print(std::ostream& __out) const {
      __out << "__asyncExtraField("  ;
          __out << "targetContextID=";  mace::printItem(__out, &(targetContextID));
          __out << ", ";
          __out << "snapshotContextIDs=";  mace::printItem(__out, &(snapshotContextIDs));
          __out << ", ";
          //__out << "event=";  mace::printItem(__out, &(event));
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
          //__out << "event=";  mace::printState(__out, &(event), (event));
          //__out << ", ";
          __out << "isRequest=";  mace::printState(__out, &(isRequest), (isRequest));
          __out << ")";
    }
    void serialize(std::string& str) const {
      serializedByteSize = str.size();
      mace::serialize(str, &targetContextID);
      mace::serialize(str, &snapshotContextIDs);
      //mace::serialize(str, &event);
      mace::serialize(str, &isRequest);
      serializedByteSize = str.size() - serializedByteSize;
    }
    int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
      serializedByteSize = 0;
      serializedByteSize +=  mace::deserialize(__mace_in, &targetContextID);
      serializedByteSize +=  mace::deserialize(__mace_in, &snapshotContextIDs);
      //serializedByteSize +=  mace::deserialize(__mace_in, &event);
      serializedByteSize +=  mace::deserialize(__mace_in, &isRequest);
      return serializedByteSize;
    }
    
    size_t getSerializedSize() const {
      return serializedByteSize;
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
      
    }*/
    
    /*int deserializeXML_RPC(std::istream& __mace_in) throw(mace::SerializationException) {
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
    }*/
    
    /*void serializeXML_RPC(std::string& str) const throw(mace::SerializationException) {
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
    }*/
  };

}
#endif
