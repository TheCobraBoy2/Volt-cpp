set(VOLT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(VOLT_SRC ${VOLT_ROOT}/src)
set(VOLT_ACT ${VOLT_SRC}/Volt)
set(VOLT_INTERNAL ${VOLT_ROOT}/internal)

add_library(Volt SHARED
    ${VOLT_SRC}/Volt.h
    ${VOLT_ACT}/Application.cpp
    ${VOLT_ACT}/Application.h
    ${VOLT_ACT}/EntryPoint.h
    src/Volt/Core/Exit.h
    src/Volt/Events/Event.h
    src/Volt/Events/ApplicationEvent.h
    src/Volt/Core/PlatformDetection.h
    src/Volt/Core/KeyCodes.h
    src/Volt/Core/ExitCodes.h
    src/Volt/Events/MouseEvent.h
    src/Volt/Window.h
    src/Platform/Windows/WindowsWindow.h
    src/Platform/Windows/WindowsWindow.cpp
    src/Volt/Core/Log.cpp
    src/Volt/Core/Log.h
    src/Volt/Core/Layer.h
    src/Volt/Core/Layer.cpp
    src/Volt/Core/LayerStack.h
    src/Volt/Core/LayerStack.cpp
    src/Volt/ImGui/ImGuiLayer.cpp
    src/Volt/Core/Input.h
    src/Volt/Util/Types/Vector2.h
    src/Platform/Windows/WindowsInput.cpp
    src/Platform/Windows/WindowsInput.h
)

target_include_directories(Volt
    PUBLIC
    ${VOLT_SRC}
    PRIVATE
    ${VOLT_INTERNAL}
)

target_link_libraries(Volt PUBLIC spdlog::spdlog glad glm glfw imgui)
target_precompile_headers(Volt PRIVATE
    "${VOLT_SRC}/vtpch.h"
)

target_compile_definitions(Volt PRIVATE VOLT_BUILD_DLL)