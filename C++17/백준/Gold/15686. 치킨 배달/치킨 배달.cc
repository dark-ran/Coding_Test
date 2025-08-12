#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
#define abs(x) ((x)<0?-(x):(x))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

int arr[50][50];
int dist[100][13];
bool selected[13];
int N, M, ans = 19876543;
vector<pii>house;
vector<pii>chiken;
int house_size, chiken_size;

int get_dist() {
	int sum = 0;
	for (int i = 0;i < house_size;i++) {
		int MIN = 1987654;
		for (int j = 0;j < chiken_size;j++) {
			if (selected[j])
				MIN = min(MIN, dist[i][j]);
		}
		sum += MIN;
	}
	return sum;
}

void choose(int idx, int cnt) {
	if (cnt == M) {
		int cal = get_dist();
		ans = min(ans, cal);
		return;
	}
	if (idx >= chiken_size) return;

	selected[idx] = true;
	choose(idx + 1, cnt + 1);
	selected[idx] = false;
	choose(idx + 1, cnt);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back({ i,j });
			else if (arr[i][j] == 2) chiken.push_back({ i,j });
		}
	house_size = house.size();
	chiken_size = chiken.size();

	for (int i = 0;i < house_size;i++)
		for (int j = 0;j < chiken_size;j++)
			dist[i][j] = abs(house[i].first - chiken[j].first) + abs(house[i].second - chiken[j].second);

	choose(0, 0);
	cout << ans;
}