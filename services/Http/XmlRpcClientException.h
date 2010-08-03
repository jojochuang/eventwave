/* 
 * XmlRpcClientException.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2007, James W. Anderson, Ryan Braud, Charles Killian
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
#ifndef XML_RPC_CLIENT_EXCEPTION_H
#define XML_RPC_CLIENT_EXCEPTION_H

#include <boost/lexical_cast.hpp>

#include "HttpClientException.h"

class XmlRpcClientException : public HttpClientException {
public:
  XmlRpcClientException(const std::string m, int faultCode) 
    : HttpClientException(m), faultCode(faultCode) { }
  XmlRpcClientException(const HttpClientException& he, int faultCode) 
    : HttpClientException(he.toString()), faultCode(faultCode) { }
  virtual std::string toString() const {
    return "server returned fault " + boost::lexical_cast<std::string>(faultCode) + ": " + message;
  }
  void rethrow() const { throw *this; }

protected:
  int faultCode;
};


#endif // XML_RPC_CLIENT_EXCEPTION_H
