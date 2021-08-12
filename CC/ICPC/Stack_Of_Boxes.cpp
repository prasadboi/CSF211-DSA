#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool empty_stacks(int A, int B, int C)
{
    /*if(A == 0 && B == 0 && C == 0) return true;
		else if(A < 0 || B < 0 || C < 0) return false;
	else return empty_stacks(A-2, B - 1, C -1)||empty_stacks(A - 1, B-2, C-1) || empty_stacks(A - 1, B - 1, C - 2);*/

    /*if(A == 0 && B == 0 && C == 0) return true;
    else{
        while(A > 1 || B > 1 || C > 1)
        {
            if(A >= B && A >= C) {A += -2; B += -1; C += -1;}
            else if(B >= A && B >= C) {B += -2; A += -1; C += -1;}
            else if(C >= A && C >= B) {C += -2; A += -1; B += -1;}
        }
    }
    if(A == 0 && B == 0 && C == 0) return true;
    else return false;*/

    int arr[3] = {A, B, C};
    int sum=0;
    for(int i=0;i<3;i++){
        sum+=arr[i];
    }
    sort(arr,arr+3);
    if((sum)%4!=0){
        return false;
    }
    else{
        int odd=0,even=0;
        for(int i=0;i<3;i++){
            if(arr[i]%2==1)odd++;
            else even++;
        }
        
        if((odd==2 && even==1) ||(even==3)){
            if(((arr[2]+arr[1])/3)<=arr[0]){
                return true;
            }
            else{
                return false;
            }
            
        }
        else{
            return false;
        }

    }

}
int main(int argc, char const *argv[])
{
    int num_test_cases = 0;
    cin>>num_test_cases;
    for(int i = 0; i < num_test_cases; i++){
        int A, B, C;
        cin >> A >> B >> C;
        if(empty_stacks(A, B, C) == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
