#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "exercise-1.h"

#define INPUT_LENGTH 1024
#define NUL '\0'

char INPUT_TEXT[INPUT_LENGTH];

int main() {
    do {
        printf("Please enter a text (Max (%d) chars):\n", INPUT_LENGTH);
        size_t current_size = 0;
        do {
            INPUT_TEXT[current_size++] = getchar(); // NOLINT(*-narrowing-conversions)
        } while (current_size < INPUT_LENGTH && INPUT_TEXT[current_size - 1] != '\n');
        INPUT_TEXT[current_size - 1] = '\0';

        printf("Choose options:\nA - all on one line\nB - on three lines\nC - inside a box\n");

        switch (getchar()) {
            case 'A': print_string_on_one_line(INPUT_TEXT, INPUT_LENGTH);
                exit(0);
            case 'B': print_string_on_three_lines(INPUT_TEXT, INPUT_LENGTH);
                exit(0);
            case 'C': print_string_inside_box(INPUT_TEXT, INPUT_LENGTH);
                exit(0);
            default:
                printf("Please enter a valid option\n");
        }
    } while (true);
}

void print_string_on_one_line(char s[], const size_t len) {
    if (len == 0) return;
    for (int i = 0; i < len && s[i] != NUL; i++) {
        putchar(s[i]);
    }
    putchar('\n');
}

void print_string_on_three_lines(char s[], size_t len) {
    if (len == 0) return;

    size_t actual_len = 0;
    size_t whitespaces_count = 0;

    for (actual_len = 0; actual_len < len && s[actual_len] != NUL; actual_len++) {
        if (isspace(s[actual_len])) {
            whitespaces_count++;
        }
    }

    const size_t whitespaces_per_line = whitespaces_count / 3;

    whitespaces_count = 0;

    for (size_t i = 0; i < actual_len; i++) {
        if (isspace(s[i])) {
            if (whitespaces_count == whitespaces_per_line) {
                whitespaces_count = 0;
                putchar('\n');
            } else {
                whitespaces_count++;
                putchar(' ');
            }
        } else {
            putchar(s[i]);
        }
    }

    putchar('\n');
}

void print_string_inside_box(char s[], const size_t len) {
    if (len == 0) return;

    size_t actual_len = 0;

    while (actual_len < len && s[actual_len] != NUL) {
        actual_len++;
    }

    for (size_t i = 0; i < actual_len + 4; i++) {
        putchar('-');
    }

    printf("\n| %s |\n", s);

    for (size_t i = 0; i < actual_len + 4; i++) {
        putchar('-');
    }
}
