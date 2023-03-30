// all includes here
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// define STUDENT struct that contains name and scores of one student,
// also next and previous pointer to make a linked list structure.
typedef struct STUDENT STUDENT;

struct STUDENT
{
	char name[40];
	int q1, q2, q3, q4, midi, midii, final;
	char grade;

	STUDENT* pNext;
	STUDENT* pPrev;
};

// all function prototypes here

void appendStudent(STUDENT* pHead, STUDENT* pStudent);
STUDENT* buildStudentList(FILE* iFilePointer);
char getLetterGrade(STUDENT* pStudent);
int getLengthofList(STUDENT* pHead);
void printStudents(STUDENT* pHead);
char** makeNamesArray(STUDENT* pHead, int n);
int compare(const void* a, const void* b);
void writeResults(STUDENT* pHead, char** names, int n, FILE* oFilePointer);
int getMinQ1(STUDENT* pHead, int n);
int getMinQ2(STUDENT* pHead, int n);
int getMinQ3(STUDENT* pHead, int n);
int getMinQ4(STUDENT* pHead, int n);
int getMinMidi(STUDENT* pHead, int n);
int getMinMidii(STUDENT* pHead, int n);
int getMinFinal(STUDENT* pHead, int n);
int getMaxQ1(STUDENT* pHead, int n);
int getMaxQ2(STUDENT* pHead, int n);
int getMaxQ3(STUDENT* pHead, int n);
int getMaxQ4(STUDENT* pHead, int n);
int getMaxMidi(STUDENT* pHead, int n);
int getMaxMidii(STUDENT* pHead, int n);
int getMaxFinal(STUDENT* pHead, int n);
float getAvgQ1(STUDENT* pHead, int n);
float getAvgQ2(STUDENT* pHead, int n);
float getAvgQ3(STUDENT* pHead, int n);
float getAvgQ4(STUDENT* pHead, int n);
float getAvgMidi(STUDENT* pHead, int n);
float getAvgMidii(STUDENT* pHead, int n);
float getAvgFinal(STUDENT* pHead, int n);
void printStatistics(STUDENT* pHead, int n);