class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(pq.size() > 1) {
            int left = pq.top();
            pq.pop();
            int right = pq.top();
            pq.pop();
            if(left != right) {
                pq.push(left - right);
            }
        }
        
        return pq.size() == 1  ? pq.top() : 0;
    }
};
