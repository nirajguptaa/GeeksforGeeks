class Solution {
  public:
    int maxProduct(int n) {
        // code here
        if(n<=3){
            return n-1;
        }
        int ans=1;
        
        while(n>3 && n!=4){
            n-=3;
            ans*=3;
        }
       
        return ans*n;
        
    }
};