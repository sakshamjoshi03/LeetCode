class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n) return "";

        int left = 0,count = 0;
        unordered_map<char,int>freqT,freqS;
        
        for(char ch : t){
            freqT[ch]++;
        }
        
        string ans = "";
        int minLen=INT_MAX;
        int start=0;
        for(int right = 0 ; right < n ; right++ )
        {
            char ch = s[right];
            freqS[ch]++;

            if(freqT.count(ch) && freqS[ch] <= freqT[ch] ) // freq count of that character is less or equal only then consider it...
            {
                count++;
            }

            while(count == m)
            {
                if(right-left+1 < minLen)
                { 
                    minLen = right-left+1;
                    start=left;
                }

                char leftchar = s[left];
                freqS[leftchar]--;

                if(freqT.count(leftchar) && freqS[leftchar] < freqT[leftchar] )//count impacted
                {
                    count--;
                }

                left++;
            }

        }
        if (minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};