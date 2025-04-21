
// Function to convert string to a string of binary nums
String binary = "";
String getBinary(String word) {
  
  for (int i = 0; i < word.length(); i++) {
    // Get ASCII (American Standard Code for Information Interchange) value of character
    char c = word.charAt(i);
    
    // Each letter is 7 bits
    for (int j = 7; j >= 0; j--) {
    // shift right by j. Then AND with 1. This will make each bit the most significant and then append it.
      if ((c >> j) & 1) {  
        binary += '1';  // If the bit is 1, append 1
      } else {
        binary += '0';  // If the bit is 0, append 0
      }
    }
  }

  return binary;
  delay(4000);  // delay 4 second
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------
int laserPin = 13;

void setup() {
  // put your setup code here, to run once:
  // Start the serial communication at 9600 baud rate
  Serial.begin(9600);
  pinMode(laserPin, OUTPUT);  // Define the digital output interface pin 13 
  

  String word = "Hello";
  String binary = getBinary(word);
  Serial.println('\n'+binary);
  
}

int num = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (num == 0){ // start condition
    digitalWrite(laserPin, HIGH); // Turn on the laser
    delay(500); // wait for 1/2 second
    digitalWrite(laserPin, LOW); // Turn off the laser
    delay(500); // wait for 1/2 second
  }
  

  if (binary[num] == '1'){
    digitalWrite(laserPin, HIGH); // Turn on the laser
	  delay(500); // wait for 1/2 second
  }else if(binary[num] == '0'){
    digitalWrite(laserPin, LOW); // Turn off the laser
	  delay(500); // wait for 1/2 second
  }

  num++;

  if (num == strlen(binary.c_str())){ // stop condition
    digitalWrite(laserPin, HIGH); // Turn off the laser
    delay(2500); // wait for 2.5 seconds to have 5 1s
    digitalWrite(laserPin, LOW); // Turn off the laser
    exit(0);  // exit loop
  }
  

}
