SET(APPS logicalnode)
SET(SERVICES TcpTransport LogicalNode Test1Ping)

INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../application.cmake)

ADD_TEST("logicalnode-test1ping" ${EXECUTABLE_OUTPUT_PATH}/logicalnode -test_case 1) 

