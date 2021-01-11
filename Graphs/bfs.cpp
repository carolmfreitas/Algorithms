#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

vector<int> adj[MAX];
int vis[MAX];
int dist[MAX];

void bfs(int v){
    queue <int> fila;
    fila.push(v);

    vis[v] = 1;
    dist[v] = 1;

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for(int i = 0; i < (int) adj[atual].size(); i++){

            if(vis[adj[atual][i]] == 0){
                vis[adj[atual][i]] = 1;
                dist[adj[atual][i]] = dist[atual] + 1;
                fila.push(adj[atual][i]);
            }
        }
    }
}