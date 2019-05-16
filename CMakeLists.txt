cmake_minimum_required (VERSION 3.1.0)
project(mos-conv)

# mos
file(GLOB_RECURSE CONV_SOURCE src/mos/*.cpp)
file(GLOB_RECURSE CONV_HEADER include/mos/*.hpp)

add_library(${PROJECT_NAME} STATIC ${CONV_HEADER} ${CONV_SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC mos BulletDynamics BulletCollision LinearMath ${BULLET_LIBRARIES})
