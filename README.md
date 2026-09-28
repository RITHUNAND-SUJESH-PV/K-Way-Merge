# K-Way-Merge
# K-Way Merge Assignment

## Title

Implementation and Comparison of K-Way Merge Using Min Heap and Pairwise Merging

## Objective

To implement and compare two methods for merging already sorted transaction lists:

1. K-way merge using a Min Heap
2. Pairwise merging

## Input Data

L1 = 10, 30, 50, 70

L2 = 20, 40, 60, 80

L3 = 15, 35, 55, 75

## K-Way Merge

A Min Heap is used to store the current smallest element from each sorted list.

The initial heap is:

[10, 20, 15]

The final merged output is:

10 15 20 30 35 40 50 55 60 70 75 80

## Pairwise Merge

First, L1 and L2 are merged.

Result:

10 20 30 40 50 60 70 80

Then this result is merged with L3.

Final result:

10 15 20 30 35 40 50 55 60 70 75 80

## Complexity Analysis

### K-Way Min Heap

Time Complexity:

O(N log k)

Space Complexity:

O(k)

Maximum heap size:

k

For this problem:

k = 3

### Pairwise Merge

The time complexity depends on the merge order.

Sequential pairwise merging can approach:

O(Nk)

Intermediate arrays require additional space.

## Comparison

| Parameter | K-Way Min Heap | Pairwise Merge |
|---|---|---|
| Data Structure | Min Heap | Arrays |
| Heap Size | k | No heap |
| Time Complexity | O(N log k) | Depends on order |
| Space | O(k) heap | O(N) intermediate |
| Scalability | High | Lower |
| Many sorted files | Suitable | Less suitable |

## Conclusion

The Min Heap based k-way merge is more suitable when the number of sorted files increases.

It maintains only one current element from each list and performs merging efficiently in O(N log k) time.

Pairwise merging is simple and suitable for a small number of lists, but it requires repeated intermediate merging as the number of lists increases.

## Files Included

- kway_merge.c
- input.txt
- output.txt
- trace_table.txt
- complexity_analysis.txt
- comparison_table.txt
- README.md
