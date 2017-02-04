#include <iostream>
using namespace std;


struct person {
    string hair;
    int age;

};

int main(){
    person pablo;
    pablo.hair = "brown";
    pablo.age = 26;

    person arrayName[100];
    arrayName[0].hair = "black";
    arrayName[0].age = 420;

    return 0;
}
