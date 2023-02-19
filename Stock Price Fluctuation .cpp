class StockPrice {
public:
    map<int,int> Price;
    map<int,int> pr;
    StockPrice() {
        ;
    }
    
    void update(int timestamp, int price) {
        if(Price[timestamp]!=0){
            pr[Price[timestamp]]--;
            if(pr[Price[timestamp]]==0)
                pr.erase(Price[timestamp]);
        }
        Price[timestamp]=price;
        pr[price]++;
        //mx=max(mx,price);
        //mn=min(mn,price);
    }
    
    int current() {
        auto it=Price.rbegin();
        return it->second;
       // return 0;
    }
    
    int maximum() {
        auto it=pr.rbegin();
        return it->first;
        //return 0;
    }
    
    int minimum() {
        auto it=pr.begin();
        return it->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
