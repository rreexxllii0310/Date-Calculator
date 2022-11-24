#include <stdio.h>
#include <stdbool.h>

typedef struct date{
  int year;
  int month;
  int day;
} Date;

bool validInput(Date date){
  if(date.year > 0 && date.month > 0 && date.month < 13 && date.day > 0 && date.day < 32) return true;
  else return false;
}

bool Leap(Date date){
  bool leap = false;
  if(date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0)){
    leap = true;
  }
  return leap;
}

int lastDate(Date date){
  int days;
  int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(date.month == 2 && Leap(date)){
    days = 29;
  }
  else{
    days = month[date.month - 1];
  }
  return days;
}

int main(void) {
  Date today, nextDate;
  while(true){
    printf("Today's date(ex:2022/11/21): ");
    scanf("%d/%d/%d", &today.year, &today.month, &today.day);
    if(validInput(today)) break;
    printf("Invalid date!\n");
  }
  int n = 0;
  while(true){
    printf("Please enter the date you want to know a few days later: ");
    scanf("%d", &n);
    if(n > 0) break;
  }
  while(n > 0){
    if(today.day != lastDate(today)){ //非最後一天
      nextDate.day = today.day + 1;
      nextDate.month = today.month;
      nextDate.year = today.year;
    }
    else if(today.month == 12){ // 12月的最後一天
        nextDate.day = 1;
        nextDate.month = 1;
        nextDate.year = today.year + 1;
    }
    else{ //其他月的最後一天
      nextDate.day = 1;
      nextDate.month = today.month + 1;
      nextDate.year = today.year;
    }
    n--;
    today.day = nextDate.day;
    today.month = nextDate.month;
    today.year = nextDate.year;
  }
  printf("%d/%d/%d\n", nextDate.year, nextDate.month, nextDate.day);
  return 0;
}