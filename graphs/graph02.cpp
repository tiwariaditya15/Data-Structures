/* GRAPH implementation using adjacency list by making use of maps */

#include<iostream>
#include<map>
#include<cstring>
#include<list>

using namespace std;

template<typename T>
class Graph{

    map<T, list<T>> adjList;
    public:

    Graph(){}

    void addEdge(T u, T v, bool bidir = true){
        adjList[u].push_back(v);
        if (bidir == true)
            adjList[v].push_back(u);
    }

    void prinAdjList(){
        for(auto row : adjList){
            T key = row.first;
            cout<<key<<"->";

            for(T element : row.second){
                cout<<element<<",";
            }
            cout<<endl;
        }
    }

};










int main(void){
    Graph<string> object;

    object.addEdge("Mumbai", "Jaipur");
    object.addEdge("Jaipur", "Delhi");
    object.addEdge("Delhi", "Lucknow");
    object.addEdge("Mumbai", "Banglore");

    object.prinAdjList();   
    return 0;
}