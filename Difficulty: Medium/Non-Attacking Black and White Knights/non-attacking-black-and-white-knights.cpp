class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        int cells=n*m;
        int total=cells*(cells-1);
        int attack=4*((n-1)*(m-2)+(n-2)*(m-1));
        return total-attack;
    }
};