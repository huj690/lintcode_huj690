/*
Lowest Common Ancestor Show Result My Submissions

Given the root and two node in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

Example
        4

    /     \

  3         7

          /     \

        5         6

For 3 and 5, the LCA is 4.

For 5 and 6, the LCA is 7.

For 6 and 7, the LCA is 7.
*/

/*
解法一：暴力
如果A和B在root的两边, 则root就是要找的公共祖先
如果A和B在root的同一边，则顺着这边往下走
*/
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if (!root) {
            return NULL;
        }
        if (root == A || root == B) { //若A或者B有一个在root，则root就是要找的公共祖先
            return root;
        }
        bool isAonLeft = covers(root->left, A);
        bool isBonLeft = covers(root->left, B);
        
        if (isAonLeft != isBonLeft) { // 不在同一边
            return root;
        }
        auto childSide = isAonLeft ? root->left : root->right; //往那一边走
        return lowestCommonAncestor(childSide, A, B);
    }

private:
    bool covers(TreeNode *root, TreeNode *node) {
        if (root == NULL) {
            return false;
        }
        if (node == root) {
            return true;
        }
        return covers(root->left, node) || covers(root->right, node);
    }
};
