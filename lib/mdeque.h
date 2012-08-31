/* 
 * mdeque.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2011, Charles Killian, Dejan Kostic, Ryan Braud, James W. Anderson, John Fisher-Ogden, Calvin Hubble, Duy Nguyen, Justin Burke, David Oppenheimer, Amin Vahdat, Adolfo Rodriguez, Sooraj Bhat, Karthik Nagaraj
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the names of the contributors, nor their associated universities 
 *      or organizations may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ----END-OF-LEGAL-STUFF---- */
/*    
#include <deque>
#include <string>
#include "CollectionSerializers.h"
#include "mace_constants.h"
#include "StrUtilNamespace.h"
#include "ScopedSerialize.h" 
*/
#ifndef _MACE_DEQUE_H
#define _MACE_DEQUE_H

  
#include <deque>
#include <string>
#include "CollectionSerializers.h"
#include "mace_constants.h"
#include "StrUtilNamespace.h"
#include "ScopedSerialize.h" 


/**
 * \file mdeque.h
 * \brief defines the mace::deque extension of std::deque
 */

namespace mace {

/**
 * \addtogroup Collections
 * @{
 */

/// mace::deque extends std::deque, provides contains(), erase(T), printability, and serializability
template<class T, class Serial = SerializeList<T>, class Alloc = std::allocator<T> >
class deque : public std::deque<T, Alloc>, public virtual Serial, public PrintPrintable {

  BOOST_CLASS_REQUIRE2(Serial, Serializer, boost, ConvertibleConcept);

public:
  typedef typename std::deque<T, Alloc> baseType;
  typedef typename baseType::iterator iterator;
  typedef typename baseType::const_iterator const_iterator;
  typedef typename baseType::const_reverse_iterator const_reverse_iterator;
  typedef typename baseType::size_type size_type;

  deque() : baseType() {
  }

  deque(size_type n) : baseType(n) {
  }

  deque(size_type n, const T& t) : baseType(n, t) {
  }

  deque(const const_iterator& b, const const_iterator& e) : baseType(b, e) {
  }
  
  deque(const const_reverse_iterator& b, const const_reverse_iterator& e) : baseType(b, e) {
  }
  
  deque(const std::deque<T, Alloc>& d) : baseType(d) {
  }

  virtual ~deque() { }

  /// returns true if the item \c t is found in the deque
  /**
   * executes by iteration (linear runtime)
   */
  bool contains(const T& t) const {
    for (const_iterator i = this->begin(); i != this->end(); i++) {
      if (*i == t) {
	return true;
      }
    }
    return false;
  }

  /// erases the element at the iterator \c pos
  iterator erase(iterator pos) {
    return baseType::erase(pos);
  }

  /// erase each element \c t if found (linear runtime)
  size_t erase(const T& t) {
    size_t r = 0;
    iterator i = this->begin();
    while (i != this->end()) {
      if (*i == t) {
	i = this->erase(i);
	r++;
      }
      else {
	i++;
      }
    }
    return r;
  }

  /// resizes the deque, truncating or adding new default elements
  void resize(size_t sz) {
    baseType::resize(sz);
  }
  
  /// returns the size of the deque
  size_t size() const {
    return baseType::size();
  }

  /// equivalent to std::list::push_back
  void add(const T& t) {
    return baseType::push_back(t);
  }

  /// Return the template parameter string Key->Data for actual template parameters. (Mace extension)
  const std::string& getTypeName() const {
    const char* types[] = { "T", "Serial", "Alloc", 0 };
    static const StrUtilNamespace::StdStringList myTypes = StrUtilNamespace::getTypeFromTemplate(__PRETTY_FUNCTION__, types);
    return myTypes[0];
  }

  void print(std::ostream& out) const {
    if(mace::PRINT_TYPE_NAMES) {
      out << "deque<"<< this->getTypeName() << ">";
    }
    printList(out, this->begin(), this->end());
  }

  void printNode(PrintNode& pr, const std::string& name) const {
    mace::printList(pr, name, "deque<" + getTypeName() + ">", this->begin(),
		    this->end());
  }

  void printState(std::ostream& out) const {
    if(mace::PRINT_TYPE_NAMES) {
      out << "deque<"<< this->getTypeName() << ">";
    }
    printListState(out, this->begin(), this->end());
  }

  private:
  class v_iterator : public _SerializeList<T>::iterator {
    private:
      iterator i;
      iterator end;

    public:
      bool isValid() {
        return i != end;
      }
      void next() {
        ASSERT(i != end);
        i++;
      }
      T& getValue() {
        return *i;
      }

      v_iterator(iterator beg, iterator end) : i(beg), end(end) {}
      ~v_iterator() {}
  };

  class v_const_iterator : public _SerializeList<T>::const_iterator {
    private:
      const_iterator i;
      const_iterator end;

    public:
      bool isValid() {
        return i != end;
      }
      void next() {
        ASSERT(i != end);
        i++;
      }
      const T& getValue() {
        return *i;
      }
			
			v_const_iterator(const_iterator beg,  const_iterator end) : i(beg),  end(end) {}
	   	~v_const_iterator() {}
  };

  protected:
    typename _SerializeList<T>::iterator* getIterator() {
      return new v_iterator(this->begin(), this->end());
    }
    typename _SerializeList<T>::const_iterator* getIterator() const {
      return new v_const_iterator(this->begin(), this->end());
    }
};

/** @} */

}

template<typename STRING,  typename ORIGIN>
class ScopedSerialize< mace::deque<STRING>,  mace::deque<ORIGIN> > {
private:
	typedef mace::deque<STRING> StringDeque;
	typedef mace::deque<ORIGIN> ObjectDeque;
	StringDeque& strQueue;
	const ObjectDeque* constObjectQueue;
	ObjectDeque* objectQueue;
public:
	/// this constructor is used if the object is const.  This does a one-time serialization.
	ScopedSerialize(StringDeque& s,  const ObjectDeque& obj) : strQueue(s),  constObjectQueue(&obj),  objectQueue(NULL){
		ADD_SELECTORS("ScopedSerialize");
		static const bool printSS = (params::containsKey("MACE_SIMULATE_NODES") ||
				params::get("LOG_SCOPED_SERIALIZE",  false));
		strQueue.clear();
		//strQueue.reserve(constObjectQueue->size());
		for (typename ObjectDeque::const_iterator i = constObjectQueue->begin(); i != constObjectQueue->end(); i++) {
			strQueue.push_back(mace::serialize(*i));
			//if (printSS) {
			//  maceout << HashString::hash(str) << " " << *constObject << Log::endl;
			//     mace::printItem(maceout,  constObject);
			//  //     maceout << Log::endl;
			//}
		}
	}
	// this constructor is used if the object is non-const.  This serializes in constructor,  and deserializes on the destructor.
	ScopedSerialize(StringDeque& s,  ObjectDeque& obj) : strQueue(s),  constObjectQueue(&obj),  objectQueue(&obj)
	{
		ADD_SELECTORS("ScopedSerialize");
		static const bool printSS = (params::containsKey("MACE_SIMULATE_NODES") ||
				params::get("LOG_SCOPED_SERIALIZE",  false));
		strQueue.clear();
		//strList.reserve(constObjectList->size());
		for (typename ObjectDeque::const_iterator i = constObjectQueue->begin(); i != constObjectQueue->end(); i++) {
			strQueue.push_back(mace::serialize(*i));
			//if (printSS) {
			//  maceout << HashString::hash(str) << " " << *constObject << Log::endl;
			//  //     mace::printItem(maceout,  constObject);
			//  //     maceout << Log::endl;
			//}
			}
	}
	  
	~ScopedSerialize() {
		ADD_SELECTORS("ScopedSerialize");
		static const bool printSS = (params::containsKey("MACE_SIMULATE_NODES") ||
				params::get("LOG_SCOPED_SERIALIZE",  false));
		if (objectQueue) {
			//objectList->resize(strList.size());
			typename ObjectDeque::iterator j = objectQueue->begin();
			for (typename StringDeque::const_iterator i = strQueue.begin(); i != strQueue.end(); i++) {
				mace::deserialize(*i,  &(*j));
				j++;
				//if (printSS) {
				//  maceout << HashString::hash(str) << " " << *object << Log::endl;
				//  //  mace::printItem(maceout,  object);
				//  //  maceout << Log::endl;
				//}
			}
			objectQueue = NULL;
	  }
		constObjectQueue = NULL;
	}
}; // class ScopedSerialize

template<typename STRING,  typename ORIGIN>
class ScopedDeserialize<mace::deque<STRING>,  mace::deque<ORIGIN> > {
private:
	typedef mace::deque<STRING> StringDeque;
	typedef mace::deque<ORIGIN> ObjectDeque;
	StringDeque* strQueue;
	const StringDeque* constStrQueue;
	ObjectDeque& objectQueue;

public:
  /// this constructor is used if the object is const.  This does a one-time serialization.
	ScopedDeserialize(const StringDeque& s,  ObjectDeque& obj) : strQueue(0),  constStrQueue(&s),  objectQueue(obj)
	{
		//objectList.resize(constStrList->size());
		typename mace::deque<ORIGIN>::iterator j = objectQueue.begin();
		for (typename StringDeque::const_iterator i = constStrQueue->begin(); i != constStrQueue->end(); i++) {
			mace::deserialize(*i,  &(*j));
			j++;
		}
	}
	
	/// this constructor is used if the object is non-const.  This serializes in constructor,  and deserializes on the destructor.
	ScopedDeserialize(StringDeque& s,  ObjectDeque& obj) : strQueue(&s),  constStrQueue(&s),  objectQueue(obj)
	{
		//objectList.resize(constStrList->size());
		typename mace::deque<ORIGIN>::iterator j = objectQueue.begin();
		for (typename StringDeque::const_iterator i = constStrQueue->begin(); i != constStrQueue->end(); i++) {
			mace::deserialize(*i,  &(*j));
			j++;
		}
	}
	
	~ScopedDeserialize() {
		if (strQueue) {
			//strQueue->resize(objectList.size());
			typename StringDeque::iterator j = strQueue->begin();
			for (typename ObjectDeque::const_iterator i = objectQueue.begin(); i != objectQueue.end(); i++) {
				mace::serialize(*j,  &(*i));
				j++;
			}
		  strQueue = NULL;
		}
		constStrQueue = NULL;
	}
}; // class ScopedSerialize



#endif // _MACE_DEQUE_H
