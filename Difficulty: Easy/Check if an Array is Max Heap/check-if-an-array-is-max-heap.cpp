class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            int lc=2*i+1;
            int rc=2*i+2;
            if((lc<n && arr[lc]>arr[i])|| rc<n && arr[rc]>arr[i]){
                return false;
            }
            
        }
        return true;
    }
};
