/* 2021.02.04 22:47
 * leetcode: 617 合并二叉树
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7

注意: 合并必须从两个树的根节点开始。

*/
/* 这回用BFS来一次*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      TreeNode* res = new TreeNode();
      if(!root1 && !root2)
        return nullptr;
      queue<TreeNode*> q1;
      queue<TreeNode*> q2;
      queue<TreeNode*> result;
      q1.push(root1);
      q2.push(root2);
      while(!q1.empty() || !q2.empty())
      {
        TreeNode* cur1 = q1.front();
        q1.pop();
        TreeNode* cur2 = q2.front();
        q2.pop();
        if(!cur1 && !cur2)
        {
          result.front() = nullptr;
          result.pop();
          continue;
        }
        int tmp;
        if(!cur1)
          tmp = cur2->val;
        else if(!cur2)
          tmp = cur1->val;
        else
          tmp = cur1->val + cur2->val;
        result.push(TreeNode(tmp));
        if(cur1)
        {
          q1.push(cur1->left);
          q1.push(cur1->right);
        }
        else 
        {
          q1.push(nullptr);
          q1.push(nullptr);
        }
        if(cur2)
        {
          q2.push(cur2->left);
          q2.push(cur2->right);
        }
        else
        {
          q2.push(nullptr);
          q2.push(nullptr);
        }
        TreeNode* left = new TreeNode();
        TreeNode* right = new TreeNode();
        result.front()->left = left;
        result.front()->right = right;
        result.pop();
        result.push(left);
        result.push(right);
      }
      return res;
    }
};
/* 以上程序可以称为屎山，又臭又长
 * 重新梳理来一个。*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      TreeNode* res = new TreeNode();
      if(!root1 && !root2)
        return nullptr;
      queue<TreeNode*> q;
      queue<TreeNode*> result;
      q.push(root1);
      q.push(root2);
      result.push(res);
      while(!q.empty())
      {
        TreeNode* cur1 = q.front();
        q.pop();
        TreeNode* cur2 = q.front();
        q.pop();
        if(!cur1 && !cur2)
          continue;
        if(cur1 && cur2)
        {
          int tmp = cur1->val + cur2->val;
          TreeNode* cur = result.front();
          cur->val = tmp;
          result.pop();
          if(cur1->left || cur2->left)
          {
            q.push(cur1->left);
            q.push(cur2->left);
            cur->left = new TreeNode();
            result.push(cur->left);
          }
          if(cur1->right || cur2->right)
          {
            q.push(cur1->right);
            q.push(cur2->right);
            cur->right = new TreeNode();
            result.push(cur->right);
          }
        }
        else if(cur1 || cur2)
        {
          int tmp = cur1 ? cur1->val : cur2->val;
          TreeNode* cur = result.front();
          cur->val = tmp;
          result.pop();
          TreeNode* now = cur1 ? cur1 : cur2;
          if(now->left)
          {
            q.push(now->left);
            q.push(nullptr);
            cur->left = new TreeNode();
            result.push(cur->left);
          }
          if(now->right)
          {
            q.push(now->right);
            q.push(nullptr);
            cur->right = new TreeNode();
            result.push(cur->right);
          }
        }
      }
      return res;
    }
};
