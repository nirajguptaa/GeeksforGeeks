class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int>mp(arr.begin(),arr.end());
        int maxlen=0;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                int len=1;
                int currNum=arr[i]+1;
                while(mp.find(currNum)!=mp.end()){
                    len++;
                    currNum++;
                }
                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }
};