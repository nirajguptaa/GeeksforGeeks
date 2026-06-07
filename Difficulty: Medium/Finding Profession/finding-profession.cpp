class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        int setBits=__builtin_popcount(pos-1);
        if(setBits%2==0){
            return "Engineer";
        }else{
            return "Doctor";
        }
    }
};