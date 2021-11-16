#include "uop_msb.h"
using namespace uop_msb;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    leds = 0;
    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Write a for-loop to count from 0 to 100 in steps of 10 - print the results to the serial terminal

    int count = 0;
    for(count = 0; count <= 100; count = count + 10) {
    
        printf("%d \n", count);

        }

    // 2. Write a for-loop to count from 100 down to 10 in steps of 5 - print the results to the serial terminal
    
    for(count = 100; count >= 0; count = count - 10) {
    
        printf("%d \n", count);

        }
    // 3. Write some code to demonstrate nested for-loops (one loop within another)
    int count2;
    for(count = 0; count <= 10; count = count + 1) {
        for(count2 = 0; count2 <= 3; count2 = count2 + 1){
            printf("%d \n", count2);
        }
        printf("Party!");
    }
    // ***** MODIFY THE CODE ABOVE HERE *****

    


    
    leds = 7;

    while (true) {

    }
}

