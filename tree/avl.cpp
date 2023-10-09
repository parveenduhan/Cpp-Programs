#include <iostream>
#include <algorithm>

using namespace std;

class AVLNode {
public:
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    int get_height(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int get_balance_factor(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return get_height(node->left) - get_height(node->right);
    }

    AVLNode* right_rotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(get_height(y->left), get_height(y->right)) + 1;
        x->height = max(get_height(x->left), get_height(x->right)) + 1;

        return x;
    }

    AVLNode* left_rotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(get_height(x->left), get_height(x->right)) + 1;
        y->height = max(get_height(y->left), get_height(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, int key) {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;  // Duplicate keys not allowed

        node->height = max(get_height(node->left), get_height(node->right)) + 1;

        int balance = get_balance_factor(node);

        // Left-Left Case
        if (balance > 1 && key < node->left->key)
            return right_rotate(node);

        // Right-Right Case
        if (balance < -1 && key > node->right->key)
            return left_rotate(node);

        // Left-Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

        // Right-Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

    AVLNode* inorder_predecessor(AVLNode* node) {
        AVLNode* current = node->left;
        while (current->right != nullptr)
            current = current->right;
        return current;
    }

    AVLNode* delete_node(AVLNode* node, int key) {
        if (node == nullptr)
            return node;

        if (key < node->key)
            node->left = delete_node(node->left, key);
        else if (key > node->key)
            node->right = delete_node(node->right, key);
        else {
            // Node with one child or no child
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = (node->left) ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;  // Copy the contents of temp
                }
                delete temp;
            } else {
                // Node with two children: Get the inorder predecessor (largest in the left subtree)
                AVLNode* temp = inorder_predecessor(node);
                // Copy the inorder predecessor's data to this node
                node->key = temp->key;
                // Delete the inorder predecessor
                node->left = delete_node(node->left, temp->key);
            }
        }

        if (node == nullptr)
            return node;

        node->height = max(get_height(node->left), get_height(node->right)) + 1;

        int balance = get_balance_factor(node);

        // Left-Left Case
        if (balance > 1 && get_balance_factor(node->left) >= 0)
            return right_rotate(node);

        // Left-Right Case
        if (balance > 1 && get_balance_factor(node->left) < 0) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

        // Right-Right Case
        if (balance < -1 && get_balance_factor(node->right) <= 0)
            return left_rotate(node);

        // Right-Left Case
        if (balance < -1 && get_balance_factor(node->right) > 0) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = delete_node(root, key);
    }

    void inorder_traversal(AVLNode* node) {
        if (node == nullptr)
            return;
        inorder_traversal(node->left);
        cout << node->key << " ";
        inorder_traversal(node->right);
    }

    void print_inorder() {
        inorder_traversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avl;

    // Insertion
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "Inorder traversal after insertion: ";
    avl.print_inorder();

    // Deletion
    avl.remove(30);

    cout << "Inorder traversal after deletion: ";
    avl.print_inorder();

    return 0;
}
