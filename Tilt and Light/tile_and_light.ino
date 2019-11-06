//Setup led pin
int led1 = D2; //yellow
int led2 = D3; //blue
//Setup tilt sensor Pin
int tiltPin = D4;
//Setup tilt value
int tilt = 0;

int photoCellPin = A0;
int photoCellReading = 0;
int ledBrightness = 0;

void setup() {
    //setup pin mode for led and tilt
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(tiltPin, INPUT);
    
    Particle.variable("light", &photoCellReading, INT);
    Particle.variable("tilt", &tilt, INT);

    //set digit 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
}

void loop() {
    //if tilted, change the light color
    photoCellReading = analogRead(photoCellPin);
    ledBrightness = 255 - map(photoCellReading, 0, 4095, 0, 255);
    
    tilt = digitalRead(tiltPin);
    if (tilt) {
        // digitalWrite(led1, tilt);
        analogWrite(led1, ledBrightness);    
        digitalWrite(led2, LOW);
    } else {
        // digitalWrite(led2, 1 - tilt);
        analogWrite(led2, ledBrightness);
        digitalWrite(led1, LOW);
    }
    
    delay(100);
}












