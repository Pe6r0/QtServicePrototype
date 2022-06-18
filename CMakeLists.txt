cmake_minimum_required(VERSION 3.1)

project(TestService)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Test)

enable_testing(true)

set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT TestService)

set(SOURCES
    src/main.cpp
    src/Service_Test.cpp
	src/Service.cpp
	src/EligibilityService.cpp
	src/RewardsService.cpp)
set(HEADERS
    include/Service_Test.h
	include/Service.h
	include/EligibilityService.h
	include/RewardsService.h)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_test(NAME mytest COMMAND mytest)

target_link_libraries(TestService 
PUBLIC

PRIVATE
Qt::Widgets
Qt::Test
Qt::Core)