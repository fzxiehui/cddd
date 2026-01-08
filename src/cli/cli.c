#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "book_cli.h"

int cli_run(int argc, char **argv)
{
    if (argc < 2) {
        printf("usage: app <command>\n");
        return -1;
    }

    if (strcmp(argv[1], "book") == 0) {
        return book_cli_run(argc - 1, argv + 1);
    }

    printf("unknown command: %s\n", argv[1]);
    return -1;
}
