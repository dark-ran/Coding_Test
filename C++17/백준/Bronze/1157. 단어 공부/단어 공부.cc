#include <iostream>
#include <algorithm>

using namespace std;


int main() {

	int cnt[26] = { 0, };
	int max = -1; // max: 알파벳 사용 개수의 최대값
	char res; // 사용 개수가 max인 알파벳

	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; // 소문자는 대문자로 처리

		if (++cnt[s[i] - 'A'] > max) { 
			max = cnt[s[i] - 'A'];
			res = s[i];
		}
	}

	int check = 0; // 가장 많이 사용된 알파벳이 여러 개인 지 체크

	for (int i = 0; i < 26; i++) {
		if (max == cnt[i]) check++;
	}

	if (check == 1) cout << res;
	else cout << "?";

	return 0;
}