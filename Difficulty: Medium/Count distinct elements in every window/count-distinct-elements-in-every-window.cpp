class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int l=0,r=0,n=arr.size();
        unordered_map<int,int>freq;
        vector<int>ans;
        
        while(r<n){
            freq[arr[r]]++;
            r++;
            if(r-l==k){
                ans.push_back(freq.size());
                freq[arr[l]]--;
                if(freq[arr[l]]==0){
                    freq.erase(arr[l]);
                }
                l++;
            }
        }
        return ans;
        
    }
};