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

int *coin_change (int denom_arr[], int length, int amount) {

    int rem = amount;
    int *coins = new int[length];
        
    for (int i=(length-1); (i>=0) && (rem != 0); i--) {
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
    int length = sizeof(denom_arr)/sizeof(int);
    int amount;
        
    cout << "Enter the amount " << endl;
    cin >> amount;
    int *coins = coin_change(denom_arr, length, amount);
    

    for(int j=0; j< length; j++){
        cout << coins[j];
    }
}

