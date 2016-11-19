#include <iostream>
using namespace std;

//Function isDNA will return TRUE if the string only contains valid DNA characters, False otherwise


bool isDNA(string str){
        bool onlyACGT = true;

        int index;
        for (index = 0; index < str.length(); index++) {
                if ((str[index] != 'A') && (str[index] != 'G') && (str[index] != 'C') && (str[index] != 'T'))
                        onlyACGT = false;

        }

        return onlyACGT;
}

int main(){
        string str;



        isDNA(str);


        return 0;


}
