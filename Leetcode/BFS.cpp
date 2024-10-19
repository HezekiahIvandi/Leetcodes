#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

void BFS(TreeNode *root){
    queue<TreeNode*> q;

    if(root == nullptr) return;
    q.push(root);

    while(!q.empty()){
        TreeNode* current = q.front();
        cout << current->val << " ";
        q.pop();

        
        if(current->left != nullptr){
            q.push(current->left);
        }
        if(current->right != nullptr){
            q.push(current->right);
        }


    }

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

    BFS(&first);
    return 0;
}