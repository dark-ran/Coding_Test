#include<iostream>
#define fori(x,y) for(int x=0;x<y;x++)
using namespace std;

int arr[100][100];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	fori(i, N)
		fori(j, N)
			cin >> arr[i][j];

	fori(k, N)
		fori(i, N)
			fori(j, N)
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;

	fori(i, N) {
		fori(j, N)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}