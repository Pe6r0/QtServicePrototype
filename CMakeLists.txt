cmake_minimum_required(VERSION 3.1)

project(Services)

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
	src/Service_Test.cpp
	src/Service.cpp
	src/ServiceManager.cpp
	src/EligibilityService.cpp
	src/RewardsService.cpp)
set(HEADERS
	include/Service.h
	include/ServiceManager.h
	include/EligibilityService.h
	include/RewardsService.h)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_test(NAME Service_Test COMMAND Service_Test)

target_link_libraries(Services 
PUBLIC

PRIVATE
Qt::Widgets
Qt::Test
Qt::Core)

add_custom_command(TARGET Services POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E
        env PATH="${_qt_bin_dir}" "${WINDEPLOYQT_EXECUTABLE}"
            "$<TARGET_FILE:Services>"
    COMMENT "Running windeployqt..."
)

add_custom_command(
        TARGET Services POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/config.json
                ${CMAKE_CURRENT_BINARY_DIR}/config.json)
