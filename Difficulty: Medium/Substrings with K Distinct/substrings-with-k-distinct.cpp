class Solution {
  public:
    int atMostK(string& s, int k){
        if (k < 0) return 0;

        int freq[26] = {0};
        int distinct = 0;
        int l = 0;
        int count = 0;

        for (int r = 0; r < s.length(); r++) {
            if (freq[s[r] - 'a'] == 0)
                distinct++;
            freq[s[r] - 'a']++;

            while (distinct > k) {
                freq[s[l] - 'a']--;
                if (freq[s[l] - 'a'] == 0)
                    distinct--;
                l++;
            }

            count += (r - l + 1);
        }
        return count;
    }
    int countSubstr(string& s, int k) {
        // code here
        return atMostK(s,k)-atMostK(s,k-1);
    }
};