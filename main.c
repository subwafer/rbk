#include <stdio.h>
#include <stdlib.h>

char project_name[100];

void create_readme_file(void) {
    FILE *file;

    file = fopen("test_README.md", "w");
    if (file == NULL) {
        printf("ERROR: Unable to create file\n");
        exit(1);
    }

    fputs("# Project Name\n\n## Abstract\n\n## Author(s)\n", file);

}

void prompt_for_project_name(void) {
    printf("Project name > ");
    fgets(project_name, 100, stdin);

    printf("Project name: %s", project_name);
}

int main(void) {

    prompt_for_project_name();

    // create_readme_file();

    return 0;
}