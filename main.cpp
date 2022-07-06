#include <iostream>
#include "cstdlib"
#include "ctime"
#include "cmath"

using namespace std;

int random_coin();
int remaining_subtotal(int coin_value, int subtotal);
// Returns the remaining subtotal after applying the value of the coin, coin_value, to the subtotal.
int round_change(int change);
// Rounds the change value to a value divisible by 5.

int main() {
    /*
     * Clag-Tidy complains about this, saying it is _still_ predictable, but Savitch says this is the way to do it.
     * :shrug:
     */
    srand(time(0));

    char repeat_simulation;
    do {
        double total_dollars_and_cents;
        cout << "Input the total cost of the item in the vending machine: ";
        cin >> total_dollars_and_cents;

        int total_cents;
        total_cents = static_cast<int>(total_dollars_and_cents * 100);

        while (total_cents > 0) {
            int a_random_coin = random_coin();
            cout << "Value of coin inserted:\t" << static_cast<double>(a_random_coin)/100.0 << endl;
            total_cents = remaining_subtotal(a_random_coin, total_cents);
            cout << "Subtotal:\t" << static_cast<double>(total_cents)/100.0 << endl;
        }

        if (total_cents <= -3) {
            //  Total,                              (1.00,           0.25,           0.10,           0.05)
            int change = abs(total_cents), change_l_count, change_q_count, change_d_count, change_n_count;

            // Round the change to a value divisible by 5.
            change = round_change(change);
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(2);
            cout << "Your change is: $" << static_cast<double>(change) / 100.0 << endl;

            // Dispense dollars, if any.
            change_l_count = change / 100;
            change -= change_l_count * 100;
            cout << change_l_count << " $1.00 coins\n";

            // Dispense quarters, if any.
            change_q_count = change / 25;
            change -= change_q_count * 25;
            cout << change_q_count << " $0.25 coins\n";

            // Dispense dimes, if any.
            change_d_count = change / 10;
            change -= change_d_count * 10;
            cout << change_d_count << " $0.10 coins\n";

            // Dispense nickles, if any.
            change_n_count = change / 5;
            change -= change_n_count * 5;
            cout << change_n_count << " $0.05 coins\n";
        }

        cout << endl << "Repeat the vending machine simulation? (Y/n) "; cin >> repeat_simulation;
    } while ((repeat_simulation == 'Y') || (repeat_simulation == 'y'));

    return 0;
}

int remaining_subtotal(int coin_value, int subtotal) {
    return subtotal - coin_value;
}

int random_coin() {
    // Clang-Tidy: Use C++11 random library rather than Rand(), because Rand() has limited randomness;
    // Savitch should've instructed on this, since the standard tought in the book is C++11. Always teach the basic
    // libraries, not just the standard library. Teach the _basic_ standard library as well. Don't just teach that
    // it exists.
    int random_number = rand() % 4,
            random_coin;
    switch (random_number) {
        case 0: random_coin = 5; break;
        case 1: random_coin = 10; break;
        case 2: random_coin = 25; break;
        case 3: random_coin = 100; break;
        default:
            cout << "Fatal error in switch. The random_number was not one of 0, 1, 2, or 3.\n";
            exit(1);
    }
    return random_coin;
}

int round_change(int change) {
    while ((change % 5) != 0) {
        ((change % 5) >= 3) ? change++ : change--;
    }
    return change;
}