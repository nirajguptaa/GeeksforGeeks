class Solution {
  public:
    int findPosition(int n) {
        // code here
        
        int pos=0;
        bool multipleBits=false;
        int currPos=1;
        while(n>0){
            int r=n%2;
            if(r==1){
                if(multipleBits){
                    return -1;
                }else{
                    
                multipleBits=true;
                pos=currPos;
                }
                
            }
            currPos++;
            n/=2;
        }
        return pos==0?-1:pos;
    }
};