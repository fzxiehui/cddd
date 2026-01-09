#include <stdio.h>
#include <string.h>
#include "../../domain/book/book.h"
#include "../../domain/book/book_repo.h"

struct file_repo_ctx {
    const char *path;
};

static int file_save(struct book_repo *self, const struct book *b)
{
    struct file_repo_ctx *ctx = self->ctx;
    FILE *fp = fopen(ctx->path, "a");
    if (!fp)
        return -1;

    fprintf(fp, "%d|%s\n", b->id, b->title);
    fclose(fp);
    return 0;
}

static int file_load(struct book_repo *self, int id, struct book *out)
{
    struct file_repo_ctx *ctx = self->ctx;
    FILE *fp = fopen(ctx->path, "r");
    if (!fp)
        return -1;

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        int fid;
        char title[128];

        if (sscanf(line, "%d|%127[^\n]", &fid, title) == 2) {
            if (fid == id) {
                out->id = fid;
                strncpy(out->title, title, sizeof(out->title) - 1);
                fclose(fp);
                return 0;
            }
        }
    }

    fclose(fp);
    return -1;
}

void file_book_repo_init(struct book_repo *repo, const char *path)
{
    static struct file_repo_ctx ctx;
    ctx.path = path;

    repo->save = file_save;
    repo->load = file_load;
    repo->ctx  = &ctx;
}
