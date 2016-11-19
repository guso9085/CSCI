#include <iostream>
using namespace std;


void multiples(int nInteger){
        int n;
        int sum = 0;

        for(n = 1; n <= nInteger; n++) {
                if (n == 10) {
                        sum = sum + n;
                        cout << n;
                }else if((n % 2) == 0) {
                        //cout << n << endl;
                        sum = sum + n;
                        cout << n << " + ";
                }else if((n % 5) == 0) {
                        //cout << n << endl;
                        cout << n << " + ";
                        sum = sum + n;


                }



        }
        cout << " = " << sum;

        cin >> nInteger;

}





int main(){
        int nInteger;
        cout << "Please enter a value for n" << endl;
        cin >> nInteger;
        multiples(nInteger);



        return 0;


}
