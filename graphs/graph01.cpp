
/* GRAPH implementation using adjacency list by making use of STL library list */   

#include<iostream>
#include<list>
#include<queue>

using namespace std;

//Templates are used for generic type of data. We define them at time of declaration of object of class
template<typename T>
class Graph{
        
        T V; //number of vertices in graph
        

        //list is standard tag library(STL) used for making program of data structure
        list<T> *adjList ; //adjacency list

        public:
        Graph(T edge){
                V = edge;
                adjList = new list<T>[V]; //intializing number of vertices at run time 
        }

        void addNodes(T x, T y, bool bidir = true){

            adjList[x].push_back(y);
            if (bidir == true)
                adjList[y].push_back(x);
        }

        void printAdjList(){
            for(int i = 0;i < V;i++){
                cout<<i<<"->";
                for(int node : adjList[i]){
                    cout<<node<<",";
                }
                cout<<endl;
            }
        }

        void bfs(int src){
            queue<int> q;
            bool *visited = new bool[V]{0};

            q.push(src);
            visited[src] = true;

              while(!q.empty()){
                int node = q.front();
                cout<<node<<"->";
                q.pop();

                for(int neighbours: adjList[node]){
                    if(!visited[neighbours])
                        q.push(neighbours);
                        visited[neighbours] = true;
                }
            }
        }

};
int main(void){
    Graph<int> obj(3);
    obj.addNodes(0, 1);
    obj.addNodes(0, 2);
    obj.addNodes(1, 2);
    //obj.printAdjList();

    obj.bfs(0);
    
    return 0;
    
}