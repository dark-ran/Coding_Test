#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;		// 테스트 케이스 개수 입력 받기

    for (int i = 0; i < t; i++) 
    {
        int a, b, result = 1;		// 결과값을 1로 초기화 시켜줘야 값을 매번 저장해가며 계산 가능
        cin >> a >> b;

        for (int j = 0; j < b; j++) 
        {
            result = (result * a) % 10;		// 거듭제곱한 결과값 저장
        }

        if (result == 0) 
        {
            cout << 10 << endl;		// 10의 거듭제곱의 경우
        }
        else 
        {
            cout << result << endl;
        }
    }
    return 0;
}