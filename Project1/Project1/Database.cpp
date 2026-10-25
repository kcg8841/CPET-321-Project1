#include <fstream>
#include <sstream>
#include <string>
#include "Database.h"
#include "GasVehicle.h"
#include "ElectricVehicle.h"

using namespace std;

// Returns how many reservations (0 to 3) the vehicle currently has
int CountReservations(Vehicle* TheVehicle)
{
    int* Reservations = TheVehicle->GetReservations();
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (Reservations[i] != 0)
        {
            count++;
        } // if()
    } // for()
    return count;
} // CountReservations()

Database::Database()
{
    inventorycount = 0;
    currentdate = 1;
    for (int i = 0; i < 50; i++)
    {
        inventory[i] = nullptr;
    } // for()
} // constructor

int Database::importcars(string filename)
{
    ifstream InFile;
    InFile.open(filename);
    if (!InFile.is_open())
    {
        return -1;
    } // if()

    int imported = 0;
    string Line;
    // Read one vehicle per line until the end of the file or the database is full
    while (inventorycount < 50 && getline(InFile, Line))
    {
        // Split the line into its seven fields
        istringstream Record(Line);
        string Field;
        string Make, Model, Year, EngineType, Capacity, Efficiency, Color;
        int FieldCount = 0;
        while (Record >> Field)
        {
            FieldCount++;
            switch (FieldCount)
            {
            case 1: { Make = Field; break; }
            case 2: { Model = Field; break; }
            case 3: { Color = Field; break; }
            case 4: { Year = Field; break; }
            case 5: { EngineType = Field; break; }
            case 6: { Capacity = Field; break; }
            case 7: { Efficiency = Field; break; }
            } // switch()
        } // while()

      // Skip blank lines
        if (FieldCount == 0)
        {
            continue;
        } // if()
        if (FieldCount != 7)
        {
            return -2;
        } // if()

      // Convert the numeric fields, a line with a bad number is malformed
        int year;
        double capacity, efficiency;
        istringstream YearStream(Year);
        istringstream CapacityStream(Capacity);
        istringstream EfficiencyStream(Efficiency);
        if (!(YearStream >> year) || !(CapacityStream >> capacity) ||
            !(EfficiencyStream >> efficiency))
        {
            return -2;
        } // if()

      // Create a GasVehicle or ElectricVehicle depending on the propulsion type
        Vehicle* NewVehicle;
        if (EngineType == "ICE")
        {
            GasVehicle* gv = new GasVehicle();
            gv->SetType(EngineType);
            gv->SetCapacity(capacity);
            gv->SetEfficiency(efficiency);
            NewVehicle = gv;
        } // if()
        else if (EngineType == "EV")
        {
            ElectricVehicle* ev = new ElectricVehicle();
            ev->SetType(EngineType);
            ev->SetCapacity(capacity);
            ev->SetEfficiency(efficiency);
            NewVehicle = ev;
        } // else if()
        else
        {
            return -3;
        } // if...else()

      // Fields that every vehicle has
        NewVehicle->SetMake(Make);
        NewVehicle->SetModel(Model);
        NewVehicle->SetYear(year);
        NewVehicle->SetColor(Color);

        // A new vehicle starts with no reservations (0 = no reservation)
        int* Reservations = NewVehicle->GetReservations();
        for (int i = 0; i < 3; i++)
        {
            Reservations[i] = 0;
        } // for()

        inventory[inventorycount] = NewVehicle;
        inventorycount++;
        imported++;
    } // while()

    return imported;
} // importcars()

int Database::getcount()
{
    return inventorycount;
} // getcount()

Vehicle* Database::getvehicle(int index)
{
    if (index < 0 || index >= inventorycount)
    {
        return nullptr;
    } // if()
    return inventory[index];
} // getvehicle()

int Database::getdate()
{
    return currentdate;
} // getdate()

void Database::advancedate()
{
    currentdate++;
    // Reservations for days that have passed are cleared so the cars are available
    for (int i = 0; i < inventorycount; i++)
    {
        updateavailability(i, currentdate);
    } // for()
} // advancedate()

bool Database::checkavailability(int index, int reservationdate)
{
    Vehicle* TheVehicle = getvehicle(index);
    if (TheVehicle == nullptr)
    {
        return false;
    } // if()

  // Not available if it is already reserved on that date
    int* Reservations = TheVehicle->GetReservations();
    for (int i = 0; i < 3; i++)
    {
        if (Reservations[i] == reservationdate)
        {
            return false;
        } // if()
    } // for()

  // Not available if all three reservations are used
    return CountReservations(TheVehicle) < 3;
} // checkavailability()

int Database::updateavailability(int index, int today)
{
    Vehicle* TheVehicle = getvehicle(index);
    if (TheVehicle == nullptr)
    {
        return -1;
    } // if()

    int deleted = 0;
    int* Reservations = TheVehicle->GetReservations();
    for (int i = 0; i < 3; i++)
    {
        // A reservation on a day before today means the car has been returned
        if (Reservations[i] != 0 && Reservations[i] < today)
        {
            TheVehicle->DeleteReservation(Reservations[i]);
            deleted++;
        } // if()
    } // for()
    return deleted;
} // updateavailability()

int Database::createreservation(int index, int reservationdate)
{
    Vehicle* TheVehicle = getvehicle(index);
    if (TheVehicle == nullptr)
    {
        return -1;
    } // if()
    if (reservationdate <= currentdate)
    {
        return 3;
    } // if()

  // Check for a duplicate in all three slots before adding the reservation
    int* Reservations = TheVehicle->GetReservations();
    for (int i = 0; i < 3; i++)
    {
        if (Reservations[i] == reservationdate)
        {
            return 1;
        } // if()
    } // for()

  // Returns 0 if added, or 2 if the vehicle already has 3 reservations
    return TheVehicle->AddReservation(reservationdate);
} // createreservation()

int Database::deletereservation(int index, int reservationdate)
{
    Vehicle* TheVehicle = getvehicle(index);
    if (TheVehicle == nullptr)
    {
        return -1;
    } // if()
    if (reservationdate <= 0)
    {
        return 1;
    } // if()
    return TheVehicle->DeleteReservation(reservationdate);
} // deletereservation()