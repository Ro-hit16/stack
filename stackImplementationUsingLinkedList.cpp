#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class node{
  public:
  int data;
  node* next;

  node(int val)
{
    this->data = val;
    this->next = NULL;
}
~node(){
    
}
};
class stack{
  public:
  node* top;
  stack(){
    top = NULL;
  }

  void push(int val){
    node* newnode = new node(val);
    if(top = NULL){
        top =newnode;
    }
    else{
        newnode->next = top;
        top =newnode;
    }
  }

  void pop(){
    if(top == NULL){
        cout<<"stack is empty"<<endl;
        return;
    }
    else{
        node* temp =  top;
        top =top->next;
        cout<<"poped data is "<<temp->data<<endl;
        delete temp;
    }
  }

 void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
  int peek(){
    if(top == NULL){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else{
        return top->data;
    }
  }
  bool empty(){
    return top == NULL;
       
   
  }
};
int main(){
stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.display();
     cout << "Top element is " << s.peek() << endl;

    s.pop();
    s.display();

    cout << "Top element is " << s.peek() << endl;

return 0;
}