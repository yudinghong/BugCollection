#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

template <typename T>
struct TreeNode {
    T value;
    TreeNode<T> *lChild;
    TreeNode<T> *rChild;
};

template <typename T>
class BST {
public:
    BST() = default;
    void insert(T value[], int n) {
        
    }
    void insert(T value) {
        if (this->root == nullptr) {
            this->root = new TreeNode<T>();
            this->root->value = value;
            this->root->lChild = nullptr;
            this->root->rChild = nullptr;
        }
        else {
            TreeNode<T> *node = this->root;
            while (node != nullptr) {
                if (value > node->value) {
                    if (node->rChild == nullptr) {
                        node->rChild = this->createNode(value);
                        break;
                    }
                    else {
                        node = node->rChild;
                    }
                }
                else {
                    if (node->lChild == nullptr) {
                        node->lChild = this->createNode(value);
                        break;
                    }
                    else {
                        node = node->lChild;
                    }
                }
            }
        }
    }

    TreeNode<T>* createNode(T value) {
        TreeNode<T> *newNode = new TreeNode<T>();
        newNode->value = value;
        newNode->lChild = nullptr;
        newNode->rChild = nullptr;
        return newNode;
    }

    void prettyPrint() {
        
    }

private:
    int getLen(TreeNode<T> *node) {
        int lCount = getLen(node->lChild);
        int rCount = getLen(node->rChild);
        int max = lCount > rCount ? lCount : rCount;
        return max;
    }

private:
    TreeNode<T> *root = nullptr;
};

int main () {
    BST<int> bst;
    bst.insert(1);
    return 0;
}