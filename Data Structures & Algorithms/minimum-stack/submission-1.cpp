class MinStack {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    stack<int> s;
    unordered_map<int, int> deleted;
public:
    MinStack() {
    }
    
    void push(int val) {
        pq.push(val);
        s.push(val);
    }
    
    void pop() {
        deleted[s.top()]++;
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        while(deleted.count(pq.top())){
            deleted[pq.top()]--;
            if(deleted[pq.top()] == 0){
                deleted.erase(pq.top());
            }
            pq.pop();
        }
        return pq.top();
    }
};
