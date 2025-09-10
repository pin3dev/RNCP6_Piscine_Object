# pragma once
# include "../domain/inc/Graph.hpp"

class Graph::IEqualityPolicy {
    public:
        virtual ~IEqualityPolicy() {}
        virtual bool equals(const Vector2& a, const Vector2& b) const = 0;
};