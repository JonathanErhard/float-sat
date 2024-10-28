GET_PROPERTY(project_path GLOBAL PROPERTY project_path)
file(GLOB_RECURSE node_sources ${project_path}/nodes/main-node/src/*.cpp)
set(node_includes ${project_path}/nodes/main-node/include)

add_executable(main-node
    ${node_sources}
    main-node.cpp
    ../../common/include/common-generated/builtin-structs.cpp
        topic/radio-up-topic.cpp
        topic/radio-down-topic.cpp
    app-configs.cpp)
target_link_libraries(main-node PUBLIC
    $<TARGET_NAME_IF_EXISTS:drivers>
      housekeeper-main-node
      commander-main-node
      transceiver-main-node
    )
target_include_directories(main-node PUBLIC include common-generated
    ${node_includes}
    )
    
if(default_linker_script)
target_link_options(main-node PUBLIC -T${RODOS_DIR}/src/bare-metal/${default_linker_script})
endif()

install(TARGETS main-node)
    
