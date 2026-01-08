#include "book_service.h"
#include "../domain/book/book.h"
#include "dto/book_dto.h"

int book_create_service(struct book_repo *repo,
                        int id,
                        const char *title)
{
	struct book b;

	if (!repo || !repo->save)
		return -1;

	if (book_init(&b, id, title) != 0)
		return -1;

	return repo->save(&b);
}

int book_rename_service(struct book_repo *repo,
                        int id,
                        const char *new_title)
{
	struct book b;

	if (!repo || !repo->load || !repo->save)
		return -1;

	if (repo->load(id, &b) != 0)
		return -1;

	if (book_rename(&b, new_title) != 0)
		return -1;

	return repo->save(&b);
}

int book_create_from_dto(struct book_repo *repo,
                         const struct book_dto *dto)
{
    struct book b;

    if (!repo || !dto)
        return -1;

    /* 领域规则在这里生效 */
    if (book_init(&b, dto->id, dto->title) != 0)
        return -1;

    return repo->save(&b);
}
