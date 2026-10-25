class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (string s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.size()) {
            int j = i;
            // Find the delimiter '#'
            while (s[j] != '#') {
                j++;
            }
            
            // Extract the length of the next string
            int length = stoi(s.substr(i, j - i));
            
            // Extract the actual string using the exact length
            string str = s.substr(j + 1, length);
            decoded.push_back(str);
            
            // Move index past the current encoded chunk
            i = j + 1 + length;
        }
        
        return decoded;
    }
};