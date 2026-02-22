class Solution {

    bool isPrime(int num){

        if(num==2){
            return true;
        }

        int fact=1;
        for(int i=1;i<num;i++){
            if(num%i==0){
                fact++;
            }
        }

        if(fact==2){
            return true;
        }else{
            return false;
        }
    }

public:
    int countPrimeSetBits(int left, int right) {
        int count=0;

        for(int i=left; i<=right ; i++){
            int numOfOne=__builtin_popcount(i);

            bool prime= isPrime(numOfOne);

            if(prime){
                count++;
            }
        }

        return count;
    }
};