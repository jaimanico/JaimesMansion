#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "playerinfo.h"
#define MAX_POINTS 10

void clearInputBuffer();
struct Inventory {
    int sword;
    int boots;
    int potion;
    int ring;
};
void printInventory(struct Inventory inv);
int chestEncountered = 0; 
void printTitle();
int diceX ();
int monsterEncounter();
int statsCheck (int playerStats, int diceRoll);

int main(int argc, char **argv)
{
 

struct Inventory playerInventory = {0, 0, 0, 0};
  srand(time(NULL));
   int rollDice;
   int trapCheck;
   struct playerInfo player1;



   char * monster[4] = {"Ogre","witch","Giant","Black Widow"};
   char * playerValues[3] ={"strength","Agility","Inteligence"};
   int monsterStrength[4] ={3,2,5,1};
   int monsterLife[4] ={3,2,3,1};

       printTitle();



   printf("\n Please enter your character's name: ");
fgets(player1.charname, 20, stdin);
size_t len = strlen(player1.charname);
if (len > 0 && player1.charname[len - 1] == '\n') {
    player1.charname[len - 1] = '\0';
}

printf("\033[0;31m"); // Set text color to red
printf ("Hello %s, are you ready for this adventure?", player1.charname);
printf("\033[0m"); // Reset text color to default
sleep(1);

     
   int val ;
   int checkVal = 0;
   int reset = 0;
   char str[20];
   int charPoints = 10;
   printf("\n\n You have %d points to allocate for strength, agility and inteligence. ", charPoints);
   while (checkVal == 0)
   {
   printf("\n\nPlease enter the amount of points to allocate for %s, (minimum of 1 point). \n ", playerValues[0]);
   scanf("%s", str);
   val = atoi(str);
   checkVal = val;
    
   
       if (val > 0 && val <= MAX_POINTS && charPoints >= val)
            {
                player1.stre = val;
                charPoints -= checkVal;
            }
                else 
            {
                printf("What do you think you are doing >:(\n");
                sleep(1);
                return 1;
            }
            
   };
   
   
   checkVal = reset;
   val = reset;
   sleep(1);
   printf("\n\tYour character now has %d in %s .\n", player1.stre, playerValues[0]);
   printf("\tYou have %d points left to allocate. \n", charPoints);
   while (checkVal == 0)
   {
   printf("\n\nPlease enter the amount of points to allocate for %s ( again min 1). \n ", playerValues[1]);
   scanf("%s", str);
   val = atoi(str);
   checkVal = val;
   if (val > 0) 
   {
       if (charPoints >= val)
       {
       player1.agi = val;
       charPoints = (charPoints - checkVal);
       printf("\n\tYour character now has %d in %s .\n", player1.agi, playerValues[1]);
       printf("\tYou have %d points left to allocate. \n", charPoints);
       }
       else 
       {
           printf("\tYou have %d points left to allocate. \n", charPoints);
           checkVal = reset;
       };
   }

else
            {
                sleep(1);
             printf("...\n");
             sleep(1);
             printf("...\n");
             printf ("You didnt spend any points in Agility. Your hero fails to grasp the concept of getting out of bed. \n");
             printf ("\tYour adventure ends before it even got started, be smarter next time :). \n");
             sleep(2);
             return 1;   
            
            }

   };
   sleep(1);
   
   checkVal = reset;
   val = reset;
    
    while (checkVal == 0)
   {
   printf("\n\nPlease enter the amount of points to allocate for %s, min 1. \n ", playerValues[2]);
   scanf("%s", str);
   val = atoi(str);
   checkVal = val;
   if (val > 0) 
   {
       if (charPoints >= val)
       {
       player1.intel = val;
       charPoints = (charPoints - checkVal);
       printf("You character now has %d in %s .\n", player1.intel, playerValues[2]);
       }
       else 
       {
           printf(" You only have %d points left to allocate. \n", charPoints);
           checkVal = reset;
       };
   }
   else
            {
                sleep(1);
             printf("...\n");
             sleep(1);
             printf("...\n");
             sleep(1);
             printf ("You didnt spend any points in Intelligence. Your hero fails to grasp the concept of getting out of bed. \n");
             printf ("\tYour adventure ends before it even got started, be smarter next time :). \n");
             sleep(2);
             return 1;   
            
            }
   };
    sleep(1);
     if (charPoints != 0)
            {
             printf ("You didnt spend all your points. Too bad for you. \n"); 
            };
    
    printf("\nYou stand at the entrance of the dungeon. You have a feeling there might be some kind of reward somewhere... \n");
    sleep(1);
    printf("You can go forward, left or right. \n\n");
    sleep(2);
    menu:
    checkVal = reset;
    int choosePath;
    while (checkVal == 0)
   {
       printf("Which way do you choose? \n");
       printf("1. Go forward \n");
       printf("2. Go left \n");
       printf("3. Go right \n\n");
       scanf("%s", str);
       val = atoi(str);
       checkVal = val;
       if (val > 0)
       {
        if (val > 3)
         {
           printf("Please enter a valid option.\n\n");
           sleep(1);
           checkVal = reset;
         }
         else
         {
             choosePath = val;
         }
        }
   }
    sleep(2);
      switch (choosePath)
      {
          case (1):
            printf("You choose the tunnel leading forward into the dungeon \n");
            printf("The tunnel descends depper into the dungeon, and you can't really see what's in front\n");
            sleep(1);
            printf("You need to roll a dice for an inteligence check \n\n");
            rollDice = diceX();
            printf ("You rolled %d \n", rollDice);
            trapCheck = statsCheck(rollDice, player1.intel );
            sleep(2);
            if ( trapCheck == 1)
             { 
                 printf("\033[0;31m"); 
                 printf("You failed to spot the hiden trap. \n");
                 sleep(1);
                 printf(" You take an arrow to the knee. \n");
                 printf("\033[0m"); 
                 printf("And with that your adventuring days are over. You limp out of the dungeon \n");
                 printf("\n\t\tWell, at least those were some cool views... \n\n");

                 return 1;
             }
             else
             {
                  printf("You spot and disable a hidden trap \n");
             }
            break;
          case (2):
            printf("You choose the tunnel leading left into the dungeon \n");
            printf("The tunnel is blocked by a massive door \n\n");
            sleep(2);
            checkVal = reset;
            int obstacle;
            while (checkVal == 0)
            {
              printf("What do you want to do? \n");  
              printf("1. Try to break down the door. \n");
              printf("2. Try to pick the lock. \n\n");
              scanf("%s", str);
              val = atoi(str);
              checkVal = val;
              if (val > 0)
              {
                if (val > 2)
                {
                  checkVal = reset;
                }  
                else
                {  
                  obstacle = val;
                }    
               } 
            }
            switch (obstacle)
            {
              case (1):
                printf("You kick the door with all your might in an attempt to break it down.\n");
                printf("Whoops, the door wasnt locked \n");
                sleep(1);
                printf("The door opens and you tumble down into the spike filled pit hidden behind the door... \n");
                printf("Unfortunately you injure yourself and can't continue forward \n ");
                printf("Your adventure ends here \n ");
                return 1;
              break;
              case (2):
                printf("You bend down to try to pick the lock only to notice that the door isnt locked. \n");
                printf("You also notice the spike filled pit that is hidden behind the door. \n");
                sleep(1);
                printf("You need to roll an agility check to see if you can jump over the pit. \n\n");
                rollDice = diceX();
                printf ("You rolled %d \n", rollDice);
                trapCheck = statsCheck(rollDice, player1.agi );
                if ( trapCheck == 1)
                { 
                    printf("\033[0;31m"); 
                    printf("\nI guess you aren't as agile as you seemed. \n");
                    sleep(1);
                    printf("Enjoy your new career as a pincushion. \n ");
                    printf("\033[0m"); 
                    printf("Your adventure ends here. \n ");
                return 1;
                }
                else
                {
                    printf("You manage to safely avoid the pit, let's go!!! \n\n");
                }
                break;
            }
              break;
            
          case (3):
            printf("You choose the right tunnel into the dungeon \n\n");
            sleep(2);
            printf("You walk deeper in to the dungeon until the tunnel ends and you find yourself \n");
            printf("in a big room with a misterious and shiny wooden chest in the middle \n\n");
            checkVal = reset;
            sleep(2);
            int item;
            while (checkVal == 0)
            {
              printf("What do you want to do ? \n");  
              printf("1. Try to open the chest \n");
              printf("2. Leave the chest alone \n\n");
              scanf("%s", str);
              val = atoi(str);
              checkVal = val;
              if (val > 0)
              {
                if (val > 2)
                {
                  checkVal = reset;
                }  
                else
                {  
                  item = val;
                }    
               } 
            }
            if (chestEncountered) {
        printf("You already opened the chest.\n");
    } 
    else 
    {
                switch (item)
                {
                    case (1):
                    switch (rand() % 5 + 1)
                      {
                        case 1: 
                          printf("You open  the chest and find a sword. When you lift it, you feel the power of the sword filling your body.\n");
                          printf("YAY! You picked up a magic sword that gives you +2 in strength.\n");
                             player1.stre += 2;
                             sleep(1);
                    printf("Your strength is now %d . \n\n", player1.stre );
                    chestEncountered = 1; 
                    playerInventory.sword = 1;

                         break;
                        case 2:
                           printf("You open the chest and find a potion. You drink it and feel your mind sharpening.\n");
                           printf("You gained +2 intelligence.\n");
                             player1.intel += 2;
                             sleep(1);
                    printf("Your intelligence is now %d . \n\n", player1.intel );
                    chestEncountered = 1; 
                    playerInventory.potion = 1;

                         break;
                         case 3:
                           printf("You open the chest and find a pair of magic boots. As you wear them, you feel lighter on your feet.\n");
                           printf("Congratulations! You gained +1 agility.\n");
                             player1.agi += 1;
                             sleep(1);
                    printf("Your agility is now %d . \n\n", player1.agi );
                      chestEncountered = 1; 
                      playerInventory.boots = 1;
                         break;
                         case 4:
                           printf("You open the chest and find an interesting ring. You couldn't resist putting it on.\n");
                           printf("Oops! The ring made you feel a little odd, and you cannot take it out. You lost 1 point from each ability.\n");
                           player1.stre -= 1;
                           player1.agi -= 1;
                           player1.intel -= 1;
                           sleep(1);
                    printf("Your stats are now %d strength, %d inteligence and %d agility. \n\n", player1.stre, player1.intel, player1.agi );
                          chestEncountered = 1; 
                          playerInventory.ring = 1;
                         break;
                        case 5:
                             printf("You open the chest but find nothing inside. What a disappointment!\n");
                              chestEncountered = 1; 
                        break;
                        }
                    break;
                    case 2:
                    printf("You leave the chest alone, there might've been a cake inside...\n");
                    break;
                      default:
                      printf("Invalid choice.\n");
        break;

               
                
      }
    }      
      }; 
    sleep(2);

    printf("You realize all 3 paths come to the same torch path.\n");
    printf("The coldness of the dungeon calls you, you got a bad feeling but you have to decide what to do now. \n\n");


       menu2:

checkVal = reset;
    int choosePath2;

    while (checkVal == 0)
   {
       printf("What do you want to do? \n");
       printf("1. Follow the torch path ahead \n");
       printf("2. Go back \n");
       printf("3. Check inventory \n\n");
       scanf("%s", str);
       val = atoi(str);
       checkVal = val;
       if (val > 0)
       {
        if (val > 3)
         {
           checkVal = reset;
         }
         else
         {
             choosePath2 = val;
         }
        }
   }
   switch(choosePath2)
   {
    case 1:
      printf("You follow the torch path, but hear some weird noises ahead...\n\n");
      int encounter = monsterEncounter() ;
      sleep(1);
      printf("...\n");
      sleep(1);
      printf("...");
      sleep(1);
      printf("\nOh! You encountered a %s with %i strength and %i life . \n", monster[encounter], monsterStrength[encounter], 
      monsterLife[encounter]);
      sleep(1);
      printf("You need to fight for your life! roll the dice to confront him with your attacks!\n\n");
      sleep(2);
      int playerStr = player1.stre;
      int totalPlayer ;
      int monsterTotal;
      int playerLife = 8;
      int monsterAlive = monsterLife[encounter];
      while (monsterAlive  > 0 ) 
        { 
          printf("Press Enter to roll the dice...\n");
    fflush(stdout); 
    clearInputBuffer();
    getchar();

          int dice1 = diceX();
          int dice2 = diceX();
          printf ("You roll %d on the dice, \n", dice1);
          printf ("The %s rolls %d on the dice \n", monster[encounter], dice2);
          sleep(1);
          totalPlayer = playerStr + dice1;
          monsterTotal = monsterStrength[encounter] + dice2;
          printf ("Your attack score is %d, \n", totalPlayer);
          sleep(2);
          printf ("The %s attack score is %d, \n", monster[encounter], monsterTotal);
          sleep(2);

            if (totalPlayer >= monsterTotal)
              { 
              printf("You attack the %s sucesfully \n\n", monster[encounter] );
              sleep(1);
              monsterAlive = (monsterAlive -1);
              }
          else
              {    
              printf ("Your attack fails and the %s hits you for one damage .\n\n", monster[encounter] );
              playerLife = (playerLife -1);
              printf ("You have %d life points remaining \n" , playerLife );
              sleep(2);
                if (playerLife == 0)
              {
              printf ("The %s proved too much for you. Your adventure ends here . \n", monster[encounter]);
              printf("You leave the dungeon for a life as a turnip farmer. \n\n");
              printf("Hey, at least it's a cool story to tell your kids! \n\n");
              return 1;   
              }
              }
            };   
    sleep(2);
    printf("\033[0;32m"); 
    printf ("You managed to slay the %s!!!\n", monster[encounter]);
    sleep(2);
    printf("\033[0m"); 
    printf("The mansion is free now, you are a proper king!!!. \n");
    printf("You completed the game, congrats!\n\n");
    printf("\t\tFeel free to play again, there might be different endings, Cya :) \n\n");

  sleep(2);
    break;
    case 2:
    printf("You decide to go back\n");
    printf("You are once again at the entrance of the mansion:\n");

goto menu;
    break;

    case 3:
printInventory(playerInventory);
goto  menu2;
sleep(1);
   }
    return 0;
}

        
int diceX ()
{
        int dice ;
        time_t t;
        srand(time(&t));
        dice = (rand() % 5) + 1;
        return dice;
}

int monsterEncounter ()
{
    int monsterEncounter ;
    time_t t;
    srand(time(&t));   
    monsterEncounter = (rand() % 3) + 1;    
    return monsterEncounter;
}

int statsCheck (int playerStats, int diceRoll)
{
    int result;
    result = 1;
    if (playerStats < diceRoll  )
    {
    result = 0; 
    }
    return result;
}
void printInventory(struct Inventory inv)
{
    if (inv.sword == 1)
    {
        printf("You have a magic sword in your inventory\n\n");
        sleep(1);
    }
    if (inv.boots == 1)
    {
        printf("You have a pair of magic boots\n\n");
        sleep(1);

    }
    if (inv.ring == 1)
    {
        printf("You have a deceiving ring\n\n");
        sleep(1);

    }
    if (inv.potion == 1)
    {
        printf("You have an empty potion in your inventory\n\n");
        sleep(1);

    }
    if (inv.sword == 0 && inv.boots == 0 && inv.ring == 0 && inv.potion == 0)
    {
        printf("You have nothing in your inventory\n\n");
        sleep(1);

    }
}
void printTitle() 
{
printf("\n");
printf("      ##     ##      ####    ##   ##  #######                     ##     #####            #     #    ##     ##   ##   #####    ####     #####   ##   ## \n");
printf("       #    ####      ##     ### ###   ##                         ##    ##   ##           ##   ##   ####    ###  ##  ##   ##    ##     ##   ##  ###  ## \n");
printf("      ##   ##  ##     ##     #######   ## #                      ##     #                 ### ###  ##  ##   #### ##  #          ##     ##   ##  #### ## \n");
printf("      ##   ##  ##     ##     #######   ####                              #####            #######  ##  ##   ## ####   #####     ##     ##   ##  ## #### \n");
printf("      ##   ######     ##     ## # ##   ## #                                  ##           ## # ##  ######   ##  ###       ##    ##     ##   ##  ##  ### \n");
printf("  ##  ##   ##  ##     ##     ##   ##   ##                               ##   ##           ##   ##  ##  ##   ##   ##  ##   ##    ##     ##   ##  ##   ## \n");
printf("  ##  ##   ##  ##    ####    ##   ##  #######                            #####            ##   ##  ##  ##   ##   ##   #####    ####     #####   ##   ## \n");
printf("   #### \n");
printf("\n");
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}