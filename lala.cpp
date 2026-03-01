class Solution {
public:
    int minPartitions(string n) {
          int ans = 0;
        for (char& c : n) 
        ans = max(ans, c - '0');//Converts character digit → integer digit.
        return ans;
    }
};