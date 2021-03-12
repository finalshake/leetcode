/* 2021.03.09
 * leetcode: 897 递增顺序查找树
 * 给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

 

示例 ：

输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  

 

提示：

    给定树中的结点数介于 1 和 100 之间。
    每个结点都有一个从 0 到 1000 范围内的唯一整数值。

*/
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
      TreeNode* start, *prev = nullptr;
      if(!root)
        return nullptr;
      traverse(root, prev, start);
      return start;
    }

    void traverse(TreeNode* root, TreeNode* prev, TreeNode*& start)
    {
      if(!root)
        return;
      traverse(root->left, prev, start);
      if(!prev)
      {
        start = root;
        prev = root;
      }
      else
      {
        prev->right = root;
        prev = root;
      }
      traverse(root->right, prev, start);
    }
};

/* 经历了几次失败，stackoverflow,终于找到原因，因为老节点的左子树指针没有改变为null,互相乱指*/
class Solution {
public:
    TreeNode* start;
    TreeNode* increasingBST(TreeNode* root) {
      TreeNode *prev = nullptr;
      if(!root)
        return nullptr;
      traverse(root, prev);
      return start;
    }

    void traverse(TreeNode* root, TreeNode*& prev)
    {
      if(!root)
      {
        if(prev)
          prev->left = nullptr;       //重要！防止最后一个子树：只有左子树，右子树为空，比如[2,1,4,null,null,3]
        return;
      }
      traverse(root->left, prev);
      if(!prev)
      {
        start = root;
        prev = root;
      }
      else
      {
        prev->right = root;
        prev->left = nullptr;          //重要！之前就没加这句，导致原节点左指针存在，乱指。
        prev = root;
      }
      traverse(root->right, prev);
    }

};
