
#include "./libft.h"
#include <stdio.h>

#include <string.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>

// Prototype of your exact function
int ft_strncmp(const char *s1, const char *s2, size_t n);

void run_test(int test_num, const char *desc, const char *s1, const char *s2, size_t n) {
    int orig_res = strncmp(s1, s2, n);
    int ft_res = ft_strncmp(s1, s2, n);

    // Normalize output values to their signs (-1, 0, 1) since the C standard 
    // only guarantees the sign of the difference, not the exact integer value.
    int orig_sign = (orig_res > 0) - (orig_res < 0);
    int ft_sign = (ft_res > 0) - (ft_res < 0);

    if (orig_sign == ft_sign) {
        printf("✅ Test %02d Passed: %s (n=%zu)\n", test_num, desc, n);
    } else {
        printf("❌ Test %02d FAILED: %s (n=%zu)\n", test_num, desc, n);
        printf("   [strncmp]: %d (Sign: %d) | [ft_strncmp]: %d (Sign: %d)\n", 
               orig_res, orig_sign, ft_res, ft_sign);
    }
}

int main(void) {
    printf("=== RUNNING LIBFT STRNCMP COMPARISON TESTS ===\n\n");

    // 1. Boundary & Limit Constraints
    run_test(1, "Zero characters requested (n = 0)", "Hello", "World", 0);
    run_test(2, "Single character exact boundary mismatch (n = 1)", "A", "B", 1);
    run_test(3, "Single character exact boundary match (n = 1)", "A", "A", 1);
    
    // 2. Strict n-Limit Enforcements
    run_test(4, "Strings match inside n, mismatch right at index n", "ABC", "ABZ", 2);
    run_test(5, "Strings match inside n, mismatch right at index n-1", "ABC", "ABZ", 3);
    run_test(6, "Requesting massive n on identical strings", "Hello", "Hello", 50);

    // 3. Early Termination & Null Checks
    run_test(7, "s1 ends early before n is reached", "AB", "ABCDE", 4);
    run_test(8, "s2 ends early before n is reached", "ABCDE", "AB", 4);
    run_test(9, "Both strings empty", "", "", 5);

    // 4. Hidden Data / Garbage Past Null Terminator
    // Creating manual array buffers to force garbage elements past '\0'
    char buf1[5] = {'A', 'B', '\0', 'X', 'Y'};
    char buf2[5] = {'A', 'B', '\0', '1', '2'};
    run_test(10, "Data matches but has distinct garbage past \\0", buf1, buf2, 5);

    // 5. Extended ASCII (The Unsigned Char Cast Validation)
    char ext_s1[2] = {(char)255, '\0'}; // Acts as a negative integer if signed
    char ext_s2[2] = {'A', '\0'};
    run_test(11, "Extended ASCII character vs normal ASCII", ext_s1, ext_s2, 1);

    printf("\n============================================\n");
    return 0;
}
