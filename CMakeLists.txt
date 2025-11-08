cmake_minimum_required(VERSION 3.24)
project(VelyraUtils DESCRIPTION "C++ utilities for Velyra projects")

include(VelyraBuildUtils/VelyraBuildUtils.cmake)

fetch_spdlog()

set(velyra_utils_src)

