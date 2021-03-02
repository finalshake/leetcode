/* 2021.03.01
 * leetcode: 572 另一个树的子树
 * 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2

给定的树 t：

   4 
  / \
 1   2

返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0

给定的树 t：

   4
  / \
 1   2

返回 false。
*/

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
      bool ret = false;
      
      do_check(s, t, ret);
      return ret;
    }

    void do_check(TreeNode* root, TreeNode* sub, bool& ret)
    {
      if(!root)
        return;
      if(check(root, sub, ret))
        return;
      do_check(root->left, sub, ret);
      do_check(root->right, sub, ret);
    }
    bool check(TreeNode* s, TreeNode* t, bool& ret)
    {
      if(!s && !t)
        return true;
      else if(!s || !t)
      {
        ret = false;
        return false;
      }
      if(s->val != t->val || !check(s->left, t->left, ret) || !check(s->right, t->right, ret))
      {
        ret = false;
        return false;
      }
      ret = true;
      return true;
    }
};

/* 尼玛随便在网页上改吧改吧就对了。*/
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
      bool ret = false;
      
      do_check(s, t, ret);
      return ret;
    }

    void do_check(TreeNode* root, TreeNode* sub, bool& ret)
    {
      if(!root)
        return;
      if(check(root, sub))
        {ret = true;return;}
      do_check(root->left, sub, ret);
      do_check(root->right, sub, ret);
    }
    bool check(TreeNode* s, TreeNode* t)
    {
      bool res = true;
      if(!s && !t)
        return true;
      else if(!s || !t)
      {
        //ret = false;
        return false;
      }
      return (s->val == t->val && check(s->left, t->left) && check(s->right, t->right));
    }

};
