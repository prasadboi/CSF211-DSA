/*
Given an array of integers nums containing n + 1 integers 
where each integer is in the range [1, n] inclusive.


Method 1 : SORT
sort the array and check for consecutive duplicate elements

Method2 : SET / HashMAP
maintain a frequency table for all the elements

Method3 : Negative Marking
if(A[A[i]] < 0) then i has already occurred once in the array . Thus return A[i];
else
    A[A[i]] *= -1;

Method4 : 
Since all numbers are in the range [1, n], 
they will be mapped to indices 1 through n inclusive, 
and hence no number will be mapped to index 0.
1.rec :-
    int store(vector<int>& nums, int cur) {
        if (cur == nums[cur])
            return cur;
        int nxt = nums[cur];
        nums[cur] = cur;
        return store(nums, nxt);
    }

    call as store(nums, 0);

2. iterative :-
    int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// method 5:
// floyd method
// Time Complexity : O(n)
// using floyd's cycle detection algorithm for the sequence x, nums[x], nums[nums[x]], nums[nums[nums[x]]]....
// cycle indicates that there must be duplicate elements

int repeatedNumber(const vector<int> &nums) {
    int tortoise = nums[0];
    int hare = nums[0];

    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

        // Find the "entrance" to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;    
}

int main(int argc, char const *argv[])
{
    vector<int> A = {3, 4, 1, 4, 1};
    cout << repeatedNumber(A) << endl;
    return 0;
}

