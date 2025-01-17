#include <iostream>
#include <conio.h> // Used for console input/output
#include <windows.h> // For Sleep() function
using namespace std;

// Flag to indicate whether the game should end
bool gameEnd = false;
bool quit = false;



// Function to control the visibility of the console cursor
void ShowConsoleCursor(bool showFlag) {
    // Get the handle to the standard output (console window)
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    // Structure to hold the console cursor information
    CONSOLE_CURSOR_INFO cursorInfo;

    // Retrieve the current cursor information and store it in cursorInfo
    GetConsoleCursorInfo(out, &cursorInfo);

    // Set the visibility of the cursor based on the input parameter 'showFlag'
    // If 'showFlag' is true, the cursor will be visible; if false, it will be hidden
    cursorInfo.bVisible = showFlag;

    // Apply the updated cursor visibility settings to the console
    SetConsoleCursorInfo(out, &cursorInfo);
}

/********Starting Game Menu**********/
string menuOpt[] = {"Start Game", "View Score", "Exit Game"};//options for menu
const int menuSize = 3; // size of option menu array
int optSelected = 0; // tracks the which option is selected

// Function to display the main menu of the Snake Game
void menu() {
    // Clears the console before printing the menu
    // This ensures the menu appears fresh without overlapping previous prints
    system("cls");
    // Print the menu title with purple color (ANSI escape code \033[95m)
    cout << "\033[95m=== Snake Game Menu ===\033[0m\n\n";

    // Loop through the menu options to display them one by one
    for (int i = 0; i < menuSize; i++) {
        // Check if the current option is the one selected by the user
        if (i == optSelected) {
            // Highlight the selected menu option with cyan color (\033[96m)
            // Add ">>" before and "<<" after the option for visual indication
            cout << ">>\033[96m " << menuOpt[i] << " \033[0m<<\n";
        } else {
            // Display non-selected options with regular formatting (no color change)
            cout << "   " << menuOpt[i] << "\n";
        }
    }
}

// Function to handle the logic for navigating and selecting options in the menu
int menuLogic() {
    // Infinite loop to keep the menu active until the user makes a valid selection
    while (true) {
        // Calls the menu function to display the menu with the current state
        menu();

        // Captures a key press from the user
        int ch = _getch();

        // Checks if the first character is the prefix for arrow keys (224)
        if (ch == 224) {
            // Captures the second part of the arrow key input
            ch = _getch();
            switch (ch) {
                case 72: // Up arrow key pressed
                    // Move the selection upwards in the menu
                    // `(optSelected - 1 + menuSize) % menuSize` ensures wrap-around behavior
                    optSelected = (optSelected - 1 + menuSize) % menuSize;
                    break;

                case 80: // Down arrow key pressed
                    // Move the selection downwards in the menu
                    // `(optSelected + 1) % menuSize` ensures wrap-around behavior
                    optSelected = (optSelected + 1) % menuSize;
                    break;
            }
        }
        // Checks if the user pressed the Enter key (ASCII value 13)
        else if (ch == 13) {
            // Returns the currently selected menu option index
            return optSelected;
        }
    }
}



// Arrays to store the snake's tail coordinates
int tailX[100], tailY[100]; 
int tail_Len; // Length of the snake's tail

// Dimensions of the game board
const int width = 110;
const int heigth = 25;

// Snake and fruit coordinates, and the score
int x, y, fruitX, fruitY, score;

// Enum for snake's movement direction
enum Dirxn {
    Stop = 0, // No movement
    Left,
    Right,
    Up,
    Down
};
Dirxn drxn; // Current direction of the snake

// Initialize default game settings
void Default() {
    gameEnd = false; // Game is not over initially
    quit = false;    // User not quitted game initially
    drxn = Stop; // Snake is stationary
    x = width / 2; // Snake starts at the center of the game board
    y = heigth / 2;
    fruitX = rand() % width; // Random x-coordinate for fruit
    fruitY = rand() % heigth; // Random y-coordinate for fruit
    tail_Len = 0; // initally reset the tail length to 0
    score = 0; // Initial score
}

// Draw the game board, snake, and fruit
void Draw() {
    // this line clears console and makes whole board again which cause flickering 
    // system("cls"); // Clear the console

/* To remove the flickring cause by the above we are using the following code */
    COORD cursorPosition = {0, 0}; // {0, 0} represents the top-left corner of the console
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    // Draw the top border
    for (int i = 0; i < width + 2; i++) {
        cout << "\033[93m#\033[0m";
    }
    cout << endl;

    // Draw the game board with snake and fruit
    for (int i = 0; i < heigth; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "\033[93m#\033[0m"; // Left border
            }

            if (i == y && j == x) {
                cout << "\033[94mO\033[0m"; // Snake's head
            } else if (i == fruitY && j == fruitX) {
                cout << "\033[92mo\033[0m"; // Fruit
            } else {
                bool tail_print = false; // Flag to check if part of the tail is here

                for (int k = 0; k < tail_Len; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        tail_print = true;
                        cout << "\033[95mo\033[0m"; // Snake's tail
                        break;
                    }
                }

                if (!tail_print) {
                    cout << " "; // Empty space
                }
            }

            if (j == width - 1) {
                cout << "\033[93m#\033[0m"; // Right border
            }
        }
        cout << endl;
    }

    // Draw the bottom border
    for (int i = 0; i < width + 2; i++) {
        cout << "\033[93m#\033[0m";
    }
    cout << endl;

    // Display the score
    cout << "\033[96mScore: " << score<<"\033[0m" << endl;
    //Which button to quit game deliberately
    cout << "\033[91mPress 'q' to quit game...\033[0m" << endl;
}

// Handle user input for snake's movement
void Input() {
    
    if (_kbhit()) { // Check if a key was pressed
        switch (_getch()) { // Get the pressed key
        case 'a': // Move left
            drxn = Left;
            break;
        case 'd': // Move right
            drxn = Right;
            break;
        case 'w': // Move up
            drxn = Up;
            break;
        case 's': // Move down
            drxn = Down;
            break;
        case 'q': // Quit the game when user want to do so
            quit = true; // 
            gameEnd = true;
            break;
        default:
            break;
        }
    }
}

// Game logic for movement, collisions, and scoring
void Logic() {
    // Update tail positions
    for (int i = tail_Len - 1; i > 0; i--) {
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    tailX[0] = x;
    tailY[0] = y;

    // Move the snake's head
    switch (drxn) {
    case Left:
        x--;
        break;
    case Right:
        x++;
        break;
    case Up:
        y--;
        break;
    case Down:
        y++;
        break;
    default:
        break;
    }

    // **Condition to end the game if the snake hits the wall**
    // Uncomment the following lines if you want to enable this behavior:
    /*
    if (x < 1 || x > width - 1 || y < 0 || y > heigth - 1) {
        gameEnd = true;
    }
    */

    // Snake wraps around the edges of the game board
    if (x >= width) {
        x = 0;
    } else if (x < 0) {
        x = width - 1;
    }

    if (y >= heigth) {
        y = 0;
    } else if (y < 0) {
        y = heigth - 1;
    }

    // Check if the snake's head collides with its tail
    for (int i = 0; i < tail_Len; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameEnd = true;
            break;
        }
    }

    // Check if the snake eats the fruit
    if (x == fruitX && y == fruitY) {
        fruitX = rand() % width; // Generate new fruit x-coordinate
        fruitY = rand() % heigth; // Generate new fruit y-coordinate
        tail_Len++; // Increase the tail length
        score += 5; // Increase the score
    }
}

// Main game loop
int main() {
    ShowConsoleCursor(false);
    while (true)
    {
        int choice= menuLogic();
        if(choice==0){
            COORD cursorPosition = {0, 0}; // {0, 0} represents the top-left corner of the console
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);


            Default(); // Initialize game settings
            while (!gameEnd)
            {                                       // Continue until the game ends
                Draw();                             // Render the game board

                Input();                            // Process user input
                Logic();                            // Update game logic
                int delay = max(10, 50 - tail_Len); // Adjust speed based on snake length
                Sleep(delay);                       // Add delay for smooth gameplay
                // Game over message
                // Set the background color to red for the "Game Over" message
    }

    // checks if user is quitting game deliberately
    if(quit){
        cout << "\033[91mQuitting Game....!\033[0m" << endl;

    }
    else{

    cout << "\n\033[48;5;1mGame Over! Final Score: " << score<<" " << "\033[0m"<<endl; // The reset sequence (\033[0m) ensures that the red background won't affect subsequent output   
    }
     
    Sleep(1000);
    system("pause");
        }
        else if(choice==1){


            cout << "\033[92mScore is: \0m " << score << endl;
            system("pause");
        }
        else if(choice ==2){
            cout << "\033[91mExiting game....!\033[0m" << endl;
            
            return 0;
        }
    }
    return 0;
}
