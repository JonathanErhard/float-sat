if("rodos" STREQUAL "")
    message(FATAL_ERROR "Name of the Rodos package to uninstall is empty.")
endif()

set(folders "lib/rodos;include/rodos;src/rodos")
list(TRANSFORM folders PREPEND "/usr/local/")
foreach(folder ${folders})
    message(STATUS "Uninstalling $ENV{DESTDIR}${folder}")
    if(EXISTS "$ENV{DESTDIR}${folder}")
        exec_program(
            "/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake" ARGS "-E rm -r \"$ENV{DESTDIR}${folder}\""
            OUTPUT_VARIABLE rm_out
            RETURN_VALUE rm_retval
        )
        if(NOT "${rm_retval}" STREQUAL 0)
            message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${folder}")
        endif()
    else()
        message(STATUS "Folder $ENV{DESTDIR}${folder} does not exist.")
    endif()
endforeach()
