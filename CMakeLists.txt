cmake_minimum_required(VERSION 3.22)
project(VelyraUtils DESCRIPTION "C++ utilities for Velyra projects")

include(VelyraBuildUtils/VelyraBuildUtils.cmake)

fetch_spdlog()
fetch_nlohmann_json()


set(velyra_utils_headers
    include/VelyraUtils/VelyraUtils.hpp
    include/VelyraUtils/Logging.hpp
    include/VelyraUtils/VelyraEnum.hpp
    include/VelyraUtils/ExportUtils.hpp
    include/VelyraUtils/TypeTraits.hpp
    include/VelyraUtils/Concepts.hpp
    include/VelyraUtils/PlatformDetection.hpp
    include/VelyraUtils/Math.hpp
    include/VelyraUtils/CpuFeatures.hpp

    include/VelyraUtils/DevUtils/MacroExpansion.hpp
    include/VelyraUtils/DevUtils/PrivateMemberGetter.hpp
    include/VelyraUtils/DevUtils/Conditions.hpp
    include/VelyraUtils/DevUtils/JsonSerializer.hpp

    include/VelyraUtils/Types/Types.hpp
    include/VelyraUtils/Types/SymbolicTypes.hpp

    include/VelyraUtils/Clock/Clock.hpp

    include/VelyraUtils/Threading/Worker.hpp
    include/VelyraUtils/Threading/ThreadPool.hpp

    include/VelyraUtils/Memory/View.hpp

    include/VelyraUtils/Conversions/Json.hpp
)

set(velyra_utils_src
    src/Logging.cpp
    src/CpuFeatures.cpp
    src/Types/SymbolicTypes.cpp

    src/Threading/Worker.cpp
    src/Threading/ThreadPool.cpp
)

add_library(VelyraUtils STATIC ${velyra_utils_headers} ${velyra_utils_src})
velyra_target_set_compile_flags(VelyraUtils)
target_include_directories(VelyraUtils PUBLIC include)
target_link_libraries(VelyraUtils PUBLIC spdlog nlohmann_json::nlohmann_json)

set(velyra_utils_test_src
    test/Utils.hpp

    test/TestLogging.cpp
    test/TestvelyraUtils.cpp
    test/TestVelyraEnum.cpp
    test/TestConcepts.cpp
    test/TestTypeTraits.cpp

    test/Types/TestSymbolicTypes.cpp

    # test/DevUtils/TestConditions.cpp
    test/DevUtils/TestJsonSerializer.cpp

    test/Threading/TestThreading.cpp

    test/Memory/TestView.cpp

    test/Conversions/TestToJson.cpp
    test/Conversions/TestFromJson.cpp
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
