class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        stack<int>st;
        int n=arr.size();
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
             while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            right[i]=st.empty()?n:st.top();
            st.push(i);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int len=right[i]-left[i]-1;
            ans[len-1]=max(ans[len-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        return ans;
    }
    
};