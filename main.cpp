
#include <iostream>
using namespace std;

/**
 * Programer: Pravesh Jung Karki
 * CSC 240 Programming05
 * Encryption System Description: A program to encode and decode messages using a shift by N cypher.
 * This program will ask the user if they want to encode or decode.
 * Then it will ask them to enter the text (either the original plane text, or the encoded text).
 * Then it will ask them to enter the shift N (1 to 25).  Then  we will execute the encode/decode and display the result.
 * And we will again ask the user if they want to do it again, or we will stop the program.
 *
 * Prime number Finder Description: In this program  we use
 * a variation of what is called "The Sieve of Eratosthenes" to find
 * the prime numbers. At first we will ask for the lower bound and
 * upper bound from the user and then give them the prime numbers
 * within that bound. We will use pointer to execute different functions.
 */

//Prototyping the below functions for encrypt/decrypt
int optionsFrom();

int shift();
void encode(char str[], int shift, char result[]);

void decode(char str[], int shift, char result[]);

int isLowerCase(char character);

int isUpperCase(char character);

void getLine(char buffer[]);



//PROTOTYPING the functions for finding prime numbers
int *initialized(int size);

int findingIndex(int size, int array[]);

void findPrime(int array[], int size, int factor);

void circleAllZero(int array[], int size);

int *primeNumbers(int array[], int size, int &size2);

int main() {
    //declaring necessary variables for encryption system
    int option;
    int shifts;
    int counter;
    char s;
    char text[81];
    char result[81];
    int options = 0;

    //declaring necessary variables for finding prime numbers
    int *pointer;
    int *firstIndex;
    int size2 = 0;
    int lowBound = 0;
    int highBound = 0;
    int index = 0;
    char result2;
    char repeat;

    do {
        cout << "Choose the options below: " << endl;
        cout << "Option1: Encryption System " << endl;
        cout << "Option2: Finding prime numbers " << endl;
        cin >> options;

        if (options == 1) {
            cout << "WELCOME to a program that encode and decode messages using a shift. " << endl;
            cout << "The program will ask you if you want to encode or decode. " << endl;
            cout << "Then it will ask you to enter the text (either the original plane text, or the encoded text)."
                 << endl;
            cout << "Then it will ask you to enter the shift N (1 to 25). " << endl;
            cout << " After that you will see the result displays below. " << endl;
            cout << "And again we will ask you if you want to do it again, or you can choose to stop the program."
                 << endl;
            cout << " ***************  LETS BEGIN  ************ " << endl;

            do {
                do {
                    option = optionsFrom();
                    shifts = shift();
                    counter = 0;
                    cout << "Enter the text that you would like to encode or decode: ";
                    getLine(text);
                    getLine(text);
                    for (int i = 0; text[i] != '\0'; i++) {
                        counter++;
                    }
                    if (counter < 1 || counter > 80) {
                        cout << " Error Invalid input." << endl;
                        cout << " The length of the text has to be maximum 80 character." << endl;

                    }
                } while (counter < 1 || counter > 80);
                if (option == 1)
                    encode(text, shifts, result);
                else
                    decode(text, shifts, result);
                cout << "\n" << endl;
                cout << " Do you like to repeat again ? " << endl;
                cout << " ENTER 'y' for yes and 'n' for no. " << endl;
                cin >> s;
            } while (s == 'y');

        } else if (options == 2) {

            cout << " Welcome to the program that gives you a prime number." << endl;
            cout << " You will asked to enter the lower bound and the upper bound. " << endl;
            cout << " The program will display all the prime numbers within that range. " << endl;
            cout << " ************************ LET'S BEGIN **********************" << endl;
            cout << " " << endl;
            cout << " Specify a range of positive integers with a low and high boundary. " << endl;
            do {
                size2 = 0;
                do {
                    do {
                        cout << " Enter the low boundary: " << endl;
                        cin >> lowBound;
                        if (lowBound <= 0) {
                            cout << "Only positive number is accepted for low bound." << endl;
                        }
                    } while (lowBound <= 0);
                    do {
                        cout << " Enter the high boundary: " << endl;
                        cin >> highBound;
                        if (highBound <= 0) {
                            cout << "Only positive number is accepted for high bound." << endl;
                        }
                    } while (highBound <= 0);
                    if (lowBound > highBound) {
                        cout << "Low Bound cannot be greater than high bound." << endl;
                    }
                } while (lowBound > highBound);

                pointer = initialized(highBound + 1);
                do {
                    index = findingIndex(highBound + 1, pointer);
                    if (index > sqrt(highBound)) {
                        circleAllZero(pointer, highBound + 1);
                    } else
                        findPrime(pointer, highBound + 1, index);
                } while (sqrt(highBound) > index);

                int *p = primeNumbers(pointer, highBound + 1, size2);
                firstIndex = p;
                cout << " " << endl;
                //resetting the pointer
                //p = firstIndex;
                cout << "The prime numbers within " << lowBound << " and " << highBound << " are:" << endl;

                while (*p < lowBound) {
                    p++;
                }
                while (p < (size2 + firstIndex)) {
                    cout << *p << " ";
                    p++;
                }
                cout << " " << endl;
                cout << "\n Do you like to repeat again ?" << endl;
                cout << "Enter 'y' for Yes and 'n' for No." << endl;
                cin >> result2;
                if (result2 == 'n' || result2 == 'N') {
                    cout << "Program is now terminating..." << endl;
                    cout << " Thank You! " << endl;
                }
            } while (result2 == 'y' || result2 == 'Y');

        }

        cout << "\n Do you like to see the Main Menu ?" << endl;
        cout << "Enter 'y' to see the main menu and 'n' to quit." << endl;
        cin >> repeat;
    }while(repeat == 'y' || repeat == 'Y');

    return 0;
}

/**
 *  This function will ask user weather they want to
 *  encode or decode. The option 1 is for encode and 2 for the decode
 *  If they enter any number except 1 or 2, it will give them an error
 *  message and ask them to enter agian.
 * @return int number 1 or 2.
 */
int optionsFrom() {
    int encode;
    int decode;
    int option;
    do {
        cout << " \n" << endl;
        cout << "Do you like to encode or decode ? " << endl;
        cout << "Option 1 --> Encode " << endl;
        cout << "Option 2 --> Decode " << endl;
        cin >> option;
        if (option != 1 && option != 2) {
            cout << " Error Invalid input." << endl;
            cout << " The option has to be either 1 or 2. \n" << endl;
        }
    } while (option != 1 && option != 2);
    return option;
}

/**
 * This function will ask the user to enter the shift
 * they like to do for encode or a decode. If the shift is not from
 * 1 to 25, then it will throw an error message and ask for
 * the valid number.
 * @return
 */
int shift() {
    int shift;
    do {
        cout << " Enter the shift N (1 to 25): " << endl;
        cin >> shift;
        if (shift < 1 || shift > 25) {
            cout << " Error Invalid input." << endl;
            cout << " The shift should be from ( 1 to 25 ). \n" << endl;
        }
    } while (shift < 1 || shift > 25);
    return shift;
}

/**
 * This function will perform the encode operation.
 * @param str will take the c-string
 * @param shift is for the shift
 * @param result is for the result
 */
void encode(char str[], int shift, char result[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')) {
            result[i] = str[i];
        } else if ((isUpperCase(str[i]) && (str[i] + shift) > 'Z') ||
                   ((str[i] + shift) > 'z')) {
            result[i] = str[i] + shift - 26;
        } else
            result[i] = str[i] + shift;
        count++;
    }
    result[count] = '\0';
    cout << "The encoded text after " << shift << " shift is: " << result;


}

/**
 * This fucntion will perform the decode operation.
 * @param str will take c-string
 * @param shift will take the number of shift
 * @param result will be used in displaying result
 */

void decode(char str[], int shift, char result[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')) {
            result[i] = str[i];
        } else if ((isLowerCase(str[i]) && (str[i] - shift) < 'a') ||
                   ((str[i] - shift) < 'A')) {
            result[i] = str[i] - shift + 26;
        } else
            result[i] = str[i] - shift;
        count++;
    }
    result[count] = '\0';
    cout << "The decoded text <<  after " << shift << " shift is: " << result;


}

/**
 * The fucntion will check if the given character
 * is lower case or not, and it will return 1 if it's a
 * lower case otherwise returns 0.
*/
int isLowerCase(char character) {
    return (character >= 'a' && character <= 'z');
}

/**
 * The function will check if the given character
 * is upper case, it will return 1 if it's an uppercase
 * otherwise it will return 0.
 * @param character
 * @return 1 or 0.
 */
int isUpperCase(char character) {
    return (character >= 'A' && character <= 'Z');
}

/**
 * This method will take c-string
 * and checks if each charcater taken is
 * new line, once it catches the new line it will stop
 * else it will keep on taking every character.
 */
void getLine(char buffer[]) {
    int ix;
    char c;
    ix = 0;
    c = cin.get();
    while (c != '\n') {
        buffer[ix] = c;
        ++ix;
        c = cin.get();
    }

    buffer[ix] = '\0';
}


/**
Given an integer size, this method will return an array of integers of that size,
with all elements initialized to zero, except for elements at indexes 0 and 1,
that are set to 'NOT PRIME' (-1)
 */
int *initialized(int size) {
    int *array = new int[size];
    int *pointer = array;
    *pointer = -1;
    *(pointer + 1) = -1;
    for (pointer = array + 2; pointer < size + array; pointer++) {
        *pointer = 0;
    }
    return array;
}

// Given an array of integers, and the size of that array,
//We will return the index of the first element that contains a zero.
int findingIndex(int size, int array[]) {
    int *pointer;
    for (pointer = array; pointer < size + array; pointer++) {
        if (*pointer == 0)
            return (pointer - array);

    }


}

/**
Given an array of integers, the size of that array, and an integer factor,
We will 'circle' the element at the index equal to the given
 factor beacuse it is a prime number,
 So we put +1, then we will scan the rest of the array and
 'cross out' (mark with a -1) every other
element with an index that is multiple of the given factor.
**/
void findPrime(int array[], int size, int factor) {
    int *pointer = array;
    *(pointer + factor) = 1;
    int *tempArray = array + factor + factor;
    for (pointer = tempArray; pointer < size + array; pointer += factor) {
        *pointer = -1;
    }

}

/**
Given an array of integers, and the size of that array,
we will scan the array and convert every element
 that contains a zero (unknown) to a +1 (circled).
**/
void circleAllZero(int array[], int size) {
    int *pointer;
    for (pointer = array; pointer < size + array; pointer++)
        if (*pointer == 0)
            *pointer = 1;
}

/**
Given an array of integers, and the size of that array,
we will return another array of integers that contains the indexes of the elements
in the first array that are 'circled' (contain a +1),
and also  we will return the size of that second array.
We will use a reference parameter to return the array's size.)
*/

int *primeNumbers(int array[], int size, int &size2) {
    int *array2 = new int[size];
    int *point1;
    int *point2 = array2;
    int *copyArray = array;
    for (point1 = array; point1 < size + copyArray; point1++) {
        if (*point1 == 1) {
            *point2 = point1 - copyArray;
            point2++; size2++;
        }
    }
    return array2;
}

