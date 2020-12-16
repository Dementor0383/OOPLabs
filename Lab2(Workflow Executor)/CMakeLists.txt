cmake_minimum_required(VERSION 3.17)
project(Lab2(Workflow Executor))

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2(Workflow Executor) main.cpp Worker.h ProgramParser.cpp ProgramParser.h Workflow.cpp Workflow.h ReaderBlock.cpp ReaderBlock.h WriterBlock.cpp WriterBlock.h GrepBlock.cpp GrepBlock.h SortBlock.cpp SortBlock.h ReplaceBlock.cpp ReplaceBlock.h DumpBlock.cpp DumpBlock.h)
