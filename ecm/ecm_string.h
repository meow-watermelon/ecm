#ifndef ECM_STRING_H
#define ECM_STRING_H

/*
 * string_occurrence:
 * - Analyzes a given string
 * - Identifies occurrences of a specified character
 * - Records the indices of these occurrences in a dynamically allocated array within a struct
 * - Provides information about the occurrences and their locations
*/

struct string_occurrence_info {
    size_t string_length;
    char token;
    long int *char_index;
    size_t count;
};
extern struct string_occurrence_info *string_occurrence(char *input_string, char input_token);

/*
 * integer_length: return length of an integer
 *
*/

extern short int integer_length(long int integer);

#endif /* ECM_STRING_H */
