cmake_minimum_required(VERSION 3.0.0)
project(Algorithm VERSION 0.1.0)

aux_source_directory(. MAIN)

aux_source_directory(./utils/date UTIL_DATE)
aux_source_directory(./utils/number UTIL_NUMBER)
aux_source_directory(./utils/string UTIL_STRING)
aux_source_directory(./utils/sort UTIL_SORT)
aux_source_directory(./utils/search UTIL_SEARCH)

aux_source_directory(./container/linearlist CONTAINER_LINEARLIST)
aux_source_directory(./container/tree CONTAINER_TREE)
aux_source_directory(./container/graph CONTAINER_GRAPH)

aux_source_directory(./math MATH)
aux_source_directory(./strings STRINGS)
aux_source_directory(./others OTHERS)
aux_source_directory(./tools TOOLS)

aux_source_directory(./include/container INCLUDE_CONTAINER)
aux_source_directory(./include/math INCLUDE_MATH)
aux_source_directory(./include/others INCLUDE_OTHERS)
aux_source_directory(./include/strings INCLUDE_STRINGS)
aux_source_directory(./include/tools INCLUDE_TOOLS)
aux_source_directory(./include/utils INCLUDE_UTILS)

add_executable(
    Algorithm 
    ${MAIN} 

    ${UTIL_ARRAY} 
    ${UTIL_DATE} 
    ${UTIL_NUMBER} 
    ${UTIL_STRING} 
    ${UTIL_SORT} 
    ${UTIL_SEARCH} 

    ${CONTAINER_LINEARLIST} 
    ${CONTAINER_TREE} 
    ${CONTAINER_GRAPH} 

    ${MATH} 
    ${STRINGS} 
    ${OTHERS}
    ${TOOLS}
    
    ${INCLUDE_CONTAINER}
    ${INCLUDE_MATH}
    ${INCLUDE_OTHERS}
    ${INCLUDE_STRINGS}
    ${INCLUDE_TOOLS}
    ${INCLUDE_UTILS})
