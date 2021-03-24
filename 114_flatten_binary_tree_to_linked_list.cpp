/* 2021.03.23
 * leetcode: 114 二叉树展开为链表
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：

    展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
    展开后的单链表应该与二叉树 先序遍历 顺序相同。

 

示例 1：

输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]

示例 2：

输入：root = []
输出：[]

示例 3：

输入：root = [0]
输出：[0]

 

提示：

    树中结点数在范围 [0, 2000] 内
    -100 <= Node.val <= 100

已经用DFS做了一遍。再用BFS试一下*/
//思路不清晰，看了题解，明天再写。
//其实就是用个stack,入栈时先右后左。
class Solution {
public:
    void flatten(TreeNode* root) {
      if(!root)
        return;
      stack<TreeNode*> s;
      s.push(root);
      while(!s.empty())
      {
        TreeNode *cur = s.top();
        s.pop();
        if(cur->right)
          s.push(cur->right);
        if(cur->left)
          s.push(cur->left);
        cur->left = nullptr;
        if(!s.empty())
          cur->right = s.top();
      }
    }
};
