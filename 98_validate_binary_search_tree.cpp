/* 2021.03.19
 * leetcode: 98 验证二叉搜索树
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

示例 1:

输入:
    2
   / \
  1   3
输出: true

示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。


 这一题可以根据二叉搜索树的性质，中序遍历，一定是从小到大排列的顺序，一旦有反序，则返回false*/
class Solution {
public:
    int prev = INT_MIN;
    int count = 0;
    bool isValidBST(TreeNode* root) {
      if(!root)
        return true;
      bool left = isValidBST(root->left);
      if((root->val <= prev) && count!=0)                               //这时候处理INT_MIN就很尴尬了，如果连着出现两个INT_MIN，理应返回false
        return false;
      count++;
      prev = root->val;
      bool right = isValidBST(root->right);
      return left && right;
    }
};
