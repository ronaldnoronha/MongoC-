cmake_minimum_required(VERSION 3.14)
project(MongoC__)

set(CMAKE_CXX_STANDARD 14)

add_executable(MongoC__ main.cpp Reader.cpp Reader.h Writer.cpp Writer.h Connection.cpp Connection.h UploadManager.cpp UploadManager.h)