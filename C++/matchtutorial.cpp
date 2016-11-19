#include <iostream>
using namespace std;


/*int countMatches (string str, char matchChar)
   {

        int count = 0;

        int index = 0;
        while (index < str.length())
        {
                if (str[index] == matchChar)
                        count = count + 1;
                index = index + 1;



        }

        return count;

   }*/

int countMatches (string str, char matchChar)
{
        int count = 0;

        int index;
        for (index = 0; index < str.length(); index = index + 1)
        {
                if (str[index] == matchChar)
                        count = count + 1;

        }
        return count;


}

int main (){
        string str;
        char matchChar = 0;

        countMatches(str, matchChar);
        return 0;

}
