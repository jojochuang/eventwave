#ifndef _m_net_h
#define _m_net_h

/**
 * \file m_net.h
 * \brief file to include for networking includes for portability
 */

#include "maceConfig.h"

#ifdef HAVE_NETINET_IN_H
#include "netinet/in.h"
#endif

#ifdef HAVE_NETINET_TCP_H
#include "netinet/tcp.h"
#endif

#ifdef HAVE_NETDB_H
#include "netdb.h"
#endif

#ifdef HAVE_SYS_SELECT_H
#include "sys/select.h"
#endif

#ifdef HAVE_SYS_SOCKET_H
#include "sys/socket.h"
#endif

#ifdef HAVE_ARPA_INET_H
#include "arpa/inet.h"
#endif

#if ! ( defined(HAVE_ARPA_INET_H) || defined(HAVE_SYS_SOCKET_H) || defined(HAVE_SYS_SELECT_H) || defined(HAVE_NETDB_H) || defined(HAVE_NETINET_IN_H) )
#include "windows.h"
#include "winsock2.h"
#include "ws2tcpip.h"

#if defined(WSAENOTCONN) && ! defined(ENOTCONN)
//#define EINPROGRESS WSAEINPROGRESS
//#define ENOBUFS WSAENOBUFS
//#define EPROTO WSAEPROTONOSUPPORT
//#define ECONNABORTED WSAECONNABORTED
//#define EWOULDBLOCK WSAEWOULDBLOCK
//#define ENOTCONN WSAENOTCONN
#define NO_SIGPIPE
#endif

#endif

#endif //_m_net_h
