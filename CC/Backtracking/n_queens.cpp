#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool search_diagonals(vector<string> curr_config, int x, int y, int n)
{
    //cout<<"start diagsearch" << x<< " "<<y<<"\n";
    for(int i = x-1, j = y-1; ((i >= 0) && (j >= 0)); i--, j--)
    {
        if(curr_config[i][j] == 'Q')
        {
            //cout<<"found true\n";
            return true;
        }
    }
    for(int i = x - 1, j = y+1; ((i >= 0) && (j < n)); i--, j++){
        if(curr_config[i][j] == 'Q')
        {
            //cout<<"found true\n";
            return true;
        }
    }
    //cout<<"found false\n";
    return false;
}

bool search_row(vector<string> curr_config, int x, int y)
{
    //cout<<"start rowsearch\n";
    for(int i = 0; i <= y; i++)
    {
        if(curr_config[x][i] == 'Q') return true;
    }
    return false;
}

bool search_col(vector<string> curr_config, int x, int y)
{
    //cout<<"start colsearch\n";
    for(int i = 0; i <= x; i++)
    {
        if(curr_config[i][y] == 'Q'){
            //cout<<"found true\n";
            return true;
        }
    }
    //cout<<"found false\n";
    return false;
}



void Queen_configs(vector<vector<string>> &ans, vector<string> &tempconfig, int idx, int n)
{
    if(idx >= n)
    {
        ans.push_back(tempconfig);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        //cout<<"\nqueen at col i : "<<i<<endl;
        string temprow;
        // in case the queen lies at position i
        for(int j = 0; j < n; j++)
        {
            if(j == i) temprow.push_back('Q');
            else temprow.push_back('.');
        }
        bool colflag = search_col(tempconfig, tempconfig.size() - 1, i);
        bool diagflag = search_diagonals(tempconfig, tempconfig.size(), i, n);
        tempconfig.push_back(temprow);
        if(!colflag && !diagflag)
        {
            //cout<<"in if1\n";
            //cout<<"tempconfig size : "<<tempconfig.size()<<endl;
            //cout<<"added row : "<<temprow<<endl;
            Queen_configs(ans, tempconfig, idx+1, n);
        }
        tempconfig.pop_back();
    }
}


vector<vector<string> > solveNQueens(int A) {
    vector<vector<string>> ans;
    vector<string> tempconfig;
    string temprow;

    Queen_configs(ans,  tempconfig, 0, A);
    return ans;
}


int main(int argc, char const *argv[])
{
    vector<vector<string>> mat = solveNQueens(4);
    cout<<mat.size()<<endl;
    for(int i = 0; i < mat.size(); i++)
    {
        for(auto j : mat[i])
        {
            cout<<j<<"\n";
        }
        cout<<endl;
    }
    return 0;
}
