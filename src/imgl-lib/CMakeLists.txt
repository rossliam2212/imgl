set(LIB_HEADERS
)

set(LIB_SOURCES
)

set(LIB_INCLUDES
)

add_library(${LIB_NAME} STATIC
        ${LIB_SOURCES}
)
target_link_libraries(${LIB_NAME} PUBLIC

)
target_include_directories(${LIB_NAME} PUBLIC ${LIB_INCLUDES})
target_link_directories(${LIB_NAME} PUBLIC ${CURLPP_LIBRARY_DIRS})

if(${ENABLE_WARNINGS})
    target_set_warnings(${LIB_NAME} ${ENABLE_WARNINGS} ${ENABLE_WARNINGS_AS_ERRORS})
endif()