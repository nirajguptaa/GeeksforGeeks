class Solution {
  public:
    bool canPlace(vector<int>&arr,int m,int k){
        int count=1;
        int last=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last>=m){
                count++;
                last=arr[i];
            }
            
        }
        return count>=k;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int l=1,h=arr[arr.size()-1];
        
        while(l<=h){
            int m=l+(h-l)/2;
            if(canPlace(arr,m,k)){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return h;
    }
};