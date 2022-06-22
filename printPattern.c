#include <stdio.h>

void incOrDec(int, int, int);
int main() 
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern. 
      int control = n;
      int increaseControl = 0;
      while(control <= n) {
          int rept = control*2-1;
          incOrDec(control+1, n, 0);
          for (int i = 0; i < rept; i++) printf("%d ", control); 
          incOrDec(control+1, n, 1);
          if (control == 1) increaseControl = 1;
          increaseControl ? control++ : control--;
      }
    return 0;
}
void incOrDec(int low, int high, int indicator) {
    if (indicator == 1) {
        for (int i = low; i < high; i++) printf("%d ", i);
        if (low <= high) printf("%d", high);
        printf("\n");
    } else {
        for (int i = high; i >= low; i--) printf("%d ", i);
    }
}

