/* 2021.02.27
 * leetcode: 543 二叉树的直径
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    

返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

 

注意：两结点之间的路径长度是以它们之间边的数目表示。

*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if(!root)
        return 0;
      int res = 0;
      traverse(root, res, 0);
      return res;
    }

    int traverse(TreeNode* root, int& res, int maxdepth)
    {
      if(!root)
      {
        return 0;
      }
      int leftdepth = traverse(root->left, res, maxdepth);
      int rightdepth = traverse(root->right, res, maxdepth);
      if(!root->left && !root->right)
      {
        maxdepth = 0;
        return 1;
      }
      maxdepth = max(leftdepth, rightdepth) + 1;
      res = max(res, leftdepth + rightdepth);
      return maxdepth;
    }
};

/* 可以再精简一些*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if(!root)
        return 0;
      int res = 0;
      traverse(root, res);
      return res;
    }

    int traverse(TreeNode* root, int& res)
    {
      if(!root)
      {
        return 0;
      }
      int leftdepth = traverse(root->left, res);
      int rightdepth = traverse(root->right, res);
      if(!root->left && !root->right)
      {
        return 1;
      }
      res = max(res, leftdepth + rightdepth);
      return max(leftdepth, rightdepth) + 1;
    }
};
