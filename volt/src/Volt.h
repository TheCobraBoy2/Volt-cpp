#pragma once

#include "Volt/Application.h"
#include "Volt/Core/Layer.h"
#include "Volt/Core/Log.h"

#ifdef VOLT_GIVEMEITALL
#define VOLT_IMGUI
#define VOLT_CODESANDBINDS
#define VOLT_SUPER_USER
#endif

#ifdef VOLT_IMGUI
#include "Volt/ImGui/ImGuiLayer.h"
#endif
#ifdef VOLT_CODESANDBINDS
#include "Volt/Core/Input.h"
#include "Volt/Core/KeyCodes.h"
#include "Volt/Core/MouseCodes.h"
#endif
#ifdef VOLT_SUPER_USER
#include "Volt/Core/Exit.h"
#endif

#include "Volt/EntryPoint.h"