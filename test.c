#include <stdio.h>
#include <stdlib.h>
#include "ecm/ecm_math.h"
#include "ecm/ecm_string.h"

int main() {
    long int n = 2;
    long int number = 123456789;
    char *str1 = "SDFSDFERTYJHGFDSFGHRRFDVBFGGRFDSFYJUKIJHGFDSCFGBHGVFCDFRETHYJHGFDQWERTYUIOKJHGFDSXCVBNMKLOPIUYTREWSDFGHNMNBVCDEFRGT";
    char c = 'C';

    printf("powi(%ld, %d): %ld\n", n, 5, powi(n, 5));
    printf("integer_length(%ld): %d\n", number, integer_length(number));

    struct string_occurrence_info *p = string_occurrence(str1, c);

    if (p == NULL) {
        perror("failed to allocate memory for string_occurrence_info struct");
        exit(EXIT_FAILURE);
    }

    printf("count: %zu\n", p->count);
    printf("index 0: %ld\n", p->char_index[0]);

    free(p->char_index);
    p->char_index = NULL;

    free(p);
    p = NULL;

    return 0;
}
