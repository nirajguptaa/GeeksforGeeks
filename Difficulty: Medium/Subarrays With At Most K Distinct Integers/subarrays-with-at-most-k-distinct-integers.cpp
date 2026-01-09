class Solution {
  public:
  int atMostK(vector<int>& nums, int k){
        int l=0,r=0;
        int count=0;
        unordered_map<int,int>map;
        int n=nums.size();
        while(r<n){
            map[nums[r]]++;
            while(map.size()>k){
                map[nums[l]]--; 
                if(map[nums[l]]==0){
                    map.erase(nums[l]);
                }
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int countAtMostK(vector<int> &nums, int k) {
        // code here
        return atMostK(nums,k);
    }
};