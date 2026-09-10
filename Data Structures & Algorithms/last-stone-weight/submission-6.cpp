class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxheap;
        int new_stone = 0;

        for (int stone : stones) {
            maxheap.push(stone);
        }

        while (maxheap.size() > 1) {
            int first = maxheap.top();
            maxheap.pop();
            int second = maxheap.top();
            maxheap.pop();

            if (first != second) {
                new_stone = first - second;
                
                maxheap.push(new_stone);
            }

        }

        if (maxheap.size() > 0) {
            return maxheap.top();
        }

        return 0;

    }
};
