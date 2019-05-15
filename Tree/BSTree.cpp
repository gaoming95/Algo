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
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        TreeNode *p, *s;
        s = (TreeNode *)malloc(sizeof(TreeNode));
        s->val = data[i];
        s->left = s->right = NULL;
        if (p == NULL)
        {
            root = *s;
        }
        else if (data[i] < p->val)
        {
            p->left = s;
        }
        else
        {
            p->right = s;
        }
    }
    return;
}

int main()
{
    int a[] = {-10, -3, 0, 5, 9};
    TreeNode *root = NULL;
    BSTree(&root, a);
    return 0;
}