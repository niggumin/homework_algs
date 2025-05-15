struct ArcGraph : public IGraph {
private:
    std::vector<std::pair<int, int>> arcs;
    int vertexCount;

public:
    ArcGraph(int size)
    : vertexCount(size)
    {
    }

    ArcGraph(const IGraph &graph)
    {
        std::vector<int> tmp(graph.VerticesCount());
        vertexCount = graph.VerticesCount();
        for (int i = 0; i < graph.VerticesCount(); ++i)
        {
            tmp = graph.GetNextVertices(i);
            for (auto x : tmp) arcs.push_back({i, x});
        }
    }

    ~ArcGraph()
    {
    }

    void AddEdge(int from, int to) override
    {
        assert(0 <= from && from < vertexCount);
        assert(0 <= to && to < vertexCount);
        arcs.push_back({from, to});
    }

    int VerticesCount() const override
    {
        return vertexCount;
    }

    std::vector<int> GetNextVertices(int vertex) const override
    {
        assert(0 <= vertex && vertex < vertexCount);
        std::vector<int> res;
        for (const auto &[from, to] : arcs)
            if (from == vertex) res.push_back(to);
    
        return res;
    }

    std::vector<int> GetPrevVertices(int vertex) const override
    {
        assert(0 <= vertex && vertex < vertexCount);
        std::vector<int> res;
        for (const auto &[from, to] : arcs)
            if (to == vertex) res.push_back(from);
            
        return res;
    }
};
