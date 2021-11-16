#include "uop_msb.h"
using namespace uop_msb;


// You are to use these ojects to read the switch inputs
DigitalIn SW1(USER_BUTTON);
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);
DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);
DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);

// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

//Use this to sound an error
Buzzer alarm;

int main()
{
    while (true)
    {
        leds = 0;

        //Beep
        alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
        wait_us(250000);
        alarm.rest();

        //Wait for the blue button using a while loop
        while (SW1==0);

        
        // For full marks, debounce the switches with suitable delays

        // This is a "combination lock" activity. Write some code to detect the following sequence of press-and-release inputs
        // SW1 and SW2, SW5, SW4, SW2 and SW3
        // If the full sequence is entered, correctly, the green LED should flash 3 times
        // If a sequence of inputs was entered incorrectly, the red LED should light and the buzzer should sound for 5 seconds
        // For full marks, debounce the switches and use flow control structures and arrays to avoid deep nesting of code

        // ***** MODIFY THE CODE BELOW HERE *****
        int buttonCount = 0;
        int sw1Count = 0;
        int sw2Count = 0;
        int sw3Count = 0;
        int sw4Count = 0;
        int sw5Count = 0;

        while(buttonCount < 4){

            while(SW1 == 0);
            while(SW1 == 1){
                wait_us(500000);
                sw1Count = 1;
                buttonCount = buttonCount + 1;
            }
            
            while(SW2 == 0);
            while(SW2 == 1){
                wait_us(500000);
                sw2Count = 1;
                buttonCount = buttonCount + 1;
            }
            while(SW3 == 0);
            while(SW3 == 1){
                wait_us(500000);
                sw3Count = 1;
                buttonCount = buttonCount + 1;
            }
            while(SW4 == 0);
            while(SW4 == 1){
                wait_us(500000);
                sw4Count = 1;
                buttonCount = buttonCount + 1;
            }
            while(SW5 == 0);
            while(SW5 == 1){
                wait_us(500000);
                sw5Count = 1;
                buttonCount = buttonCount + 1;
            }
        }

        
        
        
        //correct
        int correct(void);
        {
        int count = 0;
        while(count < 3){
            leds = 4;
            wait_us(500000);
            leds = 0;
            wait_us(500000);
        }
        }


        //wrong
        int wrong(void);
        {
        leds = 1;
        alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
        wait_us(5000000);
        alarm.rest();
        }

        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


