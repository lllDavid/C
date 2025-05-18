#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_comments(FILE *input_file, FILE *output_file) {
    char ch, prev_ch = '\0';
    int inside_single_line_comment = 0, inside_multi_line_comment = 0;

    while ((ch = fgetc(input_file)) != EOF) {
        if (!inside_multi_line_comment && ch == '/' && prev_ch == '/') {
            inside_single_line_comment = 1;
            continue;
        }

        if (ch == '*' && prev_ch == '/') {
            inside_multi_line_comment = 1;
            prev_ch = ch;
            continue;
        }

        if (inside_single_line_comment) {
            if (ch == '\n') {
                inside_single_line_comment = 0;
                fputc(ch, output_file);
            }
            continue;
        }

        if (inside_multi_line_comment) {
            if (ch == '/' && prev_ch == '*') {
                inside_multi_line_comment = 0;
            }
            prev_ch = ch;
            continue;
        }

        fputc(ch, output_file);
        prev_ch = ch;
    }
}

int main() {
    FILE *input_file = fopen("input.c", "r");
    if (input_file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output_file = fopen("output.c", "w");
    if (output_file == NULL) {
        printf("Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    remove_comments(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Comments removed successfully!\n");
    return 0;
}
