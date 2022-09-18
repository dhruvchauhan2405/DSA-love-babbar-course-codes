#include <bits/stdc++.h>
#include <stack>
using namespace std;


class TwoStack{
    // properties
    public:
        int *arr;
        int top1;
        int top2;
        int size; 

    TwoStack(int size){
        this-> size= size;
        arr= new int [size];
        top1= -1;
        top2= size; 
    }

    void push1(int element){
        // atleast a empty space is prsent
        if(top2- top1 > 1){
            top1++;
            arr[top1] = element;
        }
        else{
            cout<<"Stack Overflow"<< endl;
        }
    }
    void push2(int element){
        // atleast a empty space is prsent
        if(top2- top1 > 1){
            top2--;
            arr[top2] = element;
        }
        else{
            cout<<"Stack Overflow"<< endl;
        }
    }

    int pop1() {
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;      

        }
        else{
            return -1;
        }
    }
    int pop2() {
        if(top2<size){
            int ans = arr[top2];
            top2++;
            return ans;      

        }
        else{
            return -1;
        }
    }

};

int main() {
   
   /*stack<int> s;
   s.push(2);
   s.push(3);
   s.pop();

   cout<< "Printing top element "<< s.top() <<endl;

   if(s.empty()){
    cout<< "Stack is empty "<<endl;
   }
   else{
    cout<<"Stack is not empty"<<endl;
   }
   */

  TwoStack st(5);

  st.push1(22);
  st.push2(43);
  st.push1(44);
  st.push2(22);
  st.push1(43);
  st.push2(44);
  

  st.pop1();
   return 0;
}