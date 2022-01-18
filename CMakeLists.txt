cmake_minimum_required(VERSION 2.8)
project(SolarTest)
# Locate libraries and headers
find_library(wiringPi_LIB wiringPi)
find_package(Threads REQUIRED)

# Include headers
include_directories(${WIRINGPI_INCLUDE_DIRS}) 
include_directories("../RemoteControlTest")

#the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "./*.cpp")
add_executable(SolarTest ${SOURCES} "../RemoteControlTest/DiagnosticsSensor.cpp" "../RemoteControlTest/HumiditySensor.cpp" "../RemoteControlTest/AToD.cpp" "../RemoteControlTest/Sensor.cpp" "../RemoteControlTest/BatteryCharge.cpp" "../RemoteControlTest/CommandList.cpp" "../RemoteControlTest/ShipLog.cpp" "../RemoteControlTest/filedata.cpp" "../RemoteControlTest/Util.cpp")

# Link against libraries
target_link_libraries(SolarTest ${wiringPi_LIB} )
target_link_libraries(SolarTest ${CMAKE_THREAD_LIBS_INIT})



