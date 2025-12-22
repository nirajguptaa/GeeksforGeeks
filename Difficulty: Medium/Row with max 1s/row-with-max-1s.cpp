// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int rows=arr.size();
        int cols=arr[0].size();
        int ans=-1;
        int count=0;
        for(int i=0;i<rows;i++){
            int temp=0;
            for(int j=0;j<cols;j++){
                if(arr[i][j]==1){
                    temp+=1;
                }
            }
            if(temp>count){
                count=temp;
                ans=i;
            }
        }
        return ans;
        
    }
};