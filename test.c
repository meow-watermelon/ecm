#include <stdio.h>
#include "ecm/ecm_math.h"
#include "ecm/ecm_string.h"

int main() {
    long int n = 2;
    long int number = 123456789;
    printf("powi(%ld, %d): %ld\n", n, 5, powi(n, 5));
    printf("integer_length(%ld): %d\n", number, integer_length(number));
}
