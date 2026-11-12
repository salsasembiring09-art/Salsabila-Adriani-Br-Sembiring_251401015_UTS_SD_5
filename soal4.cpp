#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->data) root->left  = insert(root->left, v);
    else                root->right = insert(root->right, v);
    return root;
}

void postOrder(Node* r) {
    if (!r) return;
    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << " ";
}

int main() {
    Node* root = nullptr;
    int x;
    while (cin >> x && x != 0)      
        root = insert(root, x);

    cout << "Post-Order : ";
    postOrder(root);
    cout << "\n";

    if (root) {
        Node* t = root;
        while (t->right) t = t->right;   
        cout << "Nilai terbesar : " << t->data << "\n";
        cout << "Root : " << root->data << "\n";
    } else {
        cout << "Tree kosong\n";
    }
    return 0;
}