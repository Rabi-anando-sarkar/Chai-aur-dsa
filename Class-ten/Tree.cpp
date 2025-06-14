#include <iostream>

using namespace std;

class TreeNode {
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int v) {
            value = v;
            left = nullptr;
            right = nullptr;
        }
};

class Tree {
    private:
        
    public:
        void preOrder(TreeNode* root) {
            if(root != nullptr) {
                cout << root->value << " ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }
        void inOrder(TreeNode* root) {
            if(root != nullptr) {
                preOrder(root->left);
                cout << root->value << " ";
                preOrder(root->right);
            }
        }
        void postOrder(TreeNode* root) {
            if(root != nullptr) {
                preOrder(root->left);
                preOrder(root->right);
                cout << root->value << " ";
            }
        }
};

int main() {
    // Level 0
    TreeNode* root = new TreeNode(10);

    // Level 1
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);

    // Level 2
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    Tree t;

    t.preOrder(root);
    cout << '\n';

    t.inOrder(root);
    cout << '\n';

    t.postOrder(root);

    return 0;
}