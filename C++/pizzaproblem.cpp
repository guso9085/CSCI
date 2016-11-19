#include <iostream>
using namespace std;


float sqFtPizza(int numBoxes){
        float feet = 8.0/12.0;
        float squarefeet = (3.14) * (feet*feet);
        float pizza = 0;
        cout << "Enter the number of boxes that you have: " << endl;
        cin >> numBoxes;
        float hours = numBoxes / 20.0;
        for(numBoxes = 0; numBoxes <= 20; numBoxes - 20) {
                pizza = pizza + 1;
        }
        if(numBoxes < 20) {

        }

        return squarefeet;
}


int main (){
        int numBoxes = 0;
        float squarefeet = sqFtPizza(numBoxes);
        return 0;



}
