#include <iostream>
#include <vector>
#include <unordered_map>
//#include <sstream>
//#include <string>
#include <algorithm>
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
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

int dfs(TreeNode *root, int& maxd , int depth = 0){
    if(root == nullptr) {
        maxd = max(depth, maxd);
        return;
    };

    depth += 1;
    dfs(root->left, maxd, depth);
    dfs(root->right,maxd, depth);
}

bool isBalanced(TreeNode *root){

    int leftMax = 0; int rightMax = 0;
    dfs(root->left, leftMax);
    dfs(root->right, rightMax);

    if(abs(leftMax-rightMax) > 1) return false;
    return true;
}

int main() {
    return 0;
}