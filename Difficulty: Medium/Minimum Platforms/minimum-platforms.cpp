class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int platformNeed=1;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int a=1,d=0,n=arr.size();
        int count=1;
        while(a<n && d<n){
            if(arr[a]>dep[d]){
                count--;
                d++;
            }else{
                count++;;
                a++;
                platformNeed=max(count,platformNeed);
            }
        }
        return platformNeed;
    }
};
