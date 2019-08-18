// 根据前序遍历和中序遍历构建二叉树，并输出后序遍历
// UVA 536

#include <iostream>
#include <string>
using namespace std;

string pre_order, in_order;
int nodes_cnt;

struct Node {
    char val;
    Node *left, *right;
};

Node* buildTree(int pre_begin, int pre_end, int in_begin, int in_end) {
    if (pre_begin > pre_end || in_begin > in_end) {
        return nullptr;
    } else {
        Node* root = new Node;
        root->val = pre_order[pre_begin];
        int pos = -1;
        for (int i = in_begin; i <= in_end; ++i) {
            if (in_order[i] == pre_order[pre_begin]) {
                pos = i;
                break;
            }
        }
        int cnt = pos - in_begin;
        root->left = buildTree(pre_begin + 1, pre_begin + cnt, in_begin, pos - 1);
        root->right = buildTree(pre_begin + cnt + 1, pre_end, pos + 1, in_end);
        return root;
    }
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void post_order(Node* root) {
    if (root) {
        post_order(root->left);
        post_order(root->right);
        cout << root->val;
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> pre_order >> in_order) {
        nodes_cnt = pre_order.length();
        Node* root = buildTree(0, nodes_cnt - 1, 0, nodes_cnt - 1);
        post_order(root);
        cout << endl;
        deleteTree(root);
    }

    return 0;
}
