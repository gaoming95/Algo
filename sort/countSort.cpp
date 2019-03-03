#include <iostream>
#include<vector>
#include<math.h>
#include<random>
#include<algorithm>

using namespace std;

//O(n+k) ”≈µ„   Œ»∂®
vector<int> countSort(vector<int> nums, int k){
    vector<int> arr(k, 0);
    vector<int> res(nums.size(), 0);

    for(int i=0;i<nums.size();i++){
        arr[nums[i]]++;
    }
    // arr (0 0 0 0 0 2 0 1 1 1)

    for(int i=1;i<k;i++){
        arr[i] += arr[i-1];
    }

    // arr (0 0 0 0 0 2 2 3 4 5)

    for(int j=nums.size()-1; j>=0; j--){
        res[arr[nums[j]]-1] = nums[j];
        arr[nums[j]]--;
    }

    return res;
}


int main()
{
    vector<int> nums = {5, 7, 9, 5, 8};
    vector<int> res = countSort(nums, 10);
    for(auto num:res){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
