class Queue {
    // Define the data members(if any) here.
    private:
        stack<int> s1, s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if (s2.empty()) {
            // Transfer all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            return -1; // Queue is empty
        }
        int frontElement = s2.top();
        s2.pop();
        return frontElement;
    }

    int peek() {
        // Implement the peek() function here.
        if (s2.empty()) {
            // Transfer all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            return -1; // Queue is empty
        }
        return s2.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.empty() && s2.empty();
    }
};