class Solution {
  public:
//"Can we allocate books such that
// no student gets more than 'pages' pages?"
  bool tryToAllocate(vector<int> &arr, int k,int pages){
      int currPages=0;
      int student=1;//minimum students required
      for(int i=0;i<arr.size();i++){
          if(currPages+arr[i]<=pages){
              currPages+=arr[i];
          }else{
              student++;
              currPages=arr[i];
          }
      }
      return student<=k;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k){
            return -1;
        }
        int l=*max_element(arr.begin(),arr.end());
        int h=accumulate(arr.begin(),arr.end(),0);
        while(l<=h){
            int pages=l+(h-l)/2;
            if(tryToAllocate(arr,k,pages)){
                h=pages-1;
            }else{
                l=pages+1;
            }
        }
        return l;
    }
};