#include<iostream>
#include<queue>
using namespace std;

int board[101];
int dist[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin>>N>>M;

    for(int i=1;i<=100;i++) board[i]=i;

    for(int i=0;i<N+M;i++){
        int x,y;
        cin>>x>>y;
        board[x]=y;
    }

    queue<int> q;
    q.push(1);
    dist[1]=0;

    while(!q.empty()){
        int cur=q.front(); q.pop();

        for(int i=1;i<=6;i++){
            int next=cur+i;
            if(next>100) continue;

            next = board[next];

            if(dist[next]) continue;

            dist[next]=dist[cur]+1;
            q.push(next);
        }
    }

    cout<<dist[100];
}