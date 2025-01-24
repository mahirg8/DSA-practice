// Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. The push() method takes one argument, an integer 'x' to be pushed into the stack and pop() which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.

// Note: The input is given in form of queries. Since there are two operations push() and pop(), there is two types of queries as described below:
// (i) 1 x   (a query of this type means  pushing 'x' into the stack)
// (ii) 2     (a query of this type means to pop an element from the stack and print the popped element)
// Input contains separated by space and as described above. 

// Examples :

// Input: 1 2 1 3 2 1 4 2 
// Output: 3, 4

void MyStack ::push(int x) {
    // Your Code
    if (top >= 999) return;
        arr[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    if (top < 0) {
            return -1; // Stack is empty
        }
        return arr[top--];
}