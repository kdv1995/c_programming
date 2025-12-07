#include <stdio.h>
#include <time.h>

int main() {
  time_t now = time(NULL);
  struct tm *info = localtime(&now);
  char buffer[64];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", info);
  printf("Seconds since the epoch: %ld\n", now);
  printf("Year: %d\n", info->tm_year + 1900);
  printf("Month: %d\n", info->tm_mon + 1);
  printf("Day: %d\n", info->tm_mday);
  printf("Hour: %d\n", info->tm_hour);
  printf("Minute: %d\n", info->tm_min);
  printf("Second: %d\n", info->tm_sec);
  printf("Formatted date: %s\n", buffer);
  time_t t1 = time(NULL);
  time_t t2 = time(NULL) + 10000;
  double diff = difftime(t2, t1);
  printf("Difference in seconds: %.0f\n", diff);
  return 0;
}
