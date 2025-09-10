# pragma once
# include "../../utils/_utils.hpp"
# include "Vector2.hpp"

/**
 * @class Graph
 * @brief A simple graph class that manages a collection of 2D points (Vector2)
*/
class Graph {
    private:
        // Attributes
        Vector2             _size;
        std::list<Vector2>  _points;
    public:
        // Constructor
        explicit Graph(Vector2 size);
        // Destructor
        ~Graph();

        class ISource;
        // Output Ports
        class IEqualityPolicy;
        // Input Ports
        class IPointSource;
        class ILineSource;
        // Pugglable Policies
        class IRenderer;

        // APIs Methods
        void addPoint(const Vector2& point); //setter
        void addLine(const Vector2& start, const Vector2& end); //setter
        void render(IRenderer* renderer) const; // output
        const std::list<Vector2>& getPoints() const; //getter
        const Vector2 &getSize() const; //getter
        void setModelEquality(IEqualityPolicy* policy); //setter

        void ingest(IPointSource& in);
        void ingest(ILineSource& in);
    };