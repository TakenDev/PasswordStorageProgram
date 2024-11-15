#include <iostream>
#include <string>
#include <fstream> // Include fstream for file operations

using namespace std;

int createFile();

int main()
{
    createFile();

    return 0;
}

int createFile() {

    string input;


    // Corrected file path with escaped backslashes
    ofstream outFile("C:\\Users\\Randy\\OneDrive\\Desktop\\example.txt");

    // Check if the file was opened successfully
    if (outFile.is_open()) {

        cout << "Please enter a password to be stored in the file.\n \n";

        // create an array, 
        // take user input and enter it into array, 
        // send array data to text file.

        // Write to the file
        outFile << "Please enter a password to be stored in the file.\n";

        // Close the file
        outFile.close();
        cout << "File created and data written successfully." << endl;
    }
    else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}
