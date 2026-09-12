class Solution {
private:
    struct State {
        long long score;
        std::vector<int> indices;
    };

    std::vector<std::vector<int>> intervals;
    std::vector<int> nextIndex;
    std::vector<std::vector<State>> dp;
    std::vector<std::vector<bool>> seen;

    bool lexicographicallySmaller(const std::vector<int>& a,
                                   const std::vector<int>& b) {
        return a < b;
    }

    State better(const State& a, const State& b) {
        if (a.score != b.score) {
            return a.score > b.score ? a : b;
        }

        return lexicographicallySmaller(a.indices, b.indices) ? a : b;
    }

    State solve(int i, int remaining) {
        if (i == static_cast<int>(intervals.size()) || remaining == 0) {
            return {0, {}};
        }

        if (seen[i][remaining]) {
            return dp[i][remaining];
        }

        seen[i][remaining] = true;

        // Option 1: skip this interval.
        State skip = solve(i + 1, remaining);

        // Option 2: take this interval.
        State take = solve(nextIndex[i], remaining - 1);

        take.score += intervals[i][2];

        // Insert original index while keeping indices sorted.
        auto pos = std::lower_bound(
            take.indices.begin(),
            take.indices.end(),
            intervals[i][3]
        );

        take.indices.insert(pos, intervals[i][3]);

        dp[i][remaining] = better(skip, take);

        return dp[i][remaining];
    }

public:
    std::vector<int> maximumWeight(std::vector<std::vector<int>>& input) {
        int n = input.size();

        intervals.reserve(n);

        for (int i = 0; i < n; ++i) {
            intervals.push_back({
                input[i][0],  // left
                input[i][1],  // right
                input[i][2],  // weight
                i             // original index
            });
        }

        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      if (a[0] != b[0]) {
                          return a[0] < b[0];
                      }
                      return a[1] < b[1];
                  });

        // Extract all left endpoints for binary search.
        std::vector<int> starts(n);

        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i][0];
        }

        nextIndex.resize(n);

        for (int i = 0; i < n; ++i) {
            // Strictly greater than intervals[i][1].
            nextIndex[i] =
                std::upper_bound(starts.begin(), starts.end(), intervals[i][1])
                - starts.begin();
        }

        dp.assign(n, std::vector<State>(5));
        seen.assign(n, std::vector<bool>(5, false));

        return solve(0, 4).indices;
    }
};