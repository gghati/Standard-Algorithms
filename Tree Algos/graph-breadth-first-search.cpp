#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <fstream>
 
using namespace std;
 
int graph_size; // global size of the graph
 
class Graph
{
    int V;    
    list<int> *adj;    
public:
    Graph(int V); 
    void add_edge(int v, int w); // add edge to graph
    void print_bfs(int s);  // prints BFS
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::print_bfs(int s)
{
    // Initialize all verticies as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // using a queue for the BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // finding all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        graph_size--;
        queue.pop_front();
        
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 

int main(int argc, char *argv[])
{
    graph_size = 1;
    
    string mystring;
    int parent, adjacent;
    
    ifstream myfile (argv[1]);
    // file io
	if (myfile.is_open() != 1){
		cout << "Unable to open file\nPlease enter executable then file name\nEX: ./a.out graph1.txt\n"; 
		return -1;
	}
    
    // determine size of graph to be created before reading it in
    while(getline(myfile, mystring)){
        graph_size++;
    }
    Graph g(graph_size);
    
    // start from beginning of file again
    myfile.clear();
    myfile.seekg(0, ios::beg);
    
    // main work loop, reads in the parent node first and then all adjacent nodes
    while(getline(myfile, mystring)){
        istringstream iss (mystring);
        iss >> parent;
        while (iss >> adjacent){
        g.add_edge(parent, adjacent);
        }
    }
    
    cout << "BFS path: ";
    // Print the BFS regardless of disjoint
    g.print_bfs(1);
    
    // error if dijoint found
    if(graph_size > 1){
        cout << "\nERROR: GRAPH IS DISJOINTED";
    }
    else{
        cout <<"\nThe graph is NOT disjointed";
    }
    cout << endl;
    return 0;
}