# Install script for directory: /Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/mo" TYPE FILE FILES
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/mo.h"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/mo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/mo" TYPE DIRECTORY FILES
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/acceptCrit"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/algo"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/comparator"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/continuator"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/coolingSchedule"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/eval"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/explorer"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/memory"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/neighborhood"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/perturb"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/problems"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/mo/src/sampling"
    FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

