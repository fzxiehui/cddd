#ifndef DOMAIN_BOOK_REPO_H
#define DOMAIN_BOOK_REPO_H

struct book;

/* 仓储接口（抽象） */
struct book_repo {
	int (*save)(struct book_repo *self, const struct book *b);
	int (*load)(struct book_repo *self, int id, struct book *out);
	void *ctx;   // repo 私有数据（文件路径 / FILE* 等）
};

#endif
