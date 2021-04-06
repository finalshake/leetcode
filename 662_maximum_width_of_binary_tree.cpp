/* 2021.04.02
 * leetcode: 二叉树最大宽度
 * 给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。

示例 1:

输入: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

输出: 4
解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。

示例 2:

输入: 

          1
         /  
        3    
       / \       
      5   3     

输出: 2
解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。

示例 3:

输入: 

          1
         / \
        3   2 
       /        
      5      

输出: 2
解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。

示例 4:

输入: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
输出: 8
解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。

注意: 答案在32位有符号整数的表示范围内。

* ***************************************************************************************
* 想了半天，真的是半天！最终决定用BFS逐层遍历，遇到null也加入queue,最后统计每层宽度。*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if(!root)
        return 0;
      queue<TreeNode*> q;
      q.push(root);
      int max = 0;
      while(!q.empty())
      {
        int sz = q.size();
        bool out = true;
        vector<int> tmp;
        for(int i = 0; i < sz; i++)
        {
          TreeNode* cur = q.front();
          q.pop();
          if(!cur)
          {
            tmp.push_back(0);
            q.push(nullptr);
            q.push(nullptr);
          }
          else
          {
            out = false;
            tmp.push_back(1);
            q.push(cur->left);
            q.push(cur->right);
          }
        }
        if(out)
          break;
        int start = 0, end = tmp.size()-1;
        while(tmp[start] == 0)
          start++;
        while(tmp[end] == 0)
          end--;
        int length = end - start + 1;
        if(length > max)
          max = length;
      }
      return max;
    }
};
// 我尼玛竟然碰见一个大深度的树就执行超时了！
// 根据题解的提示，给每个节点编号，如果root编号是pos,则其左节点就是pos*2,右节点就是pos*2+1,我就是没想到。。。。。
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if(!root)
        return 0;
      int max = 0;
      unordered_map<TreeNode*, int> pos;
      pos[root] = 1;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        int sz = q.size();
        int l = INT_MAX, r = INT_MIN;
        for(int i = 0; i < sz; i++)
        {
          TreeNode* cur = q.front();
          q.pop();
          if(cur->left)
          {
            q.push(cur->left);
            pos[cur->left] = 2 * pos[cur];
          }
          if(cur->right)
          {
            q.push(cur->right);
            pos[cur->right] = 2 * pos[cur] + 1;
          }
          if(pos[cur] < l)
            l = pos[cur];
          if(pos[cur] > r)
            r = pos[cur];
          int tmp = r - l + 1;
          if(tmp > max)
            max = tmp;
        }
      }
      return max;
    }
};
// 又他妈溢出了，一旦层数一多就不行。。。。。。。。。。。。。。气炸了！！！
// 重新写一遍
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if(!root)
        return 0;
      int max = 0;
      unordered_map<TreeNode*, int> pos;
      pos[root] = 1;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        int sz = q.size(), L, R;
        int preventOverFlow = pos[q.back()];
        for(int i = 0; i < sz; i++)
        {
          TreeNode* cur = q.front();
          q.pop();
          if(cur->left)
          {
            q.push(cur->left);
            pos[cur->left] = 2 * pos[cur] - preventOverFlow;
          }
          if(cur->right)
          {
            q.push(cur->right);
            pos[cur->right] = 2 * pos[cur] + 1 - preventOverFlow;
          }
          if(i == 0)
            L = pos[cur];
          if(i == sz -1)
            R = pos[cur];
        }
        int tmp = R - L + 1;
        if(tmp > max)
          max = tmp;
      }
      return max;
    }
};
