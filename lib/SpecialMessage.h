#include "Message.h"
#include "Event.h"
#include "EventExtraField.h"
#ifndef _SPECIALMESSAGE_H_
#define _SPECIALMESSAGE_H_
namespace mace{
class InternalMessageHelper : public Message{ //public Serializable, virtual public Printable  {
  uint8_t getType() const{
    return std::numeric_limits<uint8_t>::max();
  }
  
};
class AsyncEvent_Message: public InternalMessageHelper{
private:
  __asyncExtraField extra;
  mace::Event event;
protected:

  mutable size_t serializedByteSize;
  mutable std::string serializedCache;
public:
  virtual __asyncExtraField & getExtra(){ return extra; }
  virtual mace::Event & getEvent(){ return event; }

  size_t getSerializedSize() const {
    if (serializedByteSize == 0 && serializedCache.empty()) {
      serialize(serializedCache);
    }
    return serializedByteSize;
  }
  std::string serializeStr() const {
    if (serializedCache.empty()) {
      serialize(serializedCache);
    }
    return serializedCache;
  }
  void deserializeStr(const std::string& __s) throw (mace::SerializationException) {
    serializedCache = __s;
    Serializable::deserializeStr(__s);
  }
};
}
#endif
