#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k) {
    int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 3};
    rotate(A, 2);
    for(int i = 0; i < A.size(); i++) 
        cout << A[i] << " ";
    return 0;
}
