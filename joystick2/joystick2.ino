// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
int counter = 0;
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
}

void loop() {
  counter++;
//  Serial.print("Switch:  ");
  int val = digitalRead(SW_pin);
  if(counter%10 == 0)
  {
    Serial.println(1);
    counter = 0;
  }
  if(val == 0)
  {
     Serial.println(val);
     delay(3000);
  }
//  Serial.print("\n");
//  Serial.print("X-axis: ");
//  Serial.print(analogRead(X_pin));
//  Serial.print("\n");
//  Serial.print("Y-axis: ");
//  Serial.println(analogRead(Y_pin));
//  Serial.print("\n\n");
    delay(10);
}
