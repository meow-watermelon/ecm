#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecm_string.h"

char *string_insert(char *orig_string, char *insert_string, size_t offset) {
    size_t orig_string_length = strlen(orig_string);
    size_t insert_string_length = strlen(insert_string);
    size_t alloc_size = orig_string_length + insert_string_length + 1;
    char *buffer = (char *)malloc(alloc_size);

    if (buffer == NULL) {
        return NULL;
    }

    // if offset is greater than or equal to original string index boundary then simply combining 2 strings
    if (offset >= orig_string_length ) {
        strcpy(buffer, orig_string);
        strcat(buffer, insert_string);

        return buffer;
    }

    // if offset is 0 then simply combining 2 strings
    if (offset == 0) {
        strcpy(buffer, insert_string);
        strcat(buffer, orig_string);

        return buffer;
    }

    size_t index = 0;

    while (index < offset) {
        buffer[index] = orig_string[index];
        ++index;
    }

    // rewind index by 1
    index = index - 1;

    buffer[index + 1] = '\0';

#ifdef DEBUG
    printf("index: %zu; pre string: %s\n", index, buffer);
#endif

    strcat(buffer, insert_string);
#ifdef DEBUG
    printf("index: %zu; middle string: %s\n", index, buffer);
#endif

    while (index < orig_string_length) {
        buffer[index + insert_string_length + 1] = orig_string[index + 1];
        ++index;
    }

    buffer[orig_string_length + insert_string_length] = '\0';

    return buffer;
}

char *string_reverse(char *input_string) {
    size_t string_length = strlen(input_string);
#ifdef DEBUG
    printf("string length: %zu\n", string_length);
#endif
    size_t index = 0;

    char *buffer = (char *)malloc(string_length + 1);
    if (buffer == NULL) {
        return NULL;
    }

    index = string_length;
    int i = 0;

    while (index > 0) {
        buffer[i] = input_string[index - 1];
        ++i;
        --index;
    }
    buffer[string_length] = '\0';

#ifdef DEBUG
    printf("buffer: %s; i: %d; index: %zu\n", buffer, i, index);
#endif

    return buffer;
}

struct string_occurrence_info *string_occurrence(char *input_string, char input_token) {
    char *cursor;
    cursor = input_string;
    struct string_occurrence_info *string;
    string = (struct string_occurrence_info *)malloc(sizeof(struct string_occurrence_info));

    if (string == NULL) {
#ifdef DEBUG
        perror("failed to allocate memory for string");
#endif
        return NULL;
    }

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
