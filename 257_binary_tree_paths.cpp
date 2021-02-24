/* 2021.02.24
 * leetcode: 257 二叉树的所有路径
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

*/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> res;
      if(!root)
        return res;
      traverse(root, res, to_string(root->val));
      return res;
    }

    void traverse(TreeNode* root, vector<string>& res, string s)
    {
      if(!root->left && !root->right)
        res.push_back(s);
      if(root->left)
      {
        string sl = s + "->" + to_string(root->left->val);         //必须另存到一个string中，不然后面再遍历右子树时s就已经加上了左子树的值
        traverse(root->left, res, sl);
      }
      if(root->right)
      {
        string sr = s + "->" + to_string(root->right->val);
        traverse(root->right, res, sr);
      }

    }
};
