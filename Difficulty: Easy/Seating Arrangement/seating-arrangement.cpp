class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n=seats.size();
        for(int i=0;i<n;i++){
            if(i==0 && seats[i+1]==0 && seats[i]==0 && k>0){
                seats[i]=1;
                k--;
            }
            if(k>0 && i>0 && i+1<n && seats[i]==0 &&  seats[i-1]==0 && seats[i+1]==0){
                seats[i]=1;
                k--;
            }
            if(k>0 && i==n-1 && seats[i]==0 && seats[i-1]==0){
                seats[i]=1;
                k--;
            }
        }
        return k==0;
    }
};