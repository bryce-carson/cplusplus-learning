#include <iostream>

using namespace std;

double calc_hat_size(double weight_pounds, double height_inches);
double calc_jacket_size(double weight_pounds, double height_inches, int age_years);
/*
 * Chest size in inches.
 */
double calc_waist_size(double weight_pounds, int age_years);
/*
 * Waist size in inches.
 */
double cm_to_inches(double centimeters);
double kg_to_pounds(double kilograms);

int main() {
    cout <<
         "This program will calculate the hat size, the waist size in inches, and the jacket size (chest size in inches) "
         " based on the metric inputs for height and weight, and the integer input of age in years.\n";

    char main_again;
    do {
        cout <<
             "For each prompt, input the information requested, then press the 'Enter' key to enter it into the "
             "program memory.\n";

        cout << "Input your height in centimeters: ";
        double height_cm; cin >> height_cm;

        cout << "Input your weight in kilograms: ";
        double weight_kg; cin >> weight_kg;

        cout << "Input your age in (whole) years: ";
        int age_years; cin >> age_years;

        /*
         * Call the functions and do the things the program is supposed to do to produce output.
         */
        double height_inches = cm_to_inches(height_cm);
        double weight_pounds = kg_to_pounds(weight_kg);

        cout <<
             "Based off of the below list of information, "
             "the converted measurements are given,\n"
             "and the clothing sizes are listed after that.\n";

        cout
                << "Height in cm: " << height_cm << endl
                << "Weight in kg: " << weight_kg << endl
                << "Age in years: " << age_years << endl
                << endl
                << "Height in inches: " << height_inches << endl
                << "Weight in pounds: " << weight_pounds << endl
                << endl
                << "Hat size: " << calc_hat_size(weight_pounds, height_inches) << endl
                << "Jacket size: " << calc_jacket_size(weight_pounds, height_inches, age_years) << " (inches)\n"
                << "Waist size: " << calc_waist_size(weight_pounds, age_years) << " (inches)\n" << endl
                << endl
                << "Jacket size in ten years: " << calc_jacket_size(weight_pounds, height_inches, (age_years + 10)) << " (inches)\n"
                << "Waist size in ten years: " << calc_waist_size(weight_pounds, (age_years + 10)) << " (inches)\n" << endl
                << endl
                << "Would you like to repeat the calculation? (Y/n) ";

        cin >> main_again;
    } while ((main_again == 'Y') || (main_again == 'y'));

    return 0;
}

double calc_hat_size(double weight_pounds, double height_inches) {
    double hat_size = (weight_pounds / height_inches) * 2.9;
    return hat_size;
}

double calc_jacket_size(double weight_pounds, double height_inches, int age_years) {
    double jacket_size = (weight_pounds * height_inches) / 288.0;

    if (age_years >= 40) {
        jacket_size += (1.0/8.0) * ((age_years - 30) / 10);
        /*
         * The Clang-Tidy warning is okay to ignore.
         * The formula is 1/8th of an inch for every 10 whole years after 30. 0.125 * 1, * 2, or * 3 is fine.
         * No precision is lost.
         */
    }

    return jacket_size;
}

double calc_waist_size(double weight_pounds, int age_years) {
    double waist_size = (weight_pounds / 5.7);

    if (age_years >= 30) {
        waist_size += 0.10 * ((age_years - 28) / 2);
        /*
        * The Clang-Tidy warning is okay to ignore.
        * The formula is 1/10th of an inch for every 2 whole years after 28. 0.10 * 1, * 2, or * 3 is fine.
        * No precision is lost.
        */
    }
}

double cm_to_inches(double centimeters) {
    double inches_per_centimeter = 0.3937;
    return centimeters * inches_per_centimeter;
}

double kg_to_pounds(double kilograms) {
    double pounds_per_kilogram = 2.2;
    return kilograms * pounds_per_kilogram;
}
