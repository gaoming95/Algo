#include <iostream>
#include<vector>
#include<math.h>
#include<random>
#include<algorithm>

using namespace std;

int getMax(vector<int> nums){
    int digit = 1;
    int base = 10;
    for(int i=0;i<nums.size();i++){
        while(nums[i] >= base){
            digit++;
            base *= 10;
        }
    }
    return digit;
}

int getDigit(int i, int d){
    int val;
    while(d--){
        val = i % 10;
        i /= 10;
    }
    return val;
}


void radixSort(vector<int> &nums){
    int k = getMax(nums);
    vector<int> countor(10, 0);
    vector<vector<int>> bucket(10, vector<int>(nums.size()));

    int digit=1;
    int index=0;
    while(digit <= k){
        for(int j=0; j<nums.size(); j++){
            int s = getDigit(nums[j], digit);
            bucket[s][countor[s]] = nums[j];
            countor[s]++;
        }

        for(int i=0;i<10;i++){
            if(countor[i]!=0){
                for(int j=0;j<countor[i];j++){
                    nums[index] = bucket[i][j];
                    index ++;
                }
            }
            countor[i] = 0;
        }
        digit ++;
        index = 0;
    }


}

int main()
{
    vector<int> nums = {123, 424, 354, 248, 789};
    radixSort(nums);
    for(auto num:nums){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
