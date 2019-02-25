#include <iostream>
#include<vector>

using namespace std;

//O(n^2)
void insertSort(vector<int> &nums){
    for(int j=1; j<nums.size(); j++){
        int temp = nums[j];
        int i = j-1;
        while(i>=0 && nums[i]>temp){
            nums[i+1] = nums[i];
            i = i-1;
        }
        nums[i+1] = temp;
    }
}


int main()
{
    vector<int> nums = {3, 1, 5, 2};
    insertSort(nums);
    for(auto num:nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
