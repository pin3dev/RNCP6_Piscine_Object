# pragma once
# include "../../ports/IPointSource.hpp"

class FilePointSource : public Graph::IPointSource {
    public:
        explicit FilePointSource(const std::string& path);
        virtual void feedPoints(Graph& g);
};