# Recursion: Boggle Game

This program implements a simple Boggle game where the user can enter words on a randomly generated letter board. The objective is to find words formed by contiguous sequences of letters that are horizontally, vertically, or diagonally adjacent. The program uses recursion to search for words on the board.

## Instructions

1. **Clone the repository to your local machine:**
   ```bash
   git clone https://github.com/sushrit7/Boogle-Board.git
   ```
2. **Compile the boogleboard.cpp file or change to the output directory and run the compiled boogleboard
   ```bash
   g++ -o boogleboard boogleboard.cpp
   ```
   
		OR

    ```bash
      cd output
    ./boogleboard
    ```
    
4. ENJOY! 
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

5. Enter **** to EXIT.
