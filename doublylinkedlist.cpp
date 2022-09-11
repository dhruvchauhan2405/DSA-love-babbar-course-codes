#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int d){
        this->data =d;
        this->prev =NULL;
        this->next =NULL;
    }

    ~Node() {
        int val = this->data;
        if(next != NULL) {
            delete next;
            next= NULL;
        }
        cout<<"memory free for node with data "<< val<<endl;
    }
};

// traversing a doubly linked list
void print(Node* head){
    Node* temp = head;

    while(temp !=NULL)
    {
        cout<< temp->data<< " ";
        temp = temp->next;
    }
    cout<<endl;
}

// Length of linked list
int getLength(Node* head){
    int len =0;

    Node* temp = head;
    while(temp !=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;

}

void insertAtHead(Node* &head, Node* &tail, int d){
    
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail =temp;
    }
    else{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
    
}

void insertAtTail(Node* &tail,Node* &head, int d){
     if(tail == NULL)
     {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
     }
     else{
     Node* temp = new Node(d);
     tail->next = temp;
     temp->prev = tail;
     tail= temp;
     }
}

void insertAtPosition(Node* &tail,Node* &head, int position, int d) {

    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }

    Node * temp = head;
    int cnt =1;

    

    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail,head,d);
        return;
    }

    //creating a node for d

    Node* NodetoInsert = new Node(d);

    NodetoInsert->next = temp->next;
    NodetoInsert->prev = temp;
    (temp->next)->prev = NodetoInsert;
    temp->next = NodetoInsert;
}

void deleteNode(int position, Node* &head){
    // position will be between 1 to len
    if (position==1)
    {   
        Node* temp = head;
        temp -> next -> prev= NULL;
        head = temp -> next;
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
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {
   
//    Node* node1 = new Node(10);
   Node* head = NULL;
   Node* tail = NULL;
   
   print(head);
//    cout<< getLength(head)<<endl;

//    insertAtHead(head,11);
//    insertAtHead(head,12);
//    insertAtHead(head,13);
   print(head);

   insertAtTail(tail,head,13);
   print(head);
   insertAtTail(tail,head,14);
   print(head);
   insertAtTail(tail,head,15);
   print(head);
   insertAtPosition(tail,head,4,20);
   print(head);

   deleteNode(3,head);
   print(head);
   
   return 0;
}