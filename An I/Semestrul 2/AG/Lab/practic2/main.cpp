#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

using namespace std;

string str;
vector<string> codes;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char ch, int freq) : ch{ch }, freq{freq }, left{nullptr }, right{nullptr } {};
    Node(char ch, int freq, Node* left, Node* right) : ch{ch }, freq{freq }, left{left }, right{right } {};
};

auto compare = [](Node* n1, Node* n2) {
    return n1->freq > n2->freq;
};

Node* huffman_encode() {
    map<char, int> mp;
    for (auto c : str) {
        mp[c]++;
    }


    priority_queue<Node*, vector<Node*>, decltype(compare)> p(compare);

    for (auto n : mp) {
        Node* node = new Node(n.first, n.second);
        p.push(node);
    }

    while (p.size() >= 2) {
        Node* n1 = p.top();
        p.pop();
        Node* n2 = p.top();
        p.pop();
        int frecv = n1->freq + n2->freq;
        Node* rad = new Node('\0', frecv, n1, n2);
        p.push(rad);

    }

    return p.top();
}

void generate_code(Node* root, string code, map<char, string>& codes) {
    if (root->ch != '\0')
        codes[root->ch] = code;
    if (root->left != nullptr)
        generate_code(root->left, code + "0", codes);
    if (root->right != nullptr)
        generate_code(root->right, code + "1", codes);
}

string encoded_string(map<char, string>codes) {
    string gstr;
    for (auto c : str)
        gstr += codes[c];
    return gstr;
}


string huffman_decode(Node* node, string encoded) {
    Node* root = node;
    string decoded;
    for (auto c : encoded) {
        if (node->ch == '\0') {
            if (c == '1')
                node = node->right;
            else
                node = node->left;
        }
        else {
            decoded += node->ch;
            node = root;
            if (c == '1')
                node = node->right;
            else
                node = node->left;
        }
    }
    decoded += node->ch;
    return decoded;
}
void read() {
    std::ifstream in("input.txt");
    std::getline(in, str);
}

int main() {
    read();
    Node* rad = huffman_encode();
    map<char, string> codes;
    string code;
    cout << "Codes for every letter: \n";
    generate_code(rad, code, codes);
    for (auto c : codes)
        cout << c.first << ' ' << c.second << '\n';

    string encoded = encoded_string(codes);
    cout << "Full code: \n";
    cout << encoded << '\n';
    string decoded = huffman_decode(rad, encoded);
    cout << "Decoded: \n";
    cout << decoded << '\n';
    return 0;
}