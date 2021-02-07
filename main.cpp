
#include <iostream>
using namespace std;

/**
 * Programer: Pravesh Jung Karki
 * Description: A program to encode and decode messages using a shift by N cypher.
 * This program will ask the user if they want to encode or decode.
 * Then it will ask them to enter the text (either the original plane text, or the encoded text).
 * Then it will ask them to enter the shift N (1 to 25).  Then  we will execute the encode/decode and display the result.
 * And we will again ask the user if they want to do it again, or we will stop the program.
 */

//Prototyping the below functions.
int options();

int shift();

void encode(char str[], int shift, char result[]);

void decode(char str[], int shift, char result[]);

int isLowerCase(char character);

int isUpperCase(char character);

void getLine(char buffer[]);

int main() {
    int option;
    int shifts;
    int counter;
    char s;
    char text[81];
    char result[81];

    cout << "WELCOME to a program that encode and decode messages using a shift. " << endl;
    cout << "The program will ask you if you want to encode or decode. " << endl;
    cout << "Then it will ask you to enter the text (either the original plane text, or the encoded text)." << endl;
    cout << "Then it will ask you to enter the shift N (1 to 25). " << endl;
    cout << " After that you will see the result displays below. " << endl;
    cout << "And again we will ask you if you want to do it again, or you can choose to stop the program." << endl;
    cout << " ***************  LETS BEGIN  ************ " << endl;

    do {
        do {
            option = options();
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
    return 0;
}

/**
 *  This function will ask user weather they want to
 *  encode or decode. The option 1 is for encode and 2 for the decode
 *  If they enter any number except 1 or 2, it will give them an error
 *  message and ask them to enter agian.
 * @return int number 1 or 2.
 */
int options() {
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
