#include "../../domain/book/book.h"
#include "../../domain/book/book_repo.h"
// #include <string.h>

static struct book g_store;
static int g_has_data = 0;

static int mem_save(struct book *b)
{
	g_store = *b;
	g_has_data = 1;
	return 0;
}

static int mem_load(int id, struct book *b)
{
	if (!g_has_data || g_store.id != id)
		return -1;

	*b = g_store;
	return 0;
}

/* 对外暴露的仓储实现 */
struct book_repo memory_book_repo = {
    .save = mem_save,
    .load = mem_load,
};
