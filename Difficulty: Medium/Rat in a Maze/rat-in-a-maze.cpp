class Solution {
  public:
  void f(int row,int col,string curr,vector<string>&ans,vector<vector<int>>& maze){
      int n=maze.size();
      if(row==n-1 && col==n-1){
          ans.push_back(curr);
          return ;
      }
    char dir[] = {'D', 'L', 'R', 'U'};
    int dRow[] = {1, 0, 0, -1};
    int dCol[] = {0, -1, 1, 0};
    for(int i=0;i<4;i++){
        int nrow=row+dRow[i];
        int ncol=col+dCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && maze[nrow][ncol]==1){
            maze[nrow][ncol]=0;
            f(nrow,ncol,curr+dir[i],ans,maze);
            maze[nrow][ncol]=1;
        }
        
    }

      
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        maze[0][0]=0;
        vector<string>ans;
        f(0,0,"",ans,maze);
        return ans;
    }
};