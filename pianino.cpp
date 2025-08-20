int czest[] = {14,15,16,17};
int nr_p_w = 2; //numer pierwszego wiersza
int nr_ost_w = 3; //numer ostatniego wiersza
int nr_p_k = 4; //numer pierwszej kolumny
int nr_ost_k = 5; //numer ostatniej kolumny
void setup() {
  Serial.begin(9600);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  

  // Ustawienie wierszy jako OUTPUT i początkowo HIGH
  for (int w = nr_p_w; w <= nr_ost_w; w++) {
    pinMode(w, OUTPUT);
    digitalWrite(w, HIGH);
  }

  // Ustawienie kolumn jako INPUT_PULLUP
  for (int c = nr_p_k; c <= nr_ost_k; c++) {
    pinMode(c, INPUT_PULLUP);
  }
}

void loop() {
  for (int w = nr_p_w; w <= nr_ost_w; w++) {
    // Aktywacja wiersza
    digitalWrite(w, LOW);
    delayMicroseconds(10); // stabilizacja

    for (int c = nr_p_k; c <= nr_ost_k; c++) {
      if(digitalRead(c) == LOW)
         {
        	Serial.println(w);
        	Serial.println(c);
        	
      		//tone(19, czest[(w-1-1)*(5-4+1)+c-3-1], 100);
        	digitalWrite(czest[(w-nr_p_w)*(nr_ost_k-nr_p_k+1)+c-nr_p_k],HIGH);
         }
      
      
    }

    // Dezaktywaa wiersza
    digitalWrite(w, HIGH);
  }

  delay(50); // niewielka przerwa między skanowaniem
}
