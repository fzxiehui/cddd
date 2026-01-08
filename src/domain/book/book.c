
#include "book.h"
#include <string.h>

int book_init(struct book *b, int id, const char *title)
{
	if (!b || !title || id <= 0)
		return -1;

	memset(b, 0, sizeof(*b));
	b->id = id;
	strncpy(b->title, title, BOOK_TITLE_MAX - 1);
	return 0;
}

int book_rename(struct book *b, const char *new_title)
{
	if (!b || !new_title || strlen(new_title) == 0)
		return -1;

	strncpy(b->title, new_title, BOOK_TITLE_MAX - 1);
	return 0;
}
