#ifndef BOOK_DTO_JSON_H
#define BOOK_DTO_JSON_H

#include "application/dto/book_dto.h"

/*使用json 初始化 dto*/
int book_dto_from_json(const char *json, struct book_dto *dto);

#endif
