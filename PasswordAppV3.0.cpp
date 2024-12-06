#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <cstdio> // For remove()
#include <chrono>
#include <ctime>
#include <iomanip>  // For put_time
#include <algorithm>


using namespace std;

// int RemovePassword();
// int EditPassword();


string input1, input2;
vector<pair<string, string>> Passwords; //vector pair of 2 strings

void AddPassword();
void RemovePassword();
void EditPassword();
void PasswordApp();
void LoggingFile(const string& message);

int main()
{
	LoggingFile("Initiating Program Launch...");
	PasswordApp();
	LoggingFile("Program Terminated Successfully.\n");

	return 0;

}
// runs the Password Entry Program
void PasswordApp() {

	int select;
	bool runprogram = true;



	LoggingFile("Program Launched Successfully.");

	do {
		cout << "Passwords" << endl;
		cout << "============================================================" << endl;
		for (size_t i = 0; i < Passwords.size(); i++) { // iterate over the vector, output password for each entry.
			cout << "#" << i + 1 << " Password: " << Passwords[i].first << " | Site/Application: " << Passwords[i].second << endl;
		}
		cout << "============================================================" << endl;
		cout << endl;

		cout << "Please select your feature: \n";
		cout << " 1: Add \n 2: Remove \n 3. Edit \n 4. Exit " << endl;
		cout << "\n> ";

		cin >> select;

		if (cin.fail()) {
			cin.clear(); // Clear the error flag
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			system("cls");
			cout << "Invalid input. Please enter an integer." << endl;
			cout << endl;
		}
		else
		{
			switch (select) {
			case 1:
				AddPassword();
				system("cls");
				break;
			case 2:
				RemovePassword();
				break;
			case 3:
				EditPassword();
				system("cls");
				break;
			case 4:
				runprogram = false;
				break;
			default:
				system("cls");
				cout << "Invalid input" << endl;
				break;
			}
		}
	} while (runprogram);
}

void AddPassword() {

		cout << "Please Enter a Password" << endl;
		cin >> input1;
		LoggingFile("Password entered Successfully.");
		
		cout << "Please Enter a Site" << endl;
		cin >> input2;
		LoggingFile("Site Entered Successfully.");
				
		Passwords.push_back(make_pair(input1, input2));
		cout << endl;
		LoggingFile("Password / Site Pushed to Vector Successfully.");
}
void RemovePassword() {
	int removeinput;

	system("cls");
	cout << "Please Select a Password to remove. \n" << endl;
	cout << "Passwords" << endl;
	cout << "============================================================" << endl;
	for (size_t i = 0; i < Passwords.size(); i++) { // Iterate over the vector, output password for each entry.
		cout << "#" << i + 1 << " Password: " << Passwords[i].first
			<< " | Site/Application: " << Passwords[i].second << endl;
	}
	cout << "============================================================" << endl;
	cout << endl;

	cout << "> ";
	cin >> removeinput;

	// Handle invalid input
	if (cin.fail()) {
		cin.clear(); // Clear the error flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		system("cls");
		cout << "Invalid input. Please enter an integer." << endl;

		LoggingFile("Invalid Removal Entry.");

	}

	// Adjust for 1-based indexing
	removeinput -= 1;

	if (removeinput >= 0 && removeinput < Passwords.size() && !Passwords.empty()) {
		// Remove the element
		Passwords.erase(Passwords.begin() + removeinput);
		system("cls");
		cout << "Erase Successful. \n" << endl;
		LoggingFile("Erased Password at index: " + to_string(removeinput + 1));

	}
	else {
		cout << "Erase Failed. \n" << endl;
	}
}


void EditPassword() {
	cout << "Your mom love";

}



void LoggingFile(const string& message) {

	ofstream logFile("C:\\Users\\Randy\\OneDrive\\Desktop\\PasswordsTest\\logtest.txt", ios::app);
	if (logFile.is_open()) {
		// Get current time for the log entry
		auto now = chrono::system_clock::now();
		time_t currentTime = chrono::system_clock::to_time_t(now);

		// Use localtime_s for thread-safety
		struct tm timeStruct;
		localtime_s(&timeStruct, &currentTime);  // Safe localtime_s call

		// Format the time
		logFile << "[" << put_time(&timeStruct, "%Y-%m-%d %H:%M:%S") << "] " << message << endl;
		logFile.close();
	}
	else {
		cerr << "Unable to open log file!" << endl;
	}
}





