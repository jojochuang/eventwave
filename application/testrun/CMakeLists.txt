SET(APPS testrun multinode contextrun)
SET(SERVICES TcpTransport 
  TestCases TestCase1 
  TestCase2
  TestCase3
  TestCase4
  TestCase5
  TestCase6 TestCase7
  #MISmulti 
  MicroBenchmark 
  #	GOLmulti
  TagServer TagClient TagClientRG
  TagServerAsync
  KeyValueServer KeyValueClient
  #FakeTagServer FakeTagClient
  TestTimerServer TestTimerClient
  TestTimer
)

INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../application.cmake)

ADD_TEST("testrun-testcase1" ${EXECUTABLE_OUTPUT_PATH}/testrun -test_case 1) 
ADD_TEST("testrun-testcase2" ${EXECUTABLE_OUTPUT_PATH}/testrun ${Mace_SOURCE_DIR}/tools/contextlattice/params.test2) 
ADD_TEST("testrun-testcase3" ${Mace_SOURCE_DIR}/tools/contextlattice/test_twophysicalnode.sh ${Mace_SOURCE_DIR}/tools/contextlattice/)
ADD_TEST("testrun-testcase4" ${EXECUTABLE_OUTPUT_PATH}/testrun ${Mace_SOURCE_DIR}/tools/contextlattice/params.test4) 
ADD_TEST("testrun-testcase5" ${EXECUTABLE_OUTPUT_PATH}/testrun ${Mace_SOURCE_DIR}/tools/contextlattice/params.test5) 
ADD_TEST("testrun-testcase6" ${EXECUTABLE_OUTPUT_PATH}/testrun ${Mace_SOURCE_DIR}/tools/contextlattice/params.test6) 
#ADD_TEST("testrun-testcase7" ${EXECUTABLE_OUTPUT_PATH}/testrun -test_case 7) 

ADD_TEST("testrun-migrate1"  ${Mace_SOURCE_DIR}/tools/contextlattice/run_migration_test.sh ${Mace_SOURCE_DIR}/tools/contextlattice/)
