#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return sum == root->val;
    }

    int remainingSum = sum - root->val;

    return hasPathSum(root->left, remainingSum) ||
           hasPathSum(root->right, remainingSum);
}

int main() {
    int rootVal;
    cin >> rootVal;

    if (rootVal == -1) {
        cout << "false";
        return 0;
    }

    TreeNode* root = new TreeNode(rootVal);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        if (rightVal != -1) {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }

    int targetSum;
    cin >> targetSum;

    cout << (hasPathSum(root, targetSum) ? "true" : "false");

    return 0;
}