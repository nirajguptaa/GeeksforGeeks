class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int l=0,h=n-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(arr[mid]>arr[h]){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        int pivot=l;
        int count=0;
        l=0,h=pivot-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]<=x){
                count=mid+1;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        
        l=pivot,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]<=x){
                count+=(mid-l+1);
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return count;
    }
};