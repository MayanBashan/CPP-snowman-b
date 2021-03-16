/**
 * Author: Mayan Bashan
 */

#pragma once
#include <string>
using namespace std;

namespace ariel{
    string snowman(int number);
    int number_of_digits(int number);
    int less_than_four(int number);
    int positive_number(int number);
    int valid_snowman(int number);
    string hat_string(int number);
    string nose_mouth_string(int number);
    string lefteye_string(int number);
    string righteye_string(int number);
    string upwards_leftarm_string(int number);
    string downwards_leftarm_string(int number);
    string upwards_rightarm_string(int number);
    string downwards_rightarm_string(int number);
    string torso_string(int number);
    string base_string(int number);
    int digit_in_given_index(int number, int index);
    int random_number();
}