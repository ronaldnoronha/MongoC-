#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <vector>


#include "Connection.h"
#include "UploadManager.h"

//#include <bsoncxx/builder/stream/document.hpp>
//#include <bsoncxx/json.hpp>
//
//#include <mongocxx/client.hpp>
//#include <mongocxx/instance.hpp>
//#include <mongocxx/stdx.hpp>
//#include <mongocxx/uri.hpp>

using namespace std;



int main() {
    Connection conn;
    // Create DB and Collection for application
    mongocxx::database db = conn.conn["testdb"];
    mongocxx::collection col = db["testcollection"];



    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
//
//    ifstream MyReadFile("ESH15.txt");
//    string myText;
//    int counter = 0;
//    getline(MyReadFile,myText);
//    cout << myText << endl;
//    while (getline (MyReadFile, myText)){
//        cout << myText << endl;
//        Tick tick;
//        createTick(myText, tick);
//        counter++;
//        if (counter>10) {
//            break;
//        }
//    }
//    cout << counter << endl;
//    MyReadFile.close();
//    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//    cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]" << endl;
//    cout << "Hello, World!" << endl;
    return 0;
}




