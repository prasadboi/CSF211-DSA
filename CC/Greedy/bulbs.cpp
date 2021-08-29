#include <bits/stdc++.h>

using namespace std;


/*
N light bulbs are connected by a wire.

Each bulb has a switch associated with it, however due to faulty wiring, 
a switch also changes the state of all the bulbs to the right of current bulb.
Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.
You can press the same switch multiple times.
Note : 0 represents the bulb is off and 1 represents the bulb is on.
*/


int main(int argc, char const *argv[])
{
    vector<int> A = {1, 1, 0, 0, 1, 1, 0, 0, 1};
    
    int n = A.size();
    int state= 0, ans = 0;
	for (int i = 0;i < A.size();i++) {
		if (A[i] == state) {
		    ans++;
    	    state = 1 - state;
        }
}
    return ans;

}