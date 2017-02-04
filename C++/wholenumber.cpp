void isPrime(int number){
    int count = 0;
    float division = 0;
    for(int i = 0; i<=number; i++){
        division = float(number) / float(i);
        if(division == int(division)){
            count++;
        }
    }

    if(count == 2){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;


}
