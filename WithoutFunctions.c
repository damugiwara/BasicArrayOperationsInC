#include<stdio.h>

int main() {
    int arr[100], n, pos, val, i, choice, j, temp, start, end, mid, key;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    while(1) {
        printf("\nMenu:\n 1. Insertion\n 2. Deletion\n 3. Traversal\n 4. Bubble sort\n 5. Binary search\n 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter the position where you want to insert the element: ");
            scanf("%d", &pos);

            if(pos < 0 || pos > n) {
                printf("Invalid position.\n");
                break;
            }

            printf("Enter the element which you want to insert: ");
            scanf("%d", &val);

            for(i = n; i > pos; i--) {
                arr[i] = arr[i-1];
            }

            arr[pos] = val;
            n++;

            printf("Array after insertion:\n");
            for(i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 2:
            printf("Enter the position where you want to delete the element from: ");
            scanf("%d", &pos);

            if(pos < 0 || pos >= n) {
                printf("Invalid position.\n");
                break;
            }

            for(i = pos; i < n-1; i++) {
                arr[i] = arr[i+1];
            }

            n--;

            printf("Array after deletion:\n");
            for(i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 3:
            printf("Array elements are:\n");
            for(i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 4:
            for(i = 0; i < n - 1; i++) {
                for(j = 0; j < n - 1 - i; j++) {
                    if(arr[j] > arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            printf("Array has been sorted:\n");
            for(i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 5:
            printf("Enter the element to search for: ");
            scanf("%d", &key);

            start = 0;
            end = n - 1;
            int found = 0;

            while(start <= end) {
                mid = (start + end) / 2;

                if(arr[mid] == key) {
                    found = 1;
                    printf("Element found at index %d\n", mid);
                    break;
                }
                else if(arr[mid] < key) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }

            if(!found) {
                printf("Element not found in the array\n");
            }

            break;

        case 6:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}
