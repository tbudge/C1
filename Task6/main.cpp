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
void switchCase();
int main(){

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
        leds = 4;
        int timeDelay = 500000;
        int buttonCount = 0;
        int score = 0;

        /*wait_us(timeDelay);
        while(buttonCount < 4){

            while(SW1 == 0 && SW2 == 0 && SW3 == 0 && SW4 == 0 && SW5 == 0);
            wait_us(timeDelay);
            if(SW1 == 1 && SW2 == 1){
                wait_us(timeDelay);
                buttonCount++;
                score++;
            
                while(SW1 == 0 && SW2 == 0 && SW3 == 0 && SW4 == 0 && SW5 == 0);
                wait_us(timeDelay);
                if(SW5 == 1){
                    wait_us(timeDelay);
                    buttonCount++;
                    score++;
                    leds = score;
             
                    while(SW1 == 0 && SW2 == 0 && SW3 == 0 && SW4 == 0 && SW5 == 0);
                    wait_us(timeDelay);
                    if(SW4 == 1){
                        wait_us(timeDelay);
                        buttonCount++;
                        score++;
                        leds = score;

                        while(SW1 == 0 && SW2 == 0 && SW3 == 0 && SW4 == 0 && SW5 == 0);
                        wait_us(timeDelay);
                        if(SW2 == 1 && SW3 == 1){
                            wait_us(timeDelay);
                            int count = 0;
                            while(count < 3){
                                leds = 4;
                                wait_us(timeDelay);
                                leds = 0;
                                wait_us(timeDelay);
                                count++;
                                }
                        }    
                        else{
                            buttonCount = buttonCount + 1;
                            }
                    }        
                    else{
                        buttonCount = buttonCount + 1;
                        }
                }
                else{
                    buttonCount = buttonCount + 1;
                    }            
            }
            else{
                buttonCount = buttonCount + 1;
                }   
        leds = score;          
        }
        
        //wrong
        leds = 1;
        alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
        wait_us(timeDelay * 10);
        alarm.rest();
        */
        int input[4];
        int correctSequence[4] = {1, 2, 3, 4};
        int button;

        while(buttonCount <4){
        while(SW1 == 0 && SW2 == 0 && SW3 == 0 && SW4 == 0 && SW5 == 0);
            if(SW1 == 1 && SW2 == 1){
                button = 1;
                buttonCount++;
                switchCase();
            }
            else if(SW5 == 1){
                button = 2;
                buttonCount++;
                switchCase();
                
            }
            else if(SW4 == 1){
                button = 3;
                buttonCount++;
                switchCase();
                
            }
            else if(SW2 == 1 && SW3 == 1){
                button = 4;
                buttonCount++;
                switchCase();
                
            }
            else{
                buttonCount++;
        


        void switchCase() {  
            switch(button){
                case 1:
                    input[buttonCount-1] = 1;
                break;
            
                case 2:
                    input[buttonCount-1] = 2;
                break;

                case 3:
                    input[buttonCount-1] = 3;
                break;

                case 4:
                    input[buttonCount-1] = 4;
                break;
            }
        }




        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}
  
        
            


