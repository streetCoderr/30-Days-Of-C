#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1001*sizeof(char));
    scanf("%[^\n]%*c", s);
    s = realloc(s, strlen(s));
    int digits[10] = {0};
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') digits[s[i]-'0']++;
    }
    for (int i = 0; i < 10; i++) printf("%d ", digits[i]);
    return 0;
}
