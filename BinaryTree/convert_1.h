// 根据中序遍历和后序遍历求出前序遍历
// 方法一：利用二叉查找树
// 二叉排序树的中序遍历一定是递增序列，后序遍历的逆序是树的构建顺序
// 洛谷P1030

#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

map<char, int> char2id;
int length;

struct Node {
    int val;
    Node *left_child, *right_child;
};

// 向二叉查找树中插入结点
void addNode(Node* node, int val) {
    if (val < node->val) {
        if (node->left_child) {
            addNode(node->left_child, val);
        } else {
            Node* temp = new Node;
            temp->val = val;
            temp->left_child = temp->right_child = nullptr;
            node->left_child = temp;
        }
    } else {
        if (node->right_child) {
            addNode(node->right_child, val);
        } else {
            Node* temp = new Node;
            temp->val = val;
            temp->left_child = temp->right_child = nullptr;
            node->right_child = temp;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    string in_order, post_order;
    cin >> in_order >> post_order;
    length = in_order.length();

    for (int i = 0; i < length; ++i) {
        char2id[in_order[i]] = i;
    }
    Node* root = new Node;
    root->val = char2id[post_order[length - 1]];
    root->left_child = root->right_child = nullptr;

    // 按后序遍历的逆序构建二叉查找树
    for (int i = length - 2; i >= 0; --i) {
        addNode(root, char2id[post_order[i]]);
    }

    // 前序遍历得出结果
    stack<Node *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        Node* node = nodes.top();
        nodes.pop();
        cout << in_order[node->val];
        if (node->right_child) {
            nodes.push(node->right_child);
        }
        if (node->left_child) {
            nodes.push(node->left_child);
        }
    }
    cout << endl;

    return 0;
}