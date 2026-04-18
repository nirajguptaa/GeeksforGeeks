class Solution {
  public:
    string toposort(vector<vector<int>>&adj,vector<bool>&used){
        vector<int>inDegree(26,0);
        for(int i=0;i<26;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<26;i++){
            if(inDegree[i]==0 && used[i]==true){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(used[it]==true && inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        int usedCount=0;
        for(int i=0;i<26;i++){
            if(used[i]==true){
                usedCount++;
            }
        }
        if(usedCount!=topo.size()){
            return "";
        }
        string ans="";
        for(int ch:topo){
            if(used[ch]){
                ans+=(char)(ch+'a');
            }
        }
        return ans;
    }
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        vector<vector<int>>adj(26);
        vector<bool>used(26,false);
        for(string w:words){
            for(char ch:w){
                used[ch-'a']=true;
            }
        }
        for(int i=0;i<n-1;i++){
            string str1=words[i];
            string str2=words[i+1];
            int len=min(str1.size(),str2.size());
            bool foundDiff=false;
            for(int j=0;j<len;j++){
                if(str1[j]!=str2[j]){
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    foundDiff=true;
                    break;
                }
            }
            if(!foundDiff && str1.size()>str2.size()){
                return "";
            }
            
        }
        return toposort(adj,used);
    }
};