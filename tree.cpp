#include <iostream>
using namespace std;

class TreeNode {
public:
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Tree {
public:
  TreeNode* root;
  Tree() {
    root = NULL;
  }
  void insert(int data) {
    TreeNode* node = new TreeNode(data);
    if (root == NULL) {
      root = node;
    } else {
      TreeNode* current = root;
      while (true) {
        if (data < current->data) {
          if (current->left == NULL) {
            current->left = node;
            break;
          } else {
            current = current->left;
          }
        } else {
          if (current->right == NULL) {
            current->right = node;
            break;
          } else {
            current = current->right;
          }
        }
      }
    }
  }
  void preorder(TreeNode* node) {
    if (node == NULL) {
      return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }
  void inorder(TreeNode* node) {
    if (node == NULL) {
      return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }
  void postorder(TreeNode* node) {
    if (node == NULL) {
      return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
  }
  void printMenu() {
    cout << "Enter 1 to insert, 2 to print preorder, 3 to print inorder, 4 to print postorder or 5 to exit: ";
  }
};

int main() {
  Tree tree;
  int choice = 0;
  while (choice != 5) {
    tree.printMenu();
    cin >> choice;
    switch (choice) {
      case 1: {
        int data;
        cout << "Enter a number to insert: ";
        cin >> data;
        tree.insert(data);
        break;
      }
      case 2: {
        cout << "Preorder traversal: ";
        tree.preorder(tree.root);
        cout << endl;
        break;
      }
      case 3: {
        cout << "Inorder traversal: ";
        tree.inorder(tree.root);
        cout << endl;
        break;
      }
      case 4: {
        cout << "Postorder traversal: ";
        tree.postorder(tree.root);
        cout << endl;
        break;
      }
      case 5: {
        cout << "Exiting program..." << endl;
        break;
      }
      default: {
        cout << "Invalid choice. Try again." << endl;
        break;
      }
    }
  }
  return 0;
}
