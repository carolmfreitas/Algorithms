#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int dist[MAX][MAX];
int n;

int main(){
    for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}