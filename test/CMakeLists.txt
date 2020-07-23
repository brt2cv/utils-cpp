add_executable(base base.cpp)

add_executable(container container.cpp)
target_link_libraries(container utils)

add_executable(pystr pystr.cpp)
target_link_libraries(pystr utils)

add_executable(json json.cpp)
target_link_libraries(json utils)

add_executable(pybind pybind11.cpp)
target_link_libraries(pybind utils pybind11::embed)

find_package(nng)
add_executable(nngpp nngpp.cpp)
target_link_libraries(nngpp nng)

add_executable(spdlog spdlog.cpp)
