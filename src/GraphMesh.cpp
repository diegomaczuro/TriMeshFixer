#include <GraphMesh.h> 

void addEdge(std::vector < std::pair<int, int> > adj[], int u,
                    int v, int wt)
{
    adj[u].push_back(std::make_pair(v, wt));
    adj[v].push_back(std::make_pair(u, wt));

    std::cout << "Start for graph2: " << std::endl;

}

void printTriGraph(std::vector<std::pair<int, int>> adj[], int V)
{
    int v, w;

    for (int u = 0; u < V; u++)
    {
        std::cout <<  "Node "<< u << " makes an edge with " << std::endl;
        for (auto current = adj[u].begin(); current!=adj[u].end(); current++)
        {
            v = current->first;
            w = current->second;
            std::cout << "\tNode"<< v << " width edge weight =" << w << std::endl;
        }
    }
}

int main()
{   
    int V = 5;
    std::vector<std::pair<int, int>> adj_list[V];
    addEdge(adj_list, 0, 1, 10);
    addEdge(adj_list, 0, 3, 10);

    //addEdge(adj_list, 1, 0, 10);
    addEdge(adj_list, 1, 2, 10);
    addEdge(adj_list, 1, 3, 20);
    //addEdge(adj_list, 2, 1, 10);
    addEdge(adj_list, 2, 3, 10);

    //addEdge(adj_list, 3, 0, 10);
    //addEdge(adj_list, 3, 1, 20);
    //addEdge(adj_list, 3, 2, 10);
    std::cout << "Start graph printing: " << std::endl;

    printTriGraph(adj_list, V);

    return 0;
}