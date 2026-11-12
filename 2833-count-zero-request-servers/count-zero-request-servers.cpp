
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int m = queries.size();

        // Step 1: Sort logs by request time
        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        // Step 2: Store query and original index
        vector<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        // Step 3: Sort queries by time
        sort(q.begin(), q.end());

        // Step 4: Frequency map
        unordered_map<int,int> mp;

        vector<int> ans(m, 0);

        int left = 0;
        int right = 0;
        int active = 0;

        // Step 5: Process each query
        for(int i = 0; i < m; i++) {

            int L = q[i].first - x;
            int R = q[i].first;

            // Add logs with time <= R
            while(right < logs.size() && logs[right][1] <= R) {

                int id = logs[right][0];

                if(mp[id] == 0) {
                    active++;
                }

                mp[id]++;
                right++;
            }

            // Remove logs with time < L
            while(left < right && logs[left][1] < L) {

                int id = logs[left][0];

                mp[id]--;

                if(mp[id] == 0) {
                    active--;
                }

                left++;
            }

            // Store answer at original query index
            ans[q[i].second] = n - active;
        }

        return ans;
    }
};
