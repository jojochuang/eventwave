SET(APPS testrun)
SET(SERVICES TcpTransport TestCases TestCase1 TestCase0 )

INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../application.cmake)

ADD_TEST("testrun-testcase1" ${EXECUTABLE_OUTPUT_PATH}/testrun -test_case 1) 
