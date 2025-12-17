class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        vector<int>odd;
        vector<int>even;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                even.push_back(arr[i]);
            }else{
                odd.push_back(arr[i]);
            }
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        
        int k=0;
        for(int i=odd.size()-1;i>=0;i--){
            arr[k++]=odd[i];
        }
        
        for(int i=0;i<even.size();i++){
            arr[k++]=even[i];
        }
        
        
    }
};