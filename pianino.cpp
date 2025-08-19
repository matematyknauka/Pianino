int licznik = 0;
int czest[] = {14,15,16,17};
void setup() {
  Serial.begin(9600);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  

  // Ustawienie wierszy jako OUTPUT i początkowo HIGH
  for (int w = 2; w <= 3; w++) {
    pinMode(w, OUTPUT);
    digitalWrite(w, HIGH);
  }

  // Ustawienie kolumn jako INPUT_PULLUP
  for (int c = 4; c <= 5; c++) {
    pinMode(c, INPUT_PULLUP);
  }
}

void loop() {
  licznik = 0;
  for (int w = 2; w <= 3; w++) {
    // Aktywacja wiersza
    digitalWrite(w, LOW);
    delayMicroseconds(10); // stabilizacja

    for (int c = 4; c <= 5; c++) {
      if(digitalRead(c) == LOW)
         {
        	Serial.println(w);
        	Serial.println(c);
        	
      		//tone(19, czest[(w-1-1)*(5-4+1)+c-3-1], 100);
        	digitalWrite(czest[(w-1-1)*(5-4+1)+c-3-1],HIGH);
         }
      
      
    }

    // Dezaktywaa wiersza
    digitalWrite(w, HIGH);
  }

  delay(50); // niewielka przerwa między skanowaniem
}
