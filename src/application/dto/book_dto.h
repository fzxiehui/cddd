#ifndef APPLICATION_BOOK_DTO_H
#define APPLICATION_BOOK_DTO_H

#define BOOK_TITLE_MAX 64

/* dto 定义 */
struct book_dto {
	int  id;
	char title[BOOK_TITLE_MAX];
};

#endif
