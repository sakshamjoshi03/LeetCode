class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size())  return false;
        unordered_map<char,int>mp1,mp2;
        
        for(char ch : s)
        {
            mp1[ch]++;
        }

        for(char ch : t)
        {
            mp2[ch]++;
        }

        if(mp1 == mp2) return true;

        return false;
    }
};