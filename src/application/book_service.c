#include "book_service.h"
#include "../domain/book/book.h"
#include "../domain/book/book_repo.h"
#include "dto/book_dto.h"
#include <string.h>
#include <stdio.h>

/* 通过id与title创建book */
int book_create_service(struct book_repo *repo,
                        int id,
                        const char *title)
{
	struct book b;

	if (!repo || !repo->save)
		return -1;

	if (book_init(&b, id, title) != 0)
		return -1;

	return repo->save(repo, &b);
}

/* 通过 id 改标题 */ 
int book_rename_service(struct book_repo *repo,
                        int id,
                        const char *new_title)
{
	struct book b;

	if (!repo || !repo->load || !repo->save)
		return -1;

	if (repo->load(repo, id, &b) != 0)
		return -1;

	if (book_rename(&b, new_title) != 0)
		return -1;

	return repo->save(repo, &b);
}

/* 通过dto创建 book */
int book_create_from_dto(struct book_repo *repo,
                         const struct book_dto *dto)
{
    struct book b;

    if (!repo || !dto)
        return -1;

    /* 领域规则在这里生效 */
    if (book_init(&b, dto->id, dto->title) != 0)
        return -1;

    return repo->save(repo, &b);
}

/* 通过 book id 获取dto 形式的book */
int book_get_book_dto(struct book_repo *repo,
                      int id,
                      struct book_dto *dto)
{
    if (!repo || !dto)
        return -1;

    struct book b;
    if (repo->load(repo, id, &b) != 0)
        return -1;

    memset(dto, 0, sizeof(*dto));
    dto->id = b.id;
    snprintf(dto->title, sizeof(dto->title), "%s", b.title);

    return 0;
}
