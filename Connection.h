//
// Created by Ronald Noronha on 29/6/20.
//

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#ifndef MONGOC___CONNECTION_H
#define MONGOC___CONNECTION_H


class Connection {

public:
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};
//    mongocxx::database = conn

    mongocxx::client* getConnection(){return &conn; }

//    ~Connection();
};


#endif //MONGOC___CONNECTION_H
