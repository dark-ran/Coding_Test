#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

struct s {
	int id, w, sale_id;
};
struct calculate_cmp {
	bool operator()(const s& a, const s& b) {
		if (a.w == b.w) return a.sale_id > b.sale_id; //기다리는 시간이 같으면 번호가 작은 계산대로
		return a.w > b.w;
	}
};
bool cmp(const s& a, const s& b) {
	if (a.w == b.w) return a.sale_id > b.sale_id;
	return a.w < b.w;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int N, K, id, w;
	cin >> N >> K;
	priority_queue<s, vector<s>, calculate_cmp>pq;
	vector<s>v;
	if (N <= K) {
		for (int i = 1;i <= N;i++) {
			cin >> id >> w;
			v.push_back({ id,w,i });
		}
	}
	else {
		for (int i = 0;i < K;i++) {
			cin >> id >> w;
			pq.push({ id,w,i });
		}
		for (int i = K;i < N;i++) {
			cin >> id >> w;
			pq.push({ id,pq.top().w + w,pq.top().sale_id });
			v.push_back(pq.top());
			pq.pop();
		}
		for (int i = 0;i < K;i++) {
			v.push_back(pq.top());
			pq.pop();
		}
	}

	sort(v.begin(), v.end(), cmp);
	ll sum = 0, cnt = 1;
	for (auto a : v) {
		sum += cnt * (ll)a.id;
		cnt++;
	}
	cout << sum;
}