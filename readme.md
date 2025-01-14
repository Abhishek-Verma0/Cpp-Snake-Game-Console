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
git clone https://github.com/yourusername/snake-game.git
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

