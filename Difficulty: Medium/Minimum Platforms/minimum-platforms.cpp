class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int platformNeeded=1;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=1,j=0;
        int count=1;
        while(i<n && j<n){
            if(arr[i]>dep[j]){
                j++;
                count--;
            }else{
                count++;
                i++;
                platformNeeded=max(platformNeeded,count);
                
            }
        }
        return platformNeeded;
    }
};
