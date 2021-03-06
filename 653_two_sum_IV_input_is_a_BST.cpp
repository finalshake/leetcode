/* 2021.03.05
 * leetcode: 653 两数之和-输入BST
 * 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:

输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

输出: True

 

案例 2:

输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

输出: False

*/
/* 目前只想到了一种思路：后序遍历BST得到从小到大排列的数组，再用二分查找法找结果。*/
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
      if(!root)
        return false;
      vector<int> tree;
      traverse(root, tree);
      int left = 0, right = tree.size()-1;
      while(left < right)
      {
        int mid = left + (right - left) / 2;
        if(mid == left || mid == right)
        {
          if(tree[left] + tree[right] == k)
            return true;
          else
            return false;
        }
        if()                                             //写到这块傻眼了吧，[1 3 5 6 9]里面找7,用mid怎么都找不到吧。所以不应该是二分，而是双指针。
      }
    }

    void traverse(TreeNode* root, vector<int>& tree)
    {
      if(!root)
        return;
      traverse(root->left);
      traverse(root->right);
      tree.push_back(root->val);
    }
};
/* 重新写吧*/
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
      if(!root)
        return false;
      vector<int> tree;
      traverse(root, tree);
      int left = 0, right = tree.size()-1;
      while(left < right)
      {
        //if(tree[left] + tree[right] == k)
          //return true;
        //if(tree[left] + tree[right] < k)
          //left++;
        //if(tree[left] + tree[right] > k)
          //right--;
        /* 直接用tree索引相加不好，因为left和right在随时改变，下个if就变了*/
        int sum = tree[left] + tree[right];
        if(sum == k)
          return true;
        else if(sum > k)
          right--;
        else if(sum < k)
          left++;
      }
      return false;
    }

    /* 应该是中序遍历大哥，你秀逗了？*/
    void traverse(TreeNode* root, vector<int>& tree)
    {
      if(!root)
        return;
      traverse(root->left, tree);
      tree.push_back(root->val);
      traverse(root->right, tree);
    }
};
/* 官方题解中用hashset的解法适用于所有二叉树的两数之和问题。可以参考。*/
