
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << "\n";
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffman(char chars[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++)
        pq.push(new Node(chars[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    printCodes(pq.top(), "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char chars[n];
    int freq[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter character and frequency: ";
        cin >> chars[i] >> freq[i];
    }

    cout << "Huffman Codes:\n";
    huffman(chars, freq, n);

    return 0;
}
