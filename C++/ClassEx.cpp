#include <iostream>

using namespace std;

class Temperature
{  // Data Members
public:
float temp;  // current temperature
char scale;  // F-Fahrenheit, C-Celsius

// Methods
public:
void setTemp(float new_temp, char new_scale)
{
        temp = new_temp;
        scale = new_scale;
}

float F()
{
        if (scale == 'F')
                return temp;
        else
                return (temp * 9. / 5.) + 32;
        // convert C to F
}

float C()
{
        if (scale == 'C')
                return temp;
        else
                return (temp - 32.) * 5. / 9.; // F to C
}

float K()
{
        return C() - 273.15;
}

};

int main()
{
        cout << "Lecture 19-1 example!" << endl;

        Temperature cold;
        Temperature warm;
        Temperature hot;

        float temp;
        cout << "Enter cold temp (F): " << endl;
        cin >> temp;
        cold.setTemp(temp, 'F');
        cout << " F: " << cold.F() << ", C: " << cold.C() << ", K: " << cold.K() << endl;

        cout << "Enter warm temp (F): " << endl;
        cin >> temp;
        warm.setTemp(temp, 'F');
        cout << " F: " << warm.F() << ", C: " << warm.C() << ", K: " << warm.K() << endl;

        cout << "Enter hot temp (F): " << endl;
        cin >> temp;
        hot.setTemp(temp, 'F');
        cout << " F: " << hot.F() << ", C: " << hot.C() << ", K: " << hot.K() << endl;

        return 0;
}
