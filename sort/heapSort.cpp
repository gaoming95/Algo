#include <iostream>
#include<vector>
#include<math.h>

using namespace std;

//O(nlogn)
void maxHeap(vector<int> &nums, int i, int high){
    int left = 2*i+1, right = 2*i+2;
    int largest;
    if(left<high&&nums[left]>nums[i]) largest = left;
    else largest = i;

    if(right<high&&nums[right]>nums[largest]) largest = right;

    if(largest!=i){
        swap(nums[i], nums[largest]);
        maxHeap(nums, largest, high);
    }

}

void bulidHeap(vector<int> &nums){
    for(int i=nums.size()/2-1; i>=0; i--){
        maxHeap(nums, i, nums.size());
    }
}


void heapSort(vector<int> &nums){
    bulidHeap(nums);
    for(int i=nums.size()-1; i>0; i--){
        swap(nums[0], nums[i]);
        maxHeap(nums, 0, i);
    }
}


//用堆来实现最大优先队列

//返回S中具有最大键值的元素
int heapMax(vector<int> &nums){
    return nums[0];
}

//去掉并返回S中具有最大键值的元素
int extractHeapMax(vector<int> &nums){
    if(nums.size()<1){
        return -1;
    }
    int maxNum = nums[0];
    swap(nums[0], nums[nums.size()-1]);
    nums.pop_back();
    maxHeap(nums, 0, nums.size());
    return maxNum;
}

//void heapInsert(vector<int> &nums, int x){
//    nums.push_back(x)
//}

//将元素x的值增加到k，假设k的值不小于x的值，（nums[i]=k）
void increaseKey(vector<int> &nums, int i, int key){
    if(key<nums[i]){
        return ;
    }
    nums[i] = key;
    while(i>0 && nums[(i-1)/2]<nums[i]){
        swap(nums[i], nums[(i-1)/2]);
        i = (i-1)/2;
    }
}

void insertHeap(vector<int> &nums, int key){
    nums.push_back(INT_MIN);
    increaseKey(nums, nums.size()-1, key);
}

int main()
{
    vector<int> nums = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    //maxHeap(nums, 1, nums.size());
    //bulidHeap(nums);
    //maxHeap(nums, 1, nums.size());
    heapSort(nums);
    for(auto num:nums){
        cout << num << " ";
    }
    cout << endl;


    bulidHeap(nums);
    int max_num = heapMax(nums);
    cout << max_num << endl;
    max_num = extractHeapMax(nums);
    cout << max_num << endl;
    for(auto num:nums){
        cout << num << " ";
    }
    cout << endl;


    increaseKey(nums, 1, 17);
    for(auto num:nums){
        cout << num << " ";
    }
    cout << endl;


    insertHeap(nums, 15);
    for(auto num:nums){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
