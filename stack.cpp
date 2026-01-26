class Solution {
public:
    string makeGood(string s) {
        string stack;
        
        for (char c : s) {
          
            if (!stack.empty() && abs(stack.back() - c) == 32) //This condition is checking whether two characters are the same letter but in different cases
            {
                stack.pop_back(); 
            } else {
                stack.push_back(c); 
            }
        }
        
        return stack;
    }
};