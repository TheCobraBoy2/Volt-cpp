#pragma once

#include <Volt/Core/Base.h>
#include "Layer.h"

#include <vtpch.h>

typedef std::vector<Volt::Layer *> LayerVec;
typedef LayerVec::iterator LayerIter;

namespace Volt
{
    class LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        void PopLayer(Layer *layer);
        void PopOverlay(Layer *overlay);

        LayerIter begin() { return layers_.begin(); }
        LayerIter end() { return layers_.end(); }

    private:
        LayerVec layers_;
        unsigned int layerInsertIndex_ = 0;
    };
}