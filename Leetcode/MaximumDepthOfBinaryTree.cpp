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

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
}; 

int maxDepth(TreeNode* root, int depth = 1){

    if(root == nullptr) return depth-1;
    int deepestDepth = depth;
    deepestDepth = maxDepth(root->left, depth+1);
    deepestDepth = max(deepestDepth, maxDepth(root->right, depth+1));;

    deepestDepth = max(depth, deepestDepth);
    return deepestDepth;
}


int main() {
    TreeNode first(1);
    TreeNode second(1);
    TreeNode third(1);
    TreeNode fourth(1);

    first.left = &second;
    first.right = &third;
    
    second.left = &fourth;

    int res = maxDepth(&first);
    cout << "Res: " << res;
    return 0;
}