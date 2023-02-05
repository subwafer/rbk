#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct project {
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

    file = fopen("test_README.md", "w");
    if (file == NULL) {
        printf("ERROR: Unable to create file\n");
        exit(1);
    }

    // Desired output:
    printf("# %s\n\n## Summary\n\n%s\n\n## Author(s)\n\n%s | %s | %s\n\n", 
        p->project_name, p->summary, p->author_name, p->author_email, p->author_role);

    fprintf(file, "# %s\n\n## Summary\n\n%s\n\n## Author(s)\n\n%s | %s | %s\n\n", 
        p->project_name, p->summary, p->author_name, p->author_email, p->author_role);

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

    printf("Project name: %s\n", p->project_name);
}

void prompt_for_summary(struct project *p) {
    printf("Summary > ");
    fgets(p->summary, 1024, stdin);

    strip_newline(strlen(p->summary), p->summary);


    printf("Summary: %s\n", p->summary);
}

void prompt_for_author(struct project *p) {
    int counter = 0;
    printf("How many authors? ");
    scanf("%d", &p->multiple_authors);
    getchar();

    while (p->multiple_authors > 1 && counter < p->multiple_authors) {
        printf("Author name > ");
        fgets(p->author_name, 100, stdin);

        strip_newline(strlen(p->author_name), p->author_name);

        printf("Author Name: %s\n", p->author_name);


        printf("Author email > ");
        fgets(p->author_email, 200, stdin);

        strip_newline(strlen(p->author_email), p->author_email);

        printf("Author Email: %s\n", p->author_email);


        printf("Author role > ");
        fgets(p->author_role, 100, stdin);

        strip_newline(strlen(p->author_role), p->author_role);

        printf("Author Role: %s\n", p->author_role);

        counter++;
    }
}

void prompt_for_author_temp(struct project *p) {
    printf("Author name > ");
    fgets(p->author_name, 100, stdin);

    strip_newline(strlen(p->author_name), p->author_name);

    printf("Author Name: %s\n", p->author_name);


    printf("Author email > ");
    fgets(p->author_email, 200, stdin);

    strip_newline(strlen(p->author_email), p->author_email);

    printf("Author Email: %s\n", p->author_email);


    printf("Author role > ");
    fgets(p->author_role, 100, stdin);

    strip_newline(strlen(p->author_role), p->author_role);

    printf("Author Role: %s\n", p->author_role);
}

int main(void) {
    struct project p;

    prompt_for_project_name(&p);
    prompt_for_summary(&p);

    prompt_for_author_temp(&p);

    create_readme_file(&p);

    return 0;
}