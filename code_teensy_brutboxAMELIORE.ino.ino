//Code Teensy Brutbox amélioré (stabilité des lectures analogiques)
//Mars 2019 A.Sacha SAKHAROV
 
 // the MIDI channel number to send messages
const int channel = 1;
 
// the MIDI continuous controller for each analog input
const int controllerA0 = 1; //
const int controllerA1 = 2; //
const int controllerA2 = 3; //
const int controllerA3 = 4; //
const int controllerA4 = 5; //
const int controllerA5 = 6; //
const int controllerA6 = 7; //
const int controllerA7 = 8; //
 
void setup() {
}
 
// store previously sent values, to detect changes
int previousA0 = -1;
int previousA1 = -1;
int previousA2 = -1;
int previousA3 = -1;
int previousA4 = -1;
int previousA5 = -1;
int previousA6 = -1;
int previousA7 = -1;
 
elapsedMillis msec = 0;
 
void loop() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
  if (msec >= 50) {
    msec = 0;
    int n0 = analogRead(A0) / 8;
    int n1 = analogRead(A1) / 8;
    int n2 = analogRead(A2) / 8;
    int n3 = analogRead(A3) / 8;
    int n4 = analogRead(A4) / 8;
    int n5 = analogRead(A5) / 8;    
    int n6 = analogRead(A6) / 8;
    int n7 = analogRead(A7) / 8;    
    int seuil = 2;
 
    // only transmit MIDI messages if analog input changed
    if (n0 != previousA0 && (abs(n0 - previousA0) > seuil)) {
      usbMIDI.sendControlChange(controllerA0, n0, channel);
      previousA0 = n0;
    }
    if (n1 != previousA1 && (abs(n1 - previousA1) > seuil)) {
      usbMIDI.sendControlChange(controllerA1, n1, channel);
      previousA1 = n1;
    }
    if (n2 != previousA2 && (abs(n2 - previousA2) > seuil)) {
      usbMIDI.sendControlChange(controllerA2, n2, channel);
      previousA2 = n2;
    }
    if (n3 != previousA3 && (abs(n3 - previousA3) > seuil)) {
      usbMIDI.sendControlChange(controllerA3, n3, channel);
      previousA3 = n3;
    }
    if (n4 != previousA4 && (abs(n4 - previousA4) > seuil)) {
      usbMIDI.sendControlChange(controllerA4, n4, channel);
      previousA4 = n4;
    }
    if (n5 != previousA5 && (abs(n5 - previousA5) > seuil)) {
      usbMIDI.sendControlChange(controllerA5, n5, channel);
      previousA5 = n5;
    }
 
    if (n6 != previousA6 && (abs(n6 - previousA6) > seuil)) {
      usbMIDI.sendControlChange(controllerA6, n6, channel);
      previousA6 = n6;
    }
    if (n7 != previousA7 && (abs(n7 - previousA7) > seuil)) {
      usbMIDI.sendControlChange(controllerA7, n7, channel);
      previousA7 = n7;
    }
 
 
  }
 
  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}

