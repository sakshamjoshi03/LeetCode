class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int maxans = 0;
        unordered_set<char>freq;
        for(int right = 0 ; right < n ; right++)
        {
            if(freq.count(s[right]) == 0)
            {
                freq.insert(s[right]);
                maxans=max(maxans,right-left+1);
            }
            else
            {
                while(freq.count(s[right])){
                    freq.erase(s[left]);
                    left++;
                }
                freq.insert(s[right]);
            }
        }
        return maxans;
    }
};