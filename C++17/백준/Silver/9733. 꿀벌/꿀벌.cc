#include<iostream>
using namespace std;
int arr[8]{ 0 };
int main() {
	string str;
	while (true) {
		cin >> str;
		if (cin.eof()) break;
		if (str == "Re")
			arr[0]++;
		else if (str == "Pt")
			arr[1]++;
		else if (str == "Cc")
			arr[2]++;
		else if (str == "Ea")
			arr[3]++;
		else if (str == "Tb")
			arr[4]++;
		else if (str == "Cm")
			arr[5]++;
		else if (str == "Ex")
			arr[6]++;
		arr[7]++;
	}
	cout << fixed;
	cout.precision(2);
	cout << "Re " << arr[0] << " " << (double)arr[0] / arr[7]<<"\n";
	cout << "Pt " << arr[1] << " " << (double)arr[1] / arr[7] << "\n";
	cout << "Cc " << arr[2] << " " << (double)arr[2] / arr[7] << "\n";
	cout << "Ea " << arr[3] << " " << (double)arr[3] / arr[7] << "\n";
	cout << "Tb " << arr[4] << " " << (double)arr[4] / arr[7] << "\n";
	cout << "Cm " << arr[5] << " " << (double)arr[5] / arr[7] << "\n";
	cout << "Ex " << arr[6] << " " << (double)arr[6] / arr[7] << "\n";
	cout << "Total " << arr[7] << " " << (double)arr[7] / arr[7] << "\n";
}