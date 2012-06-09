INCLUDE_DIRECTORIES(${Mace_SOURCE_DIR}/lib)
ADD_EXECUTABLE(libtest1 libtest1.cc)
TARGET_LINK_LIBRARIES(libtest1 boost_unit_test_framework mace)

ADD_TEST("libmace-fullcontext-test" ${EXECUTABLE_OUTPUT_PATH}/libtest1)

ADD_EXECUTABLE(fullcontext_test fullcontext_test.cc)
TARGET_LINK_LIBRARIES(fullcontext_test boost_unit_test_framework mace)

ADD_TEST("libmace-fullcontext-test" ${EXECUTABLE_OUTPUT_PATH}/libtest1)
