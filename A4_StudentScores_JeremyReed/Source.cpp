// This program with ask the user how many students there are taking 3 tests and average them

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Define constants
int students1;
const int tests = 3, students = 100;


// Function prototype to accept: an array of students names, 2D array of grades from 3 tests of each student 
// array of averages for each student, and an array of how many students there are
double findAverage(string[], const int[][tests], double[], int);


// Function prototype to accept: an array of student names, how many students there are
// array of averages for each student.
void displayList(string[], const double[], const int);

// Function prototype to accept: array of students, array of averages,
// and number of students
void selectionSort(string[], double averages[], const int size);


int main()
{
	// Define local variables
	string studentNames[students];
	int studentTests[students][tests];
	double averages[students], averageTests[students];
	
	int count;
	int students1;
	


	
	do 
	{
	
		// Display information to user

	cout << "This program is used to average students test scores for 3 tests up to a maximum of 100 students.\n";
	
	
	cout << "How many students are there?";
	cin >> students1;


	// If statement and do while loop to correct invalid input.

	if (students1 > 100 || students1 < 1)

	{
		cout << "Invalid input please enter a number between 1-100.\n";

	}
	
	} while (students1 > 100 || students1 < 1);
		
	// Ask for variables needed from user 

	for (count = 0; count < students1; count++)
	{
		int index = 0;
		cout << "Enter the name of student #" << (count + 1) << ": ";
		cin.ignore();
		getline(cin, studentNames[count]);
		cout << studentNames[count] << "\n";
		for (int index = 0; index < tests; index++)
		{
			cout << "Enter the score for test #" << (index + 1) << " of student " << studentNames[count] << ": \n";
			cin >> studentTests[count][index];

		}


	}

	// Function calls for display and find average

	findAverage(studentNames, studentTests, averageTests, students1);
	
	
	selectionSort(studentNames, averageTests, students1);

	displayList(studentNames, averageTests, students1);

	

	return 0;
}


//**********************************************************
// Function for finding average of each students test score.
// Will add up all 3 tests for each student and divide by 3.
//**********************************************************


double findAverage(string names[], const int tests1[][tests], double average[], int size)
{
	int student, test;
	double total = 0;

	
	for (student = 0; student < size; student++)
	{
		total = 0;
		for (test = 0; test < tests; test++)
		{
			
			total += tests1[student][test];
			
			average[student] = total / tests;

			
		}
		
		
	}
	return average[student];
}


//**********************************************************
// This function will display the averages for each student.
//**********************************************************

void displayList(string names[], const double averages[], const int size)
{
	
	cout << "These are the tests scores after sorting them highest to lowest.\n";


	int student;
	for (student = 0; student < size; student++)
	{
		cout << fixed << showpoint << setprecision(2);
		

		cout << (student + 1) << ". " << names[student]  << setw(8) << "--> " << averages[student] << "\n";
	}


}

//*******************************************
// Defintition for function selectionSort.
// Will sort tests in descending order.
//*******************************************

void selectionSort(string names[], double averages[], const int size)
{
	int start, minIndex, maxValue;
	string maxValue1;

	for (start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		maxValue = averages[start];
		maxValue1 = names[start];
		
		
		for (int index = start + 1; index < size; index++)
		{
			if (averages[index] > maxValue)
			{
				maxValue = averages[index];
				maxValue1 = names[index];
				minIndex = index;
				
			}
		}
		averages[minIndex] = averages[start];
		averages[start] = maxValue;
		names[minIndex] = names[start];
		names[start] = maxValue1;
	}

}