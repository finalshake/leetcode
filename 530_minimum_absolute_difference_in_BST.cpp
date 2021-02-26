/* 2021.02.26
 * leetcode: 530 二叉搜索树的最小绝对差
 * 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

 

示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。

 

提示：

    树中至少有 2 个节点。
    本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同

*/

/* 直接中序遍历，得到从小到大排列的数组，然后对比其中最小差值即可。*/
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
      if(!root)
        return 0;
      int res = INT_MAX;
      vector<int> tree;
      traverse(root, tree);
      for(int i = 1; i < tree.size(); i++)
      {
        int difference = abs(tree[i] - tree[i-1]) ;
        if(difference < res)
          res = difference;
      }
      return res;
    }

    void traverse(TreeNode* root, vector<int>& tree)
    {
      if(!root)
        return;
      traverse(root->left, tree);
      tree.push_back(root->val);
      traverse(root->right, tree);
    }
};
