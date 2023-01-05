#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  // Declare variables
  string lastName;
  double testsGrade, assignmentsGrade, totalPoints, numericGrade;
  char letterGrade;
  int numStudents = 0;
  double totalNumericGrades = 0.0;

  // Open the input file
  ifstream inputFile;
  inputFile.open("Grades.txt");

  // Print the table header
  cout << left << setw(15) << "Student Name" 
       << right << setw(10) << "Total Points" 
       << setw(10) << "Numeric Grade" 
       << setw(10) << "Letter Grade" << endl;

  // Read each student record from the file and compute the student statistics
  while (inputFile >> lastName >> testsGrade >> assignmentsGrade) {
    // Calculate the total points
    totalPoints = testsGrade + assignmentsGrade;

    // Calculate the numeric grade
    numericGrade = totalPoints / 200.0 * 100.0;

    // Calculate the letter grade
    if (numericGrade >= 90) {
      letterGrade = 'A';
    } else if (numericGrade >= 80) {
      letterGrade = 'B';
    } else if (numericGrade >= 70) {
      letterGrade = 'C';
    } else if (numericGrade >= 60) {
      letterGrade = 'D';
    } else {
      letterGrade = 'F';
    }

    // Output the student statistics
    cout << left << setw(15) << lastName 
         << right << setw(10) << setprecision(2) << fixed << totalPoints 
         << setw(10) << setprecision(2) << fixed << numericGrade 
         << setw(10) << letterGrade << endl;

    // Update the class statistics
    numStudents++;
    totalNumericGrades += numericGrade;
  }

  // Close the input file
  inputFile.close();

  // Calculate the average numeric grade
  double averageNumericGrade = totalNumericGrades / numStudents;

  // Print the class statistics
  cout << endl << "Number: " << numStudents << endl;
  cout << "Average: " << setprecision(2) << fixed << averageNumericGrade << endl;

  return 0;
}
