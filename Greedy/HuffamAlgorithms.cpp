#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

/* Node of Huffman Tree */
struct Node {
    char ch;          // character
    int freq;         // frequency
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

/* Comparator for min heap */
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq; // smaller freq has higher priority
    }
};

/* Print Huffman Codes */
void printCodes(Node* root, string code) {
    if (!root) return;

    // If leaf node (actual character)
    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char ch;
    int freq;

    priority_queue<Node*, vector<Node*>, compare> pq;

    // Input characters and frequencies
    for (int i = 0; i < n; i++) {
        cin >> ch >> freq;
        pq.push(new Node(ch, freq));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* x = pq.top(); pq.pop();   // Extract-Min
        Node* y = pq.top(); pq.pop();   // Extract-Min

        Node* z = new Node('$', x->freq + y->freq);
        z->left = x;
        z->right = y;

        pq.push(z); // Insert(Q, z)
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    cout << "Huffman Codes:\n";
    printCodes(root, "");

    return 0;
}
