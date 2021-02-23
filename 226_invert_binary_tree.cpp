/* 2021.02.23
 * leetcode: 226 翻转二叉树
 * 翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9

输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 */

/* 即所有二叉树的子树，左右子树互换。直接先序遍历，过程中互换左右子树，写起来最简单。*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if(!root)
        return nullptr;
      TreeNode* res = new TreeNode();
      res->val = root->val;
      exchange(root, res);
      return res;
    }

    void exchange(TreeNode* root, TreeNode *res)
    {
      if(!root->left && !root->right)
        return;
      if(root->left)
      {
        res->right = new TreeNode();
        res->right->val = root->left->val;
        exchange(root->left, res->right);
      }
      if(root->right)
      {
        res->left = new TreeNode();
        res->left->val = root->right->val;
        exchange(root->right, res->left);
      }
    }
};

//以下的代码运行时出错。
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if(!root)
        return nullptr;
      TreeNode* res = new TreeNode();
      res->val = root->val;
      exchange(root, res);
      return res;
    }

    void exchange(TreeNode* root, TreeNode *res)
    {
      if(!root->left && !root->right)
        return;
      res->left = root->right;
      res->right = root->left;
      if(root->left)
        exchange(root->left, res->right);
      if(root->right)
        exchange(root->right, res->left);
    }
};

/* 也可以用BFS方法*/
