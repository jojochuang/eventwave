/* 
 * mvector.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2007, Charles Killian, Dejan Kostic, Ryan Braud, James W. Anderson, John Fisher-Ogden, Calvin Hubble, Duy Nguyen, Justin Burke, David Oppenheimer, Amin Vahdat, Adolfo Rodriguez, Sooraj Bhat
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *    * Neither the names of Duke University nor The University of
 *      California, San Diego, nor the names of the authors or contributors
 *      may be used to endorse or promote products derived from
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
#include <vector>
#include <iostream>
#include "Serializable.h"
#include "XmlRpcCollection.h"
#include "StrUtil.h"
#include "mace_constants.h"

#ifndef _MACE_VECTOR_H
#define _MACE_VECTOR_H

/**
 * \file mvector.h
 * \brief definition of the mace::vector extension of std::vector
 */

namespace mace {

/**
 * \addtogroup Collections
 * @{
 */

/// mace::vector extends std::vector, but has support for printing and optional serialization, random, and the ability to get an array pointer.
/**
 * For most documentation, you should refer to the SGI STL documentation
 * http://www.sgi.com/tech/stl
 */
template<class T, class Serial = SerializeList<T>, class Alloc = std::allocator<T> >
class vector : public std::vector<T, Alloc>, public Serial, public PrintPrintable {

  BOOST_CLASS_REQUIRE2(Serial, Serializer, boost, ConvertibleConcept);

public:
  typedef typename std::vector<T, Alloc> baseType;
  typedef typename baseType::iterator iterator;
  typedef typename baseType::const_iterator const_iterator;
  typedef typename baseType::const_reverse_iterator const_reverse_iterator;
  typedef typename baseType::size_type size_type;

  vector() : baseType() {
  }

  vector(size_type n) : baseType(n) {
  }

  vector(size_type n, const T& t) : baseType(n, t) {
  }

  vector(const std::vector<T, Alloc>& v) : baseType(v) {
  }

  vector(const const_iterator& b, const const_iterator& e) : baseType(b, e) {
  }
  
  vector(const const_reverse_iterator& b, const const_reverse_iterator& e) : baseType(b, e) {
  }

  virtual ~vector() { }

  /// set the number of elements
  void resize(size_t sz) {
    baseType::resize(sz);
  }

  /// set the number of elements, providing a default object for newly constructed elements
  void resize(size_t sz, const T& t) {
    baseType::resize(sz, t);
  }
  
  /// return the number of elements
  size_t size() const {
    return baseType::size();
  }

  const_iterator find(const T& t) const {
    const_iterator i = this->begin();
    while (i != this->end()) {
      if (*i == t) {
	return i;
      }
      i++;
    }
    return i;
  }
  
  //int deserialize(std::istream& in) throw(SerializationException) {
  //
  //  size_type sz;
  //  int bytes = sizeof(sz);

  //  mace::deserialize(in, &sz);
  //  this->resize(sz);
  //  for(size_type i=0; i<sz; i++) {
  //    bytes += mace::deserialize(in, &this->operator[](i));
  //  }
  //  
  //  return bytes;
  //}

  //int deserializeXML_RPC(std::istream& in) throw(SerializationException) {
  //  return XmlRpcArrayDeserialize<vector<T, Alloc>, T>(in, *this);
  //}

  //void serialize(std::string& str) const {
  //  size_type sz = this->size();

  //  //SerializableTraits<uint32_t>::serialize(str, sz);
  //  mace::serialize(str, &sz);
  //  for(const_iterator i=this->begin(); i!=this->end(); i++) {
  //    //SerializableTraits<T>::serialize(str, *i);
  //    mace::serialize(str, &(*i));
  //  }
  //}

  //void serializeXML_RPC(std::string& str) const throw(SerializationException) {
  //  XmlRpcArraySerialize(str, this->begin(), this->end());
  //}

  
  /// Return the template parameter string Key->Data for actual template parameters. (Mace extension)
  const std::string& getTypeName() const {
    const char* types[] = { "T", "Serial", "Alloc", 0 };
    static const StrUtilNamespace::StdStringList myTypes = StrUtilNamespace::getTypeFromTemplate(__PRETTY_FUNCTION__, types);
    return myTypes[0];
  }

  void print(std::ostream& out) const {
    if(mace::PRINT_TYPE_NAMES) {
      out << "vector<"<<this->getTypeName()<<">";
    }
    printList(out, this->begin(), this->end());
  }
  void printState(std::ostream& out) const {
    if(mace::PRINT_TYPE_NAMES) {
      out << "vector<"<<this->getTypeName()<<">";
    }
    printListState(out, this->begin(), this->end());
  }

  /// return a random element, or end() if none.
  const_iterator random() const {
    if(this->size()==0) { return this->end(); }
    int rand = RandomUtil::randInt(this->size());
    return this->begin() + rand;
  }

  /// return the internal array pointer
  /// \warning DO NOT USE, NON PORTABLE AND UNSAFE
  T* getMem() {
    return this->_M_impl._M_start;
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

      v_const_iterator(const_iterator beg, const_iterator end) : i(beg), end(end) {}
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
#endif // _MACE_VECTOR_H
