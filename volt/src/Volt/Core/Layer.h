#pragma once

#include <Volt/Core/Base.h>
#include <Volt/Events/Event.h>

namespace Volt
{
    class VOLT_API Layer
    {
    public:
        Layer(const std::string &name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event &event) {}

        inline const std::string &GetName() const { return debugName_; }

    protected:
        std::string debugName_;
    };
}