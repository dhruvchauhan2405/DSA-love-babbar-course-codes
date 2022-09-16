#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next; 
};

void Print(Node* head){
    if(head==NULL)
        return;
    else{
        cout<<head->data<<endl;
        Print(head->next);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    return 0;
}