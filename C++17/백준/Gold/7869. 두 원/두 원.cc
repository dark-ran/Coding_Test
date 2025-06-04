#include<iostream>
#include<math.h>
#define d double

using namespace std;

const d pi = 3.14159265;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	d x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	d dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	cout << fixed;
	cout.precision(3);
	if (dis > r1 + r2) {
		cout << 0.000;
		return 0;
	}
	else if (dis + r1 <= r2) {
		cout << (r1 * r1 * pi);
		return 0;
	}
	else if (dis + r2 <= r1) {
		cout << (r2 * r2 * pi);
		return 0;
	}
	else {
		d t1 = acos((r1 * r1 + dis * dis - r2 * r2) / (2 * r1 * dis));
		d t2 = acos((r2 * r2 + dis * dis - r1 * r1) / (2 * r2 * dis));
		d s1 = (r1 * r1 * t1) - (r1 * r1 * sin(2 * t1) / 2);
		d s2 = (r2 * r2 * t2) - (r2 * r2 * sin(2 * t2) / 2);
		cout << s1 + s2;
		return 0;
	}
}