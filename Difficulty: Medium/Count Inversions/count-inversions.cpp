class Solution {
  public:
    int mergeCount(vector<int> &arr,int l,int m,int h){
        int i=l,j=m+1;
        vector<int>temp;
        int count=0;
        while(i<=m && j<=h){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
                count+=m-i+1;
            }
        }
        while(i<=m){
            temp.push_back(arr[i++]);
        }
        while(j<=h){
            temp.push_back(arr[j++]);
        }
        for(int k=l;k<=h;k++){
            arr[k]=temp[k-l];
        }
        return count;
    }
    int countInv(vector<int> &arr,int l,int h){
        int cnt=0;
        if(l<h){
            int m=l+(h-l)/2;
            cnt+=countInv(arr,l,m);
            cnt+=countInv(arr,m+1,h);
            cnt+=mergeCount(arr,l,m,h);
            
        }
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        return countInv(arr,0,n-1);
    }
};