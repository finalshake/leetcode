/* 2021.02.24
 * leetcode: 404 左叶子之和
 * 计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

*/

/* 决定用BFS来一把*/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
      if(!root)
        return 0;
      queue<TreeNode*> q;
      q.push(root);
      int sum = 0;
      while(!q.empty())
      {
        TreeNode* cur = q.front();
        q.pop();
        if(cur->left)
        {
          if(!cur->left->left && !cur->left->right)
            sum += cur->left->val;
          q.push(cur->left);
        }
        if(cur->right)
          q.push(cur->right);
      }
      return sum;
    }
};
