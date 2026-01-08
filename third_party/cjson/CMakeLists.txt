add_library(cjson cJSON.c)
target_include_directories(cjson 
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}
)
