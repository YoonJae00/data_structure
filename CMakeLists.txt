cmake_minimum_required(VERSION 3.30)
project(2025_1_)

set(CMAKE_CXX_STANDARD 17)

add_executable(2025_1_ main.cpp
        0312/test1.cpp
        0312/test1.h
        0312/test2.c
        0312/test3.c
        0312/structTest.c
        0312/structTest2.c
        0316/test1.c
        0316/test2.c
        0316/test3.c
        0316/test4.c
        0317/test03171.c
        0317/study2.c
        0317/test03171.c
        0319/test1.c
        0324/test01.c
        0324/test2.c
        0324/hanoi_top.c
        0324/hanoi_top_2.c
        0326/test01.c
        0331/test01.c
        0331/test02.c
        0331/test03.c
        0402/test01.c
        0402/test02.c
        0402/problem1.c
        0402/problem2.c
        0402/problem3.c
        0402/problem4.c
        0407/test01.c
        0407/test02.c
        0407/test03.c
        0409/test01.c
        0414/test01.c
        0414/test02.c
        0414/problem01.c
        0416/test01.c
        0421/test01.c
        0421/test02.c)

add_executable(middle_exam_test01 middle_exam/test01.c
        middle_exam/test02.c
        middle_exam/array_test.c
        middle_exam/test04.c
        middle_exam/test05.c
        middle_exam/pointer_test.cpp
        middle_exam/malloc_test.c
        middle_exam/pointer_test02.c
        middle_exam/stack_test01.c
        middle_exam/stack_test02.c
        middle_exam/stack_test_check_matching.c
        middle_exam/stack_postfix.c
        middle_exam/stack_postfix2.c
        middle_exam/stack_change_int.c
        middle_exam/stack_bfs.c
        middle_exam/stack_maze.c
)

add_executable(hanoi_top middle_exam/hanoi_top.c)

add_executable(terms_test middle_exam/terms.c
        middle_exam/test03.c
        middle_exam/test04.c)