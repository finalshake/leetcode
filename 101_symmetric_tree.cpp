/* Leetcode: 101 symmetric tree
 * Author: Finalshake
 * 很感谢东哥，给指点迷津，又借了本labuladong的算法小抄给我,告诉我刷刷力扣，有好处。可惜脱了一个月才开始正式刷题，书倒是看了两章。
 * 根据书中强烈推荐的方法，我打算先刷二叉树。昨天刷了100 Same tree, 就是普通的二叉树遍历问题，也就没在自己本地存解答程序。101这道
 * 题感觉就是100的翻版，只不过把一颗二叉树的左右两子树,一半先遍历左子树，一半先遍历右子树。
 * 这回可以试试递归之外的遍历方法，利用广度优先的思路遍历。
 *
 * */

//这个是用递归，先序遍历的解法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      if(root == nullptr)
        return true;
      return isSame(root->left, root->right);
    }
    bool isSame(TreeNode* left, TreeNode* right)
    {
      if(left == nullptr && right == nullptr)
        return true;
      else if(left == nullptr || right == nullptr)
        return false;
      else if(left->val != right->val)
        return false;
      return isSame(left->left, right->right) && isSame(left->right, right->left);
    }
};

//再试一下广度优先遍历
#include<queue>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      queue<TreeNode*> left;
      queue<TreeNode*> right;
      if(root == nullptr)
        return true;
      else if(root->left == nullptr && root->right == nullptr)
        return true;
      else if(root->left == nullptr || root->right == nullptr)
        return false;
      left.push(root->left);
      right.push(root->right);
      while(!left.empty() && !right.empty())
      {
        int sz = left.size();
        for(int i = 0; i < sz; i++)
        {
          TreeNode* lcur = left.front();
          TreeNode* rcur = right.front();
          left.pop();
          right.pop();
          if(lcur->val != rcur->val)
            return false;
          TreeNode* ll = lcur->left, *lr = lcur->right, *rl = rcur->left, *rr = rcur->right;
          if((ll == nullptr) ^ (rr == nullptr))
            return false;
          if((lr == nullptr) ^ (rl == nullptr))
            return false;
          if(lcur->left == nullptr && lcur->right == nullptr && rcur->left == nullptr && rcur->right == nullptr)
            continue;
          if(lcur->left != nullptr && rcur->right != nullptr)
          {
            left.push(lcur->left);
            right.push(rcur->right);
          }
          if(lcur->right != nullptr && rcur->left != nullptr)
          {
            left.push(lcur->right);
            right.push(rcur->left);
          }
        }

      }
      return true;
    }
};
/*我尼玛没想到BFS坑太大，浪费好多时间。
 * if判断一堆先是没搞清，异或运算一开始就没想到，也是醉了。
 * 还犯各种低级错误。
 * 之后要多用BFS
 * */

/* 心有不甘，看力扣官方给的BFS解答太简练了，
 * 重新写一个，只用一个队列。
 * */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      if(root == nullptr)
        return true;
      return isSame(root->left, root->right);
    }
    bool isSame(TreeNode* left, TreeNode* right)
    {
      if(!left && !right)
        return true;
      else if(!left || !right)
        return false;
      queue<TreeNode*> q;
      q.push(left);
      q.push(right);
      while(!q.empty())
      {
        TreeNode* lcur = q.front();
        q.pop();
        TreeNode* rcur = q.front();
        q.pop();
        if(!lcur->left ^ !rcur->right)
          return false;
        if(!lcur->right ^ !rcur->left)
          return false;
        if(lcur->val != rcur->val)
          return false;

        if(lcur->left)
          q.push(lcur->left);
        if(rcur->right)
          q.push(rcur->right);
        if(lcur->right)
          q.push(lcur->right);
        if(rcur->left)
          q.push(rcur->left);
      }
      return true;
    }
};


//再改
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      if(root == nullptr)
        return true;
      return isSame(root->left, root->right);
    }
    bool isSame(TreeNode* left, TreeNode* right)
    {
      queue<TreeNode*> q;
      q.push(left);
      q.push(right);
      while(!q.empty())
      {
        TreeNode* lcur = q.front();
        q.pop();
        TreeNode* rcur = q.front();
        q.pop();
        if(!lcur && !rcur)
          continue;
        if((!lcur || !rcur) || (lcur->val != rcur->val))
          return false;

        q.push(lcur->left);
        q.push(rcur->right);
        q.push(lcur->right);
        q.push(rcur->left);
      }
      return true;
    }
};
