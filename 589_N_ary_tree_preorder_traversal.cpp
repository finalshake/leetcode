/* 2021.03.02
 * leetcode: 589 N叉树的前序遍历
 * 给定一个 N 叉树，返回其节点值的 前序遍历 。

N 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

 

进阶：

递归法很简单，你可以使用迭代法完成此题吗?

 

示例 1：

输入：root = [1,null,3,2,4,null,5,6]
输出：[1,3,5,6,2,4]

示例 2：

输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]

 

提示：

    N 叉树的高度小于或等于 1000
    节点总数在范围 [0, 10^4] 内

*/
class Solution {
public:
    vector<int> preorder(Node* root) {
      vector<int> res;
      if(!root)
        return res;
      traverse(root, res);
      return res;
    }

    void traverse(Node* root, vector<int>& res)
    {
      if(!root)
        return;
      res.push_back(root->val);
      for(Node* cur : root->children)
      {
        traverse(cur, res);
      }
    }
};

/* 试一试迭代*/

class Solution {
public:
    vector<int> preorder(Node* root) {
      vector<int> res;
      if(!root)
        return res;
      stack<Node*> s;
      s.push(root);
      while(!s.empty())
      {
        Node* cur = s.top();
        s.pop();
        res.push_back(cur->val);
        stack<Node*> tmp;
        for(Node* node : cur->children)
        {
          tmp.push(node);
        }
        while(!tmp.empty())
        {
          s.push(tmp.top());
          tmp.pop();
        }
      }
      return res;
    }
};
