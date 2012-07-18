SET(APPS testrun)
SET(SERVICES TcpTransport TestCases TestCase1 TestCase0 TestCase2 TestCase3 TestCase4 )

INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../application.cmake)

ADD_TEST("testrun-testcase0" ${EXECUTABLE_OUTPUT_PATH}/testrun -test_case 0) 
ADD_TEST("testrun-testcase1" ${EXECUTABLE_OUTPUT_PATH}/testrun -test_case 1) 
ADD_TEST("testrun-testcase2" ${EXECUTABLE_OUTPUT_PATH}/testrun -test_case 2) 
ADD_TEST("testrun-testcase3" ${EXECUTABLE_OUTPUT_PATH}/testrun -test_case 3) 
ADD_TEST("testrun-testcase4" ${EXECUTABLE_OUTPUT_PATH}/testrun -test_case 4) 
