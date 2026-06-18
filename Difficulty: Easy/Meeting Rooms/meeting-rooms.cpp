class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        int last=arr[0][1];
        for(int i=1;i<arr.size();i++){
            int s=arr[i][0];
            int e=arr[i][1];
            if(last>s){
                return false;
            }
            last=max(last,e);
        }
        return true;
    }
};