/* 2021.02.22
 * leetcode: 112 路径总和
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。

叶子节点 是指没有子节点的节点。

 

示例 1：

输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true

示例 2：

输入：root = [1,2,3], targetSum = 5
输出：false

示例 3：

输入：root = [1,2], targetSum = 0
输出：false

*/

/* 还是直接用递归遍历吧， 每遍历一个节点， 减去节点的值， 如果结果小于0, 则停止遍历该分支， 如果结果大于0, 则继续
 * 如果到达叶子结果刚好为0, 则返回true, 如果遍历完所有分支都没有返回true则返回false。*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if(!root)
        return false;
      int flag = 0;
      check(root, targetSum, flag);
      return flag;
    }

    void check(TreeNode* node, int rest, int& flag)
    {
      rest = rest - node->val;
      if(rest == 0 && !node->left && !node->right)
      {
        flag = 1;
        return;
      }
      //if(rest < 0)
        //return;
      //要是有负数的话就不好判断正负了，不能停止遍历
      if(node->left)
        check(node->left, rest, flag);
      if(node->right)
        check(node->right, rest, flag);
    }
};
/* 还是官方解简练。*/
