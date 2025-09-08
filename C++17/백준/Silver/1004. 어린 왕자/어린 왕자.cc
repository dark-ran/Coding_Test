#include <iostream>
#include <cmath>
using namespace std;

int x, y, x2, y2;

bool check(int cx, int cy, int r)
{
	if (pow(cx - x, 2) + pow(cy - y, 2) <= r * r && pow(cx - x2, 2) + pow(cy - y2, 2) <= r * r) return 0;
	else if (pow(cx - x, 2) + pow(cy - y, 2) <= r * r) return 1;
	else if (pow(cx - x2, 2) + pow(cy - y2, 2) <= r * r) return 1;
	return 0;
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> x >> y >> x2 >> y2;

		int n;
		cin >> n;

		int answer = 0;
		for (int i = 0; i < n; i++)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;
			answer += check(cx, cy, r);
		}

		cout << answer << endl;
	}

	return 0;
}