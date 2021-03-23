/* 2021.03.23
 * leetcode: 116 填充每个节点的下一个右侧节点指针
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

进阶：

    你只能使用常量级额外空间。
    使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

 

示例：

输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。

 

提示：

    树中节点的数量少于 4096
    -1000 <= node.val <= 1000

BFS简单啊，先用BFS写。*/
class Solution {
public:
    Node* connect(Node* root) {
      if(!root)
        return nullptr;
      queue<Node*> q;
      q.push(root);
      while(!q.empty())
      {
        int sz = q.size();
        Node* prev = nullptr;
        for(int i = 0; i < sz; i++)
        {
          Node* cur = q.front();
          q.pop();
          if(prev)
            prev->next = cur;
          if(cur->left)
          {
            q.push(cur->left);
          }
          if(cur->right)
            q.push(cur->right);
          prev = cur;
        }
      }
      return root;
    }
};

/* 用DFS,可以增加一个level的unordered_map,记录第n层最后一个元素，一旦后面再发现该层的新元素，立即指向它，并更新level的值。*/
class Solution {
public:
    unordered_map<int, Node*> level;
    Node* connect(Node* root) {
      if(!root)
        return nullptr;
      traverse(root, 0);
      return root;
    }

    void traverse(Node* root, int lvl)
    {
      if(!root)
        return ;
      if(level.count(lvl))
      {
        level[lvl] -> next = root;
      }
      level[lvl] = root;
      traverse(root->left, lvl+1);
      traverse(root->right, lvl+1);
    }
};
