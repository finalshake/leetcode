/* 2021.03.18
 * 中等难度啦！
 * leetcode: 95 不同的二叉搜索树II
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

 

示例：

输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 

提示：

    0 <= n <= 8

*/

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
      if(!n)
        return {nullptr};                       //!!!!!!!!!!注意函数的返回值，一定要是这个形式，不能直接是NULL！！！！！！！！
      return build(1, n);
    }

    vector<TreeNode*> build(int l, int r)
    {
      if(l > r)
        return {nullptr};
      vector<TreeNode*> ret;
      for(int mid = l; mid <= r; mid++)
      {
        vector<TreeNode*> leftTrees = build(l, mid-1);
        vector<TreeNode*> rightTrees = build(mid+1, r);
        for(TreeNode* lt : leftTrees)
          for(TreeNode* rt : rightTrees)
          {
            TreeNode* node = new TreeNode(mid);
            node->left = lt;
            node->right = rt;
            ret.push_back(node);
          }
      }
      return ret;
    }
};

/* 这个题难在如何返回多种结果上，看题解也没搞透彻。*/
