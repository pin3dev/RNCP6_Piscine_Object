# pragma once
# include "../../ports/IRenderer.hpp"

class AsciiRenderer : public Graph::IRenderer {
    public:
        AsciiRenderer();
        virtual void draw(const Graph& g);
};