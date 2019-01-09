#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

typedef int graph_t;
typedef int weight_t;

struct undirected_graph{

};

struct node{
    graph_t dado;
    weight_t weight;
    node(graph_t _d = 0, weight_t _w = 0): dado(_d), weight(_w){}

    bool operator<(const node& a) const {
        return this->weight < a.weight;
    }

    bool operator>(const node& a) const {
        return this->weight > a.weight;
    }
};

struct undirected_weighted_graph{
    map<graph_t, vector<node> > adj_list;

    //DFS / BFS UTILS
    deque<graph_t> path;
    map<graph_t, bool> visited;

    void addEdge(graph_t vertex1, graph_t vertex2, weight_t weight){
        adj_list[vertex1].pb(node(vertex2, weight));
        adj_list[vertex2].pb(node(vertex1, weight));
    }

    void popEdge(graph_t vertex1, graph_t vertex2){
        bool existe = false;
        int i = 0;
        for(auto edge: adj_list[vertex1]){
            if(edge.dado == vertex2){
                existe = true;
                adj_list[vertex1].erase(adj_list[vertex1].begin()+i);
            }
            i++;
        }
        if(existe){
            i=0;
            for(auto edge: adj_list[vertex2]){
                if(edge.dado == vertex1){
                    existe = true;
                    adj_list[vertex2].erase(adj_list[vertex2].begin()+i);
                }
                i++;
            }
        }
    }

    void popVertex(graph_t vertex){
        adj_list.erase(vertex);
        int i;
        for(auto& v: adj_list){
            i=0;
            for(auto& edge: v.second){
                if(edge.dado == vertex){
                    v.second.erase(v.second.begin()+i);
                    break;
                }
                i++;
            }
        }
    }

    void dfs(graph_t root){
        path.push_back(root);
        visited[root] = true;
        for(auto vizinho: adj_list[root])
            if(!visited[vizinho.dado]) dfs(vizinho.dado);
    }

    void bfs(graph_t root){
        queue<graph_t> aux;
        aux.push(root);
        visited[root] = true;
        graph_t atual;
        while(!aux.empty()){
            atual = aux.front();
            aux.pop();
            path.push_back(atual);
            for(auto vizinho: adj_list[atual]){
                if(!visited[vizinho.dado]){
                    aux.push(vizinho.dado);
                    visited[vizinho.dado] = true;
                }
            }
        }
    }

    void dijkstra(graph_t comeco, graph_t fim){
        priority_queue<node, vector<node>, std::greater<node> > queue;
        map<graph_t, weight_t> distances;
        map<graph_t, graph_t> previous;
        for(auto vert: adj_list){
            previous[vert.first];
            distances[vert.first] = (vert.first != comeco) ? numeric_limits<weight_t>::max() : 0;
            queue.push(node(vert.first, distances[vert.first]));
        }
        node menor;
        while(!queue.empty()){
            menor = queue.top();
            queue.pop();
            if(menor.dado != fim){
                for(auto vizinho: adj_list[menor.dado]){
                    int candidato = distances[menor.dado] + vizinho.weight;
                    if(candidato < distances[vizinho.dado]){
                        distances[vizinho.dado] = candidato;
                        previous[vizinho.dado] = menor.dado;
                        queue.push(node(vizinho.dado, candidato));
                    }
                }
            }
            else{ // ACHOU O MENOR CAMINHO
                while(previous[menor.dado] != graph_t()){
                    path.push_front(menor.dado);
                    menor.dado = previous[menor.dado];
                }
                path.push_front(menor.dado);
                break;
            }
        }
    }

    void clear(void){
        path.clear();
        visited.clear();
    }

};

#endif