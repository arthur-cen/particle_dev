int led1 = D2;
int led2 = D3;

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
}

void loop() {
    // digitalWrite(led1, HIGH);
    //delay(1000) //blink for one second
    // delay(3000);
    
    // digitalWrite(led1, LOW);
    //delay(1000) //blink for one second
    // delay(3000);
    for (int i=0; i<5; i++) {
        digitalWrite(led1, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        delay(500);

        digitalWrite(led2, HIGH);
        delay(500);
        digitalWrite(led2, LOW);
        delay(500);
    }
}