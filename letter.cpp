class Solution {
public:
    vector<string> letterCombinations(string digits) {

        // If input is empty, no combinations are possible
        if (digits.empty()) {
            return {};
        }

        // Phone keypad mapping where index represents the digit
        vector<string> pad = {
            "", "",        // 0 and 1 have no letters
            "abc",         // 2
            "def",         // 3
            "ghi",         // 4
            "jkl",         // 5
            "mno",         // 6
            "pqrs",        // 7
            "tuv",         // 8
            "wxyz"         // 9
        };

        // Stores all possible combinations
        vector<string> output;

        // Start with an empty string to build combinations
        output.push_back("");

        // Iterate through each digit in the input
        for (auto key : digits) {

            // Temporary vector to store new combinations
            vector<string> temp;

            // Get letters corresponding to the current digit
            for (auto candidate : pad[key - '0']) {

                // Append current letter to all existing combinations
                for (auto c : output) {
                    temp.push_back(c + candidate);
                }
            }

            // Update output with newly formed combinations
            output.clear();
            output = temp;
        }

        // Return all possible letter combinations
        return output;
    }
};