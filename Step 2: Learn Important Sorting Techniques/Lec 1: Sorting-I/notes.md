>[!Note]- Variable names
>**n** is the size of array **arr**

## Selection Sort
Minimum elements are placed from start to end.
### Algorithm
1. Select minimum of unsorted array.
2. Swap it with the first place of unsorted array.
3. Rinse and Repeat for every element in the array

### Code
```cpp
for(int i = 0; i < n-1; i++){
    int min = i;
    for(int j = i; j < n; j++){
        if(arr[j] < arr[min]) min = j;
    }
    swap(arr[min], arr[i]);
}
```

### Complexity Analysis
**Time Complexity:**
$O(n^2)$ for Best, Average and Worst case.

>Outer Loop runs for n-1 times
>Inner Loop first runs for n times, then n-1 then n-2, ... , then 2 times
>$n + n-1 + n-2 + ... + 2 \approx \frac{n(n+1)}{2} \approx \frac{n^2}{2} + \frac{n}{2} \approx n^2$

**Space Complexity:** O(1)

## Bubble Sort
The largest element is bubbled to the end one at a time.
### Algorithm
1. Select larger of the first two elements.
2. Swap it too the second place is it isn't already there.
3. Continue the same for 2nd,3rd then 3rd, 4th and so on till second last and last element
4. Repeat but only go till third last and second last this time since the last is already sorted(the largest)
5. Keep stopping one element before the last iteration, the sorted array builds from right to left.

### Code
```cpp
for(int i = n; i >= 2; i--)
{
	bool noswap = true;
	for(int j = 0; j <= i-2; j++)
		if(arr[j] > arr[j+1])
		{
			swap(arr[j], arr[j+1]);
			noswap = false;
		}
	if(noswap) break;
}
```

### Complexity Analysis
**Time Complexity:**
$O(n)$ for Best case.
$O(n^2)$ for Average and Worst case.

- Best case is when the array is already sorted. It will stop after inner loop runs n-2 times as noswap will remain true
- Average and Worst case are calculated like selection sort.

**Space Complexity:** N/D

## Insertion Sort
Keep inserting the element of an unsorted continuosly enlarging sub-array at its correct position within the sub-array
### Algorithm
1. Sub-array of first two elements, if second element is smaller than first then swap.
2. Sub-array of first three elements, keep moving the third element to the left as long as it is smaller than its preceding element
3. Keep making these sub-arrays and place the last element in the correct position
4. Once the sub-array is the size of array, the final element can be sorted along with the array

### Code
```cpp
for(int i = 1; i < n; i++)
	for(int j = i; arr[j] < arr[j-1]; j--)
		swap(arr[j], arr[j-1]);
```

### Complexity Analysis
**Time Complexity:**
$O(n)$ for Best case.
$O(n^2)$ for Average and Worst case.

- Best case is when the array is already sorted. Each outer loop iteration will only consist of a single check by the inner loop that confirms that the last element of any sub-array is at its correct position.
- Average and Worst case are calculated like selection and bubble sort.

**Space Complexity:** N/D