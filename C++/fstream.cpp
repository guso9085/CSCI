#include <iostream>
#include <fstream>
using namespace std;

int main(void){
        ofstream dataFile;
        dataFile.open("testfile.txt", ios::out);
        if (dataFile.fail()) {
                cout << "File open error!" << endl;
                return -1;

        }
        cout << "File was created successfully. \n";
        cout << "Now closing the file. \n";
        dataFile.close();

        return 0;
}
