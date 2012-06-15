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
