#include <iostream>
#include <tree_node.cpp>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)


void solve(TreeNode* root) {
    
}

vector<vector<int>> ans;

void merge(vector<int>& work, vector<int>& a, vector<int>& b, int a_index, int b_index) {
    if(a.size() == a_index-1) {
        for(int i=b_index;i<b.size();i++) {
            work.push_back(b[i]);
        }
        return work;
    if(b.size() == b_index-1) {
        for(int i=a_index;i<a.size();i++) {
            work.push_back(a[i]);
        }
    }
    if(a.size() == a_index-1 || b.size() == b_index-1) {
        ans.push_back(work);
        return;
    }
    vector<int> a_cp(work.size());
    copy(work.begin(), work.end(), a_cp.begin()
    a_cp.push_back(a[a_index]);
    merge(work, a, b, a_index+1, b_index);
    vector<int> b_cp(work.size()+1);
    copy(work.begin(), work.end(), b_cp.begin();)
    b_cp.push_back(b[b_index]);
    merge(work, a, b, a_index, b_index+1);

}

int main() {
    vector<vector<int>> ans;

    return 0;
}