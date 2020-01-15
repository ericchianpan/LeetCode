class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        _minimum_element = INT_MAX;
    }
    
    void push(int x) {
        _elements.push_back(x);
        if(x < _minimum_element) _minimum_element = x;
    }
    
    void pop() {
        if(_elements.back() == _minimum_element) {
            int min = INT_MAX;
            for(unsigned i = 0; i < _elements.size() - 1; ++i) {
                if(_elements[i] < min) min = _elements[i];
            }
            _minimum_element = min;
        }
        _elements.pop_back();
    }
    
    int top() {
        return _elements.back();
    }
    
    int getMin() {
        return _minimum_element;
    }
private:
    vector<int> _elements;
    int _minimum_element;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
