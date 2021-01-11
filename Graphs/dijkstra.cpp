#include<bits/stdc++.h>
#define MAX 100000
#define INF 999999999

using namespace std;
typedef pair<int,int> pii;

int distancia[MAX];
vector <pii> adj[MAX];

int n,m;

void dijkstra(int start){
    for(int i = 0; i <= n; i++){
        distancia[i] = INF;
    }
    distancia[start] = 0;

    priority_queue <pii, vector<pii>, greater<pii>> fila;
    fila.push(pii(distancia[start], start));  

    while(!fila.empty()){
        int peso = fila.top().first;
        int atual = fila.top().second;
        fila.pop();

        if(distancia[atual] < peso) continue;

        for(int i = 0; i < adj[atual].size(); i++){
            int dist = adj[atual][i].first;
            int davez = adj[atual][i].second;

            if(distancia[davez] > distancia[atual] + dist){
                distancia[davez] = distancia[atual] + dist;
                fila.push({distancia[davez], davez});
            }
        }
    }
}


int main(){
    int inicio,fim;

    cin >> n >> m; //número de vértices e arestas
    cin >> inicio >> fim;

    for(int i = 0; i < m; i++){
        int x,y,d;
        cin >> x >> y >> d;
        adj[x].push_back({d,y});
        adj[y].push_back({d,x});
    }

    dijkstra(inicio); 
	cout << distancia[fim] << endl; 

    return 0;
}
