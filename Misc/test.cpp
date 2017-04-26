#include <iostream>
using namespace std;

int recursive(int j, int size){
    if (j > size){
        return 1;
    }
    for (int x = 0; x < size; x++)
    {
        cout << "entered";
        if (j < x) {
            j++;
        }
    }
    return (recursive(j, size));
}


int main(){
  recursive(5, 10);
  cout << "Terminated";
}
