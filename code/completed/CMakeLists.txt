set(COMPLETED_PROJECTS
    adventure
    bmi
    catch2_intro
    cpp_patterns
    etl_examples
    hello_world
    invoice
    library
    memory_and_polymorphism
    modern_cpp
    namespace_lookup
    pointers
    raii
    range_examples
    shared_memory
    simple_calculator
    simple_examples
    virtual_university
)

foreach(PROJECT ${COMPLETED_PROJECTS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${PROJECT})
        add_subdirectory(${PROJECT})
    endif()
endforeach()

set(OPTIONAL_COMPLETED_PROJECTS)

foreach(PROJECT ${OPTIONAL_COMPLETED_PROJECTS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${PROJECT})
        add_subdirectory(${PROJECT})
    endif()
endforeach()