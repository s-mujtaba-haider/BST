#include <iostream>
using namespace std;

template <class T>
class BST {
public:
    class treeNode {
    public:
        T data;
        treeNode* left;
        treeNode* right;
        treeNode* parent;
        treeNode() {
            left = right = parent = nullptr;
        }
    };
    treeNode* root;
    BST() {
        root = nullptr;
    }
    treeNode* CreateNode(T val) {
        treeNode* temp = new treeNode();
        temp->data = val;
        temp->right = nullptr;
        temp->left = nullptr;
        temp->parent = nullptr;
        return temp;
    }
    treeNode* Insert(T val) {
        treeNode* ptr = CreateNode(val);
        if (root == nullptr) {
            root = ptr;
        }
        else {
            treeNode* temp = root;
            while (temp) {
                if (ptr->data < root->data) {
                    root = root->left;
                }
                else {
                    root = root->right;
                }
            }
            if (temp->data > ptr->data) {
                temp->left = ptr;
            }
            else {
                temp->right = ptr;
            }
            ptr->parent = temp;
        }
        return ptr;
    }
    void Print(treeNode* r) {
        if (r == NULL) {
            cout << "No Nodes." << endl;
        }
        else {
            cout << " -> " << r->data;
            Print(r->left);
            Print(r->right);
        }
    }
    void Display() {
        cout << "Data";
        Print(root);
    }
};
int main() {
    BST<int> l;
    l.Insert(1);
    l.Insert(4);
    l.Insert(9);
    l.Insert(5);
    l.Insert(2);
    l.Insert(7);
    l.Insert(3);
    l.Insert(6);
    l.Insert(8);
    cout << "Data";
    l.Display();
    cout << endl << endl;
}