class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true; 
        }
        if (x != 0 && x % 10 == 0) {
            return false; 
        }                      
        int sum = 0; 
        for (; x > sum; x = x / 10) {
            sum = sum * 10 + x % 10; 
        }
        return sum == x || (x == sum / 10);
    }
};