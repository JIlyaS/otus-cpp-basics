cmake_minimum_required(VERSION 3.12)

project(03.guess_number)

add_executable(guess_number
    main.cpp
    read_user_data.cpp
    write_user_data.cpp
    get_arguments.cpp
    get_table_records.cpp
    process_play.cpp
    clear_table_records.cpp
)

set_target_properties(guess_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)