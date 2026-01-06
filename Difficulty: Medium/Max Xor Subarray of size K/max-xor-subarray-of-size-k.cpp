class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int l=0,r=0;
        int maxi=0;
        int xorr=0;
        while(r<n){
            xorr=xorr^arr[r];
            r++;
            if(r-l==k){
                maxi=max(maxi,xorr);
                xorr^=arr[l];
                l++;
            }
            
        }
        return maxi;
    }
};