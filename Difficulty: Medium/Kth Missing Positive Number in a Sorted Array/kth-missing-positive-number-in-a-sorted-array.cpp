class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int count=0;
        int ans=1;
        int i=0;
        int n=arr.size();
        while(true){
            if(arr[i]==ans && i<n){
                i++;
                
            }else{
                count++;
                if(count==k){
                    return ans;
                }
            }
            ans++;
        }
       
        
    }
};