vector<string> topKFrequent(vector<string>& words, int k) 
        unordered_map<string, int> freq;
        for (string &w : words) {
            freq[w]++;
        }

        // min-heap: worst element on top
        auto cmp = [&](const pair<int,string>& a,
                       const pair<int,string>& b) {
            if (a.first == b.first)
                return a.second < b.second; // reverse lex
            return a.first > b.first;       // smaller freq first
        };

        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            decltype(cmp)//Because priority_queue must know the comparator type at compile time. lambda
        > minHeap(cmp);

        for (auto &it : freq) {
            minHeap.push({it.second, it.first});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = minHeap.top().second;
            minHeap.pop();
        }

        return ans;
/*WHAT DOES true DO?
Says: a is worse than b
"i" is pushed down
"love" comes up
"love" becomes heap top
🟥 Heap top = "love"
🟩 "love" is lexicographically larger → WORST
✔ correct behavior
true = kick a down
false = let a stay
*/
