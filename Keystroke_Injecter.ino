#include <Keyboard.h>

/*
This code is used to inject keystrocks to any device which supports USB Keyboard.
This can be used to spam messages in facebook messanger, whatsapp etc.
It is recommended to use it in a computer(Whatsapp, Facebook), As sometimes samartphone cannot be fast enough.
Here I'm using Arduino Keyboard Library, So It can work with Pro Mocro, Leonardo and Due boards.
Download the required library from this GitHub link https://github.com/arduino-libraries/Keyboard and include into your sketch
If using whatsapp mobile, then change the setting->Chats, Under chat setting, Enable "Enter is send"

Connection:

          One pin of the Push Button ---> Pin No. 6
          Second Pin of Push Button  ---> Ground
          Led ---> pin No. 7

Setup Steps:-
1. Connect Pro Micro or Leonardo to the compter, Select the Board as "Arduino Leonardo"
2. Import the Library from the zip file downloaded
3. Write the desired message
4. Upload the message

Trigger Steps:-
1. Connect the Microcontroller to the device, direct USB to a computer or though OTG for smartphone
2. Open the website or app and click on the text writting area
3. Press the push button attached to the microcontroller and enjoy.
 */

int button = 6;          //Launch Push Button
int x = 1;               //Text counter
int led = 7;             //Activation indicator LED
void setup(){
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop(){
  if(digitalRead(button)==LOW){              //Launch Text Injecton when button is pressed
    while(true){                             //No limit for message, You can set limit if you want, just provide contion to the loop
      digitalWrite(led, HIGH);               //Turn on the indicator Led
      Keyboard.print(x);                     //Shows the Text No. You can remove if you want
      Keyboard.print(": Hi Bro! Whatsup!");  //The actual Message to be injected
      Keyboard.press(KEY_RETURN);            //After writing the text press the "Enter" button to send the message
      delay(1);                              //Remove the delay of face and problem
      Keyboard.releaseAll();
      x++;                                   
      delay(100);                           //Try different delay time and use the one suits your phone
    }
  }
}
