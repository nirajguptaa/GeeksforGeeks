class myStack {//last in first out
  public:
    vector<int>arr;
    int len;
    myStack(int n) {
        // Define Data Structures
        len=n;
    }

    bool isEmpty() {
        // check if the stack is empty
        return arr.size()==0;
        
    }

    bool isFull() {
        // check if the stack is full
        return arr.size()==len;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()){
            return ;
        }
        arr.push_back(x);
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()){
            return ;
        }
        arr.pop_back();
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty()){
            return -1;
        }
        int size=arr.size();
        return arr[size-1];
    }
};