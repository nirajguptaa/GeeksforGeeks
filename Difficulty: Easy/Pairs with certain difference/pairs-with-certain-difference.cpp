class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end(),greater<int>());
        int ans=0;
        
        for(int i=0;i<arr.size();){
            if(i+1<arr.size() && (arr[i]-arr[i+1])<k){
                ans+=arr[i];
                ans+=arr[i+1];
                i+=2;
            }else{
                i++;
            }
        }
        return ans;
        
    }
};