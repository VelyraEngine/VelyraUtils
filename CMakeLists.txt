cmake_minimum_required(VERSION 3.22)
project(VelyraUtils DESCRIPTION "C++ utilities for Velyra projects")

include(VelyraBuildUtils/VelyraBuildUtils.cmake)

fetch_spdlog()

set(velyra_utils_headers
    include/VelyraUtils/VelyraUtils.hpp
    include/VelyraUtils/Logging.hpp
    include/VelyraUtils/VelyraEnum.hpp
    include/VelyraUtils/ExportUtils.hpp
    include/VelyraUtils/TypeTraits.hpp
    include/VelyraUtils/PlatformDetection.hpp
    include/VelyraUtils/Math.hpp

    include/VelyraUtils/DevUtils/MacroExpansion.hpp
    include/VelyraUtils/DevUtils/PrivateMemberGetter.hpp

    include/VelyraUtils/Types/Types.hpp
    include/VelyraUtils/Types/SymbolicTypes.hpp
)

set(velyra_utils_src
    src/Logging.cpp
    src/Types/SymbolicTypes.cpp
)

add_library(VelyraUtils STATIC ${velyra_utils_headers} ${velyra_utils_src})
target_include_directories(VelyraUtils PUBLIC include)
target_link_libraries(VelyraUtils PUBLIC spdlog)

set(velyra_utils_test_src
    test/TestLogging.cpp
    test/TestvelyraUtils.cpp
    test/TestVelyraEnum.cpp
)

if (BUILD_TESTING)
    fetch_gtest()

    add_executable(TestVelyraUtils ${velyra_utils_test_src})
    target_include_directories(TestVelyraUtils PUBLIC include)
    target_link_libraries(TestVelyraUtils PUBLIC VelyraUtils GTest::gtest GTest::gtest_main)
    add_test(NAME CTestVelyraUtils COMMAND ${PROOT} $<TARGET_FILE:TestVelyraUtils>)
    set_tests_properties(CTestVelyraUtils PROPERTIES
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif ()
