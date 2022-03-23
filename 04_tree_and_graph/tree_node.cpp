#include <iostream>
#include <vector>

using namespace std;

struct BinaryNode {
    int val;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(int val) : val(val), left(nullptr), right(nullptr) {};
    BinaryNode(int val, BinaryNode* left, BinaryNode* right) : val(val), left(left), right(right) {};
};


BinaryNode* create_binary_tree(vector<int>& x, int left, int right) {
    if(left > right) return nullptr;
    int mid = (left + right) / 2;
    int val = x[mid];

    BinaryNode* leftNode = create_binary_tree(x, left, mid-1);
    BinaryNode* rightNode = create_binary_tree(x, mid+1, right);
    
    return new BinaryNode(val, leftNode, rightNode);
}
BinaryNode* fromVector(vector<int>& vector) {
    return create_binary_tree(vector, 0, vector.size()-1);
}