#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <assert.h>


bool DEBUG_MODE = false;


char *read_from_file(char *file_path, size_t *content_size);
size_t generate_from_template(char *file_path, char *dest_path);

// TODO: Make this working in live environment (exe move and use)
// TODO: Create dirs

void handle_cli_args(int argc, char **argv);

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    // char *template_path = "./examples/templates/simplec";
    // char *dest_path = "./test_main.c";
    char *template_path = "./examples/templates/clangbuild";
    char *dest_path = "./test_build.sh";
    generate_from_template(template_path, dest_path);

    return EXIT_SUCCESS;
}

void handle_cli_args(int argc, char **argv) {
    (void) argc;
    (void) argv;

/*
// NOTE: Look into getopt GNU for posix func for reading cli args
    // OR you can just write your own. argv is a pointer to pointer or a pointer to a char array
    // handle_cli_args(argc, argv);
    if (argc > 1) {
        for (int i = 0; i < argc; i++) {
            if (strcmp(argv[i], "--debug") != 0) {
                DEBUG_MODE = true;
            }
        }
    }

    if (DEBUG_MODE == false) {
        strcpy(p.README_FILE_PATH, "example/test_README.md");
        printf(">>> DEBUG MODE ACTIVE. Creating file: %s<<<<\n", p.README_FILE_PATH);
    } else {
        strcpy(p.README_FILE_PATH, "example/README.md");
    }

    // TODO: Switch statement per args
*/

    /*
    ** config command
    ** Allow user to create templates.
    ** example: rbk config --templates
    **
    ** example: rbk create . --template=cgui --sc=git
    **
     */

    printf("handle_cli_args not implemented!");
}

char *read_from_file(char *file_path, size_t *content_size) {
    // read in a file from somewhere, return the pointer to the contents
    char *buffer = {0};

    FILE *file = fopen(file_path, "r");
    if (file == NULL) goto error;

    if (fseek(file, 0, SEEK_END) < 0) goto error;

    long s = ftell(file);
    if (s < 0) goto error;

    if (fseek(file, 0, SEEK_SET) < 0) goto error;

    buffer = malloc(s * sizeof(char));

    size_t c = fread(buffer, 1, s, file);
    if (ferror(file)) goto error;

    assert(c == (size_t) s);

    if (content_size) {
        *content_size = c;
    }

    fclose(file);

    return buffer;

    error:
        if (file) fclose(file);
        if (buffer) free(buffer);

        return NULL;
}

size_t generate_from_template(char *template_path, char *dest_path) {
    size_t content_size = 0;
    char *template_content = read_from_file(template_path, &content_size);

    FILE *dest_file = fopen(dest_path, "w");

    fprintf(stdout, "Creating from template %s to dest path: %s\n", template_path, dest_path);

    // Will this create the file if it doesn't exist?
    fwrite(template_content, 1, content_size, dest_file);

    fprintf(stdout, "Completed writing template to file.\n");

    if (dest_file) fclose(dest_file);

    return content_size;
}







/*
// OLD STUFF
void create_readme_file(struct project *p);
void strip_newline(int length, char arr[]);
void prompt_for_project_name(struct project *p);
void prompt_for_summary(struct project *p);
void prompt_for_author_temp(struct project *p);



struct project {
    // TODO: Convert to pointers when relevant. From stack to heap.
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

    // TODO: Separate this out to make it easier to read
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
}

void prompt_for_summary(struct project *p) {
    printf("Summary > ");
    fgets(p->summary, 1024, stdin);

    strip_newline(strlen(p->summary), p->summary);
}

void prompt_for_author_temp(struct project *p) {
    printf("Author name > ");
    fgets(p->author_name, 100, stdin);

    strip_newline(strlen(p->author_name), p->author_name);

    printf("Author email > ");
    fgets(p->author_email, 200, stdin);

    strip_newline(strlen(p->author_email), p->author_email);

    printf("Author role > ");
    fgets(p->author_role, 100, stdin);

    strip_newline(strlen(p->author_role), p->author_role);
}

*/
