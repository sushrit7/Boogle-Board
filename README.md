# Recursion: Boggle Game

This program implements a simple Boggle game where the user can enter words on a randomly generated letter board. The objective is to find words formed by contiguous sequences of letters that are horizontally, vertically, or diagonally adjacent. The program uses recursion to search for words on the board.

## Key Features

- **Random Board Generation:** Each game starts with a fresh, unpredictable board.
- **Recursive Word Search:** The program efficiently explores the board using recursion to find valid words.
- **User-Friendly Interface:** Enter words easily and see which letters were used to form them.
- **Visual Feedback:** See the used letters visually marked on the board for better understanding.

## Instructions

1. **Clone the repository to your local machine:**
   ```bash
   git clone https://github.com/sushrit7/Boogle-Board.git
   ```
2. **Compile the boogleboard.cpp file or navigate to the output directory and run the compiled executable:**
   ```bash
   g++ -o boogleboard boogleboard.cpp
   
   //OR

   cd output
   ./boogleboard
    ```
    
4. **Enjoy the Boggle Game!**
```bash
Your Boggle Board:

  		  B C D M M 
  		  X D Q U Q 
  		  Q A N O S 
  		  Z Z W M W 
  		  N R J G V 

Please enter a word to see if it's on board. Enter **** to stop.
-->wand
		The following letters were used:

  		  # # # # # 
  		  # D # # # 
  		  # A N # # 
  		  # # W # # 
  		  # # # # # 

This board contains WAND.

Press <Enter> key to continue...
```

5. Enter **** to EXIT the game.

## Contributing

Feel free to contribute to the project and suggest improvements to enhance the Boggle gaming experience!
