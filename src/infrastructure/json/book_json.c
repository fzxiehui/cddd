#include "cJSON.h"
#include "../../application/dto/book_dto.h"
#include <string.h>

int book_dto_from_json(const char *json, struct book_dto *dto)
{
    cJSON *root = cJSON_Parse(json);
    if (!root)
        return -1;

    cJSON *id = cJSON_GetObjectItem(root, "id");
    cJSON *title = cJSON_GetObjectItem(root, "title");

    if (!cJSON_IsNumber(id) || !cJSON_IsString(title)) {
        cJSON_Delete(root);
        return -1;
    }

    dto->id = id->valueint;
    strncpy(dto->title, title->valuestring, BOOK_TITLE_MAX - 1);

    cJSON_Delete(root);
    return 0;
}
