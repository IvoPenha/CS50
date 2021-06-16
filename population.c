#include <cs50.h>
#include <stdio.h>

int birth();
int death();
int main(void)
{
    int years = 0;
     int number;
  do
  {
      number = get_int("Start size: ");
  }
  while (number < 9);
   int end;
  do
  {
      end= get_int("End size: ");
  }
  while (end < number);
    while (number<end)
    {
        int birth = number/3;
        int death = number/4;
        number = number + birth -death ;
        years++;
    }
    printf("Years: %i\n", years);
    
}
