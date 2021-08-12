#include <bits/stdc++.h>
using namespace std;

int KADANE(vector<int> &arr) {
    vector<int> max_sum_arr(arr.size(), 0);
    int max_sum = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        max_sum_arr[i] = max(max_sum_arr[i-1] + arr[i], arr[i]);
        max_sum = max(max_sum, max_sum_arr[i]);
    }
    return max_sum;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << KADANE(arr) << endl;
    return 0;
}
