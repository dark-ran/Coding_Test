#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    long long count = 0;
    vector<int> stack;
    vector<int> freq(n, 1); // freq[i]는 arr[i]가 스택에 들어올 때, 같은 값이 몇 개 있었는지 저장

    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && v[stack.back()] <= v[i]) { //마지막 값이 현재보다 작으면
            if (v[stack.back()] == v[i]) {
                freq[i] += freq[stack.back()];
            }
            count += freq[stack.back()];
            stack.pop_back();
        }
        if (!stack.empty()) { //마지막 값이 현재 값보다 클 때
            count++;
        }
        stack.push_back(i);
    }

    printf("%lld\n", count);
}
