/*
 Title:		      terminal.ino
 Author:	      Badre
 Last Updated:	26/10/2024
*/

void setup() {
  //mySerial.begin(115200);
  Serial1.begin(115200);
  Serial.begin(115200);
  delay(1000);
 
}

void loop()
{
 
  if (Serial1.available() > 0)
  {
    int c = Serial1.read();   
    Serial.write(c);  // Lit le message reçu et l'affiche sur le moniteur
  }
   delay(1);
}
