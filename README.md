# 🍭 Candy Crush Game

![Candy Crush Banner](file:///C:/Users/BASSEL/.gemini/antigravity/brain/97e26226-61dc-4f07-b715-6bb3a67160e8/candy_crush_banner_1774481658742.png)

## 🌟 Overview
A modern, C++ implementation of the classic **Candy Crush** game logic. Designed as part of the **Data Structures** course, this project demonstrates efficient grid management using a **custom 2D linked structure** (quad-linked list) to handle complex candy movements, matches, and grid refills.

---

## 🚀 Key Features
- **Custom Linked Grid:** Implemented using a 5x5 grid of `CandyNode` objects, each with pointers to their `up`, `down`, `left`, and `right` neighbors.
- **Dynamic Gameplay:**
  - **Match Detection:** Automatically detects horizontal and vertical matches of 3 or more candies.
  - **Smart Refill:** After matches are cleared, new candies are randomly generated and "dropped" into the grid.
  - **Star Collection:** Special candies marked with a 🌟 must be collected to win.
- **Move Validation:** Robust logic to ensure only adjacent swaps resulting in a match are allowed.
- **Game Optimization:** Optimized for memory efficiency using pointers and modern C++ practices.

---

## 🎮 How to Play
![Gameplay Mockup](file:///C:/Users/BASSEL/.gemini/antigravity/brain/97e26226-61dc-4f07-b715-6bb3a67160e8/candy_crush_gameplay_mockup_1774481702985.png)

1. **Launch the Game:** Run the compiled executable to start the console interface.
2. **Swap Candies:** Enter the coordinates `(x1, y1)` and `(x2, y2)` of the two candies you wish to swap.
3. **Collect Stars:** Match star-marked candies to collect them.
4. **Win Condition:** Collect **5 Stars** before you run out of moves!

---

## 🛠️ Technical Structure
The project is built with a modular object-oriented approach:

### `CandyNode.h`
Defines the core data structure:
```cpp
struct CandyNode {
    char color;      // Representation of candy color (R, G, B, Y, P)
    bool hasStar;    // Flag for star collection
    CandyNode *up, *down, *left, *right; // Neighbors
};
```

### `CandyGrid.h / .cpp`
Manages the game state, including:
- `initializeColors()`: Sets up the initial randomized grid.
- `detectMatches()`: The core algorithm for finding patterns.
- `refillGrid()`: Logic for populating the grid after clearing matches.
- `validateMove()`: Ensures game rules are followed.

### `main.cpp`
The entry point featuring the game loop and user interaction logic.

---

## 📦 Installation & Setup
1. **Clone the repository:**
   ```bash
   git clone https://github.com/Basse7514/CandyCrushGame.git
   ```
2. **Open the solution:**
   Launch `CandyCrushGame.sln` in **Visual Studio**.
3. **Build & Run:**
   - Set the configuration to `x64`.
   - Press `F5` to compile and play!

---

## 👨‍💻 Author
Developed as part of the **2nd Year SUT Data Structures** course. 

*Stay sweet, keep matching!* 🍬