#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int max = size - 1;
    int low = 0;
    int mid ;
    *count = 0;

    while(low <= max) { 
        mid = low + (max - low) / 2;
        (*count)++;
        if(mx_strcmp(arr[mid], s) == 0)
            return mid;
        else if(mx_strcmp(arr[mid], s) > 0)
            max = mid - 1;
        else if(mx_strcmp(arr[mid], s) < 0)
            low = mid + 1;
    }
    *count = 0;
    return -1;
}
