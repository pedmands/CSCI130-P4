// Preston Edmands
// CSCI 130 - 002
// Spring 2020
// Program 4
// This program calculates the cost of throwing a child’s birthday party as determined by the age of the birthday child and the number of guests invited, plus the cost of the birthday cake. It then outputs the report, breaking down the number of each item to purchase and the cost of each item, as well as the total cost, to a file name determined by the user.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

string GetName();
int GetAge();
int GetGuests();
float GetCakeCost();
string GetFileName();

float GetBalloonsCost(int numBaloons);
float GetNapkinsCost(int napkinPacks, int NAPKINS_PER_PACK);
float GetPlatesCost(int platePacks, int PLATES_PER_PACK);
float CalcuCakeCost();

void PrintReport(string fileName, string name, int numBalloons, float balloonsCost, int numBags, float giftBagsCost, int napkinPacks, float napkinsCost, int platePacks, float platesCost, int pizzas, float pizzaCost, int juiceBoxPacks, float juiceCost, float cakeCost, float total);

int main() {
    // Variable declarations
    string name; // Birthday child's name, to be entered by user.
    int age; // Birthday child's age, to be entered by user.
    int guests; // Number of guests invited, to be entered by user.
    float cakeCost; // Cost of cake, to be entered by user
    string fileName; // Name of output file, to be entered by user.
    
    // Constant declarations
    
    float COST_PER_GIFT_BAG = 4.15; // Cost per gift bag
    int NAPKINS_PER_PACK = 12; // Number of napkins in a pack
    int PLATES_PER_PACK = 8; // Plates per pack
    float COST_PER_PIZZA = 5.35;  // Cost per pizza
    int SLICES_PER_PIZZA = 12; // Number of slices per pizza
    float COST_PER_JUICE_PACK = 4.25; // Cost per juice pack
    int JUICE_BOXES_PER_PACK = 10; // Number of juice boxes per pack
    
    // Welcome the user
    cout << "Welcome to the Birthday Party Cost Calculator" << endl << endl;
    
    // --------------------- Input ---------------------
    
    // Ask the user for the child's name
    name = GetName();
    
    // Get birthday child's age from the user
    age = GetAge();
    
    // Get the number of guests from the user
    guests = GetGuests();
    
    // Get the cost of the cake from the user
    // cakeCost = GetCakeCost();
    cakeCost =
    
    // Get the file name for the output file from the user
    fileName = GetFileName();
    
    // --------------------- Calculations ---------------------
    
    // Calculate total number of children, including birthday child
    int children = guests + 1;
    
    // Calculate number and cost of balloons
    int numBalloons = guests * age; // Each guest gets one balloon for each year the child is old
    float balloonsCost = GetBalloonsCost(numBalloons);
    
    // Calculate number and cost of gift bags
    int numBags = guests; // Each guest gets one gift bag
    float giftBagsCost = numBags * COST_PER_GIFT_BAG;
    
    // Calculate number and cost of napkin packs
    int napkinPacks = ceil((children * 4) / float(NAPKINS_PER_PACK)); // Each child gets 4 napkins. NAPKINS_PER_PACK converted to float to prevent data loss for rounding up.
    float napkinsCost = GetNapkinsCost(napkinPacks, NAPKINS_PER_PACK);
    
    // Calculate number and cost of plates
    int platePacks = ceil((children * 2) / float(PLATES_PER_PACK)); // Each child gets 2 plates. PLATES_PER_PACK converted to float to prevent data loss for rounding up.
    float platesCost = GetPlatesCost(platePacks, PLATES_PER_PACK);
    
    // Calculate number and cost of pizzas
    int pizzas = ceil((children * 3) / float(SLICES_PER_PIZZA)); // Each child gets 3 slices of pizza. SLICES_PER_PIZZA converted to float to prevent data loss for rounding up.
    float pizzaCost = pizzas * COST_PER_PIZZA;
    
    // Calculate number and cost of juice box packs
    int juiceBoxPacks = ceil((children * 2) / float(JUICE_BOXES_PER_PACK)); // Each child gets 2 juice boxes. JUICE_BOXES_PER_PACK converted to float to prevent data loss for rounding up.
    float juiceCost = juiceBoxPacks * COST_PER_JUICE_PACK;
    
    // Calculate the total cost
    float total = balloonsCost + giftBagsCost + napkinsCost + platesCost + pizzaCost + juiceCost + cakeCost;
    
    // --------------------- Output ---------------------
    
    // Print the results to the ofstream output file partyReport.out, located in the same directory as the program.
    PrintReport(fileName, name, numBalloons, balloonsCost, numBags, giftBagsCost, napkinPacks, napkinsCost, platePacks, platesCost, pizzas, pizzaCost, juiceBoxPacks, juiceCost, cakeCost, total);
    
    return 0;
}

// --------------------- User Input Functions ---------------------

// GetName() gets the birthday child's name from user and returns it to main()
// Precondition: none
// Postcondition: returns name
string GetName() {
    string name;
    cout << "What is the birthday child's name? ";
    getline(cin, name);
    return name;
}

// GetAge() gets the age from user and returns it to main()
// Precondition: none
// Postcondition: returns age
int GetAge() {
    int age;
    cout << "How old will the birthday child be? ";
    cin >> age;
    cin.ignore(256, '\n');
    return age;
}

// GetGuests() gets the number of invited guests from user and returns it to main()
// Precondition: none
// Postcondition: returns guests
int GetGuests() {
    int guests;
    cout << "How many invited guests? ";
    cin >> guests;
    cin.ignore(256, '\n');
    return guests;
}

// GetCakeCost() gets the cost of the birthday cake from the user and returns it to main()
// Precondition: none
// Postcondition: returns cakeCost
float GetCakeCost() {
    float cakeCost;
    cout << "How much is the birthday cake? $";
    cin >> cakeCost;
    cin.ignore(256, '\n');
    return cakeCost;
}

// GetFileName() gets the name of the output file from the user and returns it to main()
// Precondition: none
// Postcondition: returns fileName
string GetFileName() {
    string fileName;
    cout << "What would you like to name the output file? ";
    getline(cin, fileName);
    return fileName;
}

// --------------------- Price breakpoint functions ---------------------

// GetBalloonsCost
float GetBalloonsCost(int numBaloons) {
    float costPerBalloon; // Cost per balloon
    float total;
    
    if (numBaloons > 100){
        costPerBalloon = .25;
    }
    else if (numBaloons >= 50) {
        costPerBalloon = .35;
    }
    else {
        costPerBalloon = .45;
    }
    total = numBaloons * costPerBalloon;
    return total;
}

// GetNapkinsCost
float GetnNapkinsCost(int napkinPacks, int NAPKINS_PER_PACK) {
    int numNapkins = napkinPacks * NAPKINS_PER_PACK; // Total number of napkins
    float costPerPack; // Cost per napkin pack
    float total;
    
    if (numNapkins > 300){
        costPerPack = 1.50;
    }
    else if (numNapkins > 100) {
        costPerPack = 2.50;
    }
    else {
        costPerPack = 3.00;
    }
    total = napkinPacks * costPerPack;
    return total;
}

// GetNapkinsCost
float GetnPlatesCost(int platePacks, int PLATES_PER_PACK) {
    int numPlates = platePacks * PLATES_PER_PACK; // Total number of napkins
    float costPerPack; // Cost per napkin pack
    float total;
    
    if (numPlates > 50){
        costPerPack = 3.00;
    }
    else {
        costPerPack = 3.15;
    }
    total = platePacks * costPerPack;
    return total;
}

// --------------------- Utility Functions ---------------------

// PrintReport() prints the report generated by the program to the ofstream output file partyReport.out, located in the same directory as the program.
// Precondition: fileName, name, numBalloons, balloonsCost, numBags, giftBagsCost, napkinPacks, napkinsCost, platePacks, platesCost, pizzas, pizzaCost, juiceBoxPacks, juiceCost, cakeCost, total
// Postcondition: prints the result to the output file partyReport.out
void PrintReport(string fileName, string name, int numBalloons, float balloonsCost, int numBags, float giftBagsCost, int napkinPacks, float napkinsCost, int platePacks, float platesCost, int pizzas, float pizzaCost, int juiceBoxPacks, float juiceCost, float cakeCost, float total) {
    
    // Open an output filestream
    ofstream partyReport;
    
    // Open a report file using the ofstream with the file name previously provided by user
    partyReport.open(fileName, ios::app);
    
    // Format floats to two decimal places
    partyReport << fixed << showpoint << setprecision(2);
    
    partyReport << endl;
    partyReport << "Report for " << name << "'s birthday party:" << endl << endl;
    partyReport << "  Balloons:       " << setw(3) << numBalloons << "   $ " << setw(6) << balloonsCost << endl;
    partyReport << "  Gift Bags:      " << setw(3) << numBags << "   $ " << setw(6) << giftBagsCost << endl;
    partyReport << "  Napkin Packs:   " << setw(3) << napkinPacks << "   $ " << setw(6) << napkinsCost << endl;
    partyReport << "  Plate Packs:    " << setw(3) << platePacks << "   $ " << setw(6) << platesCost << endl;
    partyReport << "  Pizzas:         " << setw(3) << pizzas << "   $ " << setw(6) << pizzaCost << endl;
    partyReport << "  Juicebox Packs: " << setw(3) << juiceBoxPacks << "   $ " << setw(6) << juiceCost << endl;
    partyReport << "  Cake:           " << setw(3) << "1" << "   $ " << setw(6) << cakeCost << endl;
    partyReport << "  Total cost:           $ " << setw(6) << total << endl << endl;
    partyReport << string(40, '*') << endl;
    
    // Close the report file
    partyReport.close();
}
