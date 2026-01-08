add_executable(ddd
    main.c
    domain/book/book.c
    application/book_service.c
    infrastructure/persistence/book_repo_memory.c
    infrastructure/json/book_json.c
)

target_link_libraries(ddd
    PRIVATE
        cjson
)
target_include_directories(ddd
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
