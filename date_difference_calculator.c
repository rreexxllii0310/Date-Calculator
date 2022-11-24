#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct date {
  int year;
  int month;
  int day;
} Date;

bool validInput(Date date) {
  if (date.year > 0 && date.month > 0 && date.month < 13 && date.day > 0 &&
      date.day < 32)
    return true;
  else
    return false;
}

bool isLeap(Date date) {
  bool leap = false;
  if (date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0)) {
    leap = true;
  }
  return leap;
}

int lastDay(Date date) {
  int days;
  int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (date.month == 2 && isLeap(date)) {
    days = 29;
  } else {
    days = month[date.month - 1];
  }
  return days;
}

int countDate(Date d1, Date d2) {
  Date temp;
  int count = 0;
  while (d1.year != d2.year || d1.month != d2.month || d1.day != d2.day) {
    if (d1.day != lastDay(d1)) { //非最後一天
      temp.day = d1.day + 1;
      temp.month = d1.month;
      temp.year = d1.year;
    } else if (d1.month == 12) { // 12月的最後一天
      temp.day = 1;
      temp.month = 1;
      temp.year = temp.year + 1;
    } else { //其他月的最後一天
      temp.day = 1;
      temp.month = d1.month + 1;
      temp.year = d1.year;
    }
    d1.day = temp.day;
    d1.month = temp.month;
    d1.year = temp.year;
    count++;
  }
  return count;
}

int main(void) {
  Date d1, d2;
  while (true) {
    printf("Enter two dates - Date 1 and Date 2(ex:2022/11/21 2023/9/7): ");
    scanf("%d/%d/%d %d/%d/%d", &d1.year, &d1.month, &d1.day, &d2.year,
          &d2.month, &d2.day);
    if (validInput(d1) && validInput(d2))
      break;
    printf("Invalid date!\n");
  }
  int count = 0;
  Date base = {0, 1, 1};
  printf("%d\n", abs(countDate(base, d1) - countDate(base, d2)));
  return 0;
}