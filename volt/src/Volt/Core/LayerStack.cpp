#include <vtpch.h>
#include "LayerStack.h"

namespace Volt
{
    LayerStack::LayerStack()
    {
        layerInsert_ = layers_.begin();
    }

    LayerStack::~LayerStack()
    {
        for (Layer *layer : layers_)
            delete layer;
    }

    void LayerStack::PushLayer(Layer *layer)
    {
        layerInsert_ = layers_.emplace(layerInsert_, layer);
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        layers_.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        auto it = std::find(layers_.begin(), layers_.end(), layer);
        if (it != layers_.end())
        {
            layers_.erase(it);
            layerInsert_--;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay)
    {
        auto it = std::find(layers_.begin(), layers_.end(), overlay);
        if (it != layers_.end())
            layers_.erase(it);
    }
}