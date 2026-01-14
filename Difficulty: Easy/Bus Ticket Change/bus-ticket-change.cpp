class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int five=0,ten=0;
        for(auto it:arr){
            if(it==5){
                five++;
            }else if(it==10){
                if(five>0){
                    five-=1;
                    ten+=1;
                }else{
                    return false;
                }
            }else{
                if(ten>=1 && five>=1){
                    ten-=1;
                    five-=1;
                }else if(five>=3){
                    five-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};