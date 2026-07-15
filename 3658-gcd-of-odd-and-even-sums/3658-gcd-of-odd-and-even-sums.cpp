class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }

    int gcdOfOddEvenSums(int n) {
        int evenSum = 0;
        int oddSum = 0;

        
        for (int i = 1, count = 0; count < n; i += 2, count++) {
            oddSum += i;
        }

        
        for (int i = 2, count = 0; count < n; i += 2, count++) {
            evenSum += i;
        }

        return gcd(evenSum, oddSum);
    }
};