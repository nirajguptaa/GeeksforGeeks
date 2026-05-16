class Solution {
  public:
    bool canPlaceCows(vector<int> &stalls, int k,int dist){
        int cows=1;
        int currpos=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-currpos>=dist){
                cows++;
                currpos=stalls[i];
            }
        }
        return cows>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int l=1;
        int n=stalls.size();
        int h=stalls[n-1];
        while(l<=h){
            int dist=l+(h-l)/2;
            if(canPlaceCows(stalls,k,dist)){
                l=dist+1;
            }else{
                h=dist-1;
            }
        }
        return h;
    }
};