#include <iostream>
#include <String>
#include <bits/stdc++.h>

using namespace std;

void print_mat(vector<vector<int>> &A)
{
    for(int i = 0; i  < A.size(); i++)
    {
        for(int j = 0; j < A[i].size(); j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print_array(vector<int> A)
{
    for(auto i : A)
        cout<<i<<" ";
    cout<<endl;
}


// THIS PROBLEM IS OF TYPE MERGING INTERVALS
int rod_cutting(int len, vector<int> &cuts)
{
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(len);
    sort(cuts.begin(), cuts.end());
        
    int N = cuts.size();
    int dp[N][N];
        
    for(int l=0; l<N; l++) 
    {
        for(int i=0; i<N-l; i++) 
        {
            // NOTE : for a particular subarray, i is the starting index and j is the ending index.
            int j = i+l;
            if(j<=i+1) dp[i][j] = 0;
            else 
            {
                int x = INT_MAX;
                for(int k=i+1; k<j; k++) 
                    x = min(x, dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]));
                    
                if(x==INT_MAX) x = 0;
                    dp[i][j] = x;
                }
            }
        }
        
        return dp[0][N-1];
}



int main(int argc, char const *argv[])
{
    int A = 6;
    vector<int> B = {1, 2, 5};
    cout<<rod_cutting(A, B);
    //vector<int> ans = 
    //for(auto i : ans)
    //    cout<<i<<" ";
    return 0;
}
