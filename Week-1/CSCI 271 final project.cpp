
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// Generate random number between 1 and 9

int getRandom() {
    return 1 + rand() % 9;
}

int main() {
    srand(time(0));

    float player_money = 0;
    float bet = 0;
    string section_choice;
    int number_choice;
    int correct_number, bomb_number;
    int turns = 0;


    // START GAME
    
    cout << "Welcome to Dice or Slice!" << endl;
    cout << "Enter the amount of money to deposit: ";
    cin >> player_money;

    
    // MAIN GAME LOOP
  
    while (true) {

    if (player_money <= 0) {
        cout << "You are out of money!" << endl;
        break;
    }

    cout << "\nYour current balance is: $" << player_money << endl;
    cout << "Enter the amount you want to bet: ";
    cin >> bet;

    if (bet <= 0 || bet > player_money) {
        cout << "Invalid bet. Try again." << endl;
        continue;
    }

  
    // Choose section
  
    cout << "Choose a section: low (1-3), mid (4-6), high (7-9)" << endl;
    cin >> section_choice;

    int min_range, max_range;

    if (section_choice == "low") {
        min_range = 1; max_range = 3;
    } 
    else if (section_choice == "mid") {
        min_range = 4; max_range = 6;
    } 
    else if (section_choice == "high") {
        min_range = 7; max_range = 9;
    } 
    else {
        cout << "Invalid section. Try again." << endl;
        continue;
    }


    // Number pick
 
    cout << "Pick a number between " << min_range << " and " << max_range << ": ";
    cin >> number_choice;

    if (number_choice < min_range || number_choice > max_range) {
        cout << "Invalid number for this section. Try again." << endl;
        continue;
    }


    // Random values
  
    correct_number = getRandom();
    bomb_number = getRandom();

    cout << "Correct number was: " << correct_number << endl;
    cout << "Bomb number was: " << bomb_number << endl;

    bool correct_section = (correct_number >= min_range && correct_number <= max_range);
    turns++;

   
    // BOMB CHECK (25% OF BET)
  
    if (number_choice == bomb_number) {
        float loss = bet * 0.25f;
        player_money -= loss;
        cout << "You hit the BOMB! You lose 25% of your BET: -$" << loss << endl;
        cout << "Money left: $" << player_money << endl;

        // NEW FEATURE ADDED HERE -------------------------------------------------
        char walk;
        cout << "Do you want to walk away with your current money? (y/n): ";
        cin >> walk;
        if (walk == 'y' || walk == 'Y') break;
        // ------------------------------------------------------------------------

        continue;
    }



    // WIN / LOSE LOGIC
 
    if (number_choice == correct_number) {
        float win = bet * 3;
        player_money += win;
        cout << "EXACT MATCH! You win TRIPLE your bet: +$" << win << endl;
    }
    else if (correct_section) {
        float win = bet * 2;
        player_money += win;
        cout << "✔ Correct SECTION! You win DOUBLE your bet: +$" << win << endl;
    }
    else {
        float loss = bet * 0.15f;
        player_money -= loss;
        cout << "Wrong guess. You lose 15% of your BET: -$" << loss << endl;
    }

    cout << "Your new balance: $" << player_money << endl;


    // NEW FEATURE ADDED HERE -----------------------------------------------------
    char walk;
    cout << "Do you want to walk away with your current money? (y/n): ";
    cin >> walk;
    if (walk == 'y' || walk == 'Y') break;
    // -----------------------------------------------------------------------------


    // Option to quit normally
    char quit;
    cout << "Play again? (y/n): ";
    cin >> quit;

    if (quit == 'n' || quit == 'N')
        break;

    }


    // END OF GAME SUMMARY

    cout << "=====================================\n";
    cout << "             GAME OVER\n";
    cout << "=====================================\n";
    cout << "Final Money: $" << player_money << endl;
    cout << "Total Turns Played: " << turns << endl;
    cout << "Thanks for playing Dice or Slice!" << endl;

    return 0;
}
