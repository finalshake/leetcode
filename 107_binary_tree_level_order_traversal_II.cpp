/* 2021.02.18
 * 感觉刷的有点慢，要不然一天多刷几道，随即用DFS或BFS。*/
/* leetcode:107二叉树的层序遍历II
 * 给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回其自底向上的层序遍历为：

[
  [15,7],
  [9,20],
  [3]
]
*/

/* 思路：还是BFS方便，每遍历完一层，就存到stack中，最后出栈到结果vector中。
 * 也可以直接遍历完一层写到vector中，最后再reverse一下就是结果。*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      stack<vector<int>> stk;
      queue<TreeNode*> q;
      vector<vector<int>> ret;
      if(!root)
        return ret;
      q.push(root);
      while(!q.empty())
      {
        int sz = q.size();
        vector<int> mid;
        for(int i = 0; i < sz; i++)
        {
          TreeNode* cur = q.front();
          q.pop();
          if(cur)
          {
            mid.push_back(cur->val);
            if(cur->left)
              q.push(cur->left);
            if(cur->right)
              q.push(cur->right);
          }
        }
        stk.push(mid);
      }
      while(!stk.empty())
      {
        ret.push_back(stk.top());
        stk.pop();
      }
      return ret;
    }
};

/* 忍不住写个递归的解法*/
class Solution {
public:
    //vector<vector<int>> levelOrderBottom(TreeNode* root) {
      //vector<vector<int>> res;
      //solve(root, 0, res);
      //return res;
    //}

    //void solve(TreeNode* node, int depth, vector<vector<int>> &res)
    //{
      //if(!node)
        //return;
      //res[depth].push_back(node->val);
      //solve(node->left, depth+1, res);
      //solve(node->right, depth+1, res);

    //}
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> res;
      solve(root, 0, res);
      reverse(res.begin(), res.end());
      return res;
    }

    void solve(TreeNode* node, int depth, vector<vector<int>> &res)
    {
      if(!node)
        return;
      if(depth >= res.size())
        res.push_back({node->val});
      else
        res[depth].push_back(node->val);
      solve(node->left, depth+1, res);
      solve(node->right, depth+1, res);

};
