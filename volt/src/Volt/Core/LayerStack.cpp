#include <vtpch.h>
#include "Log.h"
#include "LayerStack.h"

namespace Volt
{
    LayerStack::LayerStack()
    {
    }

    LayerStack::~LayerStack()
    {
        for (Layer *layer : layers_)
            delete layer;
    }

    void LayerStack::PushLayer(Layer *layer)
    {
        VT_CORE_TRACE("Pushing layer: {0}", layer->GetName());
        layers_.emplace(begin() + layerInsertIndex_, layer);
        layerInsertIndex_++;
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        VT_CORE_TRACE("Pushing overlay: {0}", overlay->GetName());
        layers_.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        VT_CORE_TRACE("Popping layer: {0}", layer->GetName());
        auto it = std::find(layers_.begin(), layers_.end(), layer);
        if (it != layers_.end())
        {
            layers_.erase(it);
            layerInsertIndex_--;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay)
    {
        VT_CORE_TRACE("Popping overlay: {0}", overlay->GetName());
        auto it = std::find(layers_.begin(), layers_.end(), overlay);
        if (it != layers_.end())
            layers_.erase(it);
    }
}