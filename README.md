# 🃏 Memory Game (Memorama) - Classic Card Matching

A console-based memory card matching game (Memorama) developed in C++ with cross-platform support. This classic two-player game challenges players to find matching pairs of letters on a 6x6 grid while tracking time, moves, and errors.

## 👨‍🎓 Developer Information

**Developer:** Magallanes López Carlos Gabriel  
**Email:** cgmagallanes23@gmail.com  
**Original Development:** November 7, 2025  
**Last Modified:** December 6, 2025

## 🎮 Game Overview

Memory Game is a terminal-based implementation of the classic Memorama card matching game. Two players take turns flipping cards to find matching pairs of letters. The game features a 6x6 grid with 18 unique letter pairs (36 cards total), complete with move tracking, error counting, and game duration timing.

### Key Features
- **Two-Player Mode**: Competitive gameplay for two players
- **6x6 Grid**: 36 cards with 18 matching pairs (A-R)
- **Real-Time Scoring**: Track points, moves, and errors
- **Cross-Platform**: Works on Windows, Linux, and macOS
- **Colored Console**: Enhanced visual experience with colored text
- **Game Statistics**: Time tracking, move counter, and error analysis
- **Input Validation**: Robust error handling for user input

## 🎯 How to Play

### Game Setup
1. **Launch the game** - Run the executable
2. **Enter player names** - Both players input their names
3. **Wait for loading** - Brief loading animation
4. **Start playing** - Cards are shuffled and hidden as 'X'

### Gameplay Rules
- Players take turns selecting two cards by entering row and column coordinates
- **Match Found**: Player scores a point and continues their turn
- **No Match**: Cards flip back, turn switches to other player
- **Winning**: Player with most pairs when all 18 pairs are found wins
- Game tracks total time, moves, and errors

### Game Controls
| Input | Description |
|-------|-------------|
| **Row (0-5)** | Enter the row number of the card |
| **Column (0-5)** | Enter the column number of the card |
| **Numbers Only** | Input validation ensures correct data type |

### Card Selection Process
1. **First Card**: 
   - Enter row coordinate (0-5)
   - Enter column coordinate (0-5)
   - Card is revealed on the board
2. **Second Card**:
   - Enter row coordinate (0-5)
   - Enter column coordinate (0-5)
   - Card is revealed for comparison
3. **Matching Logic**:
   - If cards match → Point awarded, cards stay revealed
   - If no match → Cards flip back to 'X', turn switches

## 📊 Game Board Layout
```
Grid Coordinates:
        0 1 2 3 4 5
    0   X X X X X X
    1   X X X X X X
    2   X X X X X X
    3   X X X X X X
    4   X X X X X X
    5   X X X X X X

After revealing some cards:
        0 1 2 3 4 5
    0   A X B X C X
    1   X D X D X E
    2   F X X X A X
    3   X X G X X H
    4   X B X X X X
    5   X X X X X X
```

## 🏆 Scoring System

### Point Allocation
- **+1 Point**: For each matching pair found
- **No Penalty**: Wrong guesses don't deduct points
- **Turn Continuation**: Finding a match keeps your turn active

### Statistics Tracked
- **Individual Scores**: Each player's total pairs found
- **Total Moves**: Number of card pair selections
- **Errors**: Failed match attempts + invalid selections
- **Game Duration**: Total time in minutes and seconds
- **Winner Declaration**: Highest score or tie announcement

### End Game Results Display
```
******************************************************************
*                      Game Finished!                           *
******************************************************************
*         Player 1: 10 points                                   *
*         Player 2: 8 points                                    *
*         Total Moves: 25                                       *
*         Errors: 7                                             *
*         Time: 5 min, 32 sec                                   *
******************************************************************
```

## 💻 Technical Implementation

### Core Architecture
```cpp
Main Components:
1. Card Grid System (6x6 matrix)
2. Input Validation Engine
3. Turn Management System
4. Scoring & Statistics Tracker
5. Cross-Platform Console Control
6. Timer & Chronometer
7. Random Shuffling Algorithm
```

### Cross-Platform Support

#### Supported Operating Systems
- **Windows**: Native console API (Windows.h)
- **Linux**: POSIX terminal control
- **macOS**: POSIX terminal control

#### Platform-Specific Features
```cpp
// Screen clearing
#ifdef _WIN32
    system("cls");          // Windows
#else
    system("clear");        // POSIX
#endif

// Console colors
Windows: SetConsoleTextAttribute()
POSIX:   ANSI escape codes (\033[code)

// Audio feedback
Windows: Beep(frequency, duration)
POSIX:   Bell character (\a)
```

### Data Structures
```cpp
// Letter pairs storage
std::vector<std::string> letters(18);    // Unique letters A-R
std::vector<std::string> pairs(36);      // 18 pairs doubled

// Game board matrices
std::vector<std::vector<std::string>> board(6x6);         // Actual cards
std::vector<std::vector<std::string>> visibleCards(6x6);  // Player view

// Player information
std::vector<std::string> playerNames(2);  // Two player names
```

### Key Algorithms

#### Card Shuffling
```cpp
Fisher-Yates Shuffle Algorithm:
- Generate 36 random positions
- Swap cards to randomize placement
- Ensures fair distribution
```

#### Match Detection
```cpp
Comparison Logic:
- Reveal first card at [row1][col1]
- Reveal second card at [row2][col2]
- Compare board[row1][col1] == board[row2][col2]
- Update game state based on result
```

#### Input Validation
```cpp
Multi-Layer Validation:
1. Type checking (integer only)
2. Range validation (0-5)
3. Card state verification (not already revealed)
4. Duplicate selection prevention (same card twice)
```

## 🎨 Visual Design

### Console Color Scheme
- **Primary Text**: Red (`colorCode: 4`)
- **Game Board**: White background with colored text
- **Error Messages**: Highlighted error boxes
- **Success Messages**: Celebration boxes with beep sound

### ASCII Art Elements
- **Title Screen**: Large "MEMORAMA" banner
- **Victory Screen**: "FELICIDADES" (Congratulations)
- **Tie Screen**: "EMPATE" (Tie)
- **Error Boxes**: Bordered error notifications

## 📚 Learning Outcomes

### For Players
✅ **Memory Training**: Enhance short-term memory skills  
✅ **Pattern Recognition**: Identify and remember card positions  
✅ **Strategic Thinking**: Decide when to take risks  
✅ **Competitive Play**: Two-player engagement  

### For Developers
🎓 **C++ Fundamentals**
- Vector and matrix manipulation
- String handling and comparison
- Function organization and modularity
- Namespace usage and aliasing

🎓 **Cross-Platform Development**
- Conditional compilation (#ifdef)
- Platform-specific APIs
- POSIX vs Windows differences
- Portable code design

🎓 **Input/Output Management**
- Console input validation
- Stream error handling (cin.fail())
- Buffer clearing techniques
- Formatted console output

🎓 **Game Logic Implementation**
- Turn-based systems
- State management (revealed/hidden cards)
- Win condition detection
- Error recovery mechanisms

🎓 **Time & Threading**
- Chrono library usage
- Duration calculations
- Thread sleep for delays
- Real-time tracking

🎓 **Algorithm Design**
- Random shuffling
- Grid traversal
- Coordinate mapping
- Validation logic

## 🔧 Compilation & Execution

### Requirements
- **C++ Compiler**: C++11 or later
- **Operating System**: Windows, Linux, or macOS
- **Terminal**: Console with color support (recommended)

### Compilation Commands

#### Windows (MinGW/MSVC)
```bash
g++ -std=c++11 memorama.cpp -o memorama.exe
memorama.exe
```

#### Linux/macOS (GCC/Clang)
```bash
g++ -std=c++11 memorama.cpp -o memorama
./memorama
```

### Build Options
```bash
# With optimization
g++ -std=c++11 -O2 memorama.cpp -o memorama

# With debug symbols
g++ -std=c++11 -g memorama.cpp -o memorama

# With warnings enabled
g++ -std=c++11 -Wall -Wextra memorama.cpp -o memorama
```

## 🎮 Game Features Breakdown

### Error Handling
- **Type Errors**: Non-integer input rejection
- **Range Errors**: Out-of-bounds coordinate detection
- **Logic Errors**: Same card selection prevention
- **State Errors**: Already-revealed card validation
- **Buffer Clearing**: Automatic input stream cleanup

### Validation System
```
Input Flow:
User Input → Type Check → Range Check → State Check → Accept/Reject
                ↓              ↓             ↓
           Error Msg     Error Msg     Error Msg
```

### Timing System
- **Start**: Chronometer begins at first move
- **Tracking**: Real-time duration measurement
- **End**: Timer stops when last pair is found
- **Display**: Converted to minutes and seconds

## 🐛 Error Messages

### Common Errors
| Error Type | Message | Cause |
|------------|---------|-------|
| **Range Error** | "Fuera de Rango (Numeros de 0-5)" | Input < 0 or > 5 |
| **Type Error** | "Entrada Invalida. Ingresa un Numero" | Non-integer input |
| **Card Error** | "Esa Carta ya fue descubierta" | Selecting revealed card |
| **Same Card** | "Ya elegiste esa Carta como Primera" | Duplicate selection |
| **Empty Name** | "El Nombre no puede estar Vacio" | Blank player name |

## 🌐 Language Note

The game interface is currently in **Spanish**. Error messages, prompts, and victory screens display in Spanish, making it ideal for Spanish-speaking players or language learners.

## 💡 Strategy Tips

### For Best Results
- **Mental Mapping**: Create a mental grid of revealed cards
- **Pattern Memory**: Remember letter positions, not just matches
- **Risk vs Reward**: Sometimes guessing reveals new information
- **Observation**: Watch opponent's failed attempts for clues
- **Early Game**: Explore different areas of the board
- **Late Game**: Use accumulated knowledge for quick wins

## 📥 Download & Play

### Quick Start - No Installation Required!

Simply download and play! This game is distributed as a standalone executable that runs directly without any installation process.

1. **Download** the executable file (`LetterCards.exe`)
2. **Double-click** to launch the game
3. **Start playing** immediately - no setup needed!

### System Requirements
- **OS**: Windows 10/11, Linux (Ubuntu 18.04+), or macOS 10.14+
- **RAM**: 20MB minimum
- **Storage**: ~3MB free space
- **Display**: Terminal/Console window
- **No Dependencies**: All libraries are statically linked

### Ready to Play?

✅ **No installation hassle**  
✅ **No dependencies to download**  
✅ **No configuration needed**  
✅ **Just download and play!**

Download the latest release from the [Releases](../../releases) section and start challenging your memory today!

## 📧 Contact & Support

**Developer:** Carlos Gabriel Magallanes López  
**Email:** cgmagallanes23@gmail.com  
**School:** Centro de Bachillerato Tecnológico Industrial y de Servicios No. 128

Found a bug? Have suggestions? Want to report your high score? Feel free to reach out!

---

### 🃏 Test your memory and compete with friends in this classic card matching game! 🎯

**Perfect for:**
- Memory training and cognitive development
- Competitive two-player gaming
- Learning C++ game development
- Understanding cross-platform programming
- Console-based UI design study

**Challenge your brain and have fun!** 🧠✨
