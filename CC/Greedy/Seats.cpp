#include <bits/stdc++.h>
using namespace std;
#define MOD 10000003

int main(int argc, char const *argv[])
{
    string A = "....x..xx...x..";
    int n = A.size();

    vector<int> X;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 'x')
            X.push_back(i);
    }
    //for(auto i : X) cout << i << " ";

    int ans = INT_MAX;
    int med1 = X.size() / 2;
    int med2 = (int)ceil(X.size() / 2);



    int i = med1;
    int l = 1, r = 1;
    //cout<<"for i = "<<X[i]<<"-------------------"<<endl;
    int sum = 0;
    for (int j = 0; j < i; j++)
    {   //cout<<"dist = "<<X[i] - X[j] - l<<endl;
        sum += X[i] - X[j] - l;
        sum = sum % MOD;
        l++;
    }
    for (int j = i + 1; j < X.size(); j++)
    {
        //cout<<"dist = "<<X[j] - X[i] - r<<endl;
        sum += X[j] - X[i] - r;
        sum = sum % MOD;
        r++;
    }
    ans = min(ans, sum);




    i = med2;
    l = 1, r = 1;
    //cout<<"for i = "<<X[i]<<"-------------------"<<endl;
    sum = 0;
    for (int j = 0; j < i; j++)
    {
        //cout<<"dist = "<<X[i] - X[j] - l<<endl;
        sum += X[i] - X[j] - l;
        sum = sum % MOD;
        l++;
    }
    for (int j = i + 1; j < X.size(); j++)
    {
        //cout<<"dist = "<<X[j] - X[i] - r<<endl;
        sum += X[j] - X[i] - r;
        sum = sum % MOD;
        r++;
    }
    ans = min(ans, sum);
    cout << ans << endl;
    return 0;
}
