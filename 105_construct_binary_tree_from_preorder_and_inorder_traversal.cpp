/* 2021.03.21
 * leetcode: 105 从前序与中序遍历序列构造二叉树
 * 根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

*/

class Solution {
public:
    int i = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return build(preorder, inorder);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& tmp)
    {
      if(i >= preorder.size() || tmp.empty())
        return nullptr;
      TreeNode* root = new TreeNode(preorder[i]);
      vector<int> left, right;
      int count = 0;
      while(tmp[count] != preorder[i])
      {
        left.push_back(tmp[count]);
        count++;
      }
      for(count = count+1; count < tmp.size(); count++)
      {
        right.push_back(tmp[count]);
      }
      i++;
      root->left = build(preorder, left);
      root->right = build(preorder, right);
      return root;
    }
};
/* 重新组成vector tmp效率低，可以优化一下，改用下标。*/
class Solution {
public:
    int i = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return build(preorder, inorder, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r)
    {
      if(i >= preorder.size() || l > r)
        return nullptr;
      TreeNode* root = new TreeNode(preorder[i]);
      int j;
      //for(j = 0; j < inorder.size(); j++)               还有更有效的做法，从l扫到r
      for(j = l; j <= r; j++)
      {
        if(inorder[j] == preorder[i])
          break;
      }
      int nr = j - 1;
      int nl = j + 1;
      i++;
      root->left = build(preorder, inorder, l, nr);
      root->right = build(preorder, inorder, nl, r);
      return root;
    }
};
