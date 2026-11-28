
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        // Count frequency of each factor
        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            freq[factor]++;
            minPrice = min(minPrice, price);
        }

        // Calculate how many factors are divisible by each factor
        vector<int> gain(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int j = f; j <= n; j += f) {
                gain[f] += freq[j];
            }

            // Exclude the item itself
            if (freq[f] > 0) {
                gain[f]--;
            }
        }

        // Store boosted copies: {price, count}
        vector<pair<int, int>> offers;

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            if (gain[factor] > 0 &&
                1LL * price < 2LL * minPrice) {

                offers.push_back({price, gain[factor]});
            }
        }

        // Cheapest boosted copies first
        sort(offers.begin(), offers.end());

        long long ans = 0;
        long long remaining = budget;

        // Buy value-2 copies
        for (auto offer : offers) {
            long long price = offer.first;
            long long count = offer.second;

            long long take = min(count, remaining / price);

            ans += take * 2;
            remaining -= take * price;
        }

        // Buy normal copies of the cheapest item
        ans += remaining / minPrice;

        return (int)ans;
    }
};
