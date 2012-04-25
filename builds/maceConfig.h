#ifndef _maceConfig_h
#define _maceConfig_h

/* #undef EINVAL_IS_NOTCONN */
/* #undef STUPID_FD_SET_CONST_HACK */
/* #undef OSX_MACELIB_DAEMON */
/* #undef OSX_SCHED_YIELD */

/* #undef HAVE_TOKYO_CABINET */
#define HAVE_GSL

/* #undef HAVE_UNISTD_H */
/* #undef HAVE_SYS_TIME_H */
#define HAVE_NETDB_H
#define HAVE_NETINET_IN_H
#define HAVE_NETINET_TCP_H
#define HAVE_ARPA_INET_H
#define HAVE_SYS_SELECT_H
#define HAVE_SYS_WAIT_H

#define HAVE_DRAND48
/* #undef HAVE_RAND_S */
#define HAVE_RAND
#define HAVE_PIPE
/* #undef HAVE__PIPE */
#define HAVE_FCNTL
/* #undef HAVE_IOCTLSOCKET */
#define HAVE_SIGACTION
#define HAVE_GETPPID
#define HAVE_WAITPID
/* #undef HAVE__CWAIT */

#define INCLUDE_CGI

/* #undef WINDOWS_FILES */

#define UINT64T_IS_NOT_ULONGLONG

#define SIGNED_SOCKET
#ifdef SIGNED_SOCKET
typedef int socket_t;
#else
typedef unsigned int socket_t;
#endif

#define HAVE_USECONDS_T
#ifndef HAVE_USECONDS_T
typedef unsigned int useconds_t;
#endif

#define HAVE_SUSECONDS_T
#ifndef HAVE_SUSECONDS_T
typedef int suseconds_t;
#endif

#define HAVE_UINT
#ifndef HAVE_UINT
typedef unsigned int uint;
typedef unsigned short ushort;
#endif

#define HAVE_IN_ADDR_T
#ifndef HAVE_IN_ADDR_T
typedef uint32_t in_addr_t;
#endif

#define USE_SNAPSHOT

#endif //_maceConfig_h
