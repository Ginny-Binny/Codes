class Solution {
public:
    int nearestMultipleOf10(int num) {
        return ((num + 5) / 10) * 10; 
    }
    
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int accountBalance = 100; 
        int roundedAmount = nearestMultipleOf10(purchaseAmount);
        int newBalance = accountBalance - roundedAmount;
        return newBalance;
    }
};
