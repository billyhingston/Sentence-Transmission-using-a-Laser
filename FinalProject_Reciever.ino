

int receiverPin = 2; // pin 2 for reciever
int start = 0; // for start condition
int stop = 0;// for stop condition

//----------------------------------------------------------------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(receiverPin, INPUT);

}

//----------------------------------------------------------------------------------------------------------------------

String binary = "";
void loop() {
  // put your main code here, to run repeatedly:
  int detect_light = digitalRead(receiverPin); // read laser sensor
  
  if ((start == 0)&&(detect_light == HIGH)){
    start = 1;

  }

  if((detect_light == HIGH)&&(start == 1)){
    Serial.println("Binary " + binary);
    binary += '1';  // If the bit is 1, append 1
    stop = stop + 1; // increment stop

  }else if((detect_light == LOW)&&(start == 1)&&(stop < 5)){
    Serial.println("Binary " + binary);
    binary += '0';  // If the bit is 0, append 0
    stop = 0; // reset stop

  }

  // STOP condition
  // longest section of 1s possible when converting words to binary is 4 1s. When 5 ones in a row are detected, stop.
  if ((stop >= 5)&&(start == 1)&&(detect_light == LOW)) { 
    // remove the first 2 charcters from binary (after start condition, 2 invalid characters are appended to binary). 
    String newBinary = binary.substring(2);
    // remove the 1 0 and 5 1s at the end. (6 characters)

    newBinary = newBinary.substring(0, newBinary.length() - 5);

    Serial.println("newBinary " + newBinary);

    while (true); // halt program
  }

  delay(500);

}
