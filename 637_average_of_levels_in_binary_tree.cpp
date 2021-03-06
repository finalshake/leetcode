/* 2021.03.05
 * leetcode: 637 二叉树的层平均值
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

 

示例 1：

输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。

 

提示：

    节点值的范围在32位有符号整数范围内。

*/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
      vector<double> res;
      if(!root)
        return res;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        int sz = q.size();
        int count = 0;
        long sum = 0;                //把类型改成long,不然节点是最大整数值，一加就溢出了
        for(int i = 0; i < sz; i++)
        {
          TreeNode* cur = q.front();
          q.pop();
          sum += cur->val;
          count++;
          if(cur->left)
            q.push(cur->left);
          if(cur->right)
            q.push(cur->right);
        }
        res.push_back(1.0 * sum / count);
      }
      return res;
    }
};
