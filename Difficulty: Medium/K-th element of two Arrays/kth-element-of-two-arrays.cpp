class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1=a.size(),n2=b.size();
        if(n1>n2){
            return kthElement(b,a,k);
        }
        int l=max(0,k-n2);
        int h=min(n1,k);
        while(l<=h){
            int cut1=l+(h-l)/2;
            int cut2=k-cut1;
            int left1=cut1==0?INT_MIN:a[cut1-1];
            int left2=cut2==0?INT_MIN:b[cut2-1];
            int right1=cut1==n1?INT_MAX:a[cut1];
            int right2=cut2==n2?INT_MAX:b[cut2];
            if(left1<=right2 && left2<=right1){
                return max(left1,left2);
            }else if(left1>right2){
                h=cut1-1;
            }else{
                l=cut1+1;
            }
        }
        return 0;
        
    }
};