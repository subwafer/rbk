#include <stdio.h>
#include <stdlib.h>

void create_readme_file(void) {
    FILE *file;

    file = fopen("test_README.md", "w");
    if (file == NULL) {
        printf("ERROR: Unable to create file\n");
        exit(1);
    }

    fputs("# Project Name\n\n## Abstract\n\n## Author(s)\n", file);

}

int main(void) {
    create_readme_file();

    return 0;
}