# pragma once
# include "../domain/Graph.hpp"
# include "ISource.hpp"

class Graph::ILineSource : public Graph::ISource {
    public:
        virtual ~ILineSource() {}
        virtual void feedLines(Graph& g) = 0;
};