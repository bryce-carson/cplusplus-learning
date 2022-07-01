#include <iostream>

using namespace std;

const double MARGINAL_TAX_RATE = 0.35;

double compute_marginal_tax(double principal, double interest, double marginal_tax_rate);
/*
 * Compute the marginal tax of the _double principal_ the _double marginal_tax_rate_, less any mortgage
 * _double interest_.
 *
 * If _interest_ is $0.00, then there is no deduction. Do not use this function with a negative _interest_ in the event
 * of charge-backs to the customer.
 */

double compute_mortgage_interest_tax_savings(double interest, double marginal_tax_rate);
/*
 * Compute the tax credit (savings) on a mortgage based on the _double interest_ payment and the
 * _double marginal_tax_rate_.
 */

int main() {
    char main_again;
    do {
        cout << "Input the listing price of the home the mortgage is for, then press 'Enter'.\n";
        cout << "Listing price: $";
        double listing_price;
        cin >> listing_price;

        cout << "Input the down payment made on the mortgage, then press 'Enter'.\n";
        cout << "Down payment: $";
        double down_payment;
        cin >> down_payment;

        double
                initial_mortgage_balance = (listing_price - down_payment),
                annual_mortgage_principal = initial_mortgage_balance * 0.03,
                annual_mortgage_interest = initial_mortgage_balance * 0.06,
                annual_mortgage_marginal_tax = compute_marginal_tax(annual_mortgage_principal,
                                                                    annual_mortgage_interest,
                                                                    MARGINAL_TAX_RATE),
                annual_mortgage_subtotal_cost =
                annual_mortgage_principal + annual_mortgage_interest + annual_mortgage_marginal_tax,
                annual_mortgage_total_cost = annual_mortgage_subtotal_cost -
                                             compute_mortgage_interest_tax_savings(annual_mortgage_interest,
                                                                                   MARGINAL_TAX_RATE);

        cout
                << "The initial mortgage balance is the listing price less the down payment:\n"
                << "Listing price: " << listing_price << endl
                << "Down payment: " << down_payment << endl
                << "Initial mortgage balance: " << initial_mortgage_balance << endl;

        cout
                << "The annual mortgage cost, after tax and tax credits for mortgage interest, is:\n"
                << "Annual mortgage cost:\n"
                << "\tPrincipal: " << annual_mortgage_principal << endl
                << "\tInterest: " << annual_mortgage_interest << endl
                << "\tMarginal tax: " << annual_mortgage_marginal_tax << endl
                << endl
                << "\tSubtotal: " << annual_mortgage_subtotal_cost << endl
                << "\tTotal: " << annual_mortgage_total_cost << endl;

        cout << "Would you like to use the program again? (Y/n) ";
        cin >> main_again;
    } while ((main_again == 'Y') || (main_again == 'y'));

    return 0;
}

double compute_marginal_tax(double principal, double interest, double marginal_tax_rate) {
    return (principal + interest) * marginal_tax_rate;
}

double compute_mortgage_interest_tax_savings(double interest, double marginal_tax_rate) {
    return (interest * marginal_tax_rate);
}