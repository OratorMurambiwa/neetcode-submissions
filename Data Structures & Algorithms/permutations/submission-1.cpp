class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> permutations;

        function<void()> dfs = [&]() {
            if (permutations.size() == nums.size()) {
                res.push_back(permutations);
                return;
            }

            for (int num : nums) {
                if (find(permutations.begin(), permutations.end(), num) != permutations.end()) {
                    continue;
                }

                permutations.push_back(num);

                dfs();

                permutations.pop_back();
            }


        };

        dfs();

        return res;

    }
};
