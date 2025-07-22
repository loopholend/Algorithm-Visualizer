# Algorithm-Visualizer
A C++ console-based, menu-driven algorithm visualizer for classic sorting and searching algorithms. Enter any array and step through Bubble, Insertion, Merge, Quick, Count, Radix sort, and searches, with detailed step-by-step output for easy learning.

Algorithm Visualizer — Console-based (C++)
A menu-driven, step-by-step Algorithm Visualizer for the C++ console.
Practice, learn, and visualize classic sorting and searching algorithms interactively using just your terminal!

✨ Features
Manual Array Input:
Enter your custom array (with negative and positive values).

Sorting Algorithms:

Bubble Sort

Selection Sort

Insertion Sort

Merge Sort

Quick Sort

Count Sort (supports negatives)

Radix Sort (supports negatives)

Searching Algorithms:

Linear Search

Binary Search (checks if array is sorted)

Step-by-Step Visualization:
Pauses and prints the array at every important step—comparisons, swaps, moves, merges, highlights—so you can follow the process live.

Simple Console Highlighting:
Elements involved in comparisons or swaps are shown in brackets [ ].

🚀 Usage
1. Clone and Compile
bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPO.git
cd YOUR_REPO
g++ -std=c++11 -o algo_visualizer algo_visualizer.cpp
2. Run
bash
./algo_visualizer
📝 How It Works
Menu-based:
Choose the algorithm you wish to visualize.

Manual Input:
When prompted, enter the array length and then each element separated by space (negative numbers allowed!).

Visualized Steps:
The program prints each step.
Press Enter to continue to the next stage.

📋 Sample Menu
text
--- Algorithm Visualizer Menu ---
1. Input array manually
2. Bubble Sort
3. Selection Sort
4. Insertion Sort
5. Merge Sort
6. Quick Sort
7. Count Sort
8. Radix Sort
9. Linear Search
10. Binary Search
11. Exit
Enter your choice:
💡 Example
text
Enter array length: 5
Now enter 5 elements: 7 -13 0 4 2
Array set: 7 -13 0 4 2
Select an algorithm (e.g. Bubble Sort) to step through each operation.
🏗️ Requirements
C++11 or later compiler

No dependencies beyond the C++ Standard Library

Cross-platform: works on Linux, Windows, macOS (in the terminal/console)

🙌 Educational Purpose
This project is ideal for:

Students learning algorithms

Teachers demonstrating algorithmic steps

Anyone who wants to see how classic algorithms actually work under the hood

Contributions, issues, and suggestions are welcome!

Enjoy learning algorithms, the step-by-step way!
