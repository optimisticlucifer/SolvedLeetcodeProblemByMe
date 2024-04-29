class Solution {
public:
    string removeStars(string s) {
        string str = "";
        for (auto ch : s) {
            if (ch == '*') str.pop_back();
            else str += ch;
        }
        return str;
    }
};