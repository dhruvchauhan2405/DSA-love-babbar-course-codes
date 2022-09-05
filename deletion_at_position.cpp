#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;


    //Construstor
    Node (int data) {
        this ->data = data;
        this ->next = NULL;
    }

    // destructor
    ~Node() {
        int value = this->data;
        // memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data "<< value<<endl;
    }
};

void InsertAtHead (Node* &head, int d){


    //new node create
    Node* temp =new Node(d);
    temp ->next = head;
    head =  temp;
}

void InsertAtTail (Node* &tail, int d){


    //new node create
    Node* temp =new Node(d);
    tail ->next = temp;
    tail = tail->next;
}

void InsertAtPosition(Node* &tail,Node* &head,int position, int d){
    
    
    //Insert at Head
    if(position==1){
        InsertAtHead(head,d);
        return;
    }
    Node * temp = head;
    int cnt =1;

    

    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp -> next == NULL){
        InsertAtTail(tail,d);
        return;
    }

    //creating a node for d

    Node* NodetoInsert = new Node(d);

    NodetoInsert->next = temp->next;

    temp->next = NodetoInsert;


}

void Print(Node* &head){
     
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<< endl;


}

void deleteNode(int position, Node* &head){
    // position will be between 1 to len
    if (position==1)
    {   
        Node* temp = head;
        // Deleting first node
        head = head->next;
        // memory free start node
        temp->next = NULL;
        delete temp;

    }
    else{
        // Deleting middle or last node
        Node* curr =head;
        Node* prev = NULL;

        int cnt=1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main() {


   //created a new node
   Node* node1 = new Node(10);
   //cout<< node1 ->data<<endl;
   //cout<< node1 ->next<<endl;

   //head pointed to node1
   Node* head = node1;
   Node* tail = node1;
   
   Print(head);

   //Insert at head
   InsertAtTail(tail,12);

   Print(head);

   InsertAtTail(tail, 15);

   Print(head);

   InsertAtPosition(tail,head,3,22);
   InsertAtPosition(tail,head,1,14);
   Print(head); 

   cout <<"head "<< head->data<<endl;
   cout <<"tail "<< tail->data<<endl;

   deleteNode(1,head);
   Print(head);
   deleteNode(4,head);
   Print(head);
   return 0;
}