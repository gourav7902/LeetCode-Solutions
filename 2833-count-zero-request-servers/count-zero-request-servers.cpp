
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        vector<int> ans(q);

        vector<pair<int,int>> timeIndex;

        for(int i = 0; i < q; i++) {
            timeIndex.push_back({queries[i], i});
        }

        sort(timeIndex.begin(), timeIndex.end());

        unordered_map<int,int> mp;

        int left = 0;
        int right = 0;
        int active = 0;

        for(int k = 0; k < q; k++) {

            int L = timeIndex[k].first - x;
            int R = timeIndex[k].first;

            // Add logs <= R
            while(right < logs.size() &&
                  logs[right][1] <= R) {

                int server = logs[right][0];

                if(mp[server] == 0) {
                    active++;
                }

                mp[server]++;
                right++;
            }

            // Remove logs < L
            while(left < right &&
                  logs[left][1] < L) {

                int server = logs[left][0];

                mp[server]--;

                if(mp[server] == 0) {
                    active--;
                    mp.erase(server);
                }

                left++;
            }

            // Store answer
            ans[timeIndex[k].second] = n - active;
        }

        return ans;
    }
};
