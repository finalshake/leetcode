/* 2021.02.19
 * leetcode:108 将有序数组转换为二叉搜索树
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

 */
/* 你给我翻译翻译，什么他妈的是他妈的二叉搜索树？、
 * 百度一下：根节点的值大于其左子树中任意一个节点的值，小于其右节点中任意一节点的值，这一规则适用于二叉查找树中的每一个节点。
 * 那又如何构建二叉搜索树呢？用有序数组构建的话，我觉得就二分法查找中间值，先序递归构建。*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      TreeNode* res = new TreeNode();
      int left = 0, right = nums.size()-1;
      makeTree(res, left, right, nums);
      return res;
    }

    void makeTree(TreeNode* root, int left, int right, vector<int>& nums)
    {
      int mid = (left + right) / 2;
      root->val = nums[mid];
      int left_right = mid - 1, right_left = mid + 1; //草， 在-1 和+1 的问题上想了好久。 一开始left_right没有-1, 出bug了。
      if(left_right >= left)
      {
        TreeNode* lc = new TreeNode();
        root->left = lc;
        makeTree(lc, left, left_right, nums);
      }
      if(right_left <= right)
      {
        TreeNode* rc = new TreeNode();
        root->right = rc;
        makeTree(rc, right_left, right, nums);
      }
      /* 这一段if就没有人家官方题解写的简洁，太罗嗦。
       * left_right >= left和right_left <= right其实是一回事嘛*/
    }
};
