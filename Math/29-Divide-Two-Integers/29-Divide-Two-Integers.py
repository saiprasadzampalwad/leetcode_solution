class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if divisor == 0:
             raise ValueError("Divisor cannot be zero")
        if dividend == -2**31 and divisor == -1:
             return 2**31 - 1 
         
        result = int(dividend / divisor)
        if result < -2**31:
         return -2**31
        elif result > 2**31 - 1:
         return 2**31 - 1 
        else:
             return result