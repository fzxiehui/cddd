#ifndef DOMAIN_BOOK_REPO_H
#define DOMAIN_BOOK_REPO_H

struct book;

/* 仓储接口（抽象） */
struct book_repo {
    int (*save)(struct book *b);
    int (*load)(int id, struct book *b);
};

#endif
