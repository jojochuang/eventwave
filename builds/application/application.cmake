SET(COMMONLIBS ${COMMONLIBS} interfaces mace m stdc++)

IF(XMLRPC)
  INCLUDE(${Mace_BINARY_DIR}/perl5/PerlDeps.txt)
  INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
ENDIF(XMLRPC)

INCLUDE_DIRECTORIES(/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/RequestTransport;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Http;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/File;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/RandTree;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/ReplayTree;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/RanSub;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Pastry;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Bamboo;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Chord;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/GenericOverlayRoute;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/GenericTreeMulticast;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/ScribeMS;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/SignedMulticast;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/SimApplication;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/SplitStreamMS;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/FileSync;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/DHT;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/CondorHeartBeat;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/LUFactorization;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/LUFAck;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/ThroughputTest;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/GameOfLife;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Simple /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RequestTransport;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Http;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RandTree;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ReplayTree;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RanSub;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Pastry;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Bamboo;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Chord;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericOverlayRoute;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericTreeMulticast;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ScribeMS;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SignedMulticast;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SimApplication;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SplitStreamMS;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/DHT;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/CondorHeartBeat;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/LUFactorization;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/LUFAck;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ThroughputTest;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GameOfLife;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple)

FOREACH(DIR /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RequestTransport;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Http;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RandTree;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ReplayTree;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RanSub;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Pastry;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Bamboo;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Chord;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericOverlayRoute;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericTreeMulticast;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ScribeMS;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SignedMulticast;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SimApplication;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SplitStreamMS;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/DHT;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/CondorHeartBeat;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/LUFactorization;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/LUFAck;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ThroughputTest;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GameOfLife;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple)
  INCLUDE(${DIR}/mh.cmake)
ENDFOREACH(DIR /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RequestTransport;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Http;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RandTree;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ReplayTree;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RanSub;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Pastry;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Bamboo;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Chord;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericOverlayRoute;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericTreeMulticast;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ScribeMS;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SignedMulticast;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SimApplication;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SplitStreamMS;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/DHT;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/CondorHeartBeat;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/LUFactorization;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/LUFAck;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ThroughputTest;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GameOfLife;/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple)

IF(SERVICES STREQUAL ALL) 
  #MESSAGE("Using All Services: ${ALL_SERVICES}")
  SET(SERVICES ${ALL_SERVICES})
ENDIF(SERVICES STREQUAL ALL) 

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    ${Mace_SOURCE_DIR}/application/common
                    ${Mace_BINARY_DIR}/services/interfaces
                    ${Mace_SOURCE_DIR}/services/interfaces
                    ${Mace_SOURCE_DIR}/services
                    ${Mace_SOURCE_DIR}/lib
                    ${Mace_SOURCE_DIR}
                    ${Mace_BINARY_DIR}
                    )

IF(EXTRALIBS MATCHES "Http")
  INCLUDE_DIRECTORIES(${Mace_SOURCE_DIR}/services/Http)
  SET(SVLIBDEPS ${SVLIBDEPS} Http)
ENDIF(EXTRALIBS MATCHES "Http")

IF(EXISTS ${HDFS_INC_PATH})
  FIND_LIBRARY(LIB_HDFS hdfs)
  FIND_LIBRARY(LIB_JVM jvm)
ENDIF(EXISTS ${HDFS_INC_PATH})

FOREACH(XM ${XMLRPC})
  GET_FILENAME_COMPONENT(XMBASE ${XM} NAME_WE)
  IF(${XM} MATCHES "ServiceClass.h") 
  SET_SOURCE_FILES_PROPERTIES(${XM} PROPERTIES GENERATED true)
  ENDIF(${XM} MATCHES "ServiceClass.h") 
  ADD_CUSTOM_COMMAND(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${XMBASE}XmlRpcHandler.h 
                            ${CMAKE_CURRENT_BINARY_DIR}/${XMBASE}XmlRpcClient.h 
                            ${CMAKE_CURRENT_BINARY_DIR}/${XMBASE}XmlRpcClient.cc 
                     COMMAND ${PERL_EXECUTABLE} -I ${Mace_BINARY_DIR}/perl5 ${xmlrpcc} ${XM} -c ${XMBASE}
                     MAIN_DEPENDENCY ${XM}
                     DEPENDS ${xmlrpcc_dep}
                     )
  SET(GENSRCS ${GENSRCS} ${CMAKE_CURRENT_BINARY_DIR}/${XMBASE}XmlRpcClient.cc)
ENDFOREACH(XM ${XMLRPC})

FILE(GLOB LIBFILES *.cc *.c)
SET(LIBFILES ${LIBFILES} ${GENSRCS})
FOREACH(APP ${APPS})
  LIST(REMOVE_ITEM LIBFILES ${CMAKE_CURRENT_SOURCE_DIR}/${APP}.cc)
  IF(${APP}_SRCS)
    FOREACH(SRC ${${APP}_SRCS})
      LIST(REMOVE_ITEM LIBFILES ${CMAKE_CURRENT_SOURCE_DIR}/${SRC})
    ENDFOREACH(SRC ${${APP}_SRCS})
  ENDIF(${APP}_SRCS)
ENDFOREACH(APP ${APPS})

FOREACH(SV ${SERVICES}) 
  ADD_DEFINITIONS(-DUse${SV})
  SET(SVLIBDEPS ${SVLIBDEPS} ${${SV}Service_lib})
ENDFOREACH(SV ${SERVICES}) 
# Remove duplicates in service dependencies -- reduces linker memory req
LIST(LENGTH SVLIBDEPS SVLIBDEPS_LENGTH)
IF(${SVLIBDEPS_LENGTH} GREATER 0)
  LIST(REMOVE_DUPLICATES SVLIBDEPS)
ENDIF(${SVLIBDEPS_LENGTH} GREATER 0)

#MESSAGE("Processing application ${APPS}")

#LIST(APPEND SERVICELIST ${SERVICES})
FOREACH(SV ${SERVICES})
  #MESSAGE("Service ${SV} List ${${SV}Service_sv_dep}")
  LIST(APPEND SERVICELIST ${${SV}Service_sv_dep})
ENDFOREACH(SV ${SERVICES})

IF(DEFINED SERVICELIST)
  LIST(REMOVE_DUPLICATES SERVICELIST)
ENDIF(DEFINED SERVICELIST)

FOREACH(SVL ${SERVICELIST})
  SET(DECL_LOAD_PROTO_SV "${DECL_LOAD_PROTO_SV}
namespace ${SVL}_namespace {
void load_protocol();
} ")
  SET(LOAD_PROTO_STRING_SV "${LOAD_PROTO_STRING_SV}
      ${SVL}_namespace::load_protocol();")
ENDFOREACH(SVL ${SERVICELIST})

SET(LOAD_PROTO_STRING "void load_protocols() { ${LOAD_PROTO_STRING_SV} 
} ")
#MESSAGE("Testing Apps(${APPS}) ${LOAD_PROTO_STRING}")

CONFIGURE_FILE(${Mace_SOURCE_DIR}/application/load_protocols.h.in ${CMAKE_CURRENT_BINARY_DIR}/load_protocols.h @ONLY)

#SET(SVLIBDEPSGEN OBJECT_DEPENDS DHT_gen)
#IF(SVLIBDEPS)
#  FOREACH(D ${SVLIBDEPS})
#    LIST(APPEND SVLIBDEPSGEN OBJECT_DEPENDS ${D})
#  ENDFOREACH(D ${SVLIBDEPS})
#ENDIF(SVLIBDEPS)

IF(LIBFILES)
  IF(NOT LIBNAME)
    GET_FILENAME_COMPONENT(LIBNAME ${CMAKE_CURRENT_SOURCE_DIR}Extras NAME)
  ENDIF(NOT LIBNAME)

  #IF(SVLIBDEPSGEN)
  #MESSAGE("SET_SOURCE_FILES_PROPERTIES(${LIBFILES} PROPERTIES ${SVLIBDEPSGEN})")
  #SET_SOURCE_FILES_PROPERTIES(${LIBFILES} PROPERTIES ${SVLIBDEPSGEN})
  #ENDIF(SVLIBDEPSGEN)

  ADD_LIBRARY(${LIBNAME} ${LIBTYPE} ${LIBFILES})
  IF(SVLIBDEPS)
    ADD_DEPENDENCIES(${LIBNAME} ${SVLIBDEPS})
  ENDIF(SVLIBDEPS)
  TARGET_LINK_LIBRARIES(${LIBNAME} ${SVLIBDEPS} ${EXTRALIBS} ${COMMONLIBS})
ELSE(LIBFILES)
  SET(LIBNAME)
ENDIF(LIBFILES)

#MESSAGE("${APPS} (LIB): ${SVLIBDEPS}")

FOREACH(APP ${APPS})
  IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${APP}.cc)
    SET(APP_SRC ${APP}.cc)
  ELSE(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${APP}.cc)
    IF(NOT ${APP}_SRCS)
      MESSAGE(FATAL_ERROR "Cannot find ${APP}.cc and ${APP}_SRCS not set")
    ENDIF(NOT ${APP}_SRCS)
  ENDIF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${APP}.cc)

  #IF(SVLIBDEPSGEN)
  #MESSAGE("SET_SOURCE_FILES_PROPERTIES(${APP_SRC} ${${APP}_SRCS} PROPERTIES ${SVLIBDEPSGEN})")
  #SET_SOURCE_FILES_PROPERTIES(${APP_SRC} ${${APP}_SRCS} PROPERTIES ${SVLIBDEPSGEN})
  #ENDIF(SVLIBDEPSGEN)

  ADD_EXECUTABLE(${APP} ${APP_SRC} ${${APP}_SRCS})
  IF(SVLIBDEPS)
    ADD_DEPENDENCIES(${APP} ${SVLIBDEPS})
  ENDIF(SVLIBDEPS)
  TARGET_LINK_LIBRARIES(${APP} ${LIBNAME} ${SVLIBDEPS} ${EXTRALIBS} ${COMMONLIBS})
ENDFOREACH(APP)

