#include <iostream>
#include <chrono>

using namespace std;

//creating Node class. Each Node has two values.
//Data(stored value) and the pointer to the next Node
class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data=x;
        next=NULL;
    }
};

class Stack{

    public:
    Node* top;
    Stack(){
        top=NULL;//creating empty stack
    }

    void push(int x){ // adding elements to begining of the linked list
        Node* newNode=new Node(x);
        newNode->next=top;
        top=newNode;
    }

    int pop(){ // removing elemnets from the begining of the linked list;
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
        }
        else{
            Node* temp=top;
            top=top->next;
            return temp->data;
            
        }
        
    }

    void display(){ //displaying the current stack
        Node* temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void isEmpty(){// checking whether the stack is empty
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Stack is not empty"<<endl;
        }
    }

    void StackTop(){ // showing the top elemnet
        Node* temp=top;
        cout<<temp->data<<endl;
    }
};


int main(){
    Stack s;
    //start measuring execution time
    auto start = chrono::high_resolution_clock::now();
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    //stop measuring excecution time
    auto end = chrono::high_resolution_clock::now();
    //print execution time
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nExecution time: " << duration.count() << " microseconds\n";

    return 0;

}