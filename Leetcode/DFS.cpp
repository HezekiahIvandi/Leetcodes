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



struct BinaryTree{
    int data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void dfs(BinaryTree* root){//recursively traversing
    if(root == nullptr) {
        return;
    };
    
    dfs(root->left);
    dfs(root->right);
    cout << root->data << endl; 
}

int main() {

    BinaryTree first(1);   // ROOT
    BinaryTree second(2);
    BinaryTree third(3);
    BinaryTree fourth(4);  // dfs
    BinaryTree fifth(5);
    BinaryTree sixth(6);
    BinaryTree seventh(7);

    first.left = &second;
    first.right = &third;

    second.left = &fourth;   
    second.right = &fifth;   

    third.left = &sixth;
    third.right = &seventh;
    
    cout << "Traversing DFS: "  << endl;
    dfs(&first);

    return 0;
}