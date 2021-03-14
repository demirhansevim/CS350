#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char foods[5][10] = {"Kebab", "Burger", "Pasta", "Lahmacun", "Salad"};
int main()
{
  int people;
  int *foodPoints = calloc(5,sizeof(int));
  char food[10];
  printf("Enter the number of people: ");
  scanf("%d", &people);
  int treshold = people * 3;
  printf("Foods you can choose are: Kebab, Burger, Pasta, Lahmacun, Salad\n");
  for (int i = 0; i < people; ++i)
  {
    char *chosen = calloc(5,sizeof(char));
    printf("Make 5 choices in order of your preferences\n");
    for (int j = 0; j < 5; ++j)
    {
      bool exists = false;
      bool chosenbool = false;
      printf("%d- ", j + 1);
      scanf("%s", food);
      for (int k = 0; k < 5; k++)
      {
        if (!strcmp(foods[k], food))
        {
          exists = true;
        }
        if (food[0] == chosen[k])
        {
          chosenbool = true;
        }
      }
    
  
      
      if (exists && chosenbool == false)
      {
        if (!strcmp("Kebab", food))
        {
          foodPoints[0] += 5 - j;
          chosen[0] = 'K';
        }
    
        else if (!strcmp("Burger", food))
        {
          foodPoints[1] += 5 - j;
          chosen[1] = 'B';
        }
        else if (!strcmp("Pasta", food))
        {
          foodPoints[2] += 5 - j;
          chosen[2] = 'P';
        }
        else if (!strcmp("Lahmacun", food))
        {
          foodPoints[3] += 5 - j;
          chosen[3] = 'L';
        }
        else if (!strcmp("Salad", food))
        {
          foodPoints[4] += 5 - j;
          chosen[4] = 'S';
        }
      }

      else if(exists == false)
      {
        printf("You can't choose this food.\n");
        j--;
      }
      else if(chosenbool) {
        printf("You have already chosen this food.\n");
        j--;
      }
    }
    free(chosen);
  }
    
int shortlistsize = 0;

char *shortlist = calloc(5,sizeof(char));

  for (int i = 0; i < 5; i++)
  {
    if(foodPoints[i] > treshold) {
     shortlist[i] = foods[i][0];
     shortlistsize++;
    }
  }

  if(shortlistsize == 1){
    for(int i =0; i<5; i++) {
      if(shortlist[i] != '\0')
        printf("We will order %s! No need for second round!\n",foods[i]);

    }
  }
else {
printf("Please choose again from this shortlist: ");


for(int i =0; i<5; i++) {
 if(shortlist[i] == foods[i][0])
  printf("%s ",foods[i]);  
}


if(shortlistsize > 0){
int *shortPoints = calloc(5,sizeof(int));


for (int i = 0; i < people; ++i)
  {
    char *chosen = calloc(5,sizeof(char));
    printf("\nMake %d choices in order of your preferences\n",shortlistsize);


    for (int j = 0; j < shortlistsize; ++j)
    {
      bool exists = false;
      bool chosenbool = false;

      
      printf("%d- ", j + 1);
      scanf("%s", food);


      for (int k = 0; k < 5; k++)
      {
        if (shortlist[k] == food[0] && !strcmp(foods[k], food))
        {
          exists = true;
        }
        if (food[0] == chosen[k])
        {
          chosenbool = true;
        }
      }
      if (exists && chosenbool == false)
      {
        if (!strcmp("Kebab", food))
        {
          shortPoints[0] += 5 - j;
          chosen[0] = 'K';
        }
        else if (!strcmp("Burger", food))
        {
          shortPoints[1] += 5 - j;
          chosen[1] = 'B';
        }
        else if (!strcmp("Pasta", food))
        {
          shortPoints[2] += 5 - j;
          chosen[2] = 'P';
        }
        else if (!strcmp("Lahmacun", food))
        {
          shortPoints[3] += 5 - j;
          chosen[3] = 'L';
        }
        else if (!strcmp("Salad", food))
        {
          shortPoints[4] += 5 - j;
          chosen[4] = 'S';
        }
      }
      else if(exists == false)
      {
        printf("You can't choose this food.\n");
        j--;
      }
      else if(chosenbool) {
        printf("You have already chosen this food.\n");
        j--;
      }
    }
    free(chosen);
  }
  int chosenfoodindex;
  int chosenfood;
  for (int i = 0; i < 5; i++) {
    if(shortPoints[i] > chosenfood){ 
      chosenfood = shortPoints[i];
      chosenfoodindex = i;
    }
  }
  printf("We will order %s!\n",foods[chosenfoodindex]);
  free(shortPoints);

} else {
  printf("You are eating at home/dorm today!");
}
}

  free(foodPoints);
  free(shortlist);
  
  return 0;
}
