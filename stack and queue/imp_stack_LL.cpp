/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack {
  // Write your code here

private:
    Node* top; // Pointer to the top node of the stack
    int size;  // Variable to keep track of the size of the stack

public:
  Stack() {
    top = NULL;
    size = 0;
  }

  // Function to get the size of the stack
  int getSize() { return size; }

  // Function to check if the stack is empty
  bool isEmpty() { return top == NULL; }

  // Function to push an element onto the stack
  void push(int data) {
    Node *newNode = new Node(data); // Create a new node
    newNode->next = top;            // Link the new node to the current top
    top = newNode;                  // Update the top pointer
    size++;                         // Increment the size
  }

  // Function to pop the top element from the stack
  void pop() {
    if (isEmpty()) {
      return; // Do nothing if the stack is empty
    }
    Node *temp = top; // Store the current top
    top = top->next;  // Update the top pointer to the next node
    delete temp;      // Delete the old top node
    size--;           // Decrement the size
  }

  // Function to get the top element of the stack
  int getTop() {
    if (isEmpty()) {
      return -1; // Return -1 if the stack is empty
    }
    return top->data; // Return the data of the top node
  }
};