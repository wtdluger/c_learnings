#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printList(int *x, int length_x)
{
    // int length_x = sizeof(x);
    for (int i = 0; i < length_x; ++i)
    {
        printf("%d, ", x[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a; // Store the value pointed to by 'a' in a temporary variable
    *a = *b;       // Assign the value pointed to by 'b' to the location pointed to by 'a'
    *b = temp;     // Assign the temporary value (original value of 'a') to the location pointed to by 'b'
}

void bubbleSort(int *arr, int length_arr, bool printIterations) 
{
    // int length_arr = sizeof(arr);
    for (int i = 0; i < length_arr - 1; ++i) 
    {
        for (int j = 0; j < length_arr - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);

                if (printIterations) 
                {
                    printList(arr, length_arr);
                }
            }
        }
    }
}


int main()
{
    printf("How many elements to the list? ");
    int list_length;
    scanf("%d", &list_length);

    int list_to_sort[list_length];
    printf("Begin entering numbers\n");
    for (int i = 0; i < list_length; ++i)
    {
        int j;
        scanf("%d", &j);
        list_to_sort[i] = j;
    }
    printf("List complete.\n");
    
    printf("Should the sorting steps be printed?\n0 for No, 1 for Yes.\n");
    int x;
    scanf("%d", &x);
    if (x == 0)
    {
        // printf("Not Printing Steps\n");
        bubbleSort(list_to_sort, list_length, false);
        printList(list_to_sort, list_length);
        // need this last printList() to print the sorted list
    }
    else
    {
        // printf("Printing Steps\n");
        printList(list_to_sort, list_length);
        bubbleSort(list_to_sort, list_length, true);
        // no need one last printList() because bubbleSort will print it
    }
    
    
    return 0;
}