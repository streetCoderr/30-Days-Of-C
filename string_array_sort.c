/* I used merge sort for this problem. However, implementing the solution with insertion sort should do because the problem statement clearly stated that the maximum number of strings won't exceed 50. 
Therefore using mergesort is kinda like an overkill because where mergesort really shines is when n(number of items to sort) is large.
However, I used mergesort just for the sake of getting my hands more dirty with C.*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int len1, len2;
    int len = (len2 = strlen(b)) <  (len1 = strlen(a)) ? len2 : len1; 
    int count = 0;
    while(count < len) {
        if (b[count] < a[count]) return 1;
        else if (a[count] < b[count]) return -1;
        count++;
    }
    return len1 == len2 ? 0 : (len2 < len1 ? 1 : -1);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int len1, len2;
    int len = (len2 = strlen(b)) <  (len1 = strlen(a)) ? len2 : len1; 
    int count = 0;
    while(count < len) {
        if (b[count] < a[count]) return -1;
        else if (a[count] < b[count]) return 1;
        count++;
    }
    return len1 == len2 ? 0 : (len1 < len2 ? 1 : -1); 
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distChar1[26] = { 0 };
    int distChar2[26] = { 0 };
    int len1 = strlen(a), len2 = strlen(b); 
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < len1; i++) {
        if (!distChar1[a[i] - 'a']) {
            distChar1[a[i] - 'a']++;
            sum1++;
        }
    }
    for (int i = 0; i < len2; i++) {
        if (!distChar2[b[i] - 'a']) {
            distChar2[b[i] - 'a']++;
            sum2++;
        }
    }
    if (sum1 == sum2) {
        int len = len2 < len1 ? len2 : len1;
        int count = 0;
        while(count < len) {
            if (b[count] < a[count]) return 1;
            else if (a[count] < b[count]) return -1;
            count++;
        }
        return len1 == len2 ? 0 : (len2 < len1 ? 1 : -1);
    }
    return sum1 - sum2;
}

int sort_by_length(const char* a, const char* b) {
    int len1, len2;
    if ((len1 = strlen(a)) == (len2 = strlen(b))) {
        int count = 0;
        while(count < len1) {
            if (b[count] < a[count]) return 1;
            else if (a[count] < b[count]) return -1;
            count++;
        }
        return 0;
    }
    return len1 - len2;
}

void merge (char** arr, char** tmp_arr, int lo, int mid, int hi, int (*cmp_func)(const char* a, const char* b)) {
    int h1 = lo, h2 = mid+1;
    for (int i = lo; i <= hi; i++) tmp_arr[i] = arr[i];
    for (int i = lo; i <= hi; i++) {
        if (h1 > mid) arr[i] = tmp_arr[h2++];
        else if (h2 > hi) arr[i] = tmp_arr[h1++];
        else {
            if(cmp_func(tmp_arr[h1],tmp_arr[h2]) <= 0) 
                arr[i] = tmp_arr[h1++];
            else arr[i] = tmp_arr[h2++];
        }
    }
}

void actual_string_sort(char** arr, char** tmp_arr, const int lo, const int hi,int (*cmp_func)(const char* a, const char* b)){
    if (lo >= hi) return;
    int mid = (hi+lo)/2;
    actual_string_sort(arr, tmp_arr, lo, mid, cmp_func);
    actual_string_sort(arr, tmp_arr, mid+1, hi, cmp_func);
    merge(arr, tmp_arr, lo, mid, hi, cmp_func);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char** tmp_arr = (char**)malloc(len*sizeof(char*));
    actual_string_sort(arr, tmp_arr, 0, len-1, (cmp_func));
    free(tmp_arr);
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
