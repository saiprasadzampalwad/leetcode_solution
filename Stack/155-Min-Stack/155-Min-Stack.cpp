class MinStack {
    int to, stack[10000];

public:
    MinStack() {
        to=-1;
    }
    
    void push(int val) {
        if(to==9999)
            {
                printf("stack overflow");
            }
            else
            {
                
                stack[to+1]=val;
                to++;
            
            }
    }
    
    void pop() {
        if(to==-1)
               {
                   printf("stack underflow");
               }
               else
               {
                   to--;

               }
    }
    
    int top() {
        return stack[to];
    }
    
    int getMin() {
      int min=stack[to];
      for(int i=to;i>=0;i--)
      {
        if(min>stack[i])
        {
            min=stack[i];
        }
      }
     return min;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */