class Solution {
  public:
    bool find(vector<int>&arr,int key){
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==key){
                return true;
            }else if(arr[mid]<key){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return false;
    }
    int binarySearchable(vector<int>& arr) {
        // code here
        int ans=0;
        for(int x:arr){
            if(find(arr,x)){
                ans++;
            }
        }
        return ans;
    }
};