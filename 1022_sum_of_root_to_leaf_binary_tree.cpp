/* 2021.03.13
 * leetcode: 1022 从根到叶的二进制数之和
 * 给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

返回这些数字之和。题目数据保证答案是一个 32 位 整数。

 

示例 1：

输入：root = [1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

示例 2：

输入：root = [0]
输出：0

示例 3：

输入：root = [1]
输出：1

示例 4：

输入：root = [1,1]
输出：3

 

提示：

    树中的结点数介于 1 和 1000 之间。
    Node.val 为 0 或 1 。

*/

/* DFS和BFS都可以，用DFS吧。*/
/* 2021.02.13在手机上写了个答案，结果时间空间都排后，原因在于忘了连续乘2或左移这种操作，现在用左移位。*/
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
      if(!root)
        return 0;
      int sum = 0;
      traverse(root, 0, sum);
      return sum;
    }

    void traverse(TreeNode* root, int num, int& sum)
    {
      if(!root)
        return ;
      num = (num << 1) + root->val;                  //左移一位就相当于乘以2, 必须加括号，因为它优先级低
      if(!root->left && !root->right)
      {
        sum += num;
      }
      traverse(root->left, num, sum);
      traverse(root->right, num, sum);
    }
};
