// Question 3. Stacks and Time Complexity
//Design a stack that has the push, pop and min function (returns minimum element) such that these functions
// have O(1) time complexity.


#include <stack>
#include <iostream>

using namespace std;

class MinimumStack {
private:
    stack<int> s; // Main stack 
    stack<int> minStack; // Store minimum elements
public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if(s.empty()){
            throw ("It is already empty");}
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }

    int top() {
        if(s.empty()){
            throw ("It is already empty");}
        return s.top();
    }

    int getmin() {
        if(minStack.empty()){
            throw ("It is already empty");}
        return minStack.top();
    }
};

int main() {
    MinimumStack a;
    a.push(1);
    a.push(0);
    a.push(-3);
    cout << "Minimum: " << a.getmin() << endl;
    a.pop();
    return 0;
}
