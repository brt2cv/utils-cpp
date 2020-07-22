add_executable(base base.cpp)
# target_link_libraries(base utils)  # 未调用libutils，但写上也没错

add_executable(container container.cpp)
target_link_libraries(container utils)

add_executable(pystr pystr.cpp)
target_link_libraries(pystr utils)

add_executable(json json.cpp)
target_link_libraries(json utils)
