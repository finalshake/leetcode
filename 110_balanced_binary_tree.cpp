/* 2021.02.20
 * 刷得还是不够快
 * 直接用力扣的面试模式试一试吧。
 *
 * leetcode: 110 平衡二叉树
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

 

示例 1：

输入：root = [3,9,20,null,null,15,7]
输出：true

示例 2：

输入：root = [1,2,2,3,3,null,null,4,4]
输出：false

示例 3：

输入：root = []
输出：true
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
      if(!root)
        return true;
      int min = INT_MAX;
      int max = 0;
      int depth = 1;
      if(!root->left || !root->right)
        min = 1;
      checkDepth(root, min, max, depth);
      return max - min <= 1;
    }

    void checkDepth(TreeNode* root, int &min, int &max, int depth)
    {
      if(!root->left && !root->right)
      {
        int x = depth;
        if(x < min)
          min = x;
        if(x > max)
          max = x;
        return;
      }
      //if(!root->left)
        //checkDepth(root->left, min, max, depth+1);
      //if(!root->right)
        //checkDepth(root->right, min, max, depth+1);
      /* 你怕不是个脑残吧，加！干蛋，debug了半天*/
      if(root->left)
        checkDepth(root->left, min, max, depth+1);
      if(root->right)
        checkDepth(root->right, min, max, depth+1);
    }
};

/* 还面试模式，大失败啊！！！！！
 * 以上思路就有问题，遇见[1,2,2,3,null,null,3,4,null,null,4]这样的也是不平衡的
 * 还的从平衡二叉树的定义入手。
 * 左右子树高不超过1, 子树的子树左右高不超过1。递归了懂不？*/


class Solution {
public:
    bool isBalanced(TreeNode* root) {
      if(!root)
        return true;
      int flag = 1;
      checkBalance(root, flag);
      return flag;
    }

    void checkBalance(TreeNode* root, int& flag)
    {
      if(abs(depth(root->left) - depth(root->right)) > 1)
        flag = 0;
      if(root->left)
        checkBalance(root->left, flag);
      if(root->right)
        checkBalance(root->right, flag);
    }
    int depth(TreeNode* root)
    {
      if(!root)
        return 0;

      return max(depth(root->left), depth(root->right)) + 1;
    }
};
/* 真他妈挫！时间复杂度上天。还在checkBalance函数返回bool型true上纠结半天。垃圾
 * 赶紧看官方解，加强此类型训练。*/
