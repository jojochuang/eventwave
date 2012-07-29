SET(APPS migrationtest)
SET(SERVICES TcpTransport TestCases TestCase5 )

INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../application.cmake)

#ADD_TEST("migrationtest-testcase0" ${EXECUTABLE_OUTPUT_PATH}/migrationtest -test_case 0) 
#ADD_TEST("migrationtest-testcase1" ${EXECUTABLE_OUTPUT_PATH}/migrationtest -test_case 1) 
#ADD_TEST("migrationtest-testcase2" ${EXECUTABLE_OUTPUT_PATH}/migrationtest -test_case 2) 
#ADD_TEST("migrationtest-testcase3" ${EXECUTABLE_OUTPUT_PATH}/migrationtest -test_case 3) 
#ADD_TEST("migrationtest-testcase4" ${EXECUTABLE_OUTPUT_PATH}/migrationtest -test_case 4) 
ADD_TEST("migrationtest-testcase1" ${EXECUTABLE_OUTPUT_PATH}/migrationtest -test_case 5) 

