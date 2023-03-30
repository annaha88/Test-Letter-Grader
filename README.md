# Test-Letter-Grader

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
