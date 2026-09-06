class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int k = r;

        while (l <= r) {
            int mid = (l + r) / 2;

            int total_hours = 0;

            for (int pile : piles) {
                total_hours = total_hours + (pile + mid -1) / mid;
            }

            if (total_hours <= h) {
                k = mid;
                r = mid - 1;
            }

            else {
                l = mid + 1;
            }
        }

        return k;
    }
};
