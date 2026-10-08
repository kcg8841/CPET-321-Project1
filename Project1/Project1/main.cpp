#include <iostream>
#include "Vehicle.h"
#include "Database.h"

using namespace std;

int main(int argc, char* argv[]) {
	Database db;
	int currentdate = 1;

	string filename = "Inventory.txt";

	db.importCars(filename);

    do {
        char Command;
        // Prompt the user for the program option (search by Make, Model, Year, or
        //   or exit the program)
        cout << "Enter Command (? for help) > ";
        cin >> Command;

        // Process the command
        switch (Command)
        {
        case '?': // Help screen
        {
            cout << " ? = Display Help" << endl;
            cout << " 1 = Search by Make" << endl;
            cout << " 2 = Search by Model" << endl;
            cout << " 3 = Search by Year" << endl;
            cout << " 4 = Search by Color" << endl;
            cout << " 5 = Search by Propulsion Type" << endl;
            cout << " Q = Quit / Exit the program" << endl;
            break;
        } // Case '?'
        case '1': // Search by Make
        {
            // Prompt the user for the search criteria
            string DesiredMake;
            cout << "Enter Make > ";
            cin >> DesiredMake;

            string returnstring = "Vehicle(s) of Make: " + DesiredMake + "\n";

            int vehiclecount = 0;

            // Search the database
            for (int i = 0; i < 50; i++) {
                Vehicle* current = Database.get(i);
                if (current == nullptr) continue;
                if (current->GetMake() == DesiredMake) {
                    returnstring += "- " + current->InfoOut() + "\n";
                    vehiclecount++;
                }
            }

            if (vehiclecount == 0) returnstring += "- None\n";

            // Print out matching entries
            cout << returnstring << endl;

            break;
        } // case 'a' or 'A'
        case '2' // Search by Model
        {
            // Prompt the user for the search criteria
            string DesiredModel;
            cout << "Enter Model > ";
            cin >> DesiredModel;

            string returnstring = "Vehicle(s) of Model: " + DesiredModel + "\n";

            int vehiclecount = 0;

            // Search the database
            for (int i = 0; i < 20; i++) {
                Vehicle* current = Database[i];
                if (current == nullptr) continue;
                if (current->getModel() == DesiredModel) {
                    returnstring += "- " + current->DriveEfficiencyInfo() + "\n";
                    vehiclecount++;
                }
            }

            if (vehiclecount == 0) returnstring += "- None\n";

            // Print out matching entries
            cout << returnstring << endl;

            break;
        } // case 'o' or 'O'
        case '3': // Search by Year
        {
            // Prompt the user for the search criteria
            string DesiredYear;
            cout << "Enter Year > ";
            cin >> DesiredYear;

            string returnstring = "Vehicle(s) of Year: " + DesiredYear + "\n";

            int vehiclecount = 0;

            // Search the database
            for (int i = 0; i < 20; i++) {
                Vehicle* current = Database[i];
                if (current == nullptr) continue;
                if (current->getYear() == DesiredYear) {
                    returnstring += "- " + current->DriveEfficiencyInfo() + "\n";
                    vehiclecount++;
                }
            }

            if (vehiclecount == 0) returnstring += "- None\n";

            // Print out matching entries
            cout << returnstring << endl;

            break;
        } // case 'y' or 'Y'
        case '4': // Search by Color
        {
            // Prompt the user for the search criteria
            string DesiredYear;
            cout << "Enter Year > ";
            cin >> DesiredYear;

            string returnstring = "Vehicle(s) of Year: " + DesiredYear + "\n";

            int vehiclecount = 0;

            // Search the database
            for (int i = 0; i < 20; i++) {
                Vehicle* current = Database[i];
                if (current == nullptr) continue;
                if (current->getYear() == DesiredYear) {
                    returnstring += "- " + current->DriveEfficiencyInfo() + "\n";
                    vehiclecount++;
                }
            }

            if (vehiclecount == 0) returnstring += "- None\n";

            // Print out matching entries
            cout << returnstring << endl;

            break;
        } // case 'y' or 'Y'
        case '5': // Search by Propulsion Type
        {
            // Prompt the user for the search criteria
            string DesiredYear;
            cout << "Enter Year > ";
            cin >> DesiredYear;

            string returnstring = "Vehicle(s) of Year: " + DesiredYear + "\n";

            int vehiclecount = 0;

            // Search the database
            for (int i = 0; i < 20; i++) {
                Vehicle* current = Database[i];
                if (current == nullptr) continue;
                if (current->getYear() == DesiredYear) {
                    returnstring += "- " + current->DriveEfficiencyInfo() + "\n";
                    vehiclecount++;
                }
            }

            if (vehiclecount == 0) returnstring += "- None\n";

            // Print out matching entries
            cout << returnstring << endl;

            break;
        } // case 'y' or 'Y'
        case 'q': case 'Q': // Exit the program
        {
            ExitRequested = true;
            break;
        } // case 'q' or 'Q'
       // "otherwise" is not needed, any other command is ignored
        } // switch()

    } while (!ExitRequested);
}