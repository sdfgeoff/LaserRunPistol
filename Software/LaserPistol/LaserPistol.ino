const int PIN_TRIGGER = 32;
const int PIN_RELOAD = 33;
const int PIN_LASER = 25;


const unsigned int DELAY_FROM_BUTTON_TO_LASER_MICROSECONDS = 6000;
const unsigned int LASER_PULSE_DURATION_MICROSECONDS = 30000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("BOOTED");

  pinMode(PIN_TRIGGER, INPUT_PULLUP);
  pinMode(PIN_RELOAD, INPUT_PULLUP);
  pinMode(PIN_LASER, OUTPUT);

  digitalWrite(PIN_LASER, LOW);
  digitalWrite(PIN_RELOAD, HIGH);
  digitalWrite(PIN_TRIGGER, HIGH);
  

  Serial.println("READY");
}

bool loaded = false;

void loop() {
  // put your main code here, to run repeatedly:
  if (!loaded && digitalRead(PIN_RELOAD) == LOW) {
    Serial.println("RELOADING");
    loaded = true;
  }

  if (loaded && digitalRead(PIN_TRIGGER) == LOW) {
    loaded = false;
    Serial.println("FIRING");
    delayMicroseconds(DELAY_FROM_BUTTON_TO_LASER_MICROSECONDS);
    digitalWrite(PIN_LASER, HIGH);
    delayMicroseconds(LASER_PULSE_DURATION_MICROSECONDS);
    digitalWrite(PIN_LASER, LOW);
    Serial.println("Done");
  }

  delay(1);
}
