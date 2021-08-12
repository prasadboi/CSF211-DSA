#include <bits/stdc++.h>
using namespace std;

int isNumber(const string A) {
    bool dotFlag = false;
    bool eFlag = false;

    // removing preceding spaces
    int ctr;
    for(ctr = 0; ctr < A.size();)
    {
        if(A[ctr] == ' ') ctr++;
        else break; 
    }
    if(ctr >= A.size()) return 0;
    
    int i;
    if(A[ctr] == '-') ctr++;
    for(i = ctr; i < A.size() && A[i] != ' '; i++)
    {
        if(!isdigit(A[i]) && A[i] == '.' && dotFlag == false){
            dotFlag = true;
            i++;
            if(!isdigit(A[i])) return 0;
        }
        else if(A[i] == 'e' && eFlag == false) {
            eFlag = true; dotFlag = true;
            i++;
            if(A[i] == '-'){}
            else if(!isdigit(A[i])) return 0;
        }
        else if(!isdigit(A[i])) return 0;
    }

    // checking out trailing spaces
    for(; i < A.size(); i++)
    {
        if(A[i] != ' ') return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    string A = "32467826570812365702673647926314796457921365792637946579269236594265794625762375621765476592146926410592659021465904652.687236478235187653874637824647856428756387264578245676579032657906097542609  ";
    cout << isNumber(A) << endl;    
    return 0;
}
