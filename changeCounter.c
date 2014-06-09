#include <stdio.h>
#include <cs50.h>
#include <math.h>
 
int coinCntr(int coinVal, int coinCount, int *change2); //initializes the function
 
int main(void) {
    int coinCount=0;
    float change;
    printf("I'm a change calculator!\nI calculate the minimum nessecary number of coins to make change\n");
    do {
        printf("How much change is needed? ");
        change= GetFloat();
    } 
    while (change<0); //keeps asking for change until non-negative is given
     
    int change2 = round(change*100); //converts change into workable int
  
    coinCount=coinCntr(25, coinCount, &change2);
    coinCount=coinCntr(10, coinCount, &change2);
    coinCount=coinCntr(5, coinCount, &change2);
    coinCount=coinCntr(1, coinCount, &change2);
    printf("You will need %d coins.\n",coinCount);
}
 
/*This is a function that subtracts as many possible values of 
a given coin unit, CoinVal, until the number is too small to subtract more.
For each subtraction it increments coinCount by one. * and & are used on change2
to have an actual effect on the variable.
*/
 
int coinCntr(int coinVal, int coinCount, int *change2) {
    while (*change2>=coinVal) {
       *change2 -=coinVal;
       coinCount++;
    }
    return coinCount;
}