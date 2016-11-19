#include <iostream>
using namespace std;

//Create our temperature class
class Temperature {

//Data Numbers
private:
float temp;
char scale;   //F - Fahrenheit, C - Celsius
// Methods
public:
float F()
{
        if (scale == 'F')
                return temp;
        else
                return (temp * 9/5)+32; // convert from C to F
}
float C()
{
        if (scale == 'C')
                return temp;
        else
                return (temp -32) * 5/9;

}
float K()
{
        return C() - 273.15;
}
};

int main()
{
        cout << "Lecture10-1 Example" << endl;

        Temperature current;

        current.temp= -40.;
        current.scale 'C';

        cout << "F=" << current.F() << ", C=" << current.C() << ", K=" << current.K()

                return 0;

}
