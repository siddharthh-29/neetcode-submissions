class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>hash1(26,0);
        for(int i=0;i<s.size();i++){
            hash1[s[i]-'a']++;
        }
        vector<int>hash2(26,0);
        for(int i=0;i<t.size();i++){
            hash2[t[i]-'a']++;
        }
        return (hash1==hash2);
    }
};
