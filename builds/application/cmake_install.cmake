# Install script for directory: /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/common/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/logreader/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/ttcp/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/logd/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appmacedon/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appmacedon_test/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/filecopy/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/dht/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/unit_app/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/heartbeat/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/simulator_common/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/simulator/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/http/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/notify/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/filefind/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appgroupstream/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

