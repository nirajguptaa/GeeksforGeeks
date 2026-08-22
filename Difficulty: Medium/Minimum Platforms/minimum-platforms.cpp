class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int count=1;
        int platformNeeded=1;
        int i=1,j=0;
        int n=arr.size();
        while(i<n && j<n){
            if(arr[i]>dep[j]){
                j++;
                count--;
                
            }else{
                i++;
                count++;
                platformNeeded=max(count,platformNeeded);
            }
        }
        return platformNeeded;
        
    }
};
