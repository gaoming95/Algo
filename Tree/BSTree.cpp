#include <iostream>
#include <malloc.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *BSTree(TreeNode &root, int data[])
{
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        TreeNode *p, *s;
        s = (TreeNode *)malloc(sizeof(TreeNode));
        s->val = data[i];
        s->left=s->right=NULL;
        if(p==NULL){
            *root = s;
        }
    }
    
}

void print(TreeNode *root)
{
    if (root)
    {
        print(root->left);
        printf("%5", root->val);
        print(root->right);
    }
}

int main()
{
    int a[] = {-10, -3, 0, 5, 9};
    print(BSTree(a, 5));
    return 0;
}