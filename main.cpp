#include <iostream>

using namespace std;

/* Programming project 4
 * =====================
 * There are two string-constructing functions, and three switches:
 * 1 <= bottles_of_beer_on_the_wall <= 19, which uses only one switch statement, and
 * 20 <= bottles_of_beer_on_the_wall <= 99, which uses two switch statements.
 */
string twenty_to_ninetynine_beer_bottles(int bottles_of_beer_on_the_wall);
// Predicate: only to be used when there are _FUNCTION_NAME_.
string one_to_nineteen_beer_bottles(int bottles_of_beer_on_the_wall);
// Predicate: only to be used when there are _FUNCTION_NAME_.

int main() {
    for(int bottles_of_beer_on_the_wall = 99; bottles_of_beer_on_the_wall >= 0; bottles_of_beer_on_the_wall--) {
        if (bottles_of_beer_on_the_wall == 0) {
            cout
            << "There's no more bottles of beer on the wall,\n"
            << "There's nothing left to pass around!\n"
            << "We took them down, we passed them around, the ninety-nine bottles of beer on the wall!\n";
        }
        else if (bottles_of_beer_on_the_wall == 1) {
            string current_word = one_to_nineteen_beer_bottles(bottles_of_beer_on_the_wall);
            cout
            << current_word << " bottle of beer on the wall, there's ONLY " << current_word << " bottle of beer,\n"
            << "take it down, pass it around,\n"
            << current_word << " bottle of beer on the wall!\n"
            << endl;
        }
        else if (bottles_of_beer_on_the_wall <= 19) {
            string current_word = one_to_nineteen_beer_bottles(bottles_of_beer_on_the_wall);
            cout
            << current_word << " bottles of beer on the wall, there's " << current_word << " bottles of beer,\n"
            << "take one down, pass it around,\n"
            << current_word << " bottles of beer on the wall!\n"
            << endl;
        } else {
            string current_word = twenty_to_ninetynine_beer_bottles(bottles_of_beer_on_the_wall);
            cout
            << current_word << " bottles of beer on the wall, there's " << current_word << " bottles of beer,\n"
            << "take one down, pass it around,\n"
            << current_word << " bottles of beer on the wall!\n"
            << endl;
        }
    }
    return 0;
}

string twenty_to_ninetynine_beer_bottles(int bottles_of_beer_on_the_wall) {
    int tens_place_of_beers = bottles_of_beer_on_the_wall / 10;
    int ones_place_of_beers;
    ones_place_of_beers = bottles_of_beer_on_the_wall - (tens_place_of_beers * 10);

    string tens_place;
    switch (tens_place_of_beers) {
        case 2: tens_place = "Twenty"; break;
        case 3: tens_place = "Thirty"; break;
        case 4: tens_place = "Forty"; break;
        case 5: tens_place = "Fifty"; break;
        case 6: tens_place = "Sixty"; break;
        case 7: tens_place = "Seventy"; break;
        case 8: tens_place = "Eighty"; break;
        case 9: tens_place = "Ninety"; break;
        default:
            cout << "Fatal error in twenty_to_ninetynine_beer_bottles, tens_place switch statement.\n";
            exit(1); // Not covered in the textbook yet, but I'm familiar with exit statuses.
    }

    string ones_place;
    switch (ones_place_of_beers) {
        case 0: ones_place = ""; break;
        case 1: ones_place = "-one"; break;
        case 2: ones_place = "-two"; break;
        case 3: ones_place = "-three"; break;
        case 4: ones_place = "-four"; break;
        case 5: ones_place = "-five"; break;
        case 6: ones_place = "-six"; break;
        case 7: ones_place = "-seven"; break;
        case 8: ones_place = "-eight"; break;
        case 9: ones_place = "-nine"; break;
        default:
            cout << "Fatal error in twenty_to_ninetynine_beer_bottles, ones_place switch statement.\n";
            exit(1); // Not covered in the textbook yet, but I'm familiar with exit statuses.
    }

    string english_word_for_number = tens_place + ones_place;
    return english_word_for_number;
}

string one_to_nineteen_beer_bottles(int bottles_of_beer_on_the_wall) {
    string english_word_for_number;
    switch (bottles_of_beer_on_the_wall) {
        case 19: english_word_for_number = "Nineteen"; break;
        case 18: english_word_for_number = "Eighteen"; break;
        case 17: english_word_for_number = "Seventeen"; break;
        case 16: english_word_for_number = "Sixteen"; break;
        case 15: english_word_for_number = "Fifteen"; break;
        case 14: english_word_for_number = "Fourteen"; break;
        case 13: english_word_for_number = "Thirteen"; break;
        case 12: english_word_for_number = "Twelve"; break;
        case 11: english_word_for_number = "Eleven"; break;
        case 10: english_word_for_number = "Ten"; break;
        case 9: english_word_for_number = "Nine"; break;
        case 8: english_word_for_number = "Eight"; break;
        case 7: english_word_for_number = "Seven"; break;
        case 6: english_word_for_number = "Six"; break;
        case 5: english_word_for_number = "Five"; break;
        case 4: english_word_for_number = "Four"; break;
        case 3: english_word_for_number = "Three"; break;
        case 2: english_word_for_number = "Two"; break;
        case 1: english_word_for_number = "One"; break;
        default:
            cout << "Fatal error in one_to_nineteen_beer_bottles.\n";
            exit(1); // Not covered in the textbook yet, but I'm familiar with exit statuses.
    }

    return english_word_for_number;
}