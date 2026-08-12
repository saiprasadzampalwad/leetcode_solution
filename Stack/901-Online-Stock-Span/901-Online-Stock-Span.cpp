class StockSpanner {
    int stock[100000];
    int top; 
public:
    StockSpanner() {
        top=-1;
    }
    
    int next(int price) {
        stock[top+1]=price;
        top++;
       return getMin();
    }
     int getMin() {
      int min=stock[top];
     int count=0;
      for(int i=top;i>=0;i--)
      {
        if(min<stock[i])
          break;
        if(min>=stock[i])
        {
               count++;
        }
      }
     return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */