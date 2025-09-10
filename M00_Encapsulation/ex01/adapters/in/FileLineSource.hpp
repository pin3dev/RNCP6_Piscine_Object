# pragma once
# include "../../ports/ILineSource.hpp"

class FileLineSource : public Graph::ILineSource {
    public:
        explicit FileLineSource(const std::string& path);
        virtual void feedLines(Graph& g);
};