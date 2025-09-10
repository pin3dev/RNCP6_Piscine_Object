# pragma once
# include "../../ports/IRenderer.hpp"

class PngRenderer : public Graph::IRenderer {
    public:
        PngRenderer();
        virtual void draw(const Graph& g);
};