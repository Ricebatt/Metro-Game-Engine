add_executable(Met_Game main.cpp)

include_directories(../Metro/include)

target_link_libraries(Met_Game Metro)