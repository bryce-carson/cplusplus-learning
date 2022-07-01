#include <iostream>
#include <cmath>

using namespace std;

double basal_metabolic_rate(double weight_pounds);
double activity_metabolic_rate(double weight_pounds, double activity_duration_minutes, double activity_intensity);
double digestion_metabolic_rate(double calories);

int main() {
    cout <<
    "This program will calculate the estimated number of servings of your favourite food you must consume given\n"
    "an activity level, the duration of the activity in minutes, your mass, and the caloric content of your\n"
    "favourite food.\n"
    "\n"
    "Table 1: physical activities or exercises and the associated arbitrary, relative intensity estimate.\n"
    "\tActivity\t\tIntensity\n"
    "\tRunning: 10mph\t\t17\n"
    "\tRunning:  6mph\t\t10\n"
    "\tBasketball:   \t\t8\n"
    "\tWalking:  1mph\t\t1\n"
    "\n"
    "The caloric content of your favourite food can be found on the world-wide web. For example, a double cheeseburger\n"
    "contains 1000 calories.\n"
    "\n"
    "Input your weight in pounds: ";
    double weight_pounds; cin >> weight_pounds;

    double activity_duration_minutes, activity_intensity;
    cout << "Input an activity intensity: ";
    cin >> activity_intensity;
    cout << "Input an activity duration (in minutes): ";
    cin >> activity_duration_minutes;

    cout << "Input the caloric content (the number of calories) in one serving of your favourite food: ";
    double calories;
    cin >> calories;

    double user_basal_metabolic_rate = basal_metabolic_rate(weight_pounds),
            user_activity_metabolic_rate = activity_metabolic_rate(weight_pounds, activity_duration_minutes, activity_intensity),
            user_metabolism = user_basal_metabolic_rate + user_activity_metabolic_rate,
            user_digestion_metabolic_rate = digestion_metabolic_rate(calories),
            user_servings = user_metabolism / (calories - user_digestion_metabolic_rate);

    cout <<
    "Here are the results:\n"
    "\tBasal metabolic rate:\t" << user_basal_metabolic_rate << endl <<
    "\tActivity metabolic rate:\t" << user_activity_metabolic_rate << endl <<
    "\tDigestion metabolic rate:\t" << user_digestion_metabolic_rate << " per serving (" << (user_servings * user_digestion_metabolic_rate) << " calories total)\n" <<
    "\n"
    "\tTotal metabolism (daily, with given activity): " << (user_digestion_metabolic_rate * user_servings) + user_activity_metabolic_rate + user_basal_metabolic_rate << endl <<
    "\tServings required: " << user_servings << endl;

    return 0;
}

double basal_metabolic_rate(double weight_pounds) {
    return 70.0 * pow((weight_pounds / 2.2), 0.756);
}

double activity_metabolic_rate(double weight_pounds, double activity_duration_minutes, double activity_intensity) {
    return 0.0385 * weight_pounds * activity_intensity * activity_duration_minutes;
}

double digestion_metabolic_rate(double calories) {
    return calories * 0.10;
}