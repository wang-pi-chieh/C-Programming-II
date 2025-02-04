#include<iostream>
using namespace std;

int main(){

    int N;
    int L;
    int train[50] = {0};
    int i, j;
    int temp;

    cin >> N;        //number of cases

    while(N--){

        cin >> L;    //length of train

        int count = 0;

        for(i = 0; i < L; i++){
            cin >> train[i];
        }

        for(i = 0; i < L - 1; i++){
            for(j = 0; j < L - 1 - i; j++){
                if(train[j] > train[j + 1]){
                    temp = train[j];
                    train[j] = train[j + 1];
                    train[j + 1] = temp;
                    count++;
                }
            }
        }

        cout << "Optimal train swapping takes " << count << " swaps." << endl;

    }

    return 0;
}
