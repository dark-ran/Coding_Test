#include<iostream>
#include<algorithm>

using namespace std;

typedef struct {
	int country;
	int number;
	int score;
}Contest;

bool com(Contest& a, Contest& b) {
	return a.score > b.score;
}

int main() {
	int n;
	cin >> n;
	Contest* con = new Contest[n];
	for (int i = 0; i < n; i++) {
		cin >> con[i].country >> con[i].number >> con[i].score;
	}
	sort(con, con + n, com);
	cout << con[0].country << " " << con[0].number << "\n";
	cout << con[1].country << " " << con[1].number << "\n";
	int select = 0;
	if (con[0].country == con[1].country)
		select = con[0].country;
	for (int i = 2; i < n; i++) {
		if (select != con[i].country) {
			cout << con[i].country << " " << con[i].number << "\n";
			break;
		}
	}
}