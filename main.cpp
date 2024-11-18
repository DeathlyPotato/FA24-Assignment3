/*
Name:Chen, Isaac, 2002582920, CS 135 1001, Assignment 1
Description: For minecrafting Steve, this will help 
Steve decide the rate of spawn of a crop given information.
Input: Biome (Char), Crop (Char), Day (Int)
Output: Rate of spawn of crop in biome
*/

#include <iostream> 
#include <cmath>
// include any additional packages 

using namespace std;


int main () {
    // variable declarations
    const int daysInYear = 360; 
    const double daysInMonth = 30.0; 

    char crop = ' ';
    char biome = ' ';
    int day = 0;
    int month = 0;
    
    // Prompt for biome and error check
    cout << "Please enter the current biome" << endl;
    cin >> biome;

    biome = tolower(biome);

    if ((biome != 'f' && biome != 'g' && biome != 't'
      )|| cin.fail()) {
        cout << "Error: Biome cannot be found" << endl;
        return 0;
    }


    // Prompt for crop and error check
    cout << "Please enter the crop you wish to find" << endl;
    cin >> crop;

    crop = tolower(crop);

    if ((crop != 'c' && crop != 'p' )|| cin.fail()) {
        cout << "Error: Crop does not exist" << endl;
        return 0;
    }

    // Prompt for current day and error check
    cout << "Please enter the current day in game" << endl;
    cin >> day;

    if (day < 0){
        cout << "Error: Day cannot be negative" << endl;
        return 0;
    }
    
    // Calculate the month
    day = day % daysInYear;
    month = round(day / daysInMonth);
    string lazy = " can currently be found at ";

    // Forcing me to use more
    // comments is not fun
    if (crop == 'c') {
        if (month < 7 && month > 8 && biome == 't') {
            cout << "Carrots cannot currently be found.";
        } else if (month == 9 && biome == 'g') {
            cout << "Carrots cannot be currently found.";
        } else if (month == 1) {
            cout << "Carrots" << lazy << "2x rate.";
        } else if (month < 5) {
            cout << "Carrots" << lazy << "1.5x rate.";
        } else if (month < 7) {
            cout << "Carrots" << lazy << "0.8x rate.";
        } else if (month < 10 && biome == 't') {
            cout << "Carrots" << lazy << "0.8x rate.";
        } else if (month < 13) {
            cout << "Carrots" << lazy << "2x rate.";
        }
    }

    if (crop == 'p') {
        if (month < 7 ) {
            cout << "Pumpkins currently cannot be found.";
        } else if (month == 7 || month == 8 || month == 9) {
            cout << "Pumpkins" << lazy << "0.6x rate.";
        } else if (month == 10) {
            cout << "Pumpkins" << lazy << "2.0x rate.";
        } else if (month == 11) {
            cout << "Pumpkins" << lazy << "1.5x rate.";
        } else if (month == 12) {
            cout << "Pumpkins" << lazy << "0.9x rate.";
        }
    }


    return 0; 
}