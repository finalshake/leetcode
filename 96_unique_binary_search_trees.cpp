/* 2021.03.18
 * leetcode: 96 不同的二叉搜索树
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 
 跟上一题一样，只是简单了，不用返回构建的树的数组了。*/

class Solution {
public:
    int numTrees(int n) {
      if(!n)
        return 0;
      return build(1, n);
    }

    int build(int l, int r)
    {
      if(l > r)
        //return 0;                        返回值就不能是0！ 一个子树是null也算一种情况。
        return 1;
      int ret = 0;                         //!!!初始化为0吧得
      for(int mid = l; mid <= r; mid++)
      {
        int leftTree = build(l, mid-1);
        int rightTree = build(mid+1, r);
        //if(leftTree == 0 || rightTree == 0)          不可能出现这种情况的
          //ret = leftTree + rightTree;
        ret += leftTree * rightTree;                   //！！！需要加号+
        //for(int i : leftTree)                 这样写会报错
          //for(int j : rightTree)
          //{
            //ret++;
          //}
      }
      return ret;
    }
};
// 这他妈还时间超限！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！输入19的时候。
