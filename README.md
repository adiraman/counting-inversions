# Counting Inversions

Given :- An array A containing numbers from 1,2,3,....,n in some arbitrary order.

Find :- The number of inversions i.e. number of pairs of (i,j) indices with i < j & A[i] > A[j].

eg. For A = {1,3,5,2,4,6} the inversions are (3,2); (5,2); (5,4)

Uses :- 
 - Numerical similarity measure between 2 ranked lists.
 - Collaborative filtering appplications.
 
Algorithm :- (Based on Merge Sort, O(nlog(n))

countInversions(array A, length n)
 1. base case if n = 1, return 0
 2. x = countInversions(1st half of A, n/2)
 3. y = countInversions(2nd half of A, n/2)
 4. z = countSplitInversions(1st half of A, 2nd half of A)
 5. return best of (x, y, z)

Note:- Split inversions involving an element y of the right array are precisely the numbers left in the
left when y is copied over to the output array in the merge step.