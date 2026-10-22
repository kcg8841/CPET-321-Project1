#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Database.h"

using namespace std;

int main(int argc, char* argv[]) {
	Database db;

	string filename = "Inventory.txt";

    bool ExitRequested = false;

	db.importcars(filename);

    int selectedVehicleIndex = -1;

    do {
        char Command;
        // Prompt the user for the program option (search by Make, Model, Year, or
        //   or exit the program)
        cout << "Welcome to the Car Reservation System!\n\nCurrent Selected Vehicle: " << ((selectedVehicleIndex == -1) ? "None\n" : db.getvehicle(selectedVehicleIndex)->CarDetails()) << "\nCurrent Date: " << db.getdate() << endl;
        cout << "Select Action (? For Help) > ";
        cin >> Command;

        // Process the command
        switch (Command)
        {
        case '?': // Help screen
        {
            cout << " ? = Display Help" << endl;
            cout << " S = Select Vehicle" << endl;
            cout << " D = Deselect Vehicle" << endl;
            cout << " C = Create Reservation" << endl;
            cout << " R = Remove Reservation" << endl;
            cout << " A = Advance Date" << endl;
            cout << " Q = Quit / Exit the program" << endl;
            break;
        } // Case '?'
        /*            cout << " ? = Display Help" << endl;
            cout << " 1 = Search by Make" << endl;
            cout << " 2 = Search by Model" << endl;
            cout << " 3 = Search by Year" << endl;
            cout << " 4 = Search by Color" << endl;
            cout << " 5 = Search by Propulsion Type" << endl;
            cout << " A = Advance Date by One" << endl;
            cout << " Q = Quit / Exit the program" << endl;*/
        case 's': case 'S':
            char SelectCommand;
            cout << endl << " 1 = Search by Make" << endl;
            cout << " 2 = Search by Model" << endl;
            cout << " 3 = Search by Year" << endl;
            cout << " 4 = Search by Color" << endl;
            cout << " 5 = Search by Propulsion Type" << endl;
            cout << "Select Action > ";
            cin >> SelectCommand;
            switch (SelectCommand) {
            case '1': // Search by Make
            {
                // Prompt the user for the search criteria
                string DesiredMake;
                cout << "Enter Make > ";
                cin >> DesiredMake;

                string returnstring = "Vehicle(s) of Make: " + DesiredMake + "\n";

                int vehiclecount = 0;

                Vehicle* current;

                vector<int> matchedVehicles;

                // Search the database
                for (int i = 0; i < 50; i++) {
                    current = db.getvehicle(i);
                    if (current == nullptr) continue;
                    if (current->GetMake() == DesiredMake) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    if (vehicleselection <= vehiclecount) {
                        selectedVehicleIndex = matchedVehicles[vehicleselection - 1];
                        cout << "Successfully Selected " << vehicleselection << ": " << db.getvehicle(selectedVehicleIndex)->CarDetails() << endl;
                    }
                    else {
                        cout << "Invalid Selection" << endl;
                    }
                }
                // Print out matching entries

                break;
            } // case 'a' or 'A'
            case '2': // Search by Model
            {
                // Prompt the user for the search criteria
                string DesiredModel;
                cout << "Enter Model > ";
                cin >> DesiredModel;

                string returnstring = "Vehicle(s) of Model: " + DesiredModel + "\n";

                int vehiclecount = 0;

                Vehicle* current;

                vector<int> matchedVehicles;

                // Search the database
                for (int i = 0; i < 20; i++) {
                    current = db.getvehicle(i);
                    if (current == nullptr) continue;
                    if (current->GetModel() == DesiredModel) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    if (vehicleselection <= vehiclecount) {
                        selectedVehicleIndex = matchedVehicles[vehicleselection - 1];
                        cout << "Successfully Selected " << vehicleselection << ": " << db.getvehicle(selectedVehicleIndex)->CarDetails() << endl;
                    }
                    else {
                        cout << "Invalid Selection" << endl;
                    }
                }
                // Print out matching entries

                break;
            } // case 'o' or 'O'
            case '3': // Search by Year
            {
                // Prompt the user for the search criteria
                int DesiredYear;
                cout << "Enter Year > ";
                cin >> DesiredYear;

                string returnstring = "Vehicle(s) of Year: " + to_string(DesiredYear) + "\n";

                int vehiclecount = 0;

                Vehicle* current;

                vector<int> matchedVehicles;

                // Search the database
                for (int i = 0; i < 20; i++) {
                    current = db.getvehicle(i);
                    if (current == nullptr) continue;
                    if (current->GetYear() == DesiredYear) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    if (vehicleselection <= vehiclecount) {
                        selectedVehicleIndex = matchedVehicles[vehicleselection - 1];
                        cout << "Successfully Selected " << vehicleselection << ": " << db.getvehicle(selectedVehicleIndex)->CarDetails() << endl;
                    }
                    else {
                        cout << "Invalid Selection" << endl;
                    }
                }
                // Print out matching entries

                break;
            } // case 'y' or 'Y'
            case '4': // Search by Color
            {
                // Prompt the user for the search criteria
                string DesiredColor;
                cout << "Enter Color > ";
                cin >> DesiredColor;

                string returnstring = "Vehicle(s) of Color: " + DesiredColor + "\n";

                int vehiclecount = 0;

                Vehicle* current;

                vector<int> matchedVehicles;

                // Search the database
                for (int i = 0; i < 20; i++) {
                    current = db.getvehicle(i);
                    if (current == nullptr) continue;
                    if (current->GetColor() == DesiredColor) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    if (vehicleselection <= vehiclecount) {
                        selectedVehicleIndex = matchedVehicles[vehicleselection - 1];
                        cout << "Successfully Selected " << vehicleselection << ": " << db.getvehicle(selectedVehicleIndex)->CarDetails() << endl;
                    }
                    else {
                        cout << "Invalid Selection" << endl;
                    }
                }
                // Print out matching entries

                break;
            } // case 'y' or 'Y'
            case '5': // Search by Propulsion Type
            {
                // Prompt the user for the search criteria
                string DesiredPropulsion;
                cout << "Enter Propulsion Type > ";
                cin >> DesiredPropulsion;

                string returnstring = "Vehicle(s) of Propulsion: " + DesiredPropulsion + "\n";

                int vehiclecount = 0;

                Vehicle* current;

                vector<int> matchedVehicles;

                // Search the database
                for (int i = 0; i < 20; i++) {
                    current = db.getvehicle(i);
                    if (current == nullptr) continue;
                    if (current->InfoOut().at(19) == DesiredPropulsion.front()) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    if (vehicleselection <= vehiclecount) {
                        selectedVehicleIndex = matchedVehicles[vehicleselection - 1];
                        cout << "Successfully Selected " << vehicleselection << ": " << db.getvehicle(selectedVehicleIndex)->CarDetails() << endl;
                    }
                    else {
                        cout << "Invalid Selection" << endl;
                    }
                }
                // Print out matching entries

                break;
            }
            default:
            {
                cout << "Invalid Selection" << endl;
                break;
            }
            }
            break;
             // case 'y' or 'Y'
        case 'd': case 'D': // Search by Make
        {
            if (selectedVehicleIndex == -1) cout << "No Selected Vehicle to Deselect" << endl;
            else {
                cout << "Successfully Deselected " << db.getvehicle(selectedVehicleIndex)->CarDetails() << endl;
                selectedVehicleIndex = -1;
            }
            break;
        } // case 'a' or 'A'
        case 'c': case 'C': // Search by Model
        {
            if (selectedVehicleIndex == -1) cout << "No Selected Vehicle, Select a Vehicle Before Making a Reservation" << endl;
            else {
                int reservationdate;
                cout << "What date would you like to reserve the vehicle for? > ";
                cin >> reservationdate;
                cout << endl;
                int response = db.createreservation(selectedVehicleIndex, reservationdate);
                switch (response) {
                case -1:
                    cout << "Invalid Selected Vehicle. Please Select Another Vehicle.\n";
                    break;
                case 0:
                    cout << "Successfully Created Reservation for the Date of " << reservationdate << endl;
                    break;
                case 1:
                    cout << "Reservation Failed. Vehicle Already Reserved for that Date.\n";
                    break;
                case 2:
                    cout << "Reservation Failed. Maximum Vehicle Reservations Reached.\n";
                    break;
                case 3:
                    cout << "Reservation Failed. Reservation Date Already Passed.\n";
                    break;
                default:
                    cout << "Reservation Failed. Unknown Error.";
                    break;
                }
            }
            break;
        } // case 'o' or 'O'
        case 'r': case 'R': // Search by Model
        {
            if (selectedVehicleIndex == -1) cout << "No Selected Vehicle, Select a Vehicle Before Removing a Reservation" << endl;
            else {
                int* currentreservations = db.getvehicle(selectedVehicleIndex)->GetReservations();
                cout << "Available Reservation Date(s) to Remove: " << currentreservations[0] << ", " << currentreservations[1] << ", " << currentreservations[2] << ".\n";
                int reservationdate;
                cout << "Which date would you like to remove the reservation for? > ";
                cin >> reservationdate;
                cout << endl;
                int response = db.deletereservation(selectedVehicleIndex, reservationdate);
                switch (response) {
                case -1:
                    cout << "Invalid Selected Vehicle. Please Select Another Vehicle.\n";
                    break;
                case 0:
                    cout << "Successfully Removed Reservation for the Date of " << reservationdate << endl;
                    break;
                case 1:
                    cout << "Reservation Removal Failed. No Existing Registration on That Date.\n";
                    break;
                default:
                    cout << "Reservation Removal Failed. Unknown Error.";
                    break;
                }
            }
            break;
        } // case 'o' or 'O'
        case 'a': case 'A': // Search by Color
        {
            cout << "Advanced Date from " << db.getdate() << " to " << db.getdate() + 1 << ".\n";
            db.advancedate();
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