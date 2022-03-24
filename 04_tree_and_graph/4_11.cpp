#include <iostream>
#include <random>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

class TreeNode {
    private:

    public:
    int val;
    int size;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int val) : val(val), child_numbers(1), right(nullptr), left(nullptr) {};


// std::random_device rnd;     // 非決定的な乱数生成器を生成
//     std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
//     std::uniform_int_distribution<> rand100(0, 99);        // [0, 99] 範囲の一様乱数
//     for (int i = 0; i < 20; ++i) {
//         std::cout << rand100(mt) << "\n";
//     }
    void insertInOrder(int insert_val) {
        size++;
        if(insert_val < val) {
            if(left == nullptr) {
                left = TreeNode(insert_val);
            } else {
                left->insertInOrder(insert_val);
            }
        } else {
            if(right == nullptr) {
                right = newNode;
            } else {
                right->insertInOrder(insert_val);
            }
        }
    }

    TreeNode getRandom() {
        if(size == 1) return this;
        if(left == nullptr) return right->getRandom();
        if(right == nullptr) return left->getRandom();
        std::random_device rnd;
        std::mt19937 mt(rnd());
        std::uniform_int_distribution<> randSize(1, size);
        int rand_val = randSize(mt)
        if(rand_val == 1) return this;
        if(rand_val <= right->size) return right->getRandom();
        return left->getRandom();
    }

    void deleteInOrder(int val) {}

}
int main() {
    
    return 0;
}