
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

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx]==-1){
        return nullptr;
    }
    Node* root = new Node(preorder[idx]);
    root->left=buildTree(preorder);
    root->right=buildTree(preorder);

    return root;
}

void preorderPrint(Node* root){
    if(root==nullptr){
        cout<<"-1 ";
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void postorderPrint(Node* root){
    if(root==nullptr){
        cout<<"-1 ";
        return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}

void inorderPrint(Node* root){
    if(root==nullptr){
        cout<<"-1 ";
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
 
void levelOrderPrint(Node* root){
    if(root==nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==nullptr){
            cout<<endl;
            if(!q.empty()){
                cout<< endl;
                q.push(nullptr);
                continue;
            }else{
                break;
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int height(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    return max(leftHeight,rightHeight)+1;
}

int countNodes(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftCount=countNodes(root->left);
    int rightCount=countNodes(root->right);
    return leftCount+rightCount+1;
}
int sumNodes(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftSum=sumNodes(root->left);
    int rightSum=sumNodes(root->right);
    return leftSum+rightSum+root->data;
}
int diameter(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftDiameter=diameter(root->left);
    int rightDiameter=diameter(root->right);
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    int currDiameter=leftHeight+rightHeight+1;
    return max(currDiameter,max(leftDiameter,rightDiameter));
}

int diameterOptimized(Node* root, int* height){
    if(root==nullptr){
        *height=0;
        return 0;
    }
    int lh=0, rh=0;
    int leftDiameter=diameterOptimized(root->left,&lh);
    int rightDiameter=diameterOptimized(root->right,&rh);
    *height=max(lh,rh)+1;
    int currDiameter=lh+rh+1;
    return max(currDiameter,max(leftDiameter,rightDiameter));
}

int main() {
   vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(preorder);
    cout << "Preorder Traversal: ";

    preorderPrint(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inorderPrint(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderPrint(root);
    cout << endl;
    
    cout << "Level Order Traversal: " << endl;
    levelOrderPrint(root);
}
// This program calculates the sum of numbers from 1 to a given positive integer using recursion.