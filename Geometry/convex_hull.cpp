#include<bits/stdc++.h>
using namespace std;

struct pt{
    long long x,y;
    pt operator-(pt p){
        return {x - p.x, y - p.y};
    }
    pt operator<(pt p){
        if(x == p.x) return {y < p.y};
        return {x < p.x};
    }
};

long long cross(pt a,pt b){
    return a.x * b.y - a.y * b.x;
}

bool cw(pt a, pt b, pt c){
    return cross(b-a,c-a) < 0;
}

bool ccw(pt a, pt b, pt c){
    return cross(b-a,c-a) > 0;
}

int main(){
    int n;

    while(cin >> n){
        vector<pt> pontos;

        while(n--){
            int x,y;
            cin >> x >> y;
            pontos.push_back({x,y});
        }

        sort(pontos.begin(),pontos.end());

        vector<pt> up;
        vector<pt> down;

        for(int i = 0; i < pontos.size(); i++){
            while(up.size() >= 2 and !cw(up[up.size()-2], up[up.size()-1], pontos[i])) up.pop_back();
            while(down.size() >= 2 and !ccw(down[down.size()-1], down[down.size()-2], pontos[i])) down.pop_back();
            up.push_back(pontos[i]);
            down.push_back(pontos[i]);
        }

        vector <pt> ans;

        for (int i = 0; i < (int)up.size(); i++){
            ans.push_back(up[i]);
        }
        for (int i = down.size() - 2; i > 0; i--){
            ans.push_back(down[i]);
        }

    }

    return 0;
}
