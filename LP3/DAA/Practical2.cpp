
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// Structure to represent a node in Huffman Tree
struct HuffmanNode {
    char data;                  // Stores the character
    int frequency;              // Stores frequency of character
    HuffmanNode *left, *right;  // Pointers to left and right child

    // Constructor to initialize the node
    HuffmanNode(char data, int frequency) {
        left = right = nullptr;
        this->data = data;
        this->frequency = frequency;
    }
};

// Comparator to create Min Heap based on frequency
struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        // Node with smaller frequency gets higher priority
        return left->frequency > right->frequency;
    }
};

// Function to generate and print Huffman codes
void printCodes(HuffmanNode* root, string code,
                unordered_map<char, string>& huffmanCodes) {

    // If node is NULL, return
    if (!root)
        return;

    // Check whether the current node is a leaf node
    if (!root->left && !root->right) {

        // If only one unique character exists, assign code 0
        if(code == "")
            code = "0";

        // Store the Huffman code of the character
        huffmanCodes[root->data] = code;

        // Print character and its Huffman code
        cout << root->data << ": " << code << endl;
    }

    // Traverse left subtree and append 0 to the code
    printCodes(root->left, code + "0", huffmanCodes);

    // Traverse right subtree and append 1 to the code
    printCodes(root->right, code + "1", huffmanCodes);
}

// Function to build Huffman Tree and encode the text
void buildHuffmanTree(const string& text) {

    // Check if input string is empty
    if(text.empty()) {
        cout << "Empty input!";
        return;
    }

    // Step 1: Count frequency of each character
    unordered_map<char, int> frequencyMap;

    for(char ch : text) {
        frequencyMap[ch]++;
    }

    // Step 2: Create a Min Heap (Priority Queue)
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Step 3: Create a node for each character and insert into Min Heap
    for(auto pair : frequencyMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Step 4: Build Huffman Tree using Greedy Strategy
    while(pq.size() > 1) {

        // Extract the two nodes having minimum frequency
        HuffmanNode* left = pq.top();
        pq.pop();

        HuffmanNode* right = pq.top();
        pq.pop();

        // Create a new internal node with combined frequency
        HuffmanNode* newNode =
            new HuffmanNode('\0', left->frequency + right->frequency);

        // Make the two extracted nodes children of new node
        newNode->left = left;
        newNode->right = right;

        // Insert the new combined node back into Min Heap
        pq.push(newNode);
    }

    // Step 5: The remaining node becomes the root of Huffman Tree
    HuffmanNode* root = pq.top();

    // Step 6: Generate Huffman codes using tree traversal
    unordered_map<char, string> huffmanCodes;

    cout << "\nHuffman Codes:\n";
    printCodes(root, "", huffmanCodes);

    // Step 7: Encode the original text using generated Huffman codes
    cout << "\nEncoded string: ";

    for(char ch : text) {
        cout << huffmanCodes[ch];
    }

    cout << endl;
}

int main() {

    string text;

    // Accept input text from the user
    cout << "Enter text to encode using Huffman Encoding: ";
    getline(cin, text);

    // Call function to build tree and generate encoded string
    buildHuffmanTree(text);

    return 0;
}

//Overall Time Complexity:
//O(n+klog k+L)
//space o(k^2)
