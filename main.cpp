/*
 * Project: Course Planner
 * Author: Gonzalo Patino
 * Date: October 17, 2024
 * Description:
 *   This program is a course planning tool for students, allowing them to load
 *   a course data structure, view a list of available courses, and search for
 *   individual course details. The program reads course information from a CSV file,
 *   constructs a Binary Search Tree (BST) to organize the data, and provides an interactive
 *   menu for users to navigate the functionality.
 *
 * Usage:
 *   - Load data from a CSV file containing course numbers, names, and prerequisites.
 *   - View the entire course list in alphanumeric order.
 *   - Search for details about a specific course.
 *   - Exit the program when finished.
 *
 * File Dependencies:
 *   - CSV file: "CS 300 ABCU_Advising_Program_Input.csv" should be located in the project folder.
 *
 * Class Definitions:
 *   - Course: Represents an individual course with a course number, name, and prerequisites.
 *   - Node: Represents a node in the BST containing a course.
 *
 * Functions:
 *   - loadCourses(): Loads course data from a CSV file into the BST.
 *   - addCourseToTree(): Adds a course to the BST.
 *   - displayMenu(): Displays the interactive menu options.
 *   - inOrderTraversal(): Performs an in-order traversal of the BST.
 *   - printCourseList(): Prints the entire list of courses.
 *   - searchCourse(): Searches for a specific course by course number.
 *   - printCourse(): Prints details of a specific course.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Course class to store course details
class Course {
public:
    string courseNumber;           // Course number (e.g., CSCI100)
    string courseName;             // Course name (e.g., Introduction to Computer Science)
    vector<string> prerequisites;  // List of prerequisite course numbers

    // Constructor
    Course(string number, string name, vector<string> prereqs) {
        courseNumber = number;
        courseName = name;
        prerequisites = prereqs;
    }
};

// Node struct for the Binary Search Tree (BST)
struct Node {
    Course course;
    Node* left;
    Node* right;

    // Constructor initializes a node with a course and sets child pointers to nullptr
    Node(Course c) : course(c), left(nullptr), right(nullptr) {}
};

Node* root = nullptr;
vector<Course> courses; // Vector to store all courses (for validation purposes)

// Function to search for a course by course number
// Parameters: node - the root of the BST, courseNumber - the course number to search for
// Returns: a pointer to the node containing the course, or nullptr if not found
Node* searchCourse(Node* node, string courseNumber) {
    if (node == nullptr || node->course.courseNumber == courseNumber) {
        return node;
    }
    else if (courseNumber < node->course.courseNumber) {
        return searchCourse(node->left, courseNumber);
    }
    else {
        return searchCourse(node->right, courseNumber);
    }
}

// Function to add a course to the Binary Search Tree (BST)
// Parameters: node - reference to the root of the BST, course - the course to add
void addCourseToTree(Node*& node, Course course) {
    if (node == nullptr) {
        node = new Node(course); // Create a new node if the position is empty
    }
    else if (course.courseNumber < node->course.courseNumber) {
        addCourseToTree(node->left, course); // Recursively add to the left subtree
    }
    else {
        addCourseToTree(node->right, course); // Recursively add to the right subtree
    }
}

// Procedure to load courses from file (Two-Pass Approach)
// Parameters: fileName - the name of the CSV file containing course information
void loadCourses(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: Could not open the file." << endl;
        return;
    }

    string line;

    // First pass: Load all courses without validating prerequisites
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, courseName, prerequisite;
        vector<string> prerequisites;

        // Split line by comma
        getline(ss, courseNumber, ',');
        getline(ss, courseName, ',');

        // Read remaining prerequisites
        while (getline(ss, prerequisite, ',')) {
            prerequisites.push_back(prerequisite);
        }

        // Validate line format (at least course number and name required)
        if (courseNumber.empty() || courseName.empty()) {
            cout << "Error: Invalid course data format" << endl;
            continue;
        }

        // Create Course object and add to vector
        Course newCourse(courseNumber, courseName, prerequisites);
        courses.push_back(newCourse);
    }

    file.close();

    // Second pass: Add courses to BST
    for (Course course : courses) {
        addCourseToTree(root, course);
    }

    cout << "Courses loaded successfully." << endl;
}

// Function to display the menu
// Displays the options available to the user
void displayMenu() {
    cout << "\n*******Project 2- Gonzalo Patino*******************";
    cout << "\n1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
    cout << "\nWhat would you like to do? ";
}

// In-order traversal to print courses in alphanumeric order
// Parameters: node - the root of the BST
void inOrderTraversal(Node* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left); // Traverse the left subtree
        cout << node->course.courseNumber << ", " << node->course.courseName << endl; // Print course details
        inOrderTraversal(node->right); // Traverse the right subtree
    }
}

// Function to print all courses
// Prints the entire list of courses in alphanumeric order
void printCourseList() {
    if (root == nullptr) {
        cout << "No courses loaded." << endl;
    }
    else {
        inOrderTraversal(root);
    }
}

// Function to print a specific course's details
// Parameters: courseNumber - the course number to search for
void printCourse(string courseNumber) {
    Node* result = searchCourse(root, courseNumber);
    if (result != nullptr) {
        cout << "Course Number: " << result->course.courseNumber << ", Course Name: " << result->course.courseName << endl;
        if (!result->course.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (string prereq : result->course.prerequisites) {
                cout << prereq << " ";
            }
            cout << endl;
        }
        else {
            cout << "No prerequisites" << endl;
        }
    }
    else {
        cout << "Course not found." << endl;
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string fileName = "CS 300 ABCU_Advising_Program_Input.csv";
            loadCourses(fileName); // Load courses from the CSV file
            break;
        }
        case 2:
            printCourseList(); // Print the entire list of courses
            break;
        case 3: {
            cout << "Enter course number: ";
            string courseNumber;
            cin.ignore(); // To handle any newline characters left in the input buffer
            getline(cin, courseNumber);
            printCourse(courseNumber); // Print the details of the specified course
            break;
        }
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;
        default:
            cout << choice << " is not a valid option." << endl; // Handle invalid menu choices
        }
    } while (choice != 9);

    return 0;
}
