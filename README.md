# Karasuba-Matrix-Multplication
Karatsuba matrix multiplication compared with naive algorithm
Polynomial Multiplication
      Naive:
    • Using two for loops compute the coefficient for each power in quadratic time.
      Karatsuba:
    • Append zeroes to both the arrays until their size is equal to the next nearest power of 2 of the size of bigger of two arrays.
    • Write a recursive algorithm for below pseudocode
      A(x) = a1x + a0 
      B(x) = b1x + b0 
      A(x)B(x) = a1b1x2 + (a1b0 + a0b1)x + a0b0 
      is rewritten as 
      A(x)B(x) = a1b1x2 + ((a1 + a0)(b1 + b0) − a1b1 − a0b0)x + a0b0
      Requires 3 recursive multiplication calls.

1. Output observed:
 
 		Average time for Naive Algorithm = 0.0172630000 secs				Average time for Karatsuba algorithm = 0.1366010000 secs

 2. Time complexity:
 		
 		Naive Algorithm = O(n2)
 		Karatsuba Algorithm = O(n1.59)
 
3. Note:
	  	
Inspite of having a better complexity than Naive algorithm.Karatsuba algorithm has much worse running time than the naive one. This is because of more    complex operations we perform in Karatsuba’s algorithm adds up to its runing time. Though Karatsuba’s algorithms is asymptotically better than naive multiplication but more operations overshadows the difference between n2 and n1.59 for small values of n like 1000. This fact can be seen in below graph-


















