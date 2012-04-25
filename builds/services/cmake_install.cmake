# Install script for directory: /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services

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
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RequestTransport/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Http/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RandTree/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ReplayTree/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RanSub/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Pastry/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Bamboo/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Chord/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericOverlayRoute/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericTreeMulticast/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ScribeMS/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SignedMulticast/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SimApplication/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SplitStreamMS/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/DHT/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/CondorHeartBeat/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/LUFactorization/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/LUFAck/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ThroughputTest/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GameOfLife/cmake_install.cmake")
  INCLUDE("/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Simple/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

