class MinStack {
   
public:
    stack<int> st;
    stack<int> pt;
    MinStack() {  
        
    }
    
    void push(int val) {
        st.push(val);
        if( pt.empty()||val<=pt.top()){
            pt.push(val);
        }
        
    }
    
    void pop() {
        if(st.top()==pt.top()) pt.pop();
        st.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return pt.top();      
    }
};
