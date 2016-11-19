# Install script for directory: /Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/build/moeo/lib/libmoeo.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libmoeo.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libmoeo.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libmoeo.a")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/moeo" TYPE FILE FILES "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/moeo")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/paradiseo/moeo" TYPE DIRECTORY FILES
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/acceptCrit"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/algo"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/archive"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/comparator"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/core"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/distance"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/diversity"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/do"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/explorer"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/fitness"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/hybridization"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/metric"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/replacement"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/scalarStuffs"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/selection"
    "/Users/dominikguz/Documents/Masters/S1/ParetoTSP/Src/ParadisEO-2.0/moeo/src/utils"
    FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

