SET(APPS migrationtest)
SET(SERVICES TcpTransport TestCases TestCase6)

INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../application.cmake)

ADD_TEST("migrationtest-testcase2" ${EXECUTABLE_OUTPUT_PATH}/migrationtest -test_case 6) 

