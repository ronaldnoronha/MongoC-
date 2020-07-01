//
// Created by Ronald Noronha on 1/7/20.
//

#ifndef MONGOC___UPLOADMANAGER_H
#define MONGOC___UPLOADMANAGER_H

#include "Connection.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bsoncxx/json.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

using namespace std;

struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int seconds;
};

struct Tick {
    DateTime dateTime;
    double price;
    int volume;
    int numberOfTrades;
    int delta;

    std::tm getDateTime(){

    }

};

class UploadManager {
public:
    UploadManager(Connection& conn, string fileName);
    template <class Container>
    void split(const string& str, Container& cont, char* delim);
    void createTick(const string& line, Tick& tick);

    bsoncxx::document::value make_doc(Tick& tick);

private:
    Connection* conn;
    string fileName;
};


#endif //MONGOC___UPLOADMANAGER_H
