/* 2021.04.01
 * leetcode: 652 寻找重复的子树
 * 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4

下面是两个重复的子树：

      2
     /
    4

和

    4

因此，你需要以列表的形式返回上述重复子树的根结点。

* ***************************************************************************************************
* 序列化成string型，用哈希表计数，已经做过了。
* 尝试用tuple类型，make_tuple,为每个节点构造一个标识，给标识编号id，统计id出现的次数。*/

class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<int, int> count;
    int id = 0;
    //unordered_map<tuple<int,int,int>, int> mark;                       很奇怪，unordered_map不能用tuple做key,必须上map
    map<tuple<int,int,int>, int> mark;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      identify(root);
      return res;
    }

    int identify(TreeNode* root)
    {
      if(!root)
        return -1;
      auto t = make_tuple(root->val, identify(root->left), identify(root->right));
      if(!mark.count(t))
      {
        mark[t] = id++;
      }
      count[mark[t]]++;
      if(count[mark[t]] == 2)
      {
        res.push_back(root);
      }
      return mark[t];
    }
};
