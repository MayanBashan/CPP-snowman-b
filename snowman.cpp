/**
 * Author: Mayan Bashan
 */

#include "snowman.hpp"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const int len = 8;
const int one = 1;
const int two = 2;
const int three = 3;
const int four = 4;
const int five = 5;
const int six = 6;
const int seven = 7;
const int eight = 8;
const int ten = 10;

namespace ariel{
    
    // This function returns 1 if number length equals 8, returns 0 otherwise
    int number_of_digits(int number){
        int number_of_dig = 0;
        while(number != 0){
            number_of_dig++;
            number = (int)number/ten;
        }
        if (number_of_dig == len){
            return 1;
        }
        return 0;
    }
    
    // This function returns 1 if all digits are between 1-4, returns 0 otherwise
    int less_than_four(int number){
        int number_of_dig = 0;
        int dig = 0;
        while (number != 0){
            number_of_dig++;
            dig = (int)number%ten;
            if (dig > four || dig == 0){
                return 0;
            }
            number = (int)number/ten;
        }
        return 1;
    }

    // This function returns 1 if number is positive
    int positive_number(int number){
        if (number > 0){
            return 1;
        }
        return 0;
    }

    // This function uses 3 above functions for input validation
    int valid_snowman(int number){
        if (number_of_digits(number) == 1 && less_than_four(number) == 1 && positive_number(number) == 1){
            return 1;
        }
        return 0;
    }

    // This function returns the digit in the given index in the given number
    int digit_in_given_index(int number, int index){
        int div = (int)pow(ten,len-index);
        int ans = (number/div)%ten;
        return ans;
    }

    // Hat
    string hat_string(int number){
         int dig = digit_in_given_index(number, one);
         switch (dig){
            case 1:
                return "_===_";
            case 2:
                return " ___ \n .....";
            case 3:
                return "  _ \n  /_\\ ";
            case 4:
                return " ___ \n (_*_)";
        }
        return "";
    }

    // Nose/Mouth
    string nose_mouth_string(int number){
         int dig = digit_in_given_index(number, two);
         switch (dig){
            case 1:
                return ",";
            case 2:
                return ".";
            case 3:
                return "_";
            case 4:
                return " ";
        }
        return "";
    }

    // Left Eye
    string lefteye_string(int number){
         int dig = digit_in_given_index(number, three);
         switch (dig){
            case 1:
                return ".";
            case 2:
                return "o";
            case 3:
                return "O";
            case 4:
                return "-";
        }
        return "";
    }

    // Right Eye
    string righteye_string(int number){
         int dig = digit_in_given_index(number, four);
         switch (dig){
            case 1:
                return ".";
            case 2:
                return "o";
            case 3:
                return "O";
            case 4:
                return "-";
        }
        return "";
    }

    // Upwards Left Arm
    string upwards_leftarm_string(int number){
         int dig = digit_in_given_index(number, five);
         switch (dig){
            case 2:
                return "\\";
            case 1:
            case 3:
            case 4:
                return " ";
        }
        return "";
    }

    // Downwards or Normal Left Arm
    string downwards_leftarm_string(int number){
         int dig = digit_in_given_index(number, five);
         switch (dig){
            case 1:
                return "<";
            case 3:
                return "/";
            case 2:
            case 4:
                return " ";
        }
        return "";
    }

    // Upwards Right Arm
    string upwards_rightarm_string(int number){
         int dig = digit_in_given_index(number, six);
         switch (dig){
            case 2:
                return "/";
            case 1:
            case 3:
            case 4:
                return " ";
        }
        return "";
    }

    // Downwards or Normal Left Arm
    string downwards_rightarm_string(int number){
         int dig = digit_in_given_index(number, six);
         switch (dig){
            case 1:
                return ">";
            case 3:
                return "\\";
            case 2:
            case 4:
                return " ";
        }
        return "";
    }

    // Torso
    string torso_string(int number){
         int dig = digit_in_given_index(number, seven);
         switch (dig){
            case 1:
                return " : ";
            case 2:
                return "] [";
            case 3:
                return "> <";
            case 4:
                return "   ";
        }
        return "";
    }

    // Base
    string base_string(int number){
         int dig = digit_in_given_index(number, eight);
         switch (dig){
            case 1:
                return " : ";
            case 2:
                return "\" \"";
            case 3:
                return "___";
            case 4:
                return "   ";
        }
        return "";
    }
    
    string snowman(int number){
        // if input number is valid
        if (valid_snowman(number) == 1){

            // create the correct string to each part
            string hat = hat_string(number);
            string mouth_nose = nose_mouth_string(number);
            string left_eye = lefteye_string(number);
            string right_eye = righteye_string(number);
            string up_left_arm = upwards_leftarm_string(number);
            string down_left_arm = downwards_leftarm_string(number);
            string up_right_arm = upwards_rightarm_string(number);
            string down_right_arm = downwards_rightarm_string(number);
            string torso = torso_string(number);
            string base = base_string(number);
        
            // returns the snowman string
            return "\n " + hat + "\n" + up_left_arm + "(" + left_eye + "" + mouth_nose + "" + right_eye + ")" + up_right_arm + "\n" + down_left_arm + "(" + torso+ ")" + down_right_arm + "\n" + " (" + base+ ")";
       }
        // if input number is not valid
        throw std::out_of_range("Illegal Input");
    }
}
