#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

vector<string> anagramSort(vector<string> words) {
    map<string, vector<string>> ma;
    for(string word : words) {
        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());
        ma[sorted_word].push_back(word);
    }
    vector<string> res;
    for(auto const& [key, val] : ma) {
        for(string v: val) {
            res.push_back(v);
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<string> words = {"res", "some", "ser", "sr", "soem"};
    words = anagramSort(words);
    for(string word : words) {
        cout << word << endl;
    }
    
    return 0;
}