class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i=0,j=0;
        int n=a.size(),m=b.size();
        int count=0;
        int ans=-1;
        while(i<n && j<m && count<k){
            
            if(a[i]<=b[j]){
                ans=a[i];
                i++;
            }else{
                ans=b[j];
                j++;
            }
            count++;
        }
        while(i<n && count<k){
            ans=a[i];
            count++;
            i++;
        }
        while(j<m && count<k){
            ans=b[j];
            count++;
            j++;
        }
        
        return ans;
    }
};