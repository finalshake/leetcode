/* 2021.02.25
 * leetcode: 501 二叉搜索树中的众数
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

    结点左子树中所含结点的值小于等于当前结点的值
    结点右子树中所含结点的值大于等于当前结点的值
    左子树和右子树都是二叉搜索树

例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2

返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

*/

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
      vector<int> res;
      queue<int> q;
      traverse(root, res, q, 1, 1);
      return res;
    }

    void traverse(TreeNode* root, vector<int>& res, queue<int>& q, int count, int maxval)
    {
      if(!root)
        return;
      traverse(root->left, res, q, count, maxval);
      if(q.empty())
      {
        q.push(root->val);
        res.push_back(root->val);
      }
      else
      {
        int prev = q.front();
        q.pop();
        q.push(root->val);
        if(prev == root->val)
        {
          count++;
          if(maxval == count)
          {
            res.push_back(root->val);
          }
          else if(maxval < count)
          {
            if(res.size() == 1)
            {
              maxval = count;
              res.pop_back();
              res.push_back(root->val);
            }
            else if(res.size() >= 2)
            {
              int tmp = res.back();
              res.clear();
              res.push_back(tmp);
            }
            else if(res.empty())
              res.push_back(root->val);
          }
        }
        else
          count = 1;
      }
      traverse(root->right, res, q, count, maxval);
    }
};
/*整这些妖蛾子干嘛？直接写到一数组里，另外遍历一遍不就完了。 什么时间空间复杂度之后再考虑。*/
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
      vector<int> res;
      traverse(root, res);
      unordered_map<int,int> m;
      for(int i = 0; i < res.size(); i++)
      {
        m[res[i]]++;
      }
      vector<int> ret;
      int max = INT_MIN;
      for(auto& it:m)
      {
        if(it.second > max)
        {
          max = it.second;
          ret.clear();
          ret.push_back(it.first);
        }
        else if(it.second == max)
        {
          ret.push_back(it.first);
        }
      }
      return ret;
    }

    void traverse(TreeNode* root, vector<int>& res)
    {
      if(!root)
        return;
      traverse(root->left, res);
      res.push_back(root->val);
      traverse(root->right, res);
    }
};
