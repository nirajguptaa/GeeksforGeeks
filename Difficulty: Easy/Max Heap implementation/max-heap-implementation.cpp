class maxHeap {
  private:
    // Initialize your data members
    vector<int>mh;
  public:

    void push(int x) {
        // Insert x into the heap
        mh.push_back(x);
        int i=mh.size()-1;
        while(i>0){
            int parent=(i-1)/2;
            if(mh[i]>mh[parent]){
                swap(mh[i],mh[parent]);
                i=parent;
            }else{
                break;
            }
            
        }
    }

    void pop() {
        // Remove the top (maximum) element
        if(mh.empty())return;
        mh[0]=mh.back();
        mh.pop_back();
        int i=0,n=mh.size();
        while(true){
            int left=2*i+1;
            int right=2*i+2;
            int largest=i;
            if(left<n && mh[left]>mh[largest]){
                largest=left;
            }
            if(right <n && mh[right]>mh[largest]){
                largest=right;
            }
            if(i!=largest){
                swap(mh[i],mh[largest]);
                i=largest;
            }else{
                break;
            }
        }
        
    }

    int peek() {
        // Return the top element or -1 if empty
        if(mh.size()>0){
            return mh[0];
        }else{
            return -1;
        }
    }
    

    int size() {
        // Return the number of elements in the heap
        return mh.size();
    }
};