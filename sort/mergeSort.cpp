#include <iostream>
#include<vector>
#include<math.h>

using namespace std;

//O(nlogn)
void _merge(vector<int> &nums, int left, int med, int right){
    cout << left << " " << med << " " << right <<endl;
    vector<int> L(nums.begin()+left, nums.begin()+med+1);
    for(auto num1:L){
        cout << num1 << " " ;
    }
    cout << "L" <<endl;

    vector<int> R(nums.begin()+med+1, nums.begin()+right+1);

    for(auto num2:R){
        cout << num2 << " " ;
    }
    cout << "R" <<endl;
    // 设置哨兵  简化代码  不用每次判断数组是否为空
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    int i=0, j=0;

    for(int k=left; k<=right; k++){
        if(L[i] < R[j]){
            nums[k] = L[i];
            i++;
        }else{
            nums[k] = R[j];
            j++;
        }
    }
    cout << "nums[left,right]";
    for(int k=left;k<=right;k++){
        cout << nums[k] << " ";
    }
    cout << endl;
}

void _sort(vector<int> &nums, int left, int right){
    int med = (left+right)/2;
    if(left < right){
        _sort(nums, left, med);
        _sort(nums, med+1, right);
        _merge(nums, left, med, right);
    }

}

void mergeSort(vector<int> &nums){
    _sort(nums, 0, nums.size()-1);
}





int main()
{
    vector<int> nums = {3, 1, 10, 2, 8};

    mergeSort(nums);
    for(auto num:nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
