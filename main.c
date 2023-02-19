#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct project {
    char README_FILE_PATH[300];
    char project_name[100];
    char summary[1024];

    int multiple_authors;
    char author_name[100];
    char author_email[200];
    char author_role[100];
    char authors[100][400];
};

void create_readme_file(struct project *p) {
    FILE *file;

    file = fopen(p->README_FILE_PATH, "w");
    if (file == NULL) {
        printf("ERROR: Unable to create file\n");
        exit(1);
    }

    // Desired output:
    // printf("# %s\n\n## Summary\n\n%s\n\n## Author(s)\n\n%s | %s | %s\n\n", 
    //     p->project_name, p->summary, p->author_name, p->author_email, p->author_role);

    fprintf(file, "# %s\n\n## Summary\n\n%s\n\n## Author(s)\n\n%s | %s | %s\n\n", 
        p->project_name, p->summary, p->author_name, p->author_email, p->author_role);

    printf("Successfully Generated README file\n");

}

void strip_newline(int length, char arr[]) {
    if (arr[length - 1] == '\n') {
        arr[length - 1] = '\0';
    }
}

void prompt_for_project_name(struct project *p) {
    printf("Project name > ");
    fgets(p->project_name, 100, stdin);

    strip_newline(strlen(p->project_name), p->project_name);

    // printf("Project name: %s\n", p->project_name);
}

void prompt_for_summary(struct project *p) {
    printf("Summary > ");
    fgets(p->summary, 1024, stdin);

    strip_newline(strlen(p->summary), p->summary);


    // printf("Summary: %s\n", p->summary);
}

void prompt_for_author_temp(struct project *p) {
    printf("Author name > ");
    fgets(p->author_name, 100, stdin);

    strip_newline(strlen(p->author_name), p->author_name);

    // printf("Author Name: %s\n", p->author_name);


    printf("Author email > ");
    fgets(p->author_email, 200, stdin);

    strip_newline(strlen(p->author_email), p->author_email);

    // printf("Author Email: %s\n", p->author_email);


    printf("Author role > ");
    fgets(p->author_role, 100, stdin);

    strip_newline(strlen(p->author_role), p->author_role);

    // printf("Author Role: %s\n", p->author_role);
}

void generate_c_boilerplate() {
    // TODO: Create the 'example' directory if it is not found
    FILE *file;

    file = fopen("example/test_main.c", "w");
    if (file == NULL) {
        printf("ERROR: Unable to create c boilerplate file\n");
        exit(1);
    }

    // Desired output:
    fprintf(file, "/*\n");
    fprintf(file, "\tProject generated by readyme cli\n");
    fprintf(file, "*/\n\n");
    fprintf(file, "#include <stdio.h>\n\n");
    fprintf(file, "int main(int argc, char **argv) {\n");
    fprintf(file, "\t(void) argc;\n");
    fprintf(file, "\t(void) argv;\n\n");
    fprintf(file, "\tchar hello[] = \"Hello, World!\";\n");
    fprintf(file, "\tprintf(\"%%s\\n\", hello);\n\n");
    fprintf(file, "\treturn 0;\n");
    fprintf(file, "}\n");

    printf("Successfully Generated C boilerplate file\n");

}

int main(int argc, char *argv[]) {
    int DEBUG_MODE = 0;

    struct project p;

    if (argc > 1) {
        for (int i = 0; i < argc; i++) {
            if (strcmp(argv[i], "--debug") != 0) {
                DEBUG_MODE = 1;
            }
        }
    }

    if (DEBUG_MODE == 1) {
        strcpy(p.README_FILE_PATH, "example/test_README.md");
        printf(">>> DEBUG MODE ACTIVE. Creating file: %s<<<<\n", p.README_FILE_PATH);
    } else {
        strcpy(p.README_FILE_PATH, "example/README.md");
    }


    prompt_for_project_name(&p);
    prompt_for_summary(&p);
    prompt_for_author_temp(&p);
    create_readme_file(&p);

    generate_c_boilerplate();

    return 0;
}