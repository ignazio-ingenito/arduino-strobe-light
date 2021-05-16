# Arduino Strobe Light Project
Arduino software to pilot the strobe lights of an aircraft

Use the Arduino web editor to write the program to your Arduino
You can also use [ThinkerCad](https://www.tinkercad.com/things/1QpaplXtcgZ-strobo-lights-latest/editel?sharecode=qQPAxqz-ONBvJWn7J_PZm7cocWdgge_66UVqOO47ABI) to see this software in actiono without any Arduino.

### Circuit layout
![Circuit layout](https://user-images.githubusercontent.com/25493712/118394996-e9677b00-b63f-11eb-9959-68397646d7a7.png "Circuit layout")

### Programs
This code provide 6 different programs, you've only to press the switch to go through all of them

#### To add your own program

Add your own code in a new function
```
void runProgramX() {
  Serial.print("runProgramX\n");  
  digitalWrite(ledLeft, HIGH);
  digitalWrite(ledRight, HIGH);
  digitalWrite(ledTail, HIGH);
  ...
}
```

Add your function to the function pointers array
```
void (* programs[])() = {
  runProgram0,   
  runProgram1, 
  runProgram2, 
  runProgram3,  
  runProgram4,
  runProgram5,
  runProgramX
};
```
