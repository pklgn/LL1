set(PROJECT_LIBRARY_SRC_DIR
	${CMAKE_CURRENT_SOURCE_DIR}
	CACHE PATH "LL(1)' src directory"
)
set(PROJECT_LIBRARY_TARGET
	ll_1_lib
	CACHE STRING "LL(1) lib"
)
set(PROJECT_APP_TARGET
	ll_1_app
	CACHE STRING "LL(1) app"
)

set(_lib_headers_list
	pch.h
	TaskTable.h
	LLParser.h
	Table.h
	TableRow.h
	common.h
	# Place here relative paths to all *.(h|hpp)
)

set(_lib_src_list
	pch.cpp
	TaskTable.cpp
	LLParser.cpp
	Table.cpp
	TableRow.cpp
	# Place here relative paths to all *.(h|hpp)
)

add_library(${PROJECT_LIBRARY_TARGET}
	${_lib_headers_list}
	${_lib_src_list}
)

add_executable(${PROJECT_APP_TARGET}
	pch.h
	pch.cpp

	main.cpp
)

target_link_libraries(
	${PROJECT_APP_TARGET}
PRIVATE
	${PROJECT_LIBRARY_TARGET}	
)

target_include_directories(
	${PROJECT_LIBRARY_TARGET}
PRIVATE
	${PROJECT_LIBRARY_SRC_DIR}
)

target_include_directories(
	${PROJECT_APP_TARGET}
PRIVATE
	${PROJECT_LIBRARY_SRC_DIR}
)

if(MSVC)
	source_group(
		TREE ${CMAKE_CURRENT_SOURCE_DIR}
		PREFIX "Source Files"
		FILES ${_lib_src_list}
	)
	source_group(
		TREE ${CMAKE_CURRENT_SOURCE_DIR}
		PREFIX "Header Files"
		FILES ${_lib_headers_list}
	)
endif()
