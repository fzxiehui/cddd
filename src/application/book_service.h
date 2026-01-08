
#ifndef APPLICATION_BOOK_SERVICE_H
#define APPLICATION_BOOK_SERVICE_H

#include "../domain/book/book_repo.h"
#include "./dto/book_dto.h"

int book_create_service(struct book_repo *repo,
                        int id,
                        const char *title);

int book_rename_service(struct book_repo *repo,
                        int id,
                        const char *new_title);

int book_create_from_dto(struct book_repo *repo,
                         const struct book_dto *dto);

int book_get_book_dto(struct book_repo *repo, 
		int id, struct book_dto *dto);
#endif
