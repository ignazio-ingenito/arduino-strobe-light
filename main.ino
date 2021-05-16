const byte ledLeft = 8;
const byte ledRight = 4;
const byte ledTail = 5;

const byte switchPin = 2;
const long debounce_msecs = 200;
long program = 0;

void runProgram0() {
  Serial.print("runProgram0\n");  
  digitalWrite(ledLeft, HIGH);
  digitalWrite(ledRight, HIGH);
  digitalWrite(ledTail, HIGH);
  delay(40);
  digitalWrite(ledLeft, LOW);
  digitalWrite(ledRight, LOW);
  digitalWrite(ledTail, LOW);
  delay(1460);  
}

void runProgram1() {
  Serial.print("runProgram1\n");  
  digitalWrite(ledLeft, HIGH);
  delay(25);
  digitalWrite(ledLeft, LOW);
  delay(100);
  digitalWrite(ledLeft, HIGH);
  delay(25);
  digitalWrite(ledLeft, LOW);
  delay(350);
  digitalWrite(ledRight, HIGH);
  delay(25);
  digitalWrite(ledRight, LOW);
  delay(100);
  digitalWrite(ledRight, HIGH);
  delay(25);
  digitalWrite(ledRight, LOW);
  delay(350);
  digitalWrite(ledTail, HIGH);
  delay(25);
  digitalWrite(ledTail, LOW);
  delay(100);
  digitalWrite(ledTail, HIGH);
  delay(25);
  digitalWrite(ledTail, LOW);
  delay(350);
}

void runProgram2() {
  Serial.print("runProgram2\n");  
  digitalWrite(ledLeft, HIGH);
  delay(100);
  digitalWrite(ledLeft, LOW);
  digitalWrite(ledRight, HIGH);
  delay(100);
  digitalWrite(ledRight, LOW);
  digitalWrite(ledTail, HIGH);
  delay(100);
  digitalWrite(ledTail, LOW);
}

void runProgram3() {
  Serial.print("runProgram3\n");  
  digitalWrite(ledLeft, HIGH);
  delay(10);
  digitalWrite(ledLeft, LOW);
  delay (70);
  digitalWrite(ledRight, HIGH);
  delay(10);
  digitalWrite(ledRight, LOW);
  delay (70);
  digitalWrite(ledTail, HIGH);
  delay(10);
  digitalWrite(ledTail, LOW);
  delay (70);
}

void runProgram4() {
  Serial.print("runProgram4\n");  
  digitalWrite(ledLeft, HIGH);
  delay(10);
  digitalWrite(ledLeft, LOW);
  delay (90);
  digitalWrite(ledLeft, HIGH);
  delay(10);
  digitalWrite(ledLeft, LOW);
  delay (90); 
  digitalWrite(ledLeft, HIGH);
  delay(10);
  digitalWrite(ledLeft, LOW);
  delay (90); 
  digitalWrite(ledLeft, HIGH);
  delay(10);
  digitalWrite(ledLeft, LOW);
  delay (90); 
  digitalWrite(ledLeft, HIGH);
  delay(10);
  digitalWrite(ledLeft, LOW);
  delay (90);
  digitalWrite(ledRight, HIGH);
  delay(10);
  digitalWrite(ledRight, LOW);
  delay (90);
  digitalWrite(ledRight, HIGH);
  delay(10);
  digitalWrite(ledRight, LOW);
  delay (90); 
  digitalWrite(ledRight, HIGH);
  delay(10);
  digitalWrite(ledRight, LOW);
  delay (90); 
  digitalWrite(ledRight, HIGH);
  delay(10);
  digitalWrite(ledRight, LOW);
  delay (90); 
  digitalWrite(ledRight, HIGH);
  delay(10);
  digitalWrite(ledRight, LOW);
  delay (90);
  digitalWrite(ledTail, HIGH);
  delay(10);
  digitalWrite(ledTail, LOW);
  delay (90);
  digitalWrite(ledTail, HIGH);
  delay(10);
  digitalWrite(ledTail, LOW);
  delay (90); 
  digitalWrite(ledTail, HIGH);
  delay(10);
  digitalWrite(ledTail, LOW);
  delay (90); 
  digitalWrite(ledTail, HIGH);
  delay(10);
  digitalWrite(ledTail, LOW);
  delay (90); 
  digitalWrite(ledTail, HIGH);
  delay(10);
  digitalWrite(ledTail, LOW);
  delay (90);
}

void runProgram5() {
  Serial.print("runProgram5\n");  
  digitalWrite(ledLeft, HIGH);
  digitalWrite(ledRight, HIGH);
}

void (* programs[])() = {
  runProgram0,   
  runProgram1, 
  runProgram2, 
  runProgram3,  
  runProgram4,
  runProgram5
};
 

void setup() {
  Serial.begin(9600);
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);
  pinMode(ledTail, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(switchPin), changeProgram, CHANGE);
}

void loop() {
  // handles the exceptions
  if (program >= sizeof(programs)/2)
    program = 0;

  // run the current program
  programs[program]();
}

void changeProgram() {
  // set the latest timeout for debiuncing to zero
  static unsigned long last_interrupt = 0;
  // get the actual timestamp
  unsigned long interrupt_time = millis();

  // if an interrupts come faster than debounce_msecs
  // I'm assuming it's a bounce so I'll ignore it
  if (interrupt_time - last_interrupt < debounce_msecs)
    Serial.print("bounce ignored\n");
  else
    program++;

  last_interrupt = interrupt_time;
}
