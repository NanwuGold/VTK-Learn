set(target_ renderCone)

find_package(VTK REQUIRED)
add_executable(${target_} main.cpp)

target_link_libraries(${target_} PRIVATE ${VTK_LIBRARIES})




