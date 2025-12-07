#include <stdio.h>

int binomial(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    return binomial(n - 1, r - 1) + binomial(n - 1, r);
}

int main() {
    int n, r;
    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);

    if (r > n) {
        printf("Invalid input: r cannot be greater than n\n");
        return 0;
    }

    printf("Binomial Coefficient C(%d, %d) = %d\n", n, r, binomial(n, r));

    return 0;
}
