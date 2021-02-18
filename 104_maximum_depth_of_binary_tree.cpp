/* 2021.02.17
 * leetcode:104 二叉树最大深度
 * 给定一个二叉树，找出其最大深度。
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 这个题同样有两种思路，一是递归遍历，二是BFS迭代。
 * 先试下递归，大体思路是遇见null返回0, 遇见非null的返回1+func。
 * */

class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(!root)
        return 0;
      return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};

/* 明天再试第二种BFS方法吧，熬夜不好。
 * */

/* 第二天2021.02.18
 * BFS解法的思路：每遍历一层，depth+1, 直到遍历到最后一层子节点
 * */

class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(!root)
        return 0;
      queue<TreeNode*> q;
      q.push(root);
      int depth = 0;
      while(!q.empty())
      {
        int sz = q.size();
        for(int i = 0; i < sz; i++)
        {
          TreeNode* cur = q.front();
          q.pop();
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

//好吧，官方题解里DFS将+1提到了max（）外面，能节省些时间
