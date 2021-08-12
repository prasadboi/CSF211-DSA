#include <bits/stdc++.h>
using namespace std;

void getCost_perArr(vector<int> &arr)
{
    int n = arr.size();
    int cost = 0;
    int start = 0, end = n-1;
    // create min heap
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 1; i < n; i++)
    {
        cout<<"i = "<<i<<" start : "<<start<<endl;
        if(arr[i] > arr[i-1]){}
        else
        {
            end = i-1;
            int len = end - start + 1;
            cout<<"end : "<<end<<"len : "<<len<<endl;
            pq.push(len);
            cost += min(len, n - len - start);
            start = i;
            cout<<"cost: "<<cost<<endl;
        }
    }
    if(end < n-1) {end = n-1;
    cout<<"end : "<<end<<"len : "<<end-start+1<<"cost : "<<cost<<endl;
    pq.push(end - start + 1);}

    while(pq.size() > 1){
        int x, y;
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        cost += x + y;
        pq.push(x + y);
        cout<<cost<<endl;
    }
    cout << cost << endl;    
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 5, 4, 3};
    getCost_perArr(A);
    return 0;
}
