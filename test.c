#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define TEST(fmt, ...) do { \
    fflush(stdout); \
    int r1 = printf("STD: [" fmt "]\n", ##__VA_ARGS__); \
    fflush(stdout); \
    int r2 = ft_printf("FT : [" fmt "]\n", ##__VA_ARGS__); \
    fflush(stdout); \
    if (r1 != r2) \
        printf("--> RET VALUE MISMATCH: std=%d vs ft=%d\n", r1, r2); \
    printf("----------------------------------------\n"); \
} while (0)

int main(void)
{
    printf("========================================\n");
    printf("        PRECISION BONUS TEST SUITE      \n");
    printf("========================================\n\n");

    /* ---------------------------------------------------- */
    /* 1. INTEGERS (%d, %i) & PRECISION                     */
    /* ---------------------------------------------------- */
    printf("--- [1] Integers (%d, %i) ---\n");
    TEST("%.0d", 0);          // Edge case: precision 0 with value 0 prints NOTHING
    TEST("%.d", 0);           // Same as .0
    TEST("%.5d", 42);         // Padding with leading zeros -> "00042"
    TEST("%.5d", -42);        // Negative with precision -> "-00042"
    TEST("%.3d", 12345);      // Precision smaller than number length -> "12345"
    TEST("%10.5d", 42);       // Width + Precision
    TEST("%10.5d", -42);      // Width + Precision (Negative)
    TEST("%-10.5d", 42);      // Left alignment '-' + Precision
    TEST("%-10.5d", -42);     // Left alignment '-' + Precision (Negative)
    TEST("%010.5d", 42);      // '0' flag ignored when precision '.' is present!
    TEST("%+10.5d", 42);      // '+' flag + Precision
    TEST("% 10.5d", 42);      // Space flag + Precision
    TEST("%.0d", 42);         // Non-zero value with precision 0
    TEST("%.5d", INT_MAX);   // INT_MAX
    TEST("%.5d", INT_MIN);   // INT_MIN

    /* ---------------------------------------------------- */
    /* 2. UNSIGNED INTEGERS (%u) & PRECISION                */
    /* ---------------------------------------------------- */
    printf("\n--- [2] Unsigned (%u) ---\n");
    TEST("%.0u", 0);          // Precision 0 with 0
    TEST("%.5u", 42);         // Leading zeros
    TEST("%10.5u", 42);       // Width + Precision
    TEST("%010.5u", 42);      // '0' flag ignored when precision '.' is present
    TEST("%.10u", UINT_MAX);  // UINT_MAX

    /* ---------------------------------------------------- */
    /* 3. HEXADECIMAL (%x, %X) & PRECISION                  */
    /* ---------------------------------------------------- */
    printf("\n--- [3] Hexadecimal (%x, %X) ---\n");
    TEST("%.0x", 0);          // Precision 0 with 0 -> prints NOTHING
    TEST("%.0X", 0);
    TEST("%.5x", 0xabc);      // Leading zeros -> "00abc"
    TEST("%10.5x", 0xabc);    // Width + Precision
    TEST("%#10.5x", 0xabc);   // '#' hash flag + Width + Precision
    TEST("%#10.5X", 0xabc);   // Uppercase hash + Precision
    TEST("%#5.0x", 0);        // Hash with 0 value and 0 precision

    /* ---------------------------------------------------- */
    /* 4. STRINGS (%s) & PRECISION                          */
    /* ---------------------------------------------------- */
    printf("\n--- [4] Strings (%s) ---\n");
    TEST("%.0s", "Hello");    // Truncate to 0 characters -> ""
    TEST("%.3s", "Hello");    // Truncate string -> "Hel"
    TEST("%.10s", "Hello");   // Precision greater than string length -> "Hello"
    TEST("%10.3s", "Hello");  // Width + Precision truncation -> "       Hel"
    TEST("%-10.3s", "Hello"); // Left alignment + Precision truncation -> "Hel       "
    TEST("%.3s", NULL);       // NULL pointer with precision (prints "(nul)" or similar truncation)

    /* ---------------------------------------------------- */
    /* 5. POINTERS (%p) & PRECISION                         */
    /* ---------------------------------------------------- */
    printf("\n--- [5] Pointers (%p) ---\n");
    int a = 42;
    TEST("%.5p", &a);         // Pointer precision (note standard implementation behaviors)
    TEST("%15.10p", &a);      // Width + Precision
    TEST("%.0p", NULL);       // NULL pointer precision
    TEST("%10.0p", NULL);

    /* ---------------------------------------------------- */
    /* 6. COMMON TRAPS & COMBINATIONS                       */
    /* ---------------------------------------------------- */
    printf("\n--- [6] Common Traps ---\n");
    TEST("%010.5d", -42);     // Standard says '0' flag is ignored if '.' is present with integers
    TEST("%+010.5d", 42);     // Multiple flags: +, 0, width, precision
    TEST("%-010.5d", 42);     // '-' overrides '0'
    TEST("%d", 0);           // Empty precision defaults to 0
    TEST("%5.d", 0);          // Width 5, precision 0 with value 0 -> "     " (5 spaces)

    return (0);
}