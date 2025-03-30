#include <bits/stdc++.h>

using namespace std;


class starr {
public: // Added public access specifier
    int top = -1;
    int st[10];

    int push(int x) {
        if (top >= 9) { // Check for stack overflow
            return -1; // Or handle the error appropriately
        }
        top += 1;
        st[top] = x;
        return x; // Return the pushed element, or a success code.
    }

    void pop() {
        if (top >= 0) { // Check for stack underflow
            top -= 1;
        }
        //Otherwise do nothing. or handle underflow error.
    }

    int size() { // Changed return type to int.
        return top + 1;
    }

    bool isEmpty() { // Added isEmpty function
        return top == -1;
    }

    int peek() { // Added peek function
      if(top >= 0){
        return st[top];
      }
      return -1; //Or handle the error appropriately.
    }
};

class q {
public: // Added public access specifier
    int size = 10;
    int qo[10]; // Changed qo[size] to qo[10] to avoid variable-length array issues
    int currents = 0; // Changed currents to 0 to represent the number of elements
    int start = 0; // Initialize start and end to 0 for an empty queue
    int end = 0;

    int push(int x) {
        if (currents == size) return 0; // Queue full
        qo[end] = x;
        end = (end + 1) % size;
        currents++;
        return 1; // Success
    }

    int pop() {
        if (currents == 0) return -1; // Queue empty (or some error code)
        int el = qo[start];
        start = (start + 1) % size;
        currents--;
        return el;
    }

    int top() {
        if (currents == 0) return -1; // Queue empty (or some error code)
        return qo[start];
    }

    int getSize() { // Renamed size() to getSize() to avoid conflict with size variable
        return currents;
    }

    bool isEmpty() {
      return currents == 0;
    }

    bool isFull(){
      return currents == size;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
