/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 9, 2013, 1:12 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */

float get_discount (int count) {
    
    float discount = 0.0;
    
    switch (count) {
        case 2:
            discount = 0.05;
            break;
        case 3: 
            discount = 0.10;
            break;
        case 4: 
            discount = 0.20;
            break;
        case 5:
            discount = 0.25;
            break;
        default:
            discount = 0.0;
            break;
    }
    
    return discount;
}

void best_discount (vector<int> & books, float & price, float & final_price, int series_number) {
    int potter[series_number];
    
    for (int i = 0; i< series_number; i++) {
        potter[i] = 0;
    }
    
    for (int i=0; i < books.size(); i++) {
        potter[books[i]]++;
    }
    
    int books_count = books.size();
    int unique_book_count = 0, prev_unique_count = 0;
    float temp_discount = 0.0;
    float prev_price = 0.0;
    int flag;
    
    while (books_count > 0){
        
        flag = 1;
                  
        prev_unique_count = unique_book_count;
        unique_book_count = 0;
        
        // Determine unique set of books eligible for discount
        for (int j=0; j < series_number; j++) {

            if(potter[j]>0){                
                potter[j]--;
                unique_book_count++;
                books_count--;
            }

        }
            
        // Special case - determine best possible discount
        if ((unique_book_count < series_number) && (prev_unique_count == series_number)) {
           float best_discount = 0.0;
           float best_price = 0.0;
           for(int x=1; x <= series_number; x++) {
               int book_set = unique_book_count + prev_unique_count;
               if ((book_set - x) <= series_number) {
                   float temp_discount1, temp_discount2;
                   temp_discount1 = get_discount(x);
                   temp_discount2 = get_discount(book_set - x);
                   temp_discount = temp_discount1 + temp_discount2;

                   if (temp_discount > best_discount){
                       best_discount = temp_discount;
                       best_price = ((price * x) * (1-temp_discount1)) + ((price * (book_set - x)) * (1-temp_discount2));                
                   }
               }
           }
                
           // Discard the previously discounted price because 
           // the previous set is compared with the current set for best discount
           final_price -= prev_price;
           final_price += best_price;
           flag = 0;
                
         }


         // Normal case - Calculate the price
         if(flag) {
            temp_discount = get_discount(unique_book_count);
            prev_price = ((price * unique_book_count) * (1 - temp_discount));
            final_price += prev_price;
         }
    }
}

int main(int argc, char** argv) {

    vector<int> books;
    int number, book;
    float discount = 0.0;
    float final_price = 0.0;
    float book_price = 0.0;
    int series_number = 5;
    
    cout << "Enter the number of books to purchase" << endl;
    cin >> number;
    cout << "Enter price of one book" << endl;
    cin >> book_price;
    cout << "Enter the books" << endl;
    
    for(int i=0; i<number; i++){
        cin >> book;
        books.push_back(book);
    }
    
    best_discount(books, book_price, final_price, series_number);
    
    cout << "Price for the " << number << " Potter books is: " << final_price << endl;
}

