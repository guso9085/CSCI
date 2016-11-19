#include <iostream>
using namespace std;
#include <fstream>
#include <iostream>

void SortScores(int MyArray[], int numbers){
        bool sorted = false;

        while (!sorted) {
                sorted = true;
                for (int index = 0; index < (numbers - 1); index++) {
                        if (MyArray[index] < MyArray[index+1]) {
                                int temp = MyArray[index];
                                MyArray[index] = MyArray[index+1];
                                MyArray[index+1] = temp;
                                sorted = false;

                        }

                }
        }
}


int main(){
        int i = 0;
        int MyArray[29];
        int numbers = 29;
        ifstream ifile;
        string file = "/Users/gustavsolis/Documents/CSCI/Tutorials/Recitation9_Input.txt";
        ifile.open(file.c_str(), ios::in);
        string line;
        if (ifile.is_open() == true) {
                while(getline(ifile, line, '\n')) {
                        MyArray[i] = stoi(line);
                        i++;
                }
                ifile.close();
        }

        SortScores(MyArray, numbers);

        for (int i = 0; i < 29; i++) {
                cout << MyArray[i] << endl;
        }
        return 0;

}
