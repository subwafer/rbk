#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char project_name[100];
char summary[1024];

void create_readme_file(void) {
    FILE *file;

    file = fopen("test_README.md", "w");
    if (file == NULL) {
        printf("ERROR: Unable to create file\n");
        exit(1);
    }

    fputs("# Project Name\n\n## Abstract\n\n## Author(s)\n", file);
}

void strip_newline(int length, char arr[]) {
    if (arr[length] == '\n') {
        arr[length - 1] = '\0';
    }
}

void prompt_for_project_name(void) {
    printf("Project name > ");
    fgets(project_name, 100, stdin);

    strip_newline(strlen(project_name), project_name);

    printf("Project name: %s\n", project_name);
}

void prompt_for_summary(void) {
    printf("Summary > ");
    fgets(summary, 1024, stdin);

    strip_newline(strlen(summary), summary);


    printf("Summary: %s\n", summary);
}

int main(void) {

    prompt_for_project_name();
    prompt_for_summary();

    // create_readme_file();

    return 0;
}