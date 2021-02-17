/* 2021.02.17
 * leetcode:104 二叉树最大深度
 * 给定一个二叉树，找出其最大深度。
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 这个题同样有两种思路，一是递归遍历，二是BFS迭代。
 * 先试下递归，大体思路是遇见null返回0, 遇见非null的返回1+func。
 * */

class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(!root)
        return 0;
      return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};

/* 明天再试第二种BFS方法吧，熬夜不好。
 * */
