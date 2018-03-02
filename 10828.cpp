#include <iostream>
#include <vector>

using namespace std;

class Stack{
    vector<int> stack;
    public:
        void push(int x);
        int pop();
        int size();
        bool empty();
        int top();
    Stack(vector<int> _stack){
        stack = _stack;
    }
};

void Stack::push(int x){
    stack.push_back(x);    
}

int Stack::pop(){
    if (stack.empty()) return -1;
    int last = stack[stack.size()-1];
    stack.pop_back();
    return last;
}

int Stack::size(){
    return stack.size();
}

bool Stack::empty(){
    return stack.empty();
}

int Stack::top(){
    if (stack.empty())  return -1;
    return stack[stack.size()-1];
}

int main(){
    int ins=0;
    cin >> ins;
    vector<int> stack;
    Stack ex_stack(stack);
    for(int i = 0; i < ins; i++){
        string fun;
        int arg;
        cin >> fun;
        if(fun.compare("push") == 0){
            cin >> arg;
            ex_stack.push(arg);
        }
        else if(fun.compare("pop")==0){
            cout << ex_stack.pop() <<endl;
        }
        else if(fun.compare("empty")==0){
            cout << ex_stack.empty()<<endl;
        }
        else if(fun.compare("size")==0){
            cout << ex_stack.size()<<endl;
        }
        else if(fun.compare("top")==0){
            cout << ex_stack.top()<<endl;
        }
    }
    return 0;
}