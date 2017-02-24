//write a function that removes all even numbers from an array, the function should take length of array,
//and a pointer for number found as arguements and return a pointer to the new array
//if there are no odd numbers found in the array, your code should print "no odds found"
//int * removeEvens(int *a, int length, int *oddsFound)
#include <iostream>
using namespace std;


int *removeEvens(int *a, int length, int *oddsFound){
  int oddsFoundLocal = 0;
  for(int index = 0; index < length; index++){
    if(a[index] % 2 == 1){
      oddsFoundLocal++;
    }
  }
  *oddsFound = oddsFoundLocal;
  int *newArray = new int(*oddsFound);
  int counter = 0;
  if(*oddsFound == 0){
    cout << "no odds found" << endl;
    return NULL;
  }
  for(int i = 0; i < length; i++){
    if(a[i]% 2 == 1){
      newArray[counter] = a[i];
      counter++;
    }
  }
  return newArray;
}


int main(){
  int oddsFoun = 0;
  int *oddsPTR = &oddsFoun;
  int a[] = {2,4,6,8,10};
  int *c = removeEvens(a, 5, oddsPTR);
  for (int i = 0; i < oddsFoun; i++){
    cout << c[i] << endl;
  }

}


//RIGHT ANSWER #1
/*
int *removeEvens(int *a, int length, int *oddsFound) {
  int *onlyOdds = new int[length];
  int oddsFoundLocal = 0;
  for (int i = 0; i < length; i++) {
    if (!(a[i] % 2 == 0)) {
      onlyOdds[oddsFoundLocal] = a[i];
      oddsFoundLocal++;
    }
  }
  *oddsFound = oddsFoundLocal;
  if (oddsFoundLocal == 0) {
    cout « "No odds found" « endl;
    return NULL;
  }
  int *returnableArray = new int[oddsFoundLocal];
  for (int j = 0; j < oddsFoundLocal; j++) {
    returnableArray[j] = onlyOdds[j];
  }
  return returnableArray;
}

int main() {
  // testing #1
  int a[] = {3,4,5,6,7};
  int oddsFound = 0;
  int *oddsFoundPtr = &oddsFound;
  int *b = removeEvens(a, 5, oddsFoundPtr);
  cout « "Odds found: " « oddsFound « endl;
  for (int i = 0; i < oddsFound; i++) {
    cout « b[i] « endl;
  }
}
*/
//RIGHT ANSWER 2
