#include <iostream>
#include <vector>

class Vertex
{
public:
    int data;
    std::vector<Vertex *> adjacentVertices;

    Vertex(int value) : data(value) {}
};

class Graph
{
public:
    Graph() {}

    //Untuk tambah node
    void addVertex(int value)
    {
        vertices.push_back(Vertex(value));
    }

    //Untuk tambah koneksi
    void addEdge(int from, int to)
    {
        Vertex *source = findVertex(from);
        Vertex *destination = findVertex(to);

        if (source != nullptr && destination != nullptr)
        {
            source->adjacentVertices.push_back(destination);
        }
    }

    //Untuk tampilin nodenya
    void printGraph()
    {
        for (const Vertex &vertex : vertices)
        {
            std::cout << "Vertex " << vertex.data << " is connected to: ";
            for (const Vertex *neighbor : vertex.adjacentVertices)
            {
                std::cout << neighbor->data << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    //Buat nyari node
    Vertex *findVertex(int value)
    {
        for (Vertex &vertex : vertices)
        {
            if (vertex.data == value)
            {
                return &vertex;
            }
        }
        return nullptr;
    }

    std::vector<Vertex> vertices;
};

int main()
{
    Graph graph;

    //Tambah nodenya
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);

    //Buat koneksinya
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    //Tampilin struktur graphnya
    graph.printGraph();

    return 0;
}
