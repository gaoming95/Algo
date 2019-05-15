#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    //编辑距离
    int minDistance(string word1,string word2){
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //初始化数组
        for(int i = 0;i<=m;i++){
            dp[i][0] = i;
        }
        for(int j = 0;j<=n;j++){
            dp[0][j] = j;
        }

        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[m][n];
    }

    // 硬币找零
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(auto c:coins){
            for(int i=c;i<=amount;i++){
                dp[i] = min(dp[i-c]+1,dp[i]);
            }
        }
        return dp[amount] < (amount+1) ? dp[amount]:-1;
    }
};

int main(){
    string a1 = "horse";
    string a2 = "ros";
    Solution s;
    int res = s.minDistance(a1,a2);
    cout<<res;
    return 0;
}