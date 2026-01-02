class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int l=0,m=0,h=n-1;
        while(m<=h){
            if(arr[m]==0){
                swap(arr[l],arr[m]);
                l++;
                m++;
            }else if(arr[m]==1){
                m++;
            }else{
                swap(arr[h],arr[m]);
                h--;
            }
        }
    }
};