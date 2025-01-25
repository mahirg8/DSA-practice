/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* newNode = new QueueNode(x); // Create a new node
        if (rear == NULL) {
            front = rear = newNode; // If the queue is empty, both front and rear point to the new node
            return;
        }
        rear->next = newNode; // Link the new node to the rear of the queue
        rear = newNode;       // Update the rear to the new node
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code   
        if (front == NULL) {
            return -1; // If the queue is empty, return -1
        }
        int poppedData = front->data; // Retrieve the data from the front node
        QueueNode* temp = front;      // Store the current front node
        front = front->next;         // Move front to the next node
        if (front == NULL) {
            rear = NULL; // If the queue becomes empty, update rear to NULL
        }
        delete temp; // Delete the old front node
        return poppedData;
}