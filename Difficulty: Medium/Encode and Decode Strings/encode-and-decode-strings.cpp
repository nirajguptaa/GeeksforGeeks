class Solution {
  public:
    string encode(vector<string>& arr) {
        // write your logic to encode the strings
        string total="";
        int n=arr.size();
        for(int i=0;i<n;i++){
            total+=arr[i];
            if(i+1!=n){
                total+="#";
            }
        }
        return total;
    }

    vector<string> decode(string& s) {
        // write your logic to decode the string
        vector<string>ans;
        int n=s.size();
        string curr="";
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                ans.push_back(curr);
                curr="";
                continue;
            }
            curr+=s[i];
        }
        ans.push_back(curr);
        return ans;
    }
};