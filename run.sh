c++ --std=c++11 main.cpp -o test $(pkg-config --cflags --libs libmongocxx)

./test
