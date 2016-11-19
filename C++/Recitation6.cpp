#include <iostream>
#include <fstream>
using namespace std;

void sumOfLines(int sum){
        ifstream ifile;
        ifile.open("/Users/gustavsolis/Documents/CSCI/Tutorials/input.txt", ios::in);
        string line;
        if (ifile.is_open() == true) {
                while(getline(ifile, line)) {
                        int x = std::stoi(line);
                        if ((x % 5) == 0) {
                                sum = sum + x;
                        }
                        else if ((x % 2) == 0) {
                                sum = sum + x;
                        }

                }

                ifile.close();
        }

        ofstream ofile;
        ofile.open("/Users/gustavsolis/Documents/CSCI/Tutorials/sum.txt", ios::out);

        if (ofile.is_open() == true) {
                ofile << sum;
        }
        ofile.close();


}

int main(){
        int sum = 0;
        sumOfLines(sum);

}
