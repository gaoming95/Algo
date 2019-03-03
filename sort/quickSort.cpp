#include <iostream>
#include<vector>
#include<math.h>
#include<random>

using namespace std;

//O(n^2)
int partition_(vector<int>& nums, int p, int r){
    int x = nums[r];
    int i = p-1;
    for(int j=p; j<r; j++){
        if(nums[j]<=x){
            i = i+1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[r]);
    return i+1;
}


void quickSort(vector<int>& nums, int p, int r){
    if(p<r){
        int q = partition_(nums, p, r);
        quickSort(nums, p, q-1);
        quickSort(nums, q+1, r);
    }
}

int random_partition_(vector<int>& nums, int p, int r){
    default_random_engine generator;
    uniform_int_distribution<int> distribution(p, r);
    int i = distribution(generator);
    cout << i << endl;
    swap(nums[i], nums[r]);
    return partition_(nums, p, r);
}


void random_quickSort(vector<int>& nums, int p, int r){
    if(p<r){
        int q = random_partition_(nums, p, r);
        random_quickSort(nums, p, q-1);
        random_quickSort(nums, q+1, r);
    }
}

int main()
{
    vector<int> nums = {18, 45, 100, 34, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    //quickSort(nums, 0, nums.size()-1);
    random_quickSort(nums, 0, nums.size()-1);
    for(auto num:nums){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
