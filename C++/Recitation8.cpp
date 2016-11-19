#include <iostream>
using namespace std;

int main(){
        double sum;
        double myDoubles[20];
        for (int i = 0; i <= 19; i++) {
                myDoubles[i] = i;
        }
        for (int i = 0; i <= 19; i++) {
                cout << myDoubles[i] << endl;
        }
        for (int i = 0; i <= 19; i++) {
                sum = myDoubles[i] + sum;
        }

        double result = sum / 20;

        cout << "The average value of myDoubles is: " << result << endl;
        return 0;
}
