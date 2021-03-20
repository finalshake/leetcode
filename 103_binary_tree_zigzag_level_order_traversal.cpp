/* 2021.03.20
 * leetcode: 103 二叉树的锯齿形层序遍历
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]


*/

// 可以同上题一样层序BFS,最后在隔层reverse一下vector。但是这样一个坏处就是时间复杂度要高些。
// 根据官方题解，可以用deque,它有push_front()这个方法，直接在头部插入元素。
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if(!root)
        return res;
      queue<TreeNode*> q;
      q.push(root);
      bool reverse = false;
      while(!q.empty())
      {
        int sz = q.size();
        deque<int> tmp;
        for(int i = 0; i < sz; i++)
        {
          TreeNode* cur = q.front();
          q.pop();
          if(!reverse)
            tmp.push_back(cur->val);
          else
            tmp.push_front(cur->val);
          if(cur->left)
            q.push(cur->left);
          if(cur->right)
            q.push(cur->right);
        }
        //res.push_back((vector<int>)tmp);                 这样强制转换不行，报错
        res.push_back((vector<int>){tmp.begin(), tmp.end()});
        reverse = !reverse;
      }
      return res;
    }
};
