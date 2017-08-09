

// These constants won't change.  They're used to give names
// to the pins used:


int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int sensorValue3 = 0;        // value read from the pot
int sensorValue4 = 0;        // value read from the pot

boolean message1;
boolean message2;
boolean message3;
boolean message4;
boolean message5;
boolean message6;
boolean message7;
boolean message8;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);   // this is the USB serial communication
  Serial1.begin(9600);  // tx/rx communication. This will be connectedd to the bluetooth device

  //pinMode(A10, INPUT_PULLUP);
}

void loop() {
  // read the analog in value:
  sensorValue1 = analogRead(A10);
  sensorValue2 = analogRead(A9);
  sensorValue3 = analogRead(A7);
  sensorValue4 = analogRead(A11);


// print the reading from the sensor to USB serial
  Serial.println(sensorValue1);
  
  // here is calculation of triggering
  // if you send 1, then the sound gets triggered.
  // for example...

  if (sensorValue1 > 500){
    message1 =1;
  }
  if (sensorValue1 < 200){
    message1 =0;
  }

  // note: all the messages are boolean (1 or 0).
  // 1 will trigger the sound and 0 will reset the trigger
 


  // send the message over bluetooth to the max/msp patch to trigger sounds
 
  Serial1.write((byte)0);   // start of the message
  Serial1.write(1);         // index of the message
  Serial1.print(message1);  // content of the message
  Serial1.println();        // end of the message

  Serial1.write((byte)0);
  Serial1.write(2);
  Serial1.print(message2);
  Serial1.println();

  Serial1.write((byte)0);
  Serial1.write(3);
  Serial1.print(message3);  
  Serial1.println();

  Serial1.write((byte)0);
  Serial1.write(4);
  Serial1.print(message4);  
  Serial1.println();

  Serial1.write((byte)0);
  Serial1.write(5);
  Serial1.print(message5);
  Serial1.println();

  Serial1.write((byte)0);
  Serial1.write(6);
  Serial1.print(message6);
  Serial1.println();

  Serial1.write((byte)0);
  Serial1.write(7);
  Serial1.print(message7);  
  Serial1.println();

  Serial1.write((byte)0);
  Serial1.write(8);
  Serial1.print(message8);  
  Serial1.println();

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);
}
