#include <stdio.h>

#define STUDENT 3
#define EXAMS 4

void min(int grades[][EXAMS], int pupils, int tests);
void max(int grades[][EXAMS], int pupils, int tests);
void avg(int grades[][EXAMS], int pupils, int tests);
void printArr(int grades[][EXAMS], int pupils, int tests);
void printMenu();

int main() {
  int stuGrades[STUDENT][EXAMS] = {
      {77, 68, 86, 73}, {96, 87, 89, 78}, {70, 90, 86, 81}};

  // 指向型指標, limitation: all input types should be same
  void (*processGrades[4])(int[STUDENT][EXAMS], int, int) = {printArr, min, max,
                                                             avg};

  int choice = 0;
  while (choice != 4) {
    do {
      printMenu();
      scanf("%d", &choice);
    } while (choice < 0 || choice > 4);
    if (choice != 4) {
      (*processGrades[choice])(stuGrades, STUDENT, EXAMS);
    } else {
      printf("\tProgram Ended. \n");
    }
  }

  return 0;
}

void min(int grades[][EXAMS], int pupils, int tests) {
  int lowGrade = 100;
  for (int i = 0; i < pupils; ++i) {
    for (int j = 0; j < tests; ++j) {
      if (grades[i][j] < lowGrade) {
        lowGrade = grades[i][j];
      }
    }
  }
  printf("\n\tThe lowest grade is %d", lowGrade);
  puts("");
}

void max(int grades[][EXAMS], int pupils, int tests) {
  int highScore = 0;
  for (int i = 0; i < pupils; ++i) {
    for (int j = 0; j < tests; ++j) {
      if (grades[i][j] > highScore) {
        highScore = grades[i][j];
      }
    }
  }
  printf("\n\tThe highest grade is %d", highScore);
  puts("");
}

void avg(int grades[][EXAMS], int pupils, int tests) {
  int total = 0;
  for (int i = 0; i < pupils; ++i) {
    total = 0;
    for (int j = 0; j < tests; ++j) {
      total += grades[i][j];
    }
    printf("\n\tThe average grade for student %d is %.1f", i + 1,
           (double)total / tests);
  }
  puts("");
}

void printArr(int grades[][EXAMS], int pupils, int tests) {
  printf("\n\t\t\t[0]    [1]    [2]    [3]");
  for (int i = 0; i < pupils; ++i) {
    printf("\n\tstudentGrades[%d]",i);
    for (int j = 0; j < tests; ++j) {
      // 允許輸入7個數字, -: 向左對齊
      printf("%-7d", grades[i][j]);
    }
  }
  puts("");
}

void printMenu() {
  puts("");
  puts("\tEnter a choice:");
  puts("\t0 Print the array of grades");
  puts("\t1 Find the minimum grade");
  puts("\t2 Find the maximum grade");
  puts("\t3 Print the average on all tests for each student");
  puts("\t4 End program");
  puts("Choice:");
}
