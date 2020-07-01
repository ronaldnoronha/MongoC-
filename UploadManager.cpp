//
// Created by Ronald Noronha on 1/7/20.
//

#include "UploadManager.h"



UploadManager (Connection& conn, string fileName) {
    conn = conn;
    fileName = fileName;
};

template <class Container>
void split(const string& str, Container& cont,
           char* delim)
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}

void createTick(const string& line, Tick& tick)
{
    std::vector<string> v;
    char delim[] = ", ";
    split(line, v, delim);

    string date = v[0];
    string time = v[1];
    std::vector<string> vDate;
    std::vector<string> vTime;
    char delimDate[] = "/";
    split(date, vDate,delimDate);
    char delimTime[] = ":";
    split(time,vTime,delimTime);

    DateTime dateTime{stoi(vDate[0]),stoi(vDate[1]),stoi(vDate[2]),stoi(vTime[0]),stoi(vTime[1]),stoi(vTime[2])};

    double price = stod(v[5]);
    int volume = stoi(v[6]);
    int numberOfTrades = stoi(v[7]);
    int delta = stoi(v[8])-stoi(v[9]);

    tick.dateTime = dateTime;
    tick.price = price;
    tick.volume = volume;
    tick.numberOfTrades = numberOfTrades;
    tick.delta = delta;
}

bsoncxx::document::value make_doc(Tick& tick) {
    bsoncxx::document::value doc_value = builder
            << "datetime" << tick.dateTime.getDateTime()
            << "price" << tick.price
            << "volume" << tick.volume
            << "numberOfTrades" << tick.numberOfTrades
            << "delta" << tick.delta
            << bsoncxx::builder::stream::close_document
            << bsoncxx::builder::stream::finalize;
    return doc_value;
};


