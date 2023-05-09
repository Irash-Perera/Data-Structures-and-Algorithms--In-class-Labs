#include <iostream>
#include <chrono>

using namespace std;

static int top=-1; //creating the index of the top elemnet
static const int stack_size=10; //setting the stack size
static int stack_arr[stack_size];


void push(int x){ //adding elements to the end of the stack
    top++;
    if (top>stack_size-1){
        cout<<"Stack-overflow"<<endl;
        top--;
    }
    else{
        stack_arr[top]=x;
    }
}

int pop(){ //removing elements from the end of the stack
    if(top>=0){
        top--;
        return stack_arr[top+1];
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}

void isEmpty(){ //checking whether stack is empty
    if(top==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
}

void isFull(){ //checking whether stack is full
    if(top==stack_size-1){
        cout<<"Stack is full"<<endl;
    }
    else{
        cout<<"Stack is not full"<<endl;
    }
}

void StackTop(){ //showing the top element
    cout<<stack_arr[top]<<endl;
}

void display(){ //printing the current stack
    for(int i=0;i<=top;i++){
        cout<<stack_arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    //start measuring execution time
    auto start = chrono::high_resolution_clock::now();
    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(4);
    push(30);
    push(3);
    push(1);
    display();
    //stop measuring excecution time
    auto end = chrono::high_resolution_clock::now();
    //print execution time
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nExecution time: " << duration.count() << " microseconds\n";

    return 0;
}