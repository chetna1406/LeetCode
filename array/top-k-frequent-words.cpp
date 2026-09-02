class Solution {
public:

    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {

            // Same frequency → lexicographically larger word is worse
            if (a.first == b.first)
                return a.second < b.second;

            // Lower frequency is worse
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        // Min Heap
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            cmp
        > pq;

        // Count frequencies
        unordered_map<string, int> f;

        for (int i = 0; i < words.size(); i++)
            f[words[i]]++;

        // Keep only K best words
        for (auto i : f) {

            string element = i.first;
            int frequency = i.second;

            pair<int, string> curr = {frequency, element};

            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }

            // Current word is worse → ignore
            if (curr.first < pq.top().first)
                continue;

            if (curr.first == pq.top().first &&
                curr.second > pq.top().second)
                continue;

            // Current word is better → replace worst
            pq.pop();
            pq.push(curr);
        }

        // Extract answer
        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        // Heap gives worst → best, so reverse
        reverse(res.begin(), res.end());

        return res;
    }
};