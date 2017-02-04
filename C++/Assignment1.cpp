#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>

//Defining main struct used
struct store{
    int price;
    string type;
    bool sale;
};

//Function that prints out the remaining items in the array
void itemsLeft(int count, store craiglist[100]){
    for(int k=0; k < count; k++){
      if(craiglist[k].sale == true){
        cout<<craiglist[k].type<<", "<<"for sale"<<", "<<craiglist[k].price<<endl;
      }
      else if(craiglist[k].sale == false){
        cout<<craiglist[k].type<<", "<<"wanted"<<", "<<craiglist[k].price<<endl;
      }
    }
}

//Main function
int main(){
  string filename;
  cin >> filename;

  int add = 0;
  int fileCounter = 0;
  int searchCounter = 0;
  int shiftCounter = 0;
  int count = 0;

  stringstream pablo;
  string Sline;

  store craiglist[100];

  ifstream ifile;
  ifile.open(filename.c_str(), ios::in);
  string line;

  if (ifile.is_open() == true) {


          //Main loop to build and match various structs into the array
          while(getline(ifile, line, '\n')) {
            store temp;
            add = 0;
            int i = 0;
            pablo.str(line);

              //Building temp struct to compare for matching
              while(getline(pablo, Sline, ',')){
                if (i == 0){
                  temp.type = Sline;
                }
                else if (i == 1){
                  Sline.erase(0,1);
                  if (Sline == "for sale"){
                    temp.sale = true;
                  }
                  else if (Sline == "wanted"){
                    temp.sale = false;
                  }
                }
                else if (i == 2){
                  int x = 0;
                  Sline.erase(0,1);
                  x = stoi(Sline);
                  temp.price = x;
                }
                i++;
              }

              //Checking for matches, and switching if there are any
              for(int j=0; j < count; j++){
                searchCounter++;
                if(craiglist[j].type == temp.type){
                  if(craiglist[j].sale != temp.sale){
                    if(craiglist[j].sale == true){
                      if(craiglist[j].price <= temp.price){
                        cout<<craiglist[j].type<<" "<<craiglist[j].price<<endl;
                        for (int k = j; k < count - 1; k++) {
                          craiglist[k] = craiglist[k + 1];
                          shiftCounter++;
                        }
                        count = count - 1;
                        add++;
                        break;
                      }
                    }
                    else  if(craiglist[j].price >= temp.price){
                        cout<<craiglist[j].type<<" "<<temp.price<<endl;
                        for (int k = j; k < count - 1; k++) {
                          craiglist[k] = craiglist[k + 1];
                          shiftCounter++;
                        }
                        count = count - 1;
                        add++;
                        break;
                    }
                  }
                }

              }


            //Adding to array if no matches were found
            if (add == 0){
              craiglist[count] = temp;
              count++;
            }

            //Clearing stringstream
            pablo.clear();

            fileCounter++;
          }
          ifile.close();
  }
  //Cout's and calling the Function
  cout<<"#"<<endl;
  itemsLeft(count, craiglist);
  cout<<"#"<<endl;
  cout<<"file read:"<<fileCounter<<endl;
  cout<<"search array:"<<searchCounter<<endl;
  cout<<"shift array:"<<shiftCounter<<endl;

  return 0;
}
