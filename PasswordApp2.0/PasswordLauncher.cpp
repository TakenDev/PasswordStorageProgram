#include <iostream>
#include <string>

using namespace std;

// Function prototypes
int appSelect();
int app1();
int app2();
int app3();
int app4();



int main()
{
    cout << "Please select an application\n";
    cout << "####################################\n";
    cout << "1: Application #1 \n";
    cout << "2: Application #2 \n";
    cout << "3: Application #3 \n";
    cout << "4: Application #4 \n";
    cout << "####################################\n";



    appSelect();

}

int appSelect()
{

    int x;
    cin >> x;

    switch (x) {

    case 1:
        app1();
        break;
    case 2:
        app2();
        break;
    case 3:
        app3();
        break;
    case 4:
        app4();
        break;
    }

    return 0;
}

int app1()
{
    cout << "You chose app 1.\n";
    return 0;
}
int app2()
{
    cout << "You chose app 2.\n";
    return 0;
}
int app3()
{
    cout << "You chose app 3.\n";
    return 0;
}
int app4()
{
    cout << "You chose app 4.\n";
    return 0;
}
