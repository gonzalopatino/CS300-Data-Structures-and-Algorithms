# Course Data Structures and Algorithms Projects

This repository contains key portions of my projects from the **CS-300: Data Structures and Algorithms** course. It showcases my understanding and application of various data structures, algorithm analysis, and efficient coding practices.

---

## Project One: Runtime and Memory Analysis

In this project, I evaluated the performance of different data structures—**Vector**, **Hash Table**, and **Binary Search Tree (BST)**—for storing and retrieving course data. I analyzed the **time complexity (Big O)** and **memory usage** of each structure in various operations such as insertion, lookup, and sorting.

### Key Insights:
- **Vectors** provide O(n) search time but O(1) insertion, making them efficient for small datasets but less ideal for large ones.
- **Hash Tables** offer O(1) average-case lookup and insertion, making them a top choice for quick data access.
- **BSTs**, when balanced, offer O(log n) search and insertion but require careful management to avoid performance degradation.

### Recommendation:
I recommended using the **Hash Table** for this project due to its superior average-case time complexity for both insertions and lookups.

---

## Project Two: Advising Assistance Program

For Project Two, I implemented an advising assistance program that academic advisors can use to manage course data for the Computer Science department. The program reads course data from a CSV file, stores it in the **Hash Table**, and provides several key features via a command-line interface.

### Features:
1. **Load Course Data**: Prompts the user to load course information from a file into the chosen data structure.
2. **Print Sorted Course List**: Outputs an alphanumeric list of all the courses, sorted by course number.
3. **Course Information Lookup**: Allows the user to look up specific courses by course number and view prerequisites.

### Technologies Used:
- **C++**
- **Command-Line Interface**
- **Data Structures (Hash Table)**

---

## Reflection

### 1. What was the problem you were solving in the projects for this course?
In Project One, the main problem was analyzing the runtime and memory efficiency of data structures. In Project Two, I was tasked with implementing a working solution that could read, store, and retrieve course data, while also printing a sorted list of courses.

### 2. How did you approach the problem?
I carefully considered the strengths and weaknesses of each data structure, particularly in terms of insertion, lookup, and memory usage. For Project Two, I implemented the Hash Table based on its efficiency in handling quick lookups and insertions, ensuring the program could handle the required course operations effectively.

### 3. How did you overcome any roadblocks?
I encountered challenges in handling file input and sorting courses alphanumerically. By revisiting my pseudocode, breaking down the problem, and thoroughly testing edge cases, I was able to resolve these issues. Debugging tools in the IDE and systematic testing helped ensure the program's correctness.

### 4. How has your work on this project expanded your approach to designing software and developing programs?
This project reinforced the importance of choosing the right data structure for a given problem. I now approach software design with a deeper understanding of how algorithmic efficiency directly impacts program performance and user experience.

### 5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
I’ve embraced best practices such as clear naming conventions, in-line comments, and modular code design. These practices make my programs more maintainable and adaptable, ensuring they can be easily modified or scaled in the future.

---


