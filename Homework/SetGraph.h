struct SetGraph: public IGraph
{
private:
    std::vector<std::multiset<int>> sets;
public:
    SetGraph(int size)
    : sets(size)
    {
    }
    
    SetGraph(const IGraph &graph)
    {
        sets.resize(graph.VerticesCount());
        std::vector<int> tmp;
        for (int i = 0; i < graph.VerticesCount(); ++i)
        {
            tmp = graph.GetNextVertices(i);
            for (auto x : tmp)
                sets[i].insert(x);
        }
    }
    
    ~SetGraph()
    {
    }
    
    void AddEdge(int from, int to) override
    {
        assert(0 <= from && from < sets.size());
        assert(0 <= to && to < sets.size());
        sets[from].insert(to);
    }
    
    int VerticesCount() const override
    {
        return (int) sets.size();
    }
    
    std::vector<int> GetNextVertices(int vertex) const override
    {
        assert(0 <= vertex && vertex < sets.size());
        
        std::vector<int> res(sets[vertex].begin(), sets[vertex].end());
        return res;
    }
    
    std::vector<int> GetPrevVertices(int vertex) const override
    {
        assert(0 <= vertex && vertex < sets.size());
        std::vector<int> prevVertices;
        
        for (int from = 0; from < sets.size(); ++from)
        {
            for (int to: sets[from])
            {
                if (to == vertex)
                    prevVertices.push_back(from);
            }
        }
        return prevVertices;
    }
    
};
