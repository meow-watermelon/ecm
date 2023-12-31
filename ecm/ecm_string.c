#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecm_string.h"

struct string_occurrence_info *string_occurrence(char *input_string, char input_token) {
    char *cursor;
    cursor = input_string;
    struct string_occurrence_info *string;
    string = (struct string_occurrence_info *)malloc(sizeof(struct string_occurrence_info));

    string->token = input_token;
    string->count = 0;
    string->string_length = strlen(input_string);

    // allocate an array to store index value(s)
    size_t original_char_index_size = string->string_length * sizeof(size_t);
    string->char_index = (long int *)malloc(original_char_index_size);

    if (string->char_index == NULL) {
#ifdef DEBUG
        perror("failed to allocate memory for string->char_index");
#endif
        free(string);
        string = NULL;
        return NULL;
    }
    long int *char_index_cursor = string->char_index;

    while (*cursor != '\0') {
        if (*cursor == string->token) {
            int index = cursor - input_string;
            *char_index_cursor = index;
#ifdef DEBUG
    printf("char_index address: %p => char_index value: %ld\n", (void *)char_index_cursor, *char_index_cursor);
#endif
            ++char_index_cursor;
            ++string->count;
        }

        ++cursor;
    }

    // reduce index array size only when there is at least one index found
    if (string->count > 0 && string->count < string->string_length) {
        size_t reduced_char_index_size = string->count * sizeof(size_t);
#ifdef DEBUG
    printf("reducing allocated memory size from %zu bytes to %zu bytes\n", original_char_index_size, reduced_char_index_size);
#endif
        long int *char_index_reduced = (long int *)realloc(string->char_index, reduced_char_index_size);
        if (char_index_reduced != NULL) {
#ifdef DEBUG
    printf("char_index address: %p char_index_reduced address: %p\n", (void *)string->char_index, (void *)char_index_reduced);
#endif
            string->char_index = char_index_reduced;
        } else {
#ifdef DEBUG
            perror("failed to re-allocate memory, ignore reducing memory effort");
#endif
        }
    }

    return string;
}

short int integer_length(long int integer) {
    short int counter = 1;
    long int multiplier = 1;

    while (1) {
        if (integer / multiplier >= 0 && integer / multiplier < 10) {
            break;
        }

        ++counter;
        multiplier *= 10;
    }

    return counter;
}
