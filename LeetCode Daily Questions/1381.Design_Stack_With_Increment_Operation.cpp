class CustomStack {
    vector<int>v;
    int bottom = 0;
    int top = 0;
    int size;
public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(size <= v.size()){
            return;
        }
        v.push_back(x);
        top++;
    }
    
    int pop() {
        if(v.size()<=0){
            return -1;
        }
        int a = v[top-1];
        v.erase(v.begin()+top);
        top--;
        return a;
    }
    
    void increment(int k, int val) {
        int i = 0;
        while(i<k && i<top){
            // cout<<v[i]<<endl;
            v[i] = v[i] + val;
            // cout<<v[i]<<endl;
            i++;
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
