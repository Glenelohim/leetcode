class Queue {
    stack<int> myqueue;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> temp;
        while (!myqueue.empty())
        {
            temp.push(myqueue.top());
            myqueue.pop();
        }
        myqueue.push(x);
        while (!temp.empty())
        {
            myqueue.push(temp.top());
            temp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        myqueue.pop();
    }

    // Get the front element.
    int peek(void) {
        return myqueue.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return myqueue.empty();
    }
};