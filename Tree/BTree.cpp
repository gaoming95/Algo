#include <malloc.h>
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <list>
#include <queue>
#include<stack>

using namespace std;

//二叉树结构定义
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//根据数组初始化二叉树
TreeNode *initBTree(int data[], int index, int n)
{
	TreeNode *pNode = NULL;
	if (index < n && data[index] != -1)
	{
		pNode = (TreeNode *)malloc(sizeof(TreeNode));
		if (pNode == NULL)
		{
			return NULL;
		}
		pNode->val = data[index];
		pNode->left = initBTree(data, 2 * index + 1, n);
		pNode->right = initBTree(data, 2 * index + 2, n);
	}
	return pNode;
}

//前序遍历 递归方式
void preOrder(TreeNode *root, vector<int> &result)
{
	if (root)
	{
		result.push_back(root->val);
		preOrder(root->left, result);
		preOrder(root->right, result);
	}
}
// 前序遍历 非递归方式
void preorderTraversal(TreeNode *root,vector<int> &result){
	stack< pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            result.push_back(root->val);
        }
        else
        {
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
            s.push(make_pair(root, true));
        }
    }
}

//中序遍历 递归方式
void inOrder(TreeNode *root, vector<int> &result)
{
	if (root)
	{
		inOrder(root->left, result);
		result.push_back(root->val);
		inOrder(root->right, result);
	}
}

//中序遍历 非递归方式
void inOrderTraversal(TreeNode *root,vector<int> &result){
	stack< pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            result.push_back(root->val);
        }
        else
        {
            s.push(make_pair(root->right, false));
            s.push(make_pair(root, true));
            s.push(make_pair(root->left, false));
        }
    }
}

//后序遍历 递归方式
void postOrder(TreeNode *root, vector<int> &result)
{
	if (root)
	{
		postOrder(root->left, result);
		postOrder(root->right, result);
		result.push_back(root->val);
	}
}

//后续遍历 非递归方式
void postOrderTraversal(TreeNode *root,vector<int> &result){
	stack< pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            result.push_back(root->val);
        }
        else
        {
            s.push(make_pair(root, true));
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
        }
    }
}

//层次遍历一 输出一维数组
void levelOrder(TreeNode *root, vector<int> &result)
{
	if (root == NULL)
	{
		return;
	}
	queue<TreeNode *> queue;
	queue.push(root);
	while (!queue.empty())
	{
		TreeNode *front = queue.front();
		queue.pop();
		result.push_back(front->val);
		if (front->left)
		{
			queue.push(front->left);
		}

		if (front->right)
		{
			queue.push(front->right);
		}
	}
}

//层次遍历二 输出二维数组
void levelOrder2(TreeNode *root, vector<vector<int>> &result)
{
	if (root == NULL)
	{
		return;
	}
	queue<TreeNode *> queue;
	queue.push(root);
	while (!queue.empty())
	{
		int count = queue.size();
		vector<int> vec_temp;

		while (count--)
		{
			TreeNode *front = queue.front();
			queue.pop();
			vec_temp.push_back(front->val);
			if (front->left)
			{
				queue.push(front->left);
			}

			if (front->right)
			{
				queue.push(front->right);
			}
		}
		result.push_back(vec_temp);
	}
}

//二叉树的最大深度
int maxDepth(TreeNode *root)
{
	if (root == NULL)
		return 0;
	int l1 = maxDepth(root->left);
	int l2 = maxDepth(root->right);
	return max(l1, l2) + 1;
}

//打印输出二叉树
void traverse(vector<int> nums)
{
	vector<int>::size_type size = nums.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;
}
void traverse2(vector<vector<int>> nums){
	for(int i = 0;i<nums.size();i++){
		for(int j = 0;j<nums[i].size();j++){
			cout<<nums[i][j];
		}
		cout<<'\n';
	}
}

int main()
{
	int nums[] = {1, 2, 3, 3, -1, 2, -1};
	TreeNode *root = initBTree(nums, 0, sizeof(nums) / sizeof(nums[0]));
	// vector<int> preResult;
	vector<vector<int>> preResult;
	levelOrder2(root, preResult);
	cout << "前序遍历的结果：" << '\n';
	traverse2(preResult);
	return 0;
}
