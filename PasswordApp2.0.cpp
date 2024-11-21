#include <iostream>
#include <conio.h> // For _kbhit() and _getch()
#include <string>
#include <vector>
#include <cctype>
#include <fstream>

using namespace std;

string input;
char verify;
int arrayLength = 0;
vector<string> Passwords;

int Password();

int main() {

    Password();

    return 0;
}

int Password() {
    while (true) {
        std::cout << "Type something or press Escape to exit:\n";
        // Check if a key is pressed
        if (_kbhit()) {
            char key = _getch(); // Get the pressed key
            if (key == 27) {     // ASCII code for Escape
                std::cout << "\nEscape key pressed. Exiting...\n";
                break;
            }
        }

        // Use cin for regular input
        if (!cin.eof()) { // Prevent issues if EOF is encountered
            cout << "> ";
            getline(cin, input);
            if (!input.empty()) {
                system("cls");  // Clears the console on Windows
                cout << "You entered: " << input << "\n";
                cout << "Is this correct? (Y/N): ";
                cin >> verify;
                verify = toupper(static_cast<unsigned char>(verify)); // pass to uppercase, only allow char values with int ranges of 0 - 255.
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the remaining characters in the buffer

                if (verify == 'Y') {
     
                    Passwords.push_back(input); // push input to vector
                    cout << "Password pushed successfully.\n\n";
                    continue;
                 /*
                    // Create a file.
                    ofstream outfile("C:\\Users\\Randy\\OneDrive\\Desktop\\PasswordsTest\\example.txt");

                    if (outfile.is_open()) {
                        outfile << input << "\n";  // Write a string to the file
                        system("cls");
                        cout << "Data written to the file successfully." << endl;
                        outfile.close();
                    }
                */

                }
                else {
                    cout << "Password removed.\n\n";
                    continue;
                    /*
                    // Do not Write to file.
                    cout << "Failed to open the file." << std::endl;  // Error if file can't be opened
                    */
                }
                    
            }
            else {
                system("cls");
                cout << "Please enter valid input.\n";
            }
        }
    }
    return 0;
}

