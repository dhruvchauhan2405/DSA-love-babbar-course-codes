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

void findPreSuc(Node* root,Node* &pre,Node* &suc,int key){
    if(root==NULL){
        return;
    }

    while(root!=NULL){

        // if root is given key
        if(root->data ==key)
        {
            // the minimum value in right subtree is 
            // successor
            if(root->right){
                suc = root->right;
                while(suc->left){
                    suc =suc->left;
                }
            }

            // the maximum value in left subtree is
            // predessor
            if(root->left){
                pre = root->left;
                while(pre->right){
                    pre =pre->right;
                }
            }
            return;
        }
        // If the key is greater than root, then
        // key lies in right subtree. Root
        // could be predessor if left
        // subtree of key is null
        else if(root->data<key){
            pre = root;
            root = root->right;
        }

        // If the key is smaller than the root, then
        // key lies in left subtree. Root
        // could be successor if right subtree
        // key is null
        else{
            suc = root;
            root = root->left;
        }

    }
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

    int key;
    cout<<"Enter the value whose predessor and successor needs to be found"<<endl;
    cin>>key;

    Node* pre = NULL;
    Node* suc =NULL;
    findPreSuc(root,pre,suc,key);

    if(pre!= NULL)
        cout<<"Predessor is "<< pre->data <<endl;
    else
        cout<<"-1"<<endl;

    if(suc!= NULL)
        cout<<"Successor is "<< suc->data <<endl;
    else
        cout<<"-1"<<endl;

   return 0;
}