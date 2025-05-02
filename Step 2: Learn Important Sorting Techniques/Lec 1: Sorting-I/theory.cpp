#include<iostream>

class Solution
{
    public:
    int times = 0;
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
    int selsort(int arr[], int n)
    {
        times = 0;
        if(n <= 0) return 0;
        // sort from first element to second last, cuz last element will be sorted on its own
        for(int i = 0; i < n-1; i++)
        {
            int min = i;
            // find the index of minimum element in the unsorted array
            for(int j = i+1; j < n; j++)
            {
                if (arr[min] > arr[j]) min = j;
                times++;
            }
            // swap if minimum is not already at start of unsorted array
            if(i!=min) swap(arr[i], arr[min]);
        }
        return times;
    }

    int bubsort(int arr[], int n)
    {
        times = 0;
        // i is used to calculate the last element(of unsorted array)
        for(int i = n; i >= 2; i--)
        {
            bool noswap = true;
            // bubbling starts from first till second last element
            for(int j = 0; j <= i-2; j++)
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    noswap = false;
                    times++;
                }
            // if there was no swap done, it means the array has been sorted
            if(noswap) break;
        }
        return times;
    }

    int inssort(int arr[], int n){
        times = 0;
        // a sub-array of one element(i.e first) is already sorted, so start the sub-array of first two elements
        for(int i = 1; i < n; i++)
            // insert the rightmost element in the correct place by continuosly moving it to the left until its left element is greater
            for(int j = i; arr[j] < arr[j-1]; j--)
            {
                swap(arr[j], arr[j-1]);
                times++;
            }
        return times;
    }
};

int main(){
    Solution sol;
    int array[] = {3, 13, 46, 24, 52, 20, 9};
    int size = sizeof(array)/sizeof(int);

    sol.display(array, size);
    std::cout<<'\n';
    // Selection Sort
    // std::cout<<sol.selsort(array, size);

    // Bubble Sort
    // std::cout<<sol.bubsort(array, size);

    // Insertion Sort
    // std::cout<<sol.inssort(array, size);


    std::cout<<'\n';
    sol.display(array, size);

    std::cout<<"\n\n";
return 0;
}