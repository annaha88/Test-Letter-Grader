#include "utility_annaha.h"

/* all functions have been defined in this file */
 

/// <summary>
/// apend a STUDENT struct(pStudent) to the end of current linked list.
/// </summary>
/// <param name="pHead">: head pointer of an linked list of STUDENT struct </param>
/// <param name="pStudent">STUDENT* pStudent - the pointer of new STUDENT to append</param>
void appendStudent(STUDENT* pHead, STUDENT* pStudent)
{
	STUDENT* current = pHead;
	while (current->pNext != NULL) {
		current = current->pNext;
	}
	// add a new STUDENT structs 
	current->pNext = pStudent;
	pStudent->pPrev = current;
	pStudent->pNext = NULL;
}

/* return a letter grade of a student
  input: STUDENT* pStudent - the pointer of one STUDENT struct
  return: a letter grade of the input STUDENT in char such as 'A'
*/
char getLetterGrade(STUDENT* pStudent) {
	float totalScore;
	char grade;

	totalScore = (pStudent->q1 + pStudent->q2 + pStudent->q3 + pStudent->q4) * 0.1
		+ (pStudent->midi) * 0.20 + (pStudent->midii) * 0.15 + (pStudent->final) * 0.25;

	if (totalScore >= 90)
		grade = 'A';
	else if (totalScore >= 80)
		grade = 'B';
	else if (totalScore >= 70)
		grade = 'C';
	else if (totalScore >= 60)
		grade = 'D';
	else
		grade = 'F';

	return grade;
}

/// <summary>
/// This function parse data from input file and store the information into a linked list of struct STUDENT
/// so that we can approach the values easily once parsing has done.
/// </summary>
/// <param name="iFilePointer">: file pointer of input file to read</param>
/// <returns>STUDENT* - the head pointer of the linked list that consists of STUDENT structs</returns>
STUDENT* buildStudentList(FILE* iFilePointer) {

	char buf[100];
	char* token;
	STUDENT* pStudent;
	STUDENT* pHead = NULL, * pTail = NULL;


	while (fgets(buf, sizeof(buf), iFilePointer) != NULL)
	{
		pStudent = (STUDENT*)malloc(sizeof(STUDENT));
		token = strtok(buf, ",");
		strcpy(pStudent->name, token);
		token = strtok(NULL, ",");
		pStudent->q1 = atoi(token);
		token = strtok(NULL, ",");
		pStudent->q2 = atoi(token);
		token = strtok(NULL, ",");
		pStudent->q3 = atoi(token);
		token = strtok(NULL, ",");
		pStudent->q4 = atoi(token);
		token = strtok(NULL, ",");
		pStudent->midi = atoi(token);
		token = strtok(NULL, ",");
		pStudent->midii = atoi(token);
		token = strtok(NULL, ",");
		pStudent->final = atoi(token);
		pStudent->grade = getLetterGrade(pStudent);  //get a letter grade by calling function and store in the struct

		if (pHead == NULL) {
			pHead = pStudent;
			pHead->pPrev = NULL;
			pTail = pStudent;
			pTail->pNext = NULL;
		}
		else {
			appendStudent(pHead, pStudent);
		}
	}
	return pHead;
}

/// <summary>
/// return the length of the linked list.
/// </summary>
/// <param name="pHead">: the head pointer of the linked list </param>
/// <returns></returns>
int getLengthofList(STUDENT* pHead) {

	STUDENT* current = pHead;
	int count = 0;

	for (current; current != NULL; current = current->pNext)
	{
		count += 1;
	}
	return count;
}

//print information in linked list for test use.
void printStudents(STUDENT* pHead) {

	STUDENT* current = pHead;

	for (current; current != NULL; current = current->pNext)
	{
		printf("My name is: %s, and grade is: %c\n", current->name, current->grade);
	}
}

// It return the array of student's name out of a n-length linked list STUDENT*
char** makeNamesArray(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	char** studentNames;

	studentNames = malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		studentNames[i] = malloc((sizeof(current->name) + 1) * sizeof(char));
		strcpy(studentNames[i], current->name);
		current = current->pNext;
	}
	return studentNames;
}

//This is a compare function for qsort operation. it compares string which is student name.
int compare(const void* a, const void* b)
{
	const char** str_a = (const char**)a;
	const char** str_b = (const char**)b;
	return strcmp(*str_a, *str_b);
}


/// <summary>
/// write student's name and the letter grade on output file order by name in the names array
/// </summary>
/// <param name="pHead">: the linked list of STUDENT structs</param>
/// <param name="names">: array of string which is student's name</param>
/// <param name="n">: the length of the list</param>
/// <param name="oFilePointer">: output file pointer</param>
void writeResults(STUDENT* pHead, char** names, int n, FILE* oFilePointer)
{
	STUDENT* current;
	char* name;

	for (int i = 0; i < n; i++) {
		name = names[i];
		current = pHead;
		for (current; current != NULL; current = current->pNext) {
			//if the name is same as the name of current struct, the name and the corresponding letter grade is written to outpuf file.
			if (strcmp(name, current->name) == 0) {
				fprintf(oFilePointer, "%s: \t%c\n", current->name, current->grade);
				break;
			}
		}
	}
}


/* Start functions to get Minimum values */

/// <summary>
/// get minimum score of Quiz1(q1) in the linked list of STUDENTs
/// </summary>
/// <param name="pHead">: the linked list of STUDENT structs</param>
/// <param name="n">: the length of the list</param>
/// <returns> int minimum score of Quiz1 in the list</returns>
int getMinQ1(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int minQ1 = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			minQ1 = current->q1;
		else if (minQ1 > current->q1) {
			minQ1 = current->q1;
		}
		current = current->pNext;
	}
	return minQ1;
}


int getMinQ2(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int minQ2 = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			minQ2 = current->q2;
		else if (minQ2 > current->q2) {
			minQ2 = current->q2;
		}
		current = current->pNext;
	}
	return minQ2;
}

int getMinQ3(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int minQ3 = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			minQ3 = current->q3;
		else if (minQ3 > current->q3) {
			minQ3 = current->q3;
		}
		current = current->pNext;
	}
	return minQ3;
}

int getMinQ4(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int minQ4 = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			minQ4 = current->q4;
		else if (minQ4 > current->q4) {
			minQ4 = current->q4;
		}
		current = current->pNext;
	}
	return minQ4;
}

int getMinMidi(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int minMidi = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			minMidi = current->midi;
		else if (minMidi > current->midi) {
			minMidi = current->midi;
		}
		current = current->pNext;
	}
	return minMidi;
}

int getMinMidii(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int minMidii = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			minMidii = current->midii;
		else if (minMidii > current->midii) {
			minMidii = current->midii;
		}
		current = current->pNext;
	}
	return minMidii;
}

int getMinFinal(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int minFinal = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			minFinal = current->final;
		else if (minFinal > current->final) {
			minFinal = current->final;
		}
		current = current->pNext;
	}
	return minFinal;
}


/* Start functions to get Maximum values */

/// <summary>
/// get maximum score of Quiz1(q1) in the linked list of STUDENTs
/// </summary>
/// <param name="pHead">: the linked list of STUDENT structs</param>
/// <param name="n">: the length of the list</param>
/// <returns> int maximum score of Quiz1 in the list</returns>
int getMaxQ1(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int maxQ1 = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			maxQ1 = current->q1;
		else if (maxQ1 < current->q1) {
			maxQ1 = current->q1;
		}
		current = current->pNext;
	}
	return maxQ1;
}

int getMaxQ2(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int maxQ2 = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			maxQ2 = current->q2;
		else if (maxQ2 < current->q2) {
			maxQ2 = current->q2;
		}
		current = current->pNext;
	}
	return maxQ2;
}

int getMaxQ3(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int maxQ3 = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			maxQ3 = current->q3;
		else if (maxQ3 < current->q3) {
			maxQ3 = current->q3;
		}
		current = current->pNext;
	}
	return maxQ3;
}

int getMaxQ4(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int maxQ4 = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			maxQ4 = current->q4;
		else if (maxQ4 < current->q4) {
			maxQ4 = current->q4;
		}
		current = current->pNext;
	}
	return maxQ4;
}

int getMaxMidi(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int maxMidi = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			maxMidi = current->midi;
		else if (maxMidi < current->midi) {
			maxMidi = current->midi;
		}
		current = current->pNext;
	}
	return maxMidi;
}

int getMaxMidii(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int maxMidii = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			maxMidii = current->midii;
		else if (maxMidii < current->midii) {
			maxMidii = current->midii;
		}
		current = current->pNext;
	}
	return maxMidii;
}

int getMaxFinal(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	int maxFinal = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0)
			maxFinal = current->final;
		else if (maxFinal < current->final) {
			maxFinal = current->final;
		}
		current = current->pNext;
	}
	return maxFinal;
}

/* Start functions to get Average values */

/// <summary>
/// get average score of Quiz1(q1) in the linked list of STUDENTs
/// </summary>
/// <param name="pHead">: the linked list of STUDENT structs</param>
/// <param name="n">: the length of the list</param>
/// <returns> float average score of Quiz1 in the list</returns>
float getAvgQ1(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	float sum = 0;
	float avg = 0.0;

	for (int i = 0; i < n; i++) {
		sum += current->q1;
		current = current->pNext;
	}
	avg = sum / n;

	return avg;
}

float getAvgQ2(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	float sum = 0;
	float avg = 0.0;

	for (int i = 0; i < n; i++) {
		sum += current->q2;
		current = current->pNext;
	}
	avg = sum / n;
	return avg;
}

float getAvgQ3(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	float sum = 0;
	float avg = 0.0;

	for (int i = 0; i < n; i++) {
		sum += current->q3;
		current = current->pNext;
	}
	avg = sum / n;
	return avg;
}

float getAvgQ4(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	float sum = 0;
	float avg = 0.0;

	for (int i = 0; i < n; i++) {
		sum += current->q4;
		current = current->pNext;
	}
	avg = sum / n;
	return avg;
}

float getAvgMidi(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	float sum = 0;
	float avg = 0.0;

	for (int i = 0; i < n; i++) {
		sum += current->midi;
		current = current->pNext;
	}
	avg = sum / n;
	return avg;
}

float getAvgMidii(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	float sum = 0;
	float avg = 0.0;

	for (int i = 0; i < n; i++) {
		sum += current->midii;
		current = current->pNext;
	}
	avg = sum / n;
	return avg;
}

float getAvgFinal(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;
	float sum = 0;
	float avg = 0.0;

	for (int i = 0; i < n; i++) {
		sum += current->final;
		current = current->pNext;
	}
	avg = sum / n;
	return avg;
}


/// <summary>
/// print statistics of all scores such as minimum, maximum, average
/// </summary>
/// <param name="pHead">: the linked list of STUDENT structs</param>
/// <param name="n">: the length of the list</param>
void printStatistics(STUDENT* pHead, int n)
{
	STUDENT* current = pHead;

	int minQ1, minQ2, minQ3, minQ4, minMidi, minMidii, minFinal;
	int maxQ1, maxQ2, maxQ3, maxQ4, maxMidi, maxMidii, maxFinal;
	float avgQ1, avgQ2, avgQ3, avgQ4, avgMidi, avgMidii, avgFinal;

	//getting minimum values by calling each function
	minQ1 = getMinQ1(current, n); minQ2 = getMinQ2(current, n); minQ3 = getMinQ3(current, n); minQ4 = getMinQ4(current, n);
	minMidi = getMinMidi(current, n); minMidii = getMinMidii(current, n); minFinal = getMinFinal(current, n);

	//getting maximum values by calling each function
	maxQ1 = getMaxQ1(current, n); maxQ2 = getMaxQ2(current, n); maxQ3 = getMaxQ3(current, n); maxQ4 = getMaxQ4(current, n);
	maxMidi = getMaxMidi(current, n); maxMidii = getMaxMidii(current, n); maxFinal = getMaxFinal(current, n);

	//getting maximum values by calling each function
	avgQ1 = getAvgQ1(current, n); avgQ2 = getAvgQ2(current, n); avgQ3 = getAvgQ3(current, n); avgQ4 = getAvgQ4(current, n);
	avgMidi = getAvgMidi(current, n); avgMidii = getAvgMidii(current, n); avgFinal = getAvgFinal(current, n);

	//print the values
	printf("        \tQ1\tQ2\tQ3\tQ4\tMid1\tMid2\tFinal\n");
	printf("Average:\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f\n", avgQ1, avgQ2, avgQ3, avgQ4, avgMidi, avgMidii, avgFinal);
	printf("Minimum:\t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\n", minQ1, minQ2, minQ3, minQ4, minMidi, minMidii, minFinal);
	printf("Maximum:\t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\n", maxQ1, maxQ2, maxQ3, maxQ4, maxMidi, maxMidii, maxFinal);
}

