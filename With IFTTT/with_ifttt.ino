int speakerPin = D3;
int ledPin = D2;
int forcePin = A2;
int bentPin = A0;
// create an array for the notes in the melody:
//C4,G3,G3,A3,G3,0,B3,C4
int melody[] = {1908,2551,2551,2273,2551,0,2024,1908}; 

// create an array for the duration of notes.
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4,8,8,4,4,4,4,4 };

int forceReading = 0;
int bentReading = 0;

void setup() {
    pinMode( speakerPin, OUTPUT ); // buzzer
    pinMode( ledPin, OUTPUT ); // Led
  
    Particle.variable("force", &forceReading, INT);
    Particle.variable("bent", &bentReading, INT);
}

void loop() {
    // playNotes();
    forceReading = analogRead(forcePin);
    bentReading = analogRead(bentPin);
    // delay(1000);

    if (forceReading > 2000 && bentReading > 700) {
        playNotes();
        Particle.publish("detect_force", String(forceReading));
    } else if (bentReading > 700 ) {
        digitalWrite(ledPin, HIGH);
        delay(1500);
        digitalWrite(ledPin, LOW);
        delay(500);
    } else {
        digitalWrite(ledPin, LOW);
    }
}

void playNotes()
{
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.digitalWrite(ledPin, LOW);
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000/noteDurations[thisNote];
      tone(speakerPin, melody[thisNote],noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(speakerPin);
    }
}








