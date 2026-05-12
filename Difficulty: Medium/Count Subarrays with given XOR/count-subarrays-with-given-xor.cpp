class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int count=0;
        int n=arr.size();
        int currXOR=0;
        unordered_map<int,int>seen;
        seen[0]=1;//important case
        for(int i=0;i<n;i++){
            
            currXOR^=arr[i];
            int remain=k^currXOR;
            if(seen.find(remain)!=seen.end()){
                count+=seen[remain];
            }
            seen[currXOR]++;
        }
        return count;
    }
};