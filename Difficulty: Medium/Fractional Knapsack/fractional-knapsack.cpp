class Solution {
  public:
    bool static compare(pair<int,int>a,pair<int,int>b){
        double r1=(double)a.first/a.second;
        double r2=(double)b.first/b.second;
        return r1>r2;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>>ele;
        for(int i=0;i<val.size();i++){
            ele.push_back({val[i],wt[i]});
        }
        sort(ele.begin(),ele.end(),compare);
        double total=0.0;
        int totalwt=0;
        for(int i=0;i<val.size();i++){
            if(capacity>=totalwt+ele[i].second){
                total+=ele[i].first;
                totalwt+=ele[i].second;
            }else{
                int remain=capacity-totalwt;
                total+=(((double)remain/ele[i].second)*ele[i].first);
                break;
            }
            
        }
        return total;
    }
};
