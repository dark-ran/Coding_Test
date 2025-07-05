#include <iostream>
#define MAX 100001
using namespace std;

int n;
long long arr[MAX];
long long psum[MAX];
long long sum=0;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i==0){
            psum[i]=arr[i];
        }
        else{
            psum[i]=psum[i-1]+arr[i];
        }
    }
        for(int i=0; i<n-1; i++){
        sum+=arr[i]*(psum[n-1]-psum[i]);
    }
    cout<<sum;
}