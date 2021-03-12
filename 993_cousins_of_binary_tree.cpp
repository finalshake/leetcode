/* 2021.03.11
 * leetcode: 993 二叉树的堂兄弟节点
 * 在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。

 

示例 1：

输入：root = [1,2,3,4], x = 4, y = 3
输出：false

示例 2：

输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
输出：true

示例 3：

输入：root = [1,2,3,null,4], x = 2, y = 3
输出：false

 

提示：

    二叉树的节点数介于 2 到 100 之间。
    每个节点的值都是唯一的、范围为 1 到 100 的整数。

*/
/* ！！！注意：每个节点的值唯一，说明不会出现节点值重复的情况。一旦有一个节点值是x了，就不可能再出现另一个节点x。*/
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
      if(!root)
        return false;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        int sz = q.size();
        int res = -1;
        for(int i = 0; i < sz; i++)
        {
          TreeNode* cur = q.front();
          q.pop();
          int left_res = -1;
          if(q.empty() && (cur->val == x || cur->val == y))
            return false;
          if(cur->left)
          {
            if(cur->left->val == x || cur->left->val == y)
            {
              if(res == -1)
              {
                res = cur->left->val;
                left_res = res;
              }
              else 
                return true;
            }
            q.push(cur->left);
          }
          if(cur->right)
          {
            if(cur->right->val == x || cur->right->val == y)
            {
              if(left_res != -1)
                return false;
              else if(res != -1)
                return true;
              else
                res = cur->right->val;
            }
            q.push(cur->right);
          }
        }
      }
      return false;
    }
};
