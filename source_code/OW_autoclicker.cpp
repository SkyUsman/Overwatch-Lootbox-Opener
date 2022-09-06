#include <iostream>
#include <iomanip>
#include <windows.h>    // provides functions for mouse clicks & keyboard keypress recognition

using namespace std;

void introMenu();                       // Display menu
double timeEstimation();                // Calculates estimated time for completion
void autoClick();                       // controls autoclicking

int boxCount;       // Global variable -> number of loot boxes to open

// Controls program execution
int main()
{

    introMenu();
    autoClick();

    cout << "Please close this window!";
    string endPrompt;
    cin >> endPrompt;
    return 0;
}

// Display menu that initializes on program start
void introMenu()
{
    double timeRequired;
    

    cout << "Welcome to the Autoclicker designed for opening Overwatch loot boxes!" << endl << endl;
    cout << "Number of loot boxes to open:  ";
    cin >> boxCount;
    timeRequired = timeEstimation();
    cout << "Approximately ";
    cout << fixed << showpoint << setprecision(1) << timeRequired;      // Displays the time needed formatted to 1 decimal precision
    cout << " minutes required to open " << boxCount << " boxes.\n\n";

    cout << " --------------------------- INSTRUCTIONS ---------------------------" << endl;
    cout << "       -> Move mouse into position over \"OPEN LOOT BOX\" button" << endl;
    cout << "       -> Press the \"M\" key to start or stop autoclicking" << endl;
    cout << "       -> Clicking will begin a few seconds after pressing the key." << endl;
    cout << "          Autoclick will automatically end upon opening the requested number of boxes." << endl;

}

// Calculates the number of minutes needed to open the requested number of lootboxes
double timeEstimation()
{
    double num_of_minutes;
    double num_of_seconds;
    num_of_seconds = boxCount * 7.0;
    num_of_minutes = num_of_seconds / 60.0;

    return num_of_minutes;
}

// Controls autoclicking with "M" key
void autoClick()
{
    int clickCounter = 0;
    bool activationState = false;
    int time_between_clicks = 7000;  // time between clicks (milliseconds) -> 7 seconds
    while (true)
    {

        if (GetAsyncKeyState(0x4D) & 1)     // Hexadecimal value for "M" key -> 0x4D
        {
            activationState = !activationState;
        }
        
        
        if (activationState == true)        // Starts clicking if "M" key was pressed
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0,0,0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0,0,0,0);
            clickCounter = clickCounter + 1;
        }

        if (clickCounter > (boxCount + 5))      // Breaks loop once requested number of boxes plus 5 are opened
        {
            break;
        }
        
        Sleep(time_between_clicks);

    }

    cout << "\n\nCongratuations! All loot boxes have been opened!\n\n";
}