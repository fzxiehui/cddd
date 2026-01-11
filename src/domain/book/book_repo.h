#ifndef DOMAIN_BOOK_REPO_H
#define DOMAIN_BOOK_REPO_H

struct book;

/*
 * 仓储接口（抽象）
 * 定义完成, 在main 或 cli 层级组装
 * 具体实现在infrastructure/persistence 中完成
 * 这样可以达到依赖反转目的
 * */
struct book_repo {
	int (*save)(struct book_repo *self, const struct book *b);
	int (*load)(struct book_repo *self, int id, struct book *out);
	void *ctx;   // repo 私有数据（文件路径 / FILE* 等）
};


#endif
