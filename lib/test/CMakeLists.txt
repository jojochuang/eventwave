INCLUDE_DIRECTORIES(${Mace_SOURCE_DIR}/lib)
INCLUDE_DIRECTORIES(${Mace_SOURCE_DIR}/services/Transport)
INCLUDE_DIRECTORIES(${Mace_BINARY_DIR}/services/interfaces)
INCLUDE_DIRECTORIES(${Mace_SOURCE_DIR}/services/interfaces)
#SET( SERVICES TcpTransport )
#INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../../application/application.cmake)
ADD_EXECUTABLE(libtest1 libtest1.cc)
TARGET_LINK_LIBRARIES(libtest1 boost_unit_test_framework mace)

ADD_TEST("libmace" ${EXECUTABLE_OUTPUT_PATH}/libtest1)

ADD_EXECUTABLE(fullcontext_test fullcontext_test.cc)
TARGET_LINK_LIBRARIES(fullcontext_test boost_unit_test_framework mace)

ADD_TEST("libmace-fullcontext-test" ${EXECUTABLE_OUTPUT_PATH}/fullcontext_test)

ADD_EXECUTABLE(contextlock_test contextlock_test.cc)
TARGET_LINK_LIBRARIES(contextlock_test boost_unit_test_framework mace)

ADD_TEST("libmace-contextlock-test1" ${EXECUTABLE_OUTPUT_PATH}/contextlock_test -test_option 1)
ADD_TEST("libmace-contextlock-test2" ${EXECUTABLE_OUTPUT_PATH}/contextlock_test -test_option 2)
ADD_TEST("libmace-contextlock-test3" ${EXECUTABLE_OUTPUT_PATH}/contextlock_test -test_option 3)

ADD_EXECUTABLE(ThreadStructure_test ThreadStructure_test.cc)
TARGET_LINK_LIBRARIES(ThreadStructure_test boost_unit_test_framework mace)

ADD_TEST("libmace-ThreadStructure-test" ${EXECUTABLE_OUTPUT_PATH}/ThreadStructure_test )

ADD_EXECUTABLE(ContextBaseClass_test ContextBaseClass_test.cc)
TARGET_LINK_LIBRARIES(ContextBaseClass_test boost_unit_test_framework mace)

ADD_TEST("libmace-ContextBaseClass-test" ${EXECUTABLE_OUTPUT_PATH}/ContextBaseClass_test )

ADD_EXECUTABLE(ScopedContextRPC_test ScopedContextRPC_test.cc)
TARGET_LINK_LIBRARIES(ScopedContextRPC_test boost_unit_test_framework mace)

ADD_TEST("libmace-ScopedContextRPC-test" ${EXECUTABLE_OUTPUT_PATH}/ScopedContextRPC_test )
