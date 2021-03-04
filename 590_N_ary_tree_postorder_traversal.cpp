/* 2021.03.03 00:17
 * leetcod: 590 N叉树的后序遍历
 * 给定一个 N 叉树，返回其节点值的 后序遍历 。

N 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

 

进阶：

递归法很简单，你可以使用迭代法完成此题吗?

 

示例 1：

输入：root = [1,null,3,2,4,null,5,6]
输出：[5,6,3,2,4,1]

示例 2：

输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[2,6,14,11,7,3,12,8,4,13,9,10,5,1]

 

提示：

    N 叉树的高度小于或等于 1000
    节点总数在范围 [0, 10^4] 内

*/
class Solution {
public:
    vector<int> postorder(Node* root) {
      vector<int> res;
      traverse(root, res);
      return res;
    }

    void traverse(Node* root, vector<int>& res)
    {
      if(!root)
        return;
      for(Node* cur : root->children)
      {
        traverse(cur, res);
      }
      res.push_back(root->val);
    }
};

/* 来个迭代的*/

class Solution {
public:
    vector<int> postorder(Node* root) {
      vector<int> res;
      if(!root)
        return res;
      stack<Node*> tmp;
      stack<int> res_s;
      tmp.push(root);
      while(!tmp.empty())
      {
        Node* cur = tmp.top();
        tmp.pop();
        res_s.push(cur->val);
        for(Node* node : cur->children)
        {
          tmp.push(node);
        }
      }
      while(!res_s.empty())
      {
        res.push_back(res_s.top());
        res_s.pop();
      }
      return res;
    }
};
/* 迭代总结：如果前序遍历，则用栈，逆序压栈，保证栈顶是先序遍历的顺序。
 * 同理，后序遍历，用栈，多一个中转的栈，保证结果栈的栈顶是后序遍历的顺序。*/
