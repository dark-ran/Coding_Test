#include <iostream>
#include <string>

using namespace std;

int main() {
	string str,reverse;
	while (1) {
		getline(cin, str);;
		if (str == "***") break;
		reverse = "";
		for (int i = str.length() - 1; i >= 0; i--) {
			reverse += str[i];
		}
		cout << reverse<<endl;
	}
}