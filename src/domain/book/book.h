#ifndef DOMAIN_BOOK_H
#define DOMAIN_BOOK_H

#define BOOK_TITLE_MAX 64

struct book {
	int  id;
	char title[BOOK_TITLE_MAX];
};

/* 领域行为 */
int book_init(struct book *b, int id, const char *title);
int book_rename(struct book *b, const char *new_title);

#endif

