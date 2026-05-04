class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string binary="";
        while(n>0){
            binary=char('0'+n%2)+binary;
            n/=2;
        }
        
        int left=0,right=binary.size()-1;
        while(left<right){
            if(binary[left]!=binary[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};