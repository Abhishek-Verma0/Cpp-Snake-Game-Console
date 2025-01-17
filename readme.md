# Console Snake Game

A classic Snake game implemented in C++ for Windows console with smooth movement and progressive difficulty.

## 📝 Description

This is a traditional Snake game where players control a snake to eat fruits and grow longer. The game features smooth console rendering, progressive difficulty, and screen-wrapping mechanics.

## 🌟 Features

- Smooth movement with reduced screen flickering
- Dynamic speed adjustment based on snake length
- Score tracking
- Screen wrapping (snake moves through walls)
- Tail collision detection
- ASCII-based graphics

## ⚙️ System Requirements

- Windows Operating System
- C++ Compiler (GCC/MinGW or MSVC)
- Windows Console support

## 🚀 Installation

1. Clone this repository:
```bash
git clone https://github.com/Abhishek-Verma0/Cpp-Snake-Game-Console.git
```

2. Navigate to the project directory:
```bash
cd snake-game
```

3. Compile the code:
```bash
g++ snake.cpp -o snake.exe
```

4. Run the game:
```bash
./snake.exe
```

## 🎮 Controls

- `W` - Move Up
- `S` - Move Down
- `A` - Move Left
- `D` - Move Right
- `B` - Quit Game

## 🎯 Gameplay

- Control the snake to eat fruits (`F`)
- Each fruit increases score by 5 points
- Snake grows longer with each fruit eaten
- Game ends if snake collides with its own tail
- Snake can pass through walls and appear on the opposite side
- Speed increases as snake grows longer

## 💻 Technical Details

The game uses several key components:

### Core Functions
- `Default()`: Game initialization
- `Draw()`: Console rendering
- `Input()`: Player input handling
- `Logic()`: Game mechanics
- `main()`: Game loop

### Key Features
- Double buffering for smooth rendering
- Dynamic speed adjustment
- Collision detection
- Coordinate tracking system

## 🔧 Customization

You can modify these constants in the code:
```cpp
const int width = 110;  // Game board width
const int heigth = 25;  // Game board height
```

## 📄 License

This project is licensed under the MIT License:

```
MIT License

Copyright (c) 2025

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 🐛 Known Issues

1. Potential screen flickering on some Windows configurations
2. Input lag on certain systems

## 🔜 Future Improvements

- Add high score system
- Implement pause functionality
- Add color support
- Include sound effects
- Add difficulty levels
- Create start menu

## 🤝 Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/NewFeature`)
3. Commit changes (`git commit -m 'Add NewFeature'`)
4. Push to branch (`git push origin feature/NewFeature`)
5. Open a Pull Request



## ANSI CODES
ANSI escape codes are supported on many modern terminal emulators (including Linux and macOS). They allow you to change the text color and background using special character sequences.

    \033[31;40m
1.  `\033` is the escape character (ESC in ASCII).
2. `31` represents red text color.
3. `40` represents black background color.
4. `0m` resets all attributes to default.

- \033[48;5;0m = Black background
- \033[48;5;1m = Red background
\033[48;5;2m = Green background
- \033[48;5;3m = Yellow background
- \033[48;5;4m = Blue background
- \033[48;5;5m = Magenta background
- \033[48;5;6m = Cyan background
- \033[48;5;7m = White background
- \033[48;5;<number>m = 256-color background (where <number> can be between 0 and 255)



## Text Color Setting Using ANSI codes

    "\033[31mThis text is red\033[0m"

1. `\033`: This starts the escape sequence.
2. `[31m`: This sets the text color to red.
3. `[0m:` This resets the color to default.


- 90	Bright Black (Gray)
- 91	Bright Red
- 92	Bright Green
- 93	Bright Yellow
- 94	Bright Blue
- 95	Bright Magenta
- 96	Bright Cyan
- 97	Bright White



  ### Text  Formatting Codes
- 0	Reset all styles
- 1	Bold text
- 4	Underlined text
- 7	Reverse (invert colors)