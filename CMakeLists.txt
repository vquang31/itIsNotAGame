cmake_minimum_required(VERSION 3.10)
project(itIsNotAGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Output directories for executables and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.h)

include_directories(include thirdparty)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

add_executable(itIsNotAGame ${SOURCES} ${HEADERS} )

target_link_libraries(itIsNotAGame sfml-graphics sfml-audio sfml-window sfml-system)

#if(CMAKE_SYSTEM_NAME MATCHES "Windows")
#   target_link_libraries(itIsNotAGame sfml-graphics sfml-audio sfml-window sfml-system -mwindows)
#elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
#    target_link_libraries(itIsNotAGame sfml-graphics sfml-audio sfml-window sfml-system -Wl,-no-console)
#endif()

# Copy assets to the output directory after build
add_custom_command(TARGET itIsNotAGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:itIsNotAGame>/assets)