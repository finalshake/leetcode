/* 2021.03.24
 * leetcode: 199 二叉树的右视图
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

* **********************************************************************************************
*
* 使用BFS层序遍历二叉树，将每层最右的数放入结果数组，这是最容易的方法。
* 如果想用DFS,我还得考虑考虑。。。。。*/

// ok,看了题解，可以先遍历root的右子树，每层第一个出现的节点就是结果，放入数组中。
class Solution {
public:
    vector<int> ret;
    unordered_map<int, int> res;
    vector<int> rightSideView(TreeNode* root) {
      if(!root)
        return ret;
      traverse(root, 0);
      for(int i = 0; i < res.size(); i++)
        ret.push_back(res[i]);
      return ret;
    }

    void traverse(TreeNode* root, int depth)
    {
      if(!root)
        return ;
      if(!res.count(depth))
        res[depth] = root->val;
      traverse(root->right, depth+1);
      traverse(root->left, depth+1);
    }
};

// 我靠了，时间和空间都排后面去了，这帮b都咋弄的。
// 稍作改动
class Solution {
public:
    vector<int> ret;
    vector<int> rightSideView(TreeNode* root) {
      if(!root)
        return ret;
      traverse(root, 0);
      return ret;
    }

    void traverse(TreeNode* root, int depth)
    {
      if(!root)
        return ;
      if(depth == ret.size())
        ret.push_back(root->val);
      traverse(root->right, depth+1);
      traverse(root->left, depth+1);
    }
};
