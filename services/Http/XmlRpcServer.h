/* 
 * XmlRpcServer.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2011, James W. Anderson, Ryan Braud, Charles Killian
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
#ifndef XML_RPC_SERVER_H
#define XML_RPC_SERVER_H

#include "HttpServer.h"
#include "XmlRpcUrlHandler.h"

class XmlRpcServer {
public:
  XmlRpcServer(const std::string& url, uint16_t port, int backlog = SOMAXCONN);
  XmlRpcServer(const std::string& url, HttpServer* s);
  virtual ~XmlRpcServer();
  virtual void registerHandler(const std::string& className, XmlRpcHandler* handler,
			       StringSet* methods = 0);
  virtual void run();
  virtual void shutdown();

private:
  void setupServer(const std::string& url);

private:
  bool deleteServer;
  XmlRpcUrlHandler xh;
  HttpServer* httpd;
};

#endif // XML_RPC_SERVER_H
