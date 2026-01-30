#include <iostream>
#include <vector>
using namespace std;
#include <queue>
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void inorderPrint(Node* root){
    if(root==nullptr){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
Node* insert(Node* root,int val){
    if(root==nullptr){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    return root;
}

Node* buildBst(vector<int> arr){
    Node* root=nullptr;
    for(int val:arr){
        root=insert(root,val);
    }
    return root;
}

// O(height) time complexity
bool search(Node* root,int key){
    if(root==nullptr){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key<root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}
Node* deletion(Node* root,int key){
    // base case
    if(root==nullptr){
        return root;
    }
    if(key<root->data){
        root->left=deletion(root->left,key);
    }else if(key>root->data){
        root->right=deletion(root->right,key);
    }else{
        // node found
        // case 1: no child
        if(root->left==nullptr && root->right==nullptr){
            return nullptr;
        }
        // case 2: one child
        if(root->left==nullptr){
            return root->right;
        }else if(root->right==nullptr){
            return root->left;
        }
        // case 3: two children
        Node* replace=root->right;
        while(replace->left!=nullptr){
            replace=replace->left;
        }
        root->data=replace->data;
        root->right=deletion(root->right,replace->data);
    }
    return root;
}
int main(){
    vector<int> arr ={3,2,3,5,6,1,4};
    Node* root=buildBst(arr);
    inorderPrint(root);
    cout<<endl;
    return 0;
}   