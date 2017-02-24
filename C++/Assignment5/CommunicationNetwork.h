#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>
using namespace std;
struct City{
    string cityName;
    string message;
    City *next;
    City *previous;

    City(){}; // default constructor

    City(string initName, City *initNext, City *initPrevious, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        previous = initPrevious;
        message = initMessage;
    }

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork();
        ~CommunicationNetwork();
        void addCity(string, string);
        void buildNetwork();
        void transmitMsg(char *); //this is like a string
        void printNetwork();
        void deleteCity(string);
        void deleteNetwork();
    protected:
    private:
        City *head;
        City *tail;
};

#endif // COMMUNICATIONNETWORK_H
