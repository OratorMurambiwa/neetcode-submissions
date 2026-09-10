class KthLargest {
public:

    int target;
    priority_queue<int, vector<int>, greater<int>>minHeap;

    KthLargest(int k, vector<int>& nums) {
        
        target = k;

        for (int num : nums) {
            minHeap.push(num);
            }
        
        while (minHeap.size() > target) {
            minHeap.pop();
        }

    }
    
    int add(int val) {

        minHeap.push(val);

        if (minHeap.size() > target) {
            minHeap.pop();
        }
        return minHeap.top();
        
    }

};
