/*
author: Peiman Zhiani 
Last Modified Date: 25/03/2022

- Simplified blackjack game including the comouter/ dealer on one end and the player on the other.
*/


// used libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// initializing functions
void replay(int []);
int play(int []);
void greating(int []);
void shuffle(int []);
void valueOFcards(int);
int JackKingQueen(int);
int calculatecards(int [], int);
void printlines(int);
void calculateScore (int [], int);


void printlines(int value)//this function draws the pictures eg cards, lines and ending.
{
  switch(value)
  {
    case 1:
      {
        printf("----------------------------------------------------------------\n");
        break;
      }
    case 2:
      {
        printf("----------------------------------------------------------------\n");
        printf(" >>>>>>>>>>>>>>>>>>   END OF THE rOUND   <<<<<<<<<<<<<<<<<<<<<<\n");
        printf("----------------------------------------------------------------\n");
        break;
      }
    case 3:
      {
        printf("*****************\n");
        printf("*            ****\n");
        printf("*             ***\n");
			  printf("*               *\n");
        break;
    case 4:
      {
        printf("*               *\n");
        printf("*             ***\n");
        printf("*            ****\n");
		  	printf("*****************\n");
        break;
      }
      }
  }
}

void calculateScore (int chip[], int value)// holds and calls the scores using an array
{
  
  
  switch(value)
  {
    case 1:{ //player bet
      chip[0] = chip[0] - 1;
      break;
    }
    case 2:{// computer bet
      chip[1] = chip[1] - 1;
      break;
    }
    case 3:{ //player win
      chip[0] = chip[0] + 2;
      break;
    }
    case 4:{// computer win
        chip[1] = chip[1] + 2;
      break;
    }
    case 5:{// player tie
        chip[0] = chip[0] + 1;
      break;
    }
    case 6:{// computer tie
        chip[1] = chip[1] + 1;
      break;
    }
  }
}

int calculatecards(int playercards[], int i)// calculate the value of the cards for player and check for values. 
{ 
  char ask;
  int Sum = 0;
  //check for ace
  if(playercards[i] % 100 == 1)
    {
      printlines(1);
      printf("You have an ACE! choose A value of the card %d, input 'e' for 11 or 'o' for 1! :\n", i+1);
      printlines(1);
      do{
        ask = getchar();
      }while(ask != 'e'&& ask != 'o');
  
      if(ask == 'o')
      {
        printf("You chose 1 for the value of your ACE! \n");
        Sum = Sum + 1;
      }
      else if(ask == 'e')
      {
        printf("You chose 11 for the value of your ACE! \n");
        Sum = Sum + 11;
      }
    }
   
    else if(JackKingQueen(playercards[i]) % 100 == 10) // check for jack king and queen + 10
    {
      Sum = Sum + 10;
    }
    // other values of cards 2- 10
    else
    {
      Sum = Sum + playercards[i]%100;
    }
  return Sum;
}

void valueOFcards(int cv) // displays the card pictures
{
  
  int cardvalue = cv % 100;
  char Settracker = cv /100;
  sleep(2);
  switch(cardvalue)
    {
      case 1: 
		{
			printlines(3);
			printf("* %c            *\n", Settracker);
			printf("*       A       *\n");
			printlines(4);
			break;
		}
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		{
			printlines(3);
			printf("* %c            *\n", Settracker);
			printf("*      %2d      *\n", cardvalue);
			printlines(4);
			break;
		}
		case 11:
		{
			printlines(3);
			printf("* %c            *\n", Settracker);
			printf("*       J       *\n");
			printlines(4);
			break;
		}
		case 12:
		{
			printlines(3);
			printf("* %c             *\n", Settracker);
			printf("*       Q       *\n");
			printlines(4);
			break;
		}
		case 13:
		{
			printlines(3);
			printf("* %c            *\n", Settracker);
			printf("*      K        *\n");
			printlines(4);
			break;
		}

	}

  
}

int JackKingQueen(int value) // if the cards are king queen and jack, the value is put to 10
{
	if ((value%100==11) ||(value%100==12) ||(value%100==13))
  {
    return (value/100)*100+10;
  }
    
	else
  {
    return value;
  }
    
}

void shuffle(int cards[]) // this function shuffles the cards using a temperory deck and random variable, suffling happens at the beginning of each game
{
  int i;
  int t;
  int tempdeck[52];


  
  for (i=0;i<52;i++)
  {
    tempdeck[i] = (i/13+3)*100 + i%13 + 1;
  }
		

  // randomise the seed 
  srand(time(NULL));
  for(i =0; i<52; i++)
  {
    do
    {
      t = rand() % 52;
    }while(tempdeck[t] == 0);
    
    cards[i] = tempdeck[t];
		tempdeck[t] = 0;
  }
  
  
  printf(">>>>>>>>>>>>>>>>>>  The deck is shuffled  <<<<<<<<<<<<<<<<<<<<<<\n");
  printlines(1);

}

int play(int chip[]) // the main play function of the game returns if the player wins or looses or ties
{
  int cards[52];
  int playercards[6]={0};
	int computercards[6]={0};
  int i = 0;
  int playerSum = 0;
  int ComputerSum = 0;
  char ask;

  
  
  system("clear");
  printlines(1);
  printf("Player  has: %d CHIPS                    Computer has: %d CHIPS\n", chip[0], chip[1]);
  printlines(1);
  printf("                   Each player bets one CHIP!\n");
  calculateScore (chip, 1);
  calculateScore (chip, 2);
  printf("Player  has: %d CHIPS                     Computer has: %d CHIPS\n",   chip[0], chip[1]);
  printlines(1);
// shuffle cards
  shuffle(cards);
  playercards[0] = cards[0];
  playercards[1] = cards[1];
  computercards[0] = cards[2];
  computercards[1] = cards[3];
  printf("                  First Computer's card is: \n\n");
  valueOFcards(computercards[0]);
  printf("\n");
  printf("\n");
  printf("                     Your First card is: \n\n");
	valueOFcards(playercards[0]);
	printf("\n");
  printf("                     Your Second card is: \n\n");
	valueOFcards(playercards[1]);
  for(i=0; i<2; i++)
  {
    // calculate the sum of first 2 player cards 
    playerSum = playerSum + calculatecards(playercards, i);
    printf("\n");
    
    // check if the player has already hit 21
    if (playerSum > 21)
			{
				printf("The player's first two card add up to:  %d! the value is over 21...\n\n",playerSum);
				printf("Computer wins!\n");
        printlines(2);
				return 1;
			}
		else if (playerSum == 21)
			{
				printf("The player's first two card add up to:  %d! BLACKJACK! \n\n",playerSum);
				printf("Player wins!\n");
        printlines(2);
				return 0;
			}		
	}
  printlines(1);
	printf("The player's first two card add up to:  %d \n",playerSum);
  printlines(1);
  
	// ask for player's nezt draw
  for (i = 0; i<4; i++)
  {
    char more = 'n';

    printf("Would you like to draw more cards? (type y for yes and n for no)  ");
    do
    {
      more = getchar();
    }while(more != 'y' && more != 'n' );
    
    if(more == 'y')
    {
      playercards[i+2] = cards[i+4];
      printf("Your %drd card is: \n\n", i+3 );
      valueOFcards(playercards[i+2]);
      
      // check for the sum after each card 
      playerSum = playerSum+ calculatecards(playercards, i+2);
      
      //check if the player is at 21 in each increment 
      printlines(1);
      if (playerSum > 21)
			{
				printf("The player cards add up to:  %d .the value is over 21\n\n",playerSum);
				printf("Computer wins!\n");
        printlines(2);
				return 1;
			}
			else if (playerSum == 21)
			{
				printf("The player cards add up to:  %d. BLACKJACK! \n\n",playerSum);
				printf("Player wins!\n");
        printlines(2);
				return 0;
			}		
			else printf("The player cards add up to:  %d\n\n",playerSum);
		}
		else 
		{
      printlines(1);
			printf("The player hold a total of :  %d  points\n\n",playerSum);
			break;
		}
  
    printlines(1);
      
      
    
  }
  //case of not getting to 21 in 6 draw
  if (i == 4)
	{
		printf(" Since the sum of your 6 cards is not larger than 21! Player considered a winner!!! rare luck!\n ");
    printlines(2);
		return 0;
	}
  printlines(1);
  printf("Computer's turn: \n");
  printlines(1);
  printf("                  First Computer's card is: \n\n");
	valueOFcards(computercards[0]);
  printf("\n");
  printf("                  Second Computer's card is: \n\n");
	valueOFcards(computercards[1]);

  printlines(1);
  // checking for computer's first 2 card value
  if (computercards[0]%100 + computercards[1]%100 == 2)
	{
		ComputerSum = 12; // two ACE card choose first 1 and second 11.
    
		printf("The Computer's first two card add up to:   %d\n", ComputerSum);
	}
	else if ((JackKingQueen(computercards[0]))%100 + (JackKingQueen(computercards[1]))%100 == 1)
	{
		ComputerSum = 21; // computer hit blackjack
		printf("The Computer's first two card add up to:  %d\n", ComputerSum);
		printf("Computer wins!\n");
    printlines(2);
		return 1;
	}
	else if (computercards[0]%100==1 || computercards[1]%100==1)// computer hit one ace
	{
		ComputerSum = (computercards[0]+computercards[1])%100+(rand()%2)*10;
		printf("The Computer's first two card add up to:  %d \n", ComputerSum);
	}
	else
	{
		ComputerSum = (JackKingQueen(computercards[0]))%100 + (JackKingQueen(computercards[1]))%100;
		printf("The Computer's first two card add up to:  %d\n", ComputerSum);
	}
  printlines(1);

  for (i=0; i<4 && ComputerSum <= 16; i++)
	{
		computercards[i+2] = cards[i+7];
		printf("The Computer's %drd card is: \n", i+3);
		valueOFcards(computercards[i+2]);
    
		// if computer got ace as for any of the cards after 2nd one
		if (computercards[i+2]%100 == 1) 
		{
			if (ComputerSum + 11 <= 21)
			{
				printf("Computer has chosen A as 11\n");
				ComputerSum = ComputerSum + 11;
				printf("The Computer's cards add up to:  %d \n\n", ComputerSum);
			}
			else
			{
				printf("Computer chose 1 for A. \n");
				ComputerSum = ComputerSum +1;
				printf("The Computer's cards add up to:  %d \n\n", ComputerSum);
			}
		}
		else
		{
			ComputerSum = ComputerSum + JackKingQueen(computercards[i+2])%100;
			printf("The Computer's cards add up to:  %d\n\n", ComputerSum);
		}
	}
  //case of not getting to 21 in 6 draw
	if (i == 4)
	{
		printf("Since the sum of your 6 cards is not larger than 21! Computer considered a winner!!! rare luck!\n\n");
		return 1;
	}
  printlines(1);
  //check for the winner
  if (ComputerSum > 21 || playerSum > ComputerSum)
	{
    printf("Player got  %d  while Computer has  %d \n",playerSum, ComputerSum );
		printf("Player wins!\n");
    printlines(2);
		return 0;
	}
	else if (playerSum == ComputerSum)
	{
		printf("TIE! player and computer get the same score!\n");
    printlines(2);
		return 3;
	}
	else if (playerSum < ComputerSum)
	{
    printf("Computer got  %d  while Player has  %d \n", ComputerSum, playerSum );
		printf("Computer wins!\n");
    printlines(2);
		return 1;
    
	}
		
	return 3;
  printlines(2);
}

void greating(int chip[]) //prints the rules for the user and has a inter changable token value
{
  printlines(1);
  printf("rules of the game are simple; you draw a random card from a full deck of 52 cards.   The values of the cards are as follows: \n\t -Ace is 1 point, (2) is 2 points, ....., (9) is 9 points and Ten, Jack, Queen and King are 10 points.\n");
  printf("\t -A player's turn consist of drawing cards from the deck and adding up the point values. the aim is to get 21 points or close to 21. If the sumation passes the 21; the drawing will stop after reseting the summation to 0.\n"); 
  printf("\t -Each player gets a total of %d CHIPS, and each time a player wins they will get a chip from their opponent. whomever gets to 0 chip first looses.\n", chip[1]);
  printlines(1);
}

void replay(int chip[]) // a loop that asks the user for replay, if the player or computer runs out of tokens or player wants to stop after a round they can also leave, it will also display the stats
{
  int score;
  char PlayAgain;
  printf("Would you like to play again? (y for yes,  n for no) \n");
  printlines(1);
  do{
    PlayAgain = getchar();
  }while(PlayAgain != 'n' && PlayAgain != 'y');
  if(PlayAgain == 'y')
  {
    printf("You can press 'Ctrl + c ' at anytime to end the game.\n"); 
    printf("Lets play another round ... \n");
    printlines(1);
    score = play(chip);
    if(score == 1)
      {
        calculateScore (chip, 4);
      }
      else if (score == 0)
      {
        calculateScore (chip, 3);
      }
      else
      {
        calculateScore (chip, 1);
        calculateScore (chip, 2);
      }
      printf("Player chips:     %d                Computer chips:    %d\n",chip[0], chip[1]);
    if(chip[0] == 0 || chip[0] == 20)
    {
     printlines(1);
      printf("You have either 0 or macimum amount of chips. Comeback again!");
      printlines(1);
      printf("Player final chips:     %d                Computer final chips:    %d\n",chip[0], chip[1]);
      printlines(2);
      exit(0);
    }
    else
    {
      replay(chip);
    }
  }
  else
  {
    printlines(1);
    printf("We will be waiting for your return! \n");
    printlines(1);
    printf("Player final chips:     %d         Computer final chips:    %d\n",chip[0], chip[1]);
    printlines(2);
    exit(0);
    
  }
}

void printwelcome(int value) // print the welcome tezt
{
  switch(value){
    case 1:
      {
        printf("             Welcome To BlackJack!\n");
        printlines(1);
        printf("If you want to hear the rules type 'r', else press enter to start.\n");
        printf("If you want to start playing type 'p' enter to start playing\n"); 
        printf("You can press 'Ctrl + c ' at anytime to end the game.\n");
        printlines(1);
        break;
      }
    case 2:
      {
        printf("If you want to start playing type 'p' enter to start playing"); 
        printf("You can press 'Ctrl + c ' at anytime to end the game.\n");
        break;
      }
  }
}

int main (void) // main function that starts the program
{
  int score;
  char start_game;
  char start_game2; 
  int chip[2] ={10, 10}; // the first chip value chip[0] is for player and chip[1] is for computer
  
  printwelcome(1);
  do
  {
    start_game = getchar();
    
  }while(start_game != 'r' && start_game != 'p');

  if (start_game == 'r')
  {
    greating(chip);
    printwelcome(2); 
    printlines(1);
    start_game2 = getchar();
    
    do
      {
          start_game2 = getchar();
      }while( start_game2 != 'p');
    
    if(start_game2 == 'p')
    {
      
      score = play(chip);
      if(score == 1)
      {
       calculateScore (chip, 4);
      }
      else if (score == 0)
      {
        calculateScore (chip, 3);
      }
      else
      {
        calculateScore (chip, 5);
        calculateScore (chip, 6);
      }
      
      replay(chip);
    }
  }
    
  else if(start_game == 'p')
  {
    score = play(chip);
    if(score == 1)
      {
        calculateScore (chip, 4);
      }
    else if (score == 0)
      {
        calculateScore (chip, 3);
      }
    
    else
      {
        calculateScore (chip, 5);
        calculateScore (chip, 6);
      }
    printf("Player chips:     %d                Computer chips:    %d\n",chip[0], chip[1]);
    replay(chip);
  }
  
  return 0;
}

