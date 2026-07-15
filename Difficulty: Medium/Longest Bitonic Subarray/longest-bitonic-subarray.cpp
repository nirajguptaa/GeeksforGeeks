class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>nextGreat(n,1);
        vector<int>prevGreat(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]){
                nextGreat[i]=nextGreat[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1]){
                prevGreat[i]=prevGreat[i+1]+1;
            }
        }
        int longestBitonic=0;
        for(int i=0;i<n;i++){
            longestBitonic=max(longestBitonic,nextGreat[i]+prevGreat[i]-1);
        }
        return longestBitonic;
    }
};