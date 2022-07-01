#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    
    int k = -1, l = -1;
    for (int i = 0; i < n-1; i++) {
        if(strcmp(s[i], s[i+1]) < 0) k = i;
    }
    if (k == -1) return 0;
    for (int i = k+1; i < n; i++) {
        if (strcmp(s[k], s[i]) < 0) l = i;
    }
    
    char* tmp = s[k];
    s[k] = s[l];
    s[l] = tmp;
    for (int i = 1; i <= (n-k-1)/2; i++) {
        tmp = s[n-i];
        s[n-i] = s[k+i];
        s[k+i] = tmp;
    }
    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do {
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}