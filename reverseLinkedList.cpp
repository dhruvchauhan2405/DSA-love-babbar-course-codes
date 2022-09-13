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

Node* reverseLinkedList (Node* &head)
{
    if(head == NULL || head->next== NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;

    while( curr!= NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev= curr;
        curr= forward;
    }
    return prev;
}



int main() {


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


   head = reverseLinkedList(head);
   Print(head);
   
   return 0;
}