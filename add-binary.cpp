class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int pos_a = a.size() - 1, pos_b = b.size() - 1;
        int carry = 0;
        while(pos_a >= 0 || pos_b >= 0 || carry) {
            int da = pos_a >= 0 ? a[pos_a--] - '0' : 0;
            int db = pos_b >= 0 ? b[pos_b--] - '0' : 0;
            res.insert(0, to_string(da ^ db ^ carry));
            carry = da & db | carry & (da ^ db);
        }
        return res;
    }
};
