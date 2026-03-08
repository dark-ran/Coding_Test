#include<iostream>
using namespace std;
bool check[26]{ false };
int main() {
	string arr = "CAMBRIDGE";
	char a;
	for (char b : arr) 
		check[b - 'A'] = true;
	while ((a = getchar()) != '\n') {
		if (!check[a-'A'])
			cout << a;
	}
}