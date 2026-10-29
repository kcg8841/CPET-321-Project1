#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Database.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Create Database
	Database db;

    // Car Inventory File
	string filename = "Inventory.txt";

    bool ExitRequested = false;

    // Fill Database
	db.importcars(filename);

    int selectedVehicleIndex = -1;

    cout << "Welcome to the Car Reservation System!\n\n";

    // Execution Loop
    do {
        char Command;
        // Prompt the user for the program option (Help, Select, Deselect, Create, Check, Remove, Advance, or Quit)
        cout << "Current Selected Vehicle : " << ((selectedVehicleIndex == -1) ? "None" : (db.getvehicle(selectedVehicleIndex)->CarDetails())) << "\nCurrent Date : " << db.getdate() << "\n\nOptions: Select, Deselect, Create, Check, Remove, Advance\n";
        cout << "Select Action (? For Help) > ";
        cin >> Command;

        // Process the command
        switch (Command)
        {
        case '?': // Help screen
        {
            cout << " ? = Display Help" << endl;
            cout << " I = Display All Vehicles" << endl;
            cout << " W = Display All Reserved Vehicles" << endl;
            cout << " O = Display All Open Vehicles" << endl;
            cout << " S = Select Vehicle" << endl;
            cout << " D = Deselect Vehicle" << endl;
            cout << " C = Create Reservation" << endl;
            cout << " H = Check Reservation" << endl;
            cout << " R = Remove Reservation" << endl;
            cout << " A = Advance Date" << endl;
            cout << " Q = Quit / Exit the program" << endl;
            break;
        } // Case '?'
        case 's': case 'S': // Select Vehicle
        {
            // Prompt for Search Method
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
                    // If a match is found, add to list of matched vehicles and append text to output string
                    if (current->GetMake() == DesiredMake) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                // Print out vehicles to select
                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    // Get user selection
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    // Verify user selection
                    if (vehicleselection <= vehiclecount) {
                        selectedVehicleIndex = matchedVehicles[vehicleselection - 1];
                        cout << "\nSuccessfully Selected " << vehicleselection << ": " << db.getvehicle(selectedVehicleIndex)->CarDetails() << endl;
                    }
                    else {
                        cout << "\nInvalid Selection" << endl;
                    }
                }
                // Print out matching entries

                break;
            } // case '1'
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
                for (int i = 0; i < 50; i++) {
                    current = db.getvehicle(i);
                    if (current == nullptr) continue;
                    // If a match is found, add to list of matched vehicles and append text to output string
                    if (current->GetModel() == DesiredModel) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                // Print out vehicles to select
                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    // Get user selection
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    // Verify user selection
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
            } // case '2'
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
                for (int i = 0; i < 50; i++) {
                    current = db.getvehicle(i);
                    if (current == nullptr) continue;
                    // If a match is found, add to list of matched vehicles and append text to output string
                    if (current->GetYear() == DesiredYear) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                // Print out vehicles to select
                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    // Get user selection
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    // Verify user selection
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
            } // case '3'
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
                for (int i = 0; i < 50; i++) {
                    current = db.getvehicle(i);
                    if (current == nullptr) continue;
                    // If a match is found, add to list of matched vehicles and append text to output string
                    if (current->GetColor() == DesiredColor) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                // Print out vehicles to select
                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    // Get user selection
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    // Verify user selection
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
            } // case '4'
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
                for (int i = 0; i < 50; i++) {
                    current = db.getvehicle(i);
                    if (current == nullptr) continue;
                    // If a match is found, add to list of matched vehicles and append text to output string
                    if (current->InfoOut().at(19) == DesiredPropulsion.front()) {
                        vehiclecount++;
                        matchedVehicles.push_back(i);
                        returnstring += to_string(vehiclecount) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                    }
                }

                // Print out vehicles to select
                if (vehiclecount == 0) cout << returnstring + "- None\n";
                else {
                    // Get user selection
                    int vehicleselection;
                    cout << returnstring << endl;
                    cout << "Select Vehicle Between 1-" << vehiclecount << " > ";
                    cin >> vehicleselection;

                    // Verify user selection
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
        } // case '5'
        case 'd': case 'D': // Deselect Vehicle
        {
            // Skip if no selected vehicle
            if (selectedVehicleIndex == -1) cout << "No Selected Vehicle to Deselect" << endl;
            else {
                cout << "Successfully Deselected " << db.getvehicle(selectedVehicleIndex)->CarDetails() << endl;
                // Deselect vehicle (remove index)
                selectedVehicleIndex = -1;
            }
            break;
        } // case 'd' or 'D'
        case 'c': case 'C': // Create Reservation
        {
            // Skip if there is no selected vehicle
            if (selectedVehicleIndex == -1) cout << "No Selected Vehicle, Select a Vehicle Before Making a Reservation" << endl;
            else {
                // Get user input for which date to reserve for
                int reservationdate;
                cout << "What date would you like to reserve the vehicle for? > ";
                cin >> reservationdate;
                cout << endl;

                // Attempt to reserve vehicle
                int response = db.createreservation(selectedVehicleIndex, reservationdate);

                // Give error message corresponding to reservation success
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
        } // case 'c' or 'C'
        case 'r': case 'R': // Remove Reservation
        {
            // Skip if there is no selected vehicle
            if (selectedVehicleIndex == -1) cout << "No Selected Vehicle, Select a Vehicle Before Removing a Reservation" << endl;
            else {
                // Get current reservations and display to user
                int* currentreservations = db.getvehicle(selectedVehicleIndex)->GetReservations();
                cout << "Available Reservation Date(s) to Remove: " << currentreservations[0] << ", " << currentreservations[1] << ", " << currentreservations[2] << ".\n";
                
                // Get user selection for reservation to delete
                int reservationdate;
                cout << "Which date would you like to remove the reservation for? > ";
                cin >> reservationdate;
                cout << endl;
                // Attempt to remove reservation
                int response = db.deletereservation(selectedVehicleIndex, reservationdate);

                // Give error message depending on removal success
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
        } // case 'r' or 'R'
        case 'h': case 'H': // Check Reservations
        {
            // Skip if there is no current selected vehicle
            if (selectedVehicleIndex == -1) cout << "No Selected Vehicle, Select a Vehicle Before Checking a Reservation" << endl;
            else {
                // Get the current vehicle, and then get the reservations from that vehicle
                int* currentreservations = db.getvehicle(selectedVehicleIndex)->GetReservations();
                cout << "Current Vehicle Reservations: " << currentreservations[0] << ", " << currentreservations[1] << ", " << currentreservations[2] << ".\n";
            }
            break;
        } // case 'h' or 'H'
        case 'i': case 'I': // Check Reservations
        {
            string returnstring = "All Vehicles:\n";

            int vehiclecount = 0;

            Vehicle* current;

            vector<int> matchedVehicles;

            // Search the database
            for (int i = 0; i < 50; i++) {
                current = db.getvehicle(i);
                if (current == nullptr) continue;
                // If a match is found, add to list of matched vehicles and append text to output string
                vehiclecount++;
                matchedVehicles.push_back(i);
                returnstring += to_string(i+1) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
            }

            cout << returnstring;
            break;
        } // case 'h' or 'H'
        case 'w': case 'W': // Check Reservations
        {
            string returnstring = "All Reserved Vehicles:\n";

            int vehiclecount = 0;

            Vehicle* current;

            int* currentreservations;

            int* blank = new int[3];
       

            vector<int> matchedVehicles;

            // Search the database
            for (int i = 0; i < 50; i++) {
                current = db.getvehicle(i);
                currentreservations = current->GetReservations();
                if (current == nullptr) continue;
                // If a match is found, add to list of matched vehicles and append text to output string
                if (currentreservations[0] != 0 || currentreservations[1] != 0 || currentreservations[2] != 0) {
                    vehiclecount++;
                    matchedVehicles.push_back(i);
                    returnstring += to_string(i+1) + ") " + current->CarDetails() + " " + current->InfoOut() + "Current Reservations: " + to_string(currentreservations[0]) + ", " + to_string(currentreservations[1]) + ", " + to_string(currentreservations[2]) + ".\n\n";
                }
            }

            cout << returnstring;

            break;
        } // case 'h' or 'H'
        case 'o': case 'O': // Check Reservations
        {
            string returnstring = "All Open Vehicles:\n";

            int vehiclecount = 0;

            Vehicle* current;

            int* currentreservations;

            int* blank = new int[3];


            vector<int> matchedVehicles;

            // Search the database
            for (int i = 0; i < 50; i++) {
                current = db.getvehicle(i);
                currentreservations = current->GetReservations();
                if (current == nullptr) continue;
                // If a match is found, add to list of matched vehicles and append text to output string
                if (currentreservations[0] == 0 && currentreservations[1] == 0 && currentreservations[2] == 0) {
                    vehiclecount++;
                    matchedVehicles.push_back(i);
                    returnstring += to_string(i+1) + ") " + current->CarDetails() + " " + current->InfoOut() + "\n";
                }
            }

            cout << returnstring;

            break;
        } // case 'h' or 'H'
        case 'a': case 'A': // Advance Date
        {
            cout << "\nAdvanced Date from " << db.getdate() << " to " << db.getdate() + 1 << ".\n";
            // Advance Date Within the Database
            db.advancedate();
            break;
        } // case 'a' or 'A'
        case 'q': case 'Q': // Exit the program
        {
            ExitRequested = true;
            break;
        } // case 'q' or 'Q'
       // "otherwise" is not needed, any other command is ignored
        } // switch()

        cout << endl << endl << "-----------------------------------------\n";

    } while (!ExitRequested);
}