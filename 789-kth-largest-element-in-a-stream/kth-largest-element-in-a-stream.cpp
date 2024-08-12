class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) {
            if(min_heap.size()<k) {
                min_heap.push(num);
            }
            else if(num > min_heap.top()) {
                min_heap.push(num);
                if(min_heap.size() > k) {
                    min_heap.pop();
                }
            }
        }
    }
    
    int add(int val) {
        if (min_heap.size() < k) {
            min_heap.push(val);
        } 
        else if (val > min_heap.top()) {
            min_heap.push(val);
            min_heap.pop();
        }
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */