#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book_cli.h"
#include "application/book_service.h"
#include "application/dto/book_dto.h"

/* repo 注入点 */
#include "infrastructure/persistence/book_repo_memory.h"

int book_cli_run(int argc, char **argv)
{
	if (argc < 2) {
		printf("usage: app book <add>\n");
		return -1;
	}

	if (strcmp(argv[1], "add") == 0) {
		if (argc < 4) {
			printf("usage: app book add <id> <title>\n");
			return -1;
		}

		struct book_dto dto = {0};
		dto.id = atoi(argv[2]);
		strncpy(dto.title, argv[3], sizeof(dto.title) - 1);

		book_create_from_dto(&memory_book_repo, &dto);
		printf("book added\n");
		return 0;
	}

	printf("unknown book command\n");
	return -1;
}
