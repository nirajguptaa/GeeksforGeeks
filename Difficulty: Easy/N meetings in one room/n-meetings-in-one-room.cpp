class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        if(start.size()==0 || end.size()==0)return 0; 
        vector<pair<int,int>>meet;
        int n=start.size();
        for(int i=0;i<n;i++){
            meet.push_back({end[i],start[i]});
        }
        sort(meet.begin(),meet.end());
        int meetTakePlace=1;
        int lastMeetTime=meet[0].first;
        for(int i=1;i<n;i++){
            if(meet[i].second>lastMeetTime){
                meetTakePlace++;
                lastMeetTime=max(lastMeetTime,meet[i].first);
            }
        }
        return meetTakePlace;
    }
};