class Solution {
public:
    int divide(long  dividend, long  divisor) {
         // Set sign and work with positive numbers

    int sign = dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0 ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);
        
    long sum = 0;
    long bitWiseOne = 1;
    
    // Use bitshift operation 1 << n which is 2^n to take large values out of dividend.
    // For each (divisor * 2^n) taken out of dividend, increment sum by (2^n).
    

    for (int n = 31; n >= 0; n--)
    {
        // Check if divisor * 2^n is less than dividend
        
        if (divisor << n <= dividend)
        {   
            
            // Subtract divisor * 2^n from dividend
            
            dividend = dividend - (divisor << n);
            
            // Add 1 * 2^n to sum
            
            sum = sum + (bitWiseOne << n);
        }
    }

    if (sign == -1)
        sum = -sum;

    if (sum > INT_MAX)
        return INT_MAX;
        
    if (sum < INT_MIN)
        return INT_MIN;
        
    return sum;

    }
};