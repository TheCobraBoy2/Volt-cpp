add_executable(VoltTest src/main.cpp)

target_link_libraries(VoltTest PRIVATE Volt spdlog::spdlog)

target_precompile_headers(VoltTest REUSE_FROM Volt)
target_compile_definitions(VoltTest PRIVATE Volt_EXPORTS)

add_custom_command(TARGET VoltTest POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Volt>
        $<TARGET_FILE_DIR:VoltTest>
)