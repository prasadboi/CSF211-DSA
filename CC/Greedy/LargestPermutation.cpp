#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
     
    int n; 
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];

    // map to store indexes of every value in A
    unordered_map<int, int> m;
    for(int i = 0; i < n; ++i){
        m[A[i]] = i;
    }
     

    vector<int> A_sorted(n);
    for(int i = 0; i < n; ++i) A_sorted[i] = A[i];
    sort(A.begin(), A.end());
     

    int B;
    cin>>B;
    for(int i = 0; i < B; ++i){
        cout<<"swapping values : "<<i<<" "<<m[A_sorted[n - 1 - i]]<<endl;
        swap(A[i], A[m[A_sorted[n - 1 - i]]]);
    }
     

    for(int i = 0; i < n; i++) cout<<A[i]<<" ";
    return 0;
}
