#include <iostream>
#include <conio.h> // Used for console input/output
#include <windows.h> // For Sleep() function
using namespace std;

// Flag to indicate whether the game should end
bool gameEnd = false;

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
    drxn = Stop; // Snake is stationary
    x = width / 2; // Snake starts at the center of the game board
    y = heigth / 2;
    fruitX = rand() % width; // Random x-coordinate for fruit
    fruitY = rand() % heigth; // Random y-coordinate for fruit
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
        cout << "#";
    }
    cout << endl;

    // Draw the game board with snake and fruit
    for (int i = 0; i < heigth; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#"; // Left border
            }

            if (i == y && j == x) {
                cout << "O"; // Snake's head
            } else if (i == fruitY && j == fruitX) {
                cout << "F"; // Fruit
            } else {
                bool tail_print = false; // Flag to check if part of the tail is here

                for (int k = 0; k < tail_Len; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        tail_print = true;
                        cout << "o"; // Snake's tail
                        break;
                    }
                }

                if (!tail_print) {
                    cout << " "; // Empty space
                }
            }

            if (j == width - 1) {
                cout << "#"; // Right border
            }
        }
        cout << endl;
    }

    // Draw the bottom border
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;

    // Display the score
    cout << "Score: " << score << endl;
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
        case 'b': // Quit the game
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

    Default(); // Initialize game settings
    while (!gameEnd) { // Continue until the game ends
        Draw(); // Render the game board
        Input(); // Process user input
        Logic(); // Update game logic
        int delay = max(10, 50 - tail_Len); // Adjust speed based on snake length
        Sleep(delay); // Add delay for smooth gameplay
    }


        // Game over message 
   
    cout << "\nGame Over! Final Score: " << score << endl;
  
    system("pause");
    return 0;
}
