# pragma once
# include "../domain/Graph.hpp"
# include "ISource.hpp"

class Graph::IPointSource : public Graph::ISource {
    public:
        virtual ~IPointSource() {}
        virtual void feedPoints(Graph& g) = 0;
};