IF(${PROJECT_NAME} STREQUAL "Mace")
  SET(APPS modelchecker)
  SET(modelchecker_SRCS ServiceTests.cc ${EXTERNAL_TEST_SRCS})
  SET(LIBNAME MaceMC)
ELSE(${PROJECT_NAME} STREQUAL "Mace")
  SET(APPS ${PROJECT_NAME}_modelchecker)
  SET(${PROJECT_NAME}_modelchecker_SRCS modelchecker.cc ${EXTERNAL_TEST_SRCS})
  SET(LIBNAME ${PROJECT_NAME}MaceMC)
  LINK_DIRECTORIES(${Mace_BINARY_DIR}/application/simulator_common)
ENDIF(${PROJECT_NAME} STREQUAL "Mace")

SET(SERVICES ALL)
SET(EXTRALIBS SimulatorCommonFiles)

INCLUDE_DIRECTORIES(${Mace_SOURCE_DIR}/application/simulator_common)
INCLUDE_DIRECTORIES(${Mace_SOURCE_DIR}/application/modelchecker)

# Uncomment the line below for better performance
#SET(CMAKE_CXX_FLAGS "-O2")

INCLUDE(${${PROJECT_NAME}_BINARY_DIR}/${APPLICATION_SUBDIR}/application.cmake)

IF(${PROJECT_NAME} STREQUAL "Mace")
ELSE(${PROJECT_NAME} STREQUAL "Mace")
  SET_TARGET_PROPERTIES(${PROJECT_NAME}_modelchecker PROPERTIES OUTPUT_NAME modelchecker)
ENDIF(${PROJECT_NAME} STREQUAL "Mace")
