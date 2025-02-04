#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int n, min, max;
    printf("Enter how many numbers to generate: ");
    scanf("%d", &n);
    printf("Enter the range (min max): ");
    scanf("%d %d", &min, &max);
    
    printf("Random numbers between %d and %d:\n", min, max);
    for(int i = 0; i < n; i++) {
        int random_number = rand() % (max - min + 1) + min;
        printf("%d ", random_number);
    }
    printf("\n");
    
    return 0;
}