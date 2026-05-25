cmake_minimum_required(VERSION 4.1.0)
project(tokyo
    LANGUAGES CXX
    VERSION   1.0.0
)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(TOKYO_BUILD_DEMO "Build tokyo demo" OFF)

add_library(tokyo INTERFACE)
add_library(tokyo::tokyo ALIAS tokyo)

target_include_directories(tokyo INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)

target_sources(tokyo INTERFACE
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
    FILES     ${CMAKE_CURRENT_SOURCE_DIR}/tokyo/tokyo_main.hxx
)

if(TOKYO_BUILD_DEMO)
    add_executable(demo
        demo/main.cpp
    )
    target_link_libraries(demo
        PRIVATE
            tokyo::tokyo
    )
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS tokyo
    EXPORT tokyoTargets
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT tokyoTargets
    FILE tokyoTargets.cmake
    NAMESPACE tokyo::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tokyo)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/tokyoConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
    ARCH_INDEPENDENT)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/tokyoConfig.cmake
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/tokyoTargets.cmake\")\n")

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/tokyoConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/tokyoConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tokyo
)
