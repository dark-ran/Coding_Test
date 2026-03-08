#include <iostream>
#include <vector> 
#include <queue> 
#include <limits.h>
#define MAX 1001 
#define INF INT_MAX
using namespace std ;

int N, E ;
int V1, V2 ; 
vector<pair<int, int> > v[MAX]; 
int DIST[MAX] ; 

int dijkstra(int start, int end) { 
    for (int i = 1; i <= N ; i++) DIST[i] = INF ; 

    priority_queue<pair<int, int> > pq ; 

    pq.push(make_pair(-0, start)) ; 
    DIST[start] = 0 ;

    while(!pq.empty()) { 
        int curr_w = -pq.top().first ; 
        int curr_v = pq.top().second ; 

        pq.pop() ; 

        for (int i = 0 ; i < v[curr_v].size(); i++) { 
            int next_v = v[curr_v][i].first ;  
            int next_w = v[curr_v][i].second ; 

            if ( DIST[next_v] > curr_w + next_w ) { 
                DIST[next_v] = curr_w + next_w ; 
                pq.push(make_pair(-DIST[next_v], next_v)) ; 
            }
        }
    }
    return DIST[end] ; 
}

void Input() { 
    cin >> N >> E; 

    int a, b, c; 
    for (int i = 0 ; i < E; i++) {
        cin >> a >> b >> c;  

        v[a].push_back(make_pair(b, c)) ; 
        v[b].push_back(make_pair(a, c)) ;
    }
    cin >> V1 >> V2; 

}

int main(void) {    
    ios::sync_with_stdio(false); 
    cin.tie(0) ; 

    Input() ; 
    int result = INF ; 

    int v1_to_v2 = dijkstra(V1, V2) ; // v1 -> v2 , v2 -> v1 
    dijkstra(1, V1); 
    int source_to_v1 = DIST[V1] ;  // 1 -> v1 
    int source_to_v2 = DIST[V2] ;  // 1 -> v2 

    int v1_to_dest = dijkstra(V1, N) ; 
    int v2_to_dest = dijkstra(V2, N) ; 

    
    if ( v1_to_v2 == INF || source_to_v1 == INF || source_to_v2 == INF ) { 
        cout << -1 << '\n'; 
        return 0 ; 
    } else { 
        if ( v2_to_dest == INF ) { 
            cout << -1 << '\n'; 
            return 0 ; 
        } else { 
            // 1 -> v1 -> v2 -> N 
            result = min(result, source_to_v1 + v1_to_v2 + v2_to_dest ) ; 
        }

        if ( v1_to_dest != INF ) { 
            // 1 -> v2 -> v1 -> N 
            // v1_to_v2 == v2_to_v1
            result = min(result, source_to_v2 + v1_to_v2 + v1_to_dest) ; 
        }
    }

    cout << result << '\n';
    return 0; 
}