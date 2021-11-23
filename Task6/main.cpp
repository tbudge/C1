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

void switchCase(int button, int* input) {  
    switch(button) {
        case 1:
            input[0] = 1;
            //leds = 1;
        break;
            
        case 2:
            input[1] = 2;
            //leds = 2;
        break;

        case 3:
            input[2] = 3;
            //leds = 3;
        break;

        case 4:
            input[3] = 4;
            //leds = 4;
        break;
    }
}

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
        wait_us(500000);
        leds = 4; 

        // For full marks, debounce the switches with suitable delays

        // This is a "combination lock" activity. Write some code to detect the following sequence of press-and-release inputs
        // SW1 and SW2, SW5, SW4, SW2 and SW3
        // If the full sequence is entered, correctly, the green LED should flash 3 times
        // If a sequence of inputs was entered incorrectly, the red LED should light and the buzzer should sound for 5 seconds
        // For full marks, debounce the switches and use flow control structures and arrays to avoid deep nesting of code

        // ***** MODIFY THE CODE BELOW HERE *****

        int timeDelay = 300000;
        int button;
        int score;    
            
        int input[4];
        int correctSequence[4] = {1, 2, 3, 4};
        

        for(int buttonCount = 0; buttonCount < 4; buttonCount++, wait_us(timeDelay)){
            while(SW1 == 0 && SW2 == 0 && SW3 == 0 && SW4 == 0 && SW5 == 0){}
                wait_us(timeDelay);
                if(SW1 == 1 && SW2 == 1){
                    button = 1;
                    //leds = 1;
                    switchCase(button, input);
                }
                else if(SW5 == 1){
                    button = 2;
                    //leds = 2;
                    switchCase(button, input);
                
                }
                else if(SW4 == 1){
                    button = 3;
                    //leds = 3;
                    switchCase(button, input);
                
                }
                else if(SW2 == 1 && SW3 == 1){
                    button = 4;
                    //leds = 4;
                    switchCase(button, input);
                
                }
                else{
                    //leds = 7;     leds are for troubleshooting hence are commented out
                }
        }
                
        for(int count = 0; count < 4; count++){
            if(input[count] == correctSequence[count]){
                score++;
            }
            else{}
        }
                   
        if(score == 4){    
            for(int count = 0; count < 3; count++){
                leds = 4;
                wait_us(500000);
                leds = 0;
                wait_us(500000);
                
            }    
        }    
        else{
            leds = 1;
            alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
            wait_us(timeDelay * 10);
            alarm.rest();            
        }
        
        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}
  
        
            


