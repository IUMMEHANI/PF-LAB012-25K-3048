#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, extra, i;
    float total = 0.0;
    printf("Enter number of days for sales data: ");
    scanf("%d", &n);
    float *sales = (float*)malloc(n * sizeof(float));
    if (sales == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter sales for day %d: ", i + 1);
        scanf("%f", &sales[i]);
        total += sales[i];
    }
    printf("\nTotal sales for %d days: %.2f\n", n, total);
    printf("\nEnter number of additional days: ");
    scanf("%d", &extra);
    if (extra > 0) {
        sales = (float*)realloc(sales, (n + extra) * sizeof(float));
        if (sales == NULL) {
            printf("Memory reallocation failed.\n");
            return 1;
        }
        for (i = n; i < n + extra; i++) {
            printf("Enter sales for day %d: ", i + 1);
            scanf("%f", &sales[i]);
        }
        total = 0.0;
        for (i = 0; i < n + extra; i++) {
            total += sales[i];
        }
        printf("\nTotal sales for %d days: %.2f\n", n + extra, total);
    }
    free(sales);
    return 0;
}

