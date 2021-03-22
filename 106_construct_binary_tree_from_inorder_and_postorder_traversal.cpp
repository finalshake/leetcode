/* 2021.03.22
 * leetcode: 106 从中序和后序遍历构造二叉树
 * 根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

思路与上一题大致相同，后序数组的结构是left-right-root,中序遍历数组的结构是left-root-right*/

class Solution {
public:
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      for(int i = 0; i < inorder.size(); i++)
      {
        index[inorder[i]] = i;
      }
      return build(inorder, postorder, 0, postorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int pl, int pr, int il, int ir)
    {
      if(pl > pr || il > ir)
        return nullptr;
      TreeNode* node = new TreeNode(postorder[pr]);
      int mid = index[postorder[pr]];
      node->left = build(inorder, postorder, pl, pl+mid-il-1, il, mid-1);
      node->right = build(inorder, postorder, pl+mid-il, pr-1, mid+1, ir);
      return node;
    }
};
