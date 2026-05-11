class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long actualSum=0;
        long long actualSq=0;
        for(int i=0;i<n;i++){
            actualSum+=arr[i];
            actualSq+=1LL*arr[i]*arr[i];
        }
        long long expectedSum=n*(n+1)/2;
        long long expectedSq=(n*(n+1)*(2*n+1))/6;
        long long val1=actualSum-expectedSum;
        long long val2=actualSq-expectedSq;
        val2/=val1;
        long long repeat=(val1+val2)/2;
        long long missing=val2-repeat;
        return {(int)repeat,(int)missing};
        
    }
};