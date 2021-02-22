/* 2021.02.22
 * leetcode: 111 二叉树的最小深度
 * 给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

 

示例 1：

输入：root = [3,9,20,null,null,15,7]
输出：2

示例 2：

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5

*/
/* 这题书上有，直接BFS写程序吧*/
class Solution {
public:
    int minDepth(TreeNode* root) {
      if(!root)
        return 0;
      queue<TreeNode*> q;
      q.push(root);
      int depth = 1;
      while(!q.empty())
      {
        int sz = q.size();
        for(int i = 0; i < sz; i++)
        //for(int i = 0; i < q.size(); i++)     巨大bug, 谁他妈让你自作聪明直接上q.size()的？ q的大小在for里面变化了，为什么不套模板？
        {
          TreeNode* cur = q.front();
          q.pop();
          if(!cur->left && !cur->right)
            return depth;
          if(cur->left)
            q.push(cur->left);
          if(cur->right)
            q.push(cur->right);
        }
        depth++;
      }
      return depth;
    }
};
