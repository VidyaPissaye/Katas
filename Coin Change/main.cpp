/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 19, 2013, 9:39 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */

int *coin_change (int denom_arr[], int amount) {

    int rem=amount;
    int *coins = new int[5];
        
    for (int i=4; (i>=0) && (rem != 0); i--) {
        int number = rem/denom_arr[i];
        if (number > 0) {
                coins[i] = number;              
                rem = rem % denom_arr[i];
     
        }
    }
    return coins;
}

int main(int argc, char** argv) {

    int denom_arr[] = {1, 5, 10, 25, 100};
    int amount;
    
        
    cout << "Enter the amount " << endl;
    cin >> amount;
    int *coins = coin_change(denom_arr, amount);
    

    for(int j=0; j<5; j++){
        cout << coins[j];
    }
}

