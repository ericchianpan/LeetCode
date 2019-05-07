class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(unsigned i = 0; i < words.size(); ++i) {
           if(match(words[i], pattern)) res.push_back(words[i]);
        }
        return res;
    }
private:
    bool match(const string& str, const string& pattern) {
        char map[26] {};
        bool mapped[26] {};
        for(size_t i = 0; i < str.size(); ++i) {
            if(map[pattern[i] - 'a'] == NULL) {
                if(mapped[str[i] - 'a']) return false;
                map[pattern[i] - 'a'] = str[i];
                mapped[str[i] - 'a'] = true;
            }
            else {
                if(map[pattern[i] - 'a'] != str[i]) return false;
            }
        }
        return true;
    }
};
