// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define rep(i,n) for(int i=0;i<n;i++)
// #define Rep(i,n) for(int i=1;i<=n;i++)
// #define ALL(v) v.begin(), v.end()
// const ll MOD = 1000000007;

// enum suit {
//     club = 1,
//     diamond = 2,
//     hears = 3,
//     spead = 4,

// };

// template <class T, class BaseClass>
// class deck {
//     public:
//         deck() : {}

//         void shuffle() {
//             current_index = 0;
//         }

//         template<typename T, typename std::enable_if<std::is_base_of<BaseClass, T>::value>::type* = nullptr>
//         T drow() {
//             if(!isAvailable()) return NULL;
//             T card = cards[current_index];
//             current_index++;
//             return card;
//         }

        
//     private:
//         int current_index = 0; /// position of top 

//         vector<T> cards(card_number);

//         int card_number = T.numbers();

//         bool isAvailable() {
//             return current_index < card_number; 
//         }
// };

// class card {
//     public:
//         virtual vector<card> generate_deck() {};
//         virtual int numbers() {};

//     private:
// };

// class trump : public card {
//     public:
//         virtual vector<trump> generate_deck() {
//             for(int i=1;i<14;i++) {
//                 for(int )
//             }
//         }
//         virtual int numbers() {
//             return 54;
//         }

//     private:
//         int number;
//         suit suit;
// };

// int main() {
//     cin.tie(0);
//     ios_base::sync_with_stdio(false);
    
//     return 0;
// }