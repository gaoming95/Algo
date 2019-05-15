#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
    int n,m;
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.empty()) n = grid.size();
        else return 0;
        if(!grid[0].empty()) m = grid.size();
        else return 0;
        
        int res;

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                res ++;
                dfs(grid,i,j);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0||i>n||j<0||j>m) return;
        if(grid[i][j] == '0'){
            return;
        }else{
            grid[i][j] == '0';
            dfs(grid,i-1,j);
            dfs(grid,i+1,j);
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);
        }
    }
};

int main(){
    char flag;
    
    while ((flag=getchar())!=EOF) {
        putchar(flag);
        string tmpStr;
        vector<int> buff;
        char c;
        while ((c = getchar()) != '\n') {
            if (c != ' ')
                tmpStr.push_back(c);
            else {
                if (tmpStr != "") {
                    buff.push_back(atoi(tmpStr.c_str()));
                    tmpStr = "";
                }
            }
        }
        if(tmpStr!="")
            buff.push_back(atoi(tmpStr.c_str()));
        for (auto a : buff)
            cout << a << ' ';
        cout << '\n';
    }
    return 0;
}