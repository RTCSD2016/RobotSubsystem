cmake_minimum_required(VERSION 2.6)

project(main)

 
# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_CXX_FLAGS "-D_GNU_SOURCE -D_REENTRANT -D__XENO__")
SET(CMAKE_EXE_LINKER_FLAGS "-Xlinker -rpath -Xlinker /usr/xenomai/lib ")

INCLUDE_DIRECTORIES(${ProjDirPath}/.)
INCLUDE_DIRECTORIES(/usr/xenomai/include)

LINK_DIRECTORIES(/usr/lib)
LINK_DIRECTORIES(/usr/xenomai/lib)

# ADD_EXECUTABLE
ADD_EXECUTABLE(main 
    "${ProjDirPath}/./main.cpp"
    "${ProjDirPath}/./RobotCommand.cpp"
    "${ProjDirPath}/./TrajectoryPlannning.cpp"

)

TARGET_LINK_LIBRARIES(main native xenomai pthread rt)

