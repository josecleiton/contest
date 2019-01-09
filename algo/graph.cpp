#include "graph.hpp"
#define FOR(x) for(int i=0;i<x;i++)
using namespace std;

int main(){
    undirected_weighted_graph uwg;
    int narestas;
    cin >> narestas;
    int v1, v2, w;
    FOR(narestas){
        cin>>v1>>v2>>w;
        uwg.addEdge(v1, v2, w);
    }

    cout << "PARA ACOMPANHAR O GRAFO VEJA A IMAGEM GRAPH.PNG" << endl << endl;

    cout << "BFS TEST: ";
    uwg.bfs(2);
    char h = 'a';
    for(auto v: uwg.path) cout << (char)(h+v) << " -> ";
    cout << "/" << endl;


    cout << endl << "DIJKSTRA TEST: ";
    uwg.clear();
    uwg.dijkstra(4, 0);
    for(auto v: uwg.path) cout << (char)(h+v) << " -> ";
    cout << "/" << endl;

    return 0;
}