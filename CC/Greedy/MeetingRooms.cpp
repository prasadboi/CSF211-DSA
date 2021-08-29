#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<vector<int>> A(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++){
        cin>>A[i][0]>>A[i][1];
    }


    //--------------------------------------------------------------------------------------------------------
    // solution via sorting
    vector<vector<int>> B = A;
    sort(A.begin(), A.end()); // sorted by start time
    sort(B.begin(), B.end(), cmp); // sorted by end time
    int rooms = 1;
    int max_rooms = 1;
    for(int i = 1, j = 0; i < A.size() && j < B.size();){
        if(A[i][0] >= B[j][1]){
            j++;
            rooms--;
        }
        else{
            i++;
            rooms++;
        }
        max_rooms = max(rooms, max_rooms);
    }
    cout<<max_rooms<<endl;

    //--------------------------------------------------------------------------------------------------------


    // solution via min heap
    sort(A.begin(),A.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int max_rooms_=1;
    pq.push(A[0][1]);
    for(int i=1;i<A.size();i++){
        if(pq.top()>A[i][0]) max_rooms_++;
        else pq.pop();
        pq.push(A[i][1]);
    }
    cout<<max_rooms_<<endl;

    return 0;
}
