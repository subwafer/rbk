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

int main(int argc, char *argv[]) {
    if (argc > 0) {
        for (int i = 0; i < argc; i++) {
            // rbk .
            // rbk . -t=simplec
            // rbk --DEBUG
            if (strcmp(argv[i], "--DEBUG") == 0) {
                printf("########DEBUG MODE ACTIVE############\n\n");
                DEBUG_MODE = true;
            }
        }
    }

    char *template_path = {0};
    char *dest_path = {0};

    if (DEBUG_MODE == true) {
        // char *template_path = "./examples/templates/simplec";
        // char *dest_path = "./test_main.c";
        template_path = "./examples/templates/clangbuild";
        dest_path = "./test_build.sh";
    } else {
        printf("CLI Args not implemented.\n");
    }

    generate_from_template(template_path, dest_path);
    return EXIT_SUCCESS;
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


