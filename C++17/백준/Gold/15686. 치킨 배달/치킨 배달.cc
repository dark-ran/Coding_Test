#include<iostream>
#include<vector>
#define pii pair<int,int>
#define abs(x) ((x)<0?-(x):(x))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

int arr[50][50];
bool selected[13];
int N, M, ans = 19876543;
vector<pii>house;
vector<pii>chiken;
int house_size, chiken_size;

int get_dist() {
	int sum = 0;
	for (int i = 0;i < house_size;i++) {
		int x = house[i].first;
		int y = house[i].second;
		int dist = 198765;
		for (int j = 0;j < chiken_size;j++) {
			if (!selected[j]) continue;
			int num = abs(x - chiken[j].first) + abs(y - chiken[j].second);
			dist = min(dist, num);
		}
		sum += dist;
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
	choose(0, 0);
	cout << ans;
}