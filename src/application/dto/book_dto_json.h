#ifndef BOOK_DTO_JSON_H
#define BOOK_DTO_JSON_H

#include "application/dto/book_dto.h"

int book_dto_from_json(const char *json, struct book_dto *dto);

#endif
