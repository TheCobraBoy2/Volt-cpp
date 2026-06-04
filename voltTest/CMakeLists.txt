add_executable(VoltTest src/main.cpp)

target_link_libraries(VoltTest PRIVATE Volt spdlog::spdlog)

target_precompile_headers(VoltTest REUSE_FROM Volt)