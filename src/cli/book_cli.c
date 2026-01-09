#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book_cli.h"
#include "application/book_service.h"
#include "application/dto/book_dto.h"

/* repo 注入点 */
#include "infrastructure/persistence/book_repo_file.h"

int book_cli_run(int argc, char **argv)
{
	/* repo */
	struct book_repo repo;
	file_book_repo_init(&repo, "./books.db");

	if (argc < 2) {
		printf("usage: ddd book <add><get>\n");
		return -1;
	}

	if (strcmp(argv[1], "add") == 0) {
		if (argc < 4) {
			printf("usage: app book add <id> <title>\n");
			return -1;
		}
		book_create_service(&repo, atoi(argv[2]), argv[3]);

		return 0;
	}

	if (strcmp(argv[1], "get") == 0) {
		if (argc < 3) {
			printf("usage: app book get <id>\n");
			return -1;
		}
			struct book_dto dto = {};
			book_get_book_dto(&repo, atoi(argv[2]), &dto);
			printf("%s\n", dto.title);

		return 0;
	}

	printf("unknown book command\n");
	return -1;
}
