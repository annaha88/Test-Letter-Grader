/***************************************************************************************************************************
* Program: A Test Letter Grader
*
* Description: This program determines letter grades for students in a class.
* It creates output file of letter grades with their name.
* It also display the average of scores along with minimum and maximum scores for each test in the console.
* 
* Two arguments are needed in command line.
* The 1st is the name of an input file that contains the names and scores of students.
*   - The format of the data in the input file must be fixed. It has name and 7 scores separated by comma in one line.
*		ex) Thui Bhu, 100, 90, 80, 100, 89, 99, 88\n
*   - The number of line is variable.
* The 2nd is the name of an output disk file that will be created: ex) userdecide.txt
*   - All student name will be stored in a sorted order with their letter grades into the output file.
* 
* Grading : 4 quizzes 40%, midterm I 20%, midterm II is 15%, final is 25%.
* Final score = (quiz 1+2+3+4 ) * .10 + mid1 * .20 + mid2 * .15 + final*.25 
* letter grade: Final score >= 90% A, 80%-89% B, 70%-79% C, 60%-69% D, <=59% F
*
* @author Anna Ha
* @date Sep-12-2022 submission
*
****************************************************************************************************************************/

#include "utility_annaha.h"

int main(int argc, char* argv[])
{
	FILE* iFilePointer, * oFilePointer; // input and output file pointers
	STUDENT* pHead;						// the head pointer of the linked list of STUDENT struct
	char** names;						// array of students names
	int n;								// the number of students in the class

/* argument check and open the files */
	if (argc != 3)
	{
		printf("Usage: %s inputFileName outputFileName\n", argv[0]);
		exit(1);
	}
	else
	{		
		if ((iFilePointer = fopen(argv[1], "r")) == NULL) {
			printf("An error occured while opening the input file %s\n", argv[1]);
			exit(1);
		}

		if ((oFilePointer = fopen(argv[2], "w")) == NULL) {
			printf("An error occured while opening the output file %s\n", argv[2]);
			exit(1);
		}
/* Read input file and store the information into the memory */
		pHead = buildStudentList(iFilePointer);			// build linked list to store the information from input file. And get the head pointer of the linked list. 
		n = getLengthofList(pHead);						// get the number of students using the linked list.
	
/* Making contents for output file */
		names = makeNamesArray(pHead, n);				// make an array of student names of STUDENT struct to sort
		qsort(names, n, sizeof(char*), compare);		// sort the name array using quick sort function.
		// start writing to output file
		fprintf(oFilePointer, "Letter grade for %d students given in %s file is:\n\n", n, argv[1]);
		writeResults(pHead, names, n, oFilePointer);	// write student name and the corresponding grade into the file.
		// free memory of the names array 
		for (int i = 0; i < n; i++) {
			free(names[i]);
		}
		free(names);

/* Display in console */
		printf(" Letter grade has been calculated for students listed in input file %s and written to output file %s\n\n",
			argv[1], argv[2]);
		printf("\nHere is the class averages:\n");
		printStatistics(pHead, n);						// print statistics of all scores such as minimum, maximum, average.
	}

/* free allocated memory for the linked list */
	STUDENT* temp;
	while (pHead != NULL) {
		temp = pHead;
		pHead = pHead->pNext;
		free(temp);
	}
/* close files */
	fclose(iFilePointer);
	fclose(oFilePointer);

	return 0;
}//end of main