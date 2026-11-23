class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    vector<int> arr;
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int pro = 1;
        int i = arr.size()-1;
        while(k--){
            pro *= arr[i];
            i--;
        }

        return pro;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */