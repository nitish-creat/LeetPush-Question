class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int , vector<int> , greater<int>> mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.size() == 0 || num < maxi.top()){
            maxi.push(num);
        }
        else{
            mini.push(num);
        }

        if(maxi.size() > mini.size() +1){
            mini.push(maxi.top());
            maxi.pop();
        }
        else if(mini.size() > maxi.size()){
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if(maxi.size() == mini.size()){
            double mean = maxi.top() + mini.top();
            return mean/2;
        }
        return maxi.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */