cmake_minimum_required(VERSION 3.22)
project(Gate_way)
include_directories(${CMAKE_SOURCE_DIR}/header/)
include_directories(${PROJECT_SOURCE_DIR}/header)
set(Src
        "src/IDataTypeHandling.cpp"
        "src/IDataBaseHandler.cpp"
        "src/IDataBaseUpdater.cpp"
        "src/MyCommandHandler.cpp"
        )


file(GLOB SRC
        "src/IDataTypeHandling.cpp"
        "src/IDataBaseHandler.cpp"
        "src/IDataBaseUpdater.cpp"
        "src/MyCommandHandler.cpp"
        )

add_executable(Gate_way ./main.cpp ${SRC})
target_link_libraries (Gate_way PRIVATE opendnp3 modbus)
install(TARGETS Gate_way RUNTIME DESTINATION bin)
