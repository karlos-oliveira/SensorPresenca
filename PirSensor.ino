int Relay = 2;
int Pir1 = 7;
int Pir2 = 8;
int Ldr = A0;               
int Seconds = 10;

bool isMotion(){
  int pir1 = digitalRead(Pir1);
  int pir2 = digitalRead(Pir2);
  
  if(pir1 == HIGH || pir2 == HIGH)  
    return true;

  return false;
}

bool isDark(){
  int lightIntensity = analogRead(Ldr);
  delay(10); 
  
  return (lightIntensity < 600);
}

void illuminate(){
    digitalWrite(Relay, HIGH);
    delay(Seconds * 1000);
    digitalWrite(Relay, LOW);
}

void setup()
{
  pinMode(Relay, OUTPUT);
  pinMode(Pir1, INPUT);
  pinMode(Pir2, INPUT);
  
  Serial.begin(9600);
}
 
void loop()
{
  if(isDark() && isMotion())
    illuminate();
}
