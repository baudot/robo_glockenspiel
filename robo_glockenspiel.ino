#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
#define d4 3
#define e4 4
#define f4 5
#define a5 6

int distance = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  pinMode(d4, OUTPUT);
  pinMode(e4, OUTPUT);
  pinMode(f4, OUTPUT);
  pinMode(a5, OUTPUT);
}

void loop() {
  distance = (sonar.ping_cm());
  if (distance != 0 && distance < 30) {
    Serial.println("Person Detected");
    play_song();
    while (distance < 50) {
      distance = sonar.ping_cm();
      Serial.println(distance); // Don't play again if the person hasn't left.
    }
  }
}


void play_song() {
  pling(d4, 1000);
  pling(d4, 500);
  pling(a5, 250);
  pling(a5, 750);
  pling(a5, 500);
  pling(e4, 750);
  pling(f4, 250);
  pling(e4, 500);
  pling(d4, 3000);
}

void pling(int note, int duration) {
  digitalWrite(note, HIGH);
  delay(50);
  digitalWrite(note, LOW);
  delay(duration);
}

