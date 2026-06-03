cmake_minimum_required(VERSION 3.11)
project(VoltSolution)

# Fetch spdlog from GitHub
include(FetchContent)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/imgui)

add_compile_definitions()

add_subdirectory(volt)
add_subdirectory(voltTest)