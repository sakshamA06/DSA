>[!Note]- Variable Names
> **n** is the size of **arr**
## Merge Sort
Divide in half, sort the sub-arrays, merge em back.

**Time Complexity:**
$O(n*\log_{2}{n})$ for Best, Average and Worst case.

**Space Complexity:**
O(n) for the temp array.

## Quick Sort
Pick a pivot, place it in its correct position by moving the elements smaller than it on its left and elements larger than it on its right, then sort both split parts recursively doing the same thing.

### Algorithm
1. Pick any pivot
2. Place it into its correct position using two pointer method:
	- A pivot is at its correct position when all the elements in its left(their order doesn't matter) are smaller than it and all the elements in its right are larger than itself.
	1. One pointer starts at leftmost(i) and another starts at rightmost(j).
	2. Keep moving the left pointer towards right as long as the elements are smaller than the pivot, stop when it encounters a larger element.
	3. Same for right pointer moving left, it keeps going until it encounter a smaller element.
	4. After both have stopped, they swap these elements, so that smaller element if at i and larger is at j.
	5. Keep going and at the end when j preceeds i, that means all the elements it encountered were larger, and all the elements i encountered were smaller.
	6. j is the correct index of pivot, its also the partition index since this is the point where the split will happen.
3. Now split the array(hypothetically) into two sub-arrays and sort them recursively using above steps.

### Code
```cpp
void quisort(int arr[], int low, int high)
{
	if (low>=high) return;
	int pivot = low;
	int i = low;
	int j = high;
	while(i<j)
	{
		while(arr[i] <= arr[pivot] && i<high) i++;
		while(arr[j] > arr[pivot] && j>low) j--;
		if(i<j) swap(arr[i], arr[j]);
	}
	swap(arr[j], arr[pivot]);
	quisort(arr, low, j-1);
	quisort(arr, j+1, high);
}
```
>[!caution] Edge Cases
> >[!info] The first condition of inner two while loops
> > i moves to the right until it finds an element larger than pivot, u can choose to do the equal on the j while loop as well, it only determines if i or j will go over equal elements
>
> >[!info] The second condition of inner two while loops
> > Second condition is to prevent i and j from moving out of array limits,  i<=high will cause problems as well, when i == high, it will be true, and if the last element is <= pivot, then i pointer will go out of bounds, same for why j>=low will cause problems.
> 
> >[!info] if inside outer while
> > Even though the outer while condition checks for i<j, we need to check it again inside if cuz i might have exceeded j while going thru the inner two while loops

>[!info] After the outer while, j contains the partition index, not pivot(its never changed, always been low), so we separate the arrays using j instead of pivot

### Complexity Analysis
**Time Complexity:**
$O(n*\log_{2}{n})$ for Best, Average and Worst case.

**Space Complexity:**
O(1) cuz everything is being swapped in place(not considering recursive stack space).