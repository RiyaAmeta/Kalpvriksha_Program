#include <stdio.h>
#include <math.h>
int ModularExponentiation(int base, int exponent, int modulus)
{
    if (modulus < 1)
    {
        printf("Modulus value M should be greater than 1\n");
        return -1;
    }

    int result = 1;
    base = base % modulus;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }

        exponent = exponent / 2;
        base = (base * base) % modulus;
    }

    return result;
}

int main()
{
    int B, N, M;

    printf("Enter base (B): ");
    scanf("%d", &B);
    printf("Enter exponent (N): ");
    scanf("%d", &N);
    printf("Enter modulus (M): ");
    scanf("%d", &M);

    int result = ModularExponentiation(B, N, M);

    if (result != -1)
    {
        printf("Result: %d\n", result);
    }

    return 0;
}
