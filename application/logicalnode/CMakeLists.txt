SET(APPS logicalnode)
SET(SERVICES TcpTransport LogicalNode Test1Ping Test2OfferedLoad)

INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../application.cmake)

ADD_TEST("logicalnode-test1ping" ${EXECUTABLE_OUTPUT_PATH}/logicalnode -test_case 1 -fork 1) 
#ADD_TEST("logicalnode-test2offeredload" ${EXECUTABLE_OUTPUT_PATH}/logicalnode -test_case 2 -fork 1) 

