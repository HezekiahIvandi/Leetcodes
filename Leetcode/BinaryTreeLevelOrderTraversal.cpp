#include <iostream>
#include <vector>
#include <unordered_map>
//#include <sstream>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <limits>
//#include <cctype> 
// Include any other headers you need
using namespace std;

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef unordered_map<int, int> umap;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x),left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

void levelTraverse(TreeNode* root, vector<vector<int>>& res, int depth = 0){
    if(root == nullptr) return;
    
    if (res.size() == depth) {
        res.push_back({});
    }
    levelTraverse(root->left, res, depth + 1);
    levelTraverse(root->right, res, depth + 1);
    res[depth].push_back(root->val);
}

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    levelTraverse(root, res);
    return res;
}


int main() {
    TreeNode first(1);
    TreeNode second(2);
    TreeNode third(3);
    TreeNode fourth(4);
    TreeNode fifth(5);

    first.left = &second;
    first.right = &third;

    second.left = &fourth;
    third.right = &fifth;

    vector<vector<int>> res = levelOrder(&first);
    
    for(int i = 0; i < res.size(); i++){
        cout << "Level "  << i << ": "<< endl;
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}