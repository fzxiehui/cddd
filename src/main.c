#include <stdio.h>
#include "application/book_service.h"
#include "application/dto/book_dto.h"
#include "application/dto/book_dto_json.h"
#include "infra/book_repo.h"

int main(void)
{
    const char *json =
        "{ \"id\": 1, \"title\": \"DDD with C\" }";

    struct book_dto dto;

    if (book_dto_from_json(json, &dto) != 0) {
        printf("json error\n");
        return -1;
    }

    book_create_from_dto(&memory_book_repo, &dto);
    printf("done\n");
    return 0;
}
