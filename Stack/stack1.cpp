#include<iostream>
#include<climits>
using namespace std;
#define n 30
class stack{
    int* arr;
    int top;

    public:
    stack(){
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if(top==n-1){
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if(top==-1){
            cout << "stack is empty"<<endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if(top==-1){
            cout << "Stack is empty";
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top==-1;
    }


};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    //st.push(4);
    //st.pop();
    st.pop();
    cout << st.Top()<<endl;
    cout << st.empty()<<endl;
    return 0;
} 