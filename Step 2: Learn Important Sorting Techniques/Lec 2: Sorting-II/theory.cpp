#include<iostream>

class Solution
{
    public:
    void display(int arr[], int n)
    {
        std::cout<<"{";
        for(int i = 0; i < n; i++)
        {
            std::cout<<arr[i];
            if(i!=n-1) std::cout<<", ";
        }
        std::cout<<"}";
    }

    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void mersort(int arr[], int low, int high)
    {
        if(low >= high) return;

        int mid = (low +  high)/2;
        // sort first half
        mersort(arr, low, mid);
        // sort second half
        mersort(arr, mid+1, high);

        // merging the two halves
        int temp[high+1];
        int index = 0;
        int left = low;
        int right = mid+1;
        while((left <= mid) && (right <= high))
        {
            if(arr[left] <= arr[right]){
                temp[index] = arr[left];
                left++;
            }
            else {
                temp[index] = arr[right];
                right++;
            }
            index++;
        }
        while(left <= mid)
        {
            temp[index] = arr[left];
            left++;
            index++;
        }
        while(right <= high)
        {
            temp[index] = arr[right];
            right++;
            index++;
        }
        // updating the main array
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
    }

    void recbubsort(int arr[], int n)
    {
        // each iteration of recursion puts one more largest number at the last
        if(n==1) return;
        bool swapped = false;
        // loop to bubble the largest number to end
        for(int j=0; j<n-1; j++)
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        // only continue recursion if array isnt sorted i.e. swapped is true(optimised for best case)
        if(swapped) recbubsort(arr, n-1);
    }

    void recinssort(int arr[], int n, int i)
    {
        // each recursion iteration sorts the last element of the sub-array
        if(i>=n) return;
        while(arr[i] < arr[i-1] && i>=1){
            swap(arr[i], arr[i-1]);
            i--;
        }
        // increase the sub-array size
        recinssort(arr, n, i+1);
    }

    void quisort(int arr[], int low, int high)
    {
        // if low == high then its single element sub-array
        if (low>=high) return;
        // can choose pivot to be anything, chose first element here
        int pivot = low;
        // the two pointers from left and right
        int i = low;
        int j = high;
        while(i<j)
        {
            // i  means arr[i] and j means [j] in the following comment
            // as long as
            while(arr[i] <= arr[pivot] && i<high) i++;
            while(arr[j] > arr[pivot] && j>low) j--;
            if(i<j) swap(arr[i], arr[j]);
        }
        swap(arr[j], arr[pivot]);
        quisort(arr, low, j-1);
        quisort(arr, j+1, high);
    }
};

int main(){
    Solution sol;
    // int array[] = {3, 13, 46, 24, 52, 20, 9, 1, 2};
    int array[] = {2, 2, 2, 2};
    int size = sizeof(array)/sizeof(int);

    sol.display(array, size);
    std::cout<<'\n';
    // Merge Sort
    // sol.mersort(array, 0, size-1);

    // Recursive Bubble Sort
    // sol.recbubsort(array, size);

    // Recursive Insertion Sort
    // sol.recinssort(array, size, 1);

    // Quick Sort
    // sol.quisort(array, 0, size-1);

    std::cout<<'\n';
    sol.display(array, size);

    std::cout<<"\n\n";
return 0;
}