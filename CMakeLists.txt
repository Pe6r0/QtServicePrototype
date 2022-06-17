cmake_minimum_required(VERSION 3.1)

project(TestService)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_WIN32_EXECUTABLE ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Test)


enable_testing(true)

set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT TestService)

set(SOURCES
    src/main.cpp
    src/TestService.cpp
	src/Service.cpp
	src/EService.cpp
	src/RService.cpp)
set(HEADERS
    include/TestService.h
	include/Service.h
	include/EService.h
	include/RService.h)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_test(NAME mytest COMMAND mytest)

target_link_libraries(TestService 
PUBLIC

PRIVATE
Qt5::Widgets
Qt5::Test
Qt5::Core)