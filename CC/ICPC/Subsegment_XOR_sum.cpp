#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int XorSum(vector<int> A, int n)
{
    int sum = 0;
    int prod = 1;
 
    for (int i = 0; i < 30; i++) {
        int odd_ctr = 0;

        bool is_odd = false;
 
        for (int j = 0; j < n; j++) 
        {
            if ((A[j] & (1 << i)) > 0) is_odd = !is_odd;
            if (is_odd) odd_ctr++;
        }
 
        for (int j = 0; j < n; j++) {
            sum = sum + (prod*odd_ctr);
            if ((A[j] & (1 << i)) > 0) odd_ctr = (n - j - odd_ctr);
        }
        prod = prod*2;
    }
    return sum;
}

int main()
{
    int num_test = 0;
		cin>>num_test;
		for(int i = 0; i < num_test; i++)
		{
			int n;
			cin>>n;
			vector<int> V(n , 0);
			for(int i = 0; i < n; i++) cin>>V[i];
			cout<<XorSum(V, n);
		}
    return 0;
}
