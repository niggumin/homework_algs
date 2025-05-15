struct MatrixGraph: public IGraph{
private:
    std::vector<std::vector<bool>> matrix;
public:
    MatrixGraph(int size)
    : matrix(size)
    {
        for (auto& row : matrix) row.resize(size);
    }
    
    MatrixGraph(const IGraph &graph)
    {
        matrix.resize(graph.VerticesCount());
        for (auto& row : matrix) row.resize(graph.VerticesCount());
        
        std::vector<int> tmp;
        for (int i = 0; i < graph.VerticesCount(); ++i)
        {
            tmp = graph.GetNextVertices(i);
            for (int x : tmp) matrix[i][x] = true;
        }
        
    }
    
    ~MatrixGraph()
    {
    }
    
    void AddEdge(int from, int to) override
    {
        assert(0 <= from && from < matrix.size());
        assert(0 <= to && to < matrix.size());
        matrix[from][to] = true;
    }
    
    int VerticesCount() const override
    {
        return (int) matrix.size();
    }
    
    std::vector<int> GetNextVertices(int vertex) const override
    {
        assert(0 <= vertex && vertex < matrix.size());
        std::vector<int> res;
        for (int i = 0; i < matrix.size(); ++i)
            if (matrix[vertex][i]) res.push_back(i);
        
        return res;
    }
    
    std::vector<int> GetPrevVertices(int vertex) const override
    {
        assert(0 <= vertex && vertex < matrix.size());
        std::vector<int> res;
        for (int i = 0; i < matrix.size(); ++i)
            if (matrix[i][vertex]) res.push_back(i);
        
        return res;
    }
};

