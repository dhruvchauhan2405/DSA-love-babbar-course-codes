#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            this->data = d;
            this->left =NULL;
            this->right =NULL;
        }


};

void inorder(Node* root){
    // base case
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    // base case
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    // base case
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){
            // purana level complete traverse
            cout<<endl;
            if(!q.empty()){
                // queue still has some child
                q.push(NULL);
            }
        }
        else{
            cout<< temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* &root, int d){
    // base case
    if(root ==NULL){
        root = new Node(d);
        return root;
    }

    if(d> root->data)
    {
        // right part me insert karna hai
        root->right = insertIntoBST(root->right,d);
    }
    else{
        // left me insert karna hai
        root->left = insertIntoBST(root->left,d);
    }
    return root;
} 

void takeInput(Node* &root){

    int data;
    cin>> data;

    while(data!= -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

Node* minVal(Node* root) {
    Node * temp = root;

    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root) {
    Node * temp = root;

    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

int main() {
   
    Node* root =NULL;

    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    cout<<"Printing Inorder"<<endl;
    inorder(root);

    cout<<endl<<"Printing Preorder"<<endl;
    preorder(root);

    cout<<endl<<"Printing Postorder"<<endl;
    postorder(root);

    cout<<endl<<"Minimum value is "<< minVal(root)->data<<endl;
    cout<<"Maximum value is "<< maxVal(root)->data<<endl;


   return 0;
}