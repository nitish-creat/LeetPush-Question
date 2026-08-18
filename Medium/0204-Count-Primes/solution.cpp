class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        if(n <= 2) return 0;
        int count = 1;
        if(n > 0) prime[0] = false;
        if(n > 1) prime[1] = false;
        
        for(int i = 3; i*i < n ;i+=2){
            if(prime[i] == true){
                for(int j =  i*i; j < n ;j+= 2*i){
                    prime[j] = false;
                }
            }
        }
        for(int i =3;i<n ;i+=2){
            if(prime[i]) count++;
        }

        return count;
    }
};