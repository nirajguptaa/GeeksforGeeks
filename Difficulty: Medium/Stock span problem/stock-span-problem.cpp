class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<pair<int,int>>st;
        int n=arr.size();
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<=arr[i]){
                st.pop();
            }
                
            if(st.empty()){
               ans[i]=i+1;
            }else{
                 ans[i]=i-st.top().second;
            }
                
            st.push({arr[i],i});
                
        }
        return ans;
    }
};