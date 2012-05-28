INCLUDE_DIRECTORIES(${Mace_SOURCE_DIR}/lib)
ADD_EXECUTABLE(libtest1 libtest1.cc)
TARGET_LINK_LIBRARIES(libtest1 boost_unit_test_framework mace)

ADD_TEST("libmace-test1" ${EXECUTABLE_OUTPUT_PATH}/libtest1)
