SET(APPS contextrun)
SET(SERVICES TcpTransport 
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
