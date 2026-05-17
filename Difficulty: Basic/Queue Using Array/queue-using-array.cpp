class myQueue {

  public:
  vector<int>Arr;
  int len;
    myQueue(int n) {//first in first out
        // Define Data Structures
        len=n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return Arr.size()==0;
    }

    bool isFull() {
        // check if the queue is full
        return Arr.size()==len;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()){
            return ;
        }
        Arr.push_back(x);
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()){
            return ;
        }
        Arr.erase(Arr.begin());
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()){
            return -1;
        }
        return Arr[0];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()){
            return -1;
        }
        return Arr[Arr.size()-1];
    }
    
};


// 1 x : Call enqueue(x)
// 2: Call dequeue()
// 3: Call getFront()
// 4: Call getRear()
// 5: Call isEmpty()
// 6: Call isFull()