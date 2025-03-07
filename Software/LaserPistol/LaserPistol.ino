const int PIN_TRIGGER = 32;
const int PIN_RELOAD = 33;
const int PIN_LASER = 25;


const unsigned int DELAY_FROM_BUTTON_TO_LASER_MICROSECONDS = 6000;
const unsigned int LASER_PULSE_DURATION_MICROSECONDS = 30000;

const int INTERNAL_LED_PIN = 22;



const int STATE_NOT_LOADED = 1;
const int STATE_LOADING_LEVER_UP = 2;
const int STATE_LOADED = 3;
const int STATE_SIGHTING = 4;



int state = STATE_NOT_LOADED;


void  printState(int state) {
  if (state == STATE_NOT_LOADED) {
    Serial.print("NOT_LOADED");
  } else if (state == STATE_LOADING_LEVER_UP) {
    Serial.print("LOADING_LEVER_UP");
  } else if (state == STATE_LOADED) {
    Serial.print("LOADED");
  } else if (state == STATE_SIGHTING) {
    Serial.print("SIGHTING");
  } else {
    Serial.print("UNKNOWN");
  }

}


void setState(int new_state) {
  Serial.print("Changing from state ");
  printState(state);
  Serial.print(" to ");
  printState(new_state);
  Serial.println("");
  state = new_state;
  // Avoid state trashing (eg by switch bounce)
  delayMicroseconds(1000);
}




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("BOOTED");

  pinMode(PIN_TRIGGER, INPUT_PULLUP);
  pinMode(PIN_RELOAD, INPUT_PULLUP);
  pinMode(PIN_LASER, OUTPUT);
  pinMode(INTERNAL_LED_PIN, OUTPUT);

  digitalWrite(PIN_LASER, LOW);
  digitalWrite(PIN_RELOAD, HIGH);
  digitalWrite(PIN_TRIGGER, HIGH);

  if (digitalRead(PIN_TRIGGER) == LOW) {
     setState(STATE_SIGHTING);
  }

  digitalWrite(INTERNAL_LED_PIN, LOW);

  Serial.println("READY");
}






void loop() {
  // put your main code here, to run repeatedly:

  bool trigger_pressed = digitalRead(PIN_TRIGGER) == LOW;
  bool loading_lever_up = digitalRead(PIN_RELOAD) == LOW;
  
  if (state == STATE_SIGHTING) {
    analogWrite(PIN_LASER, 64);
    if (loading_lever_up == true) {
      pinMode(PIN_LASER, OUTPUT);
      digitalWrite(PIN_LASER, LOW);
      setState(STATE_LOADING_LEVER_UP);
    }
  }

  if (state == STATE_NOT_LOADED) {
    if (loading_lever_up == true) {
      setState(STATE_LOADING_LEVER_UP);
    }
  }

  if (state == STATE_LOADING_LEVER_UP) {
    if (loading_lever_up == false) {
      setState(STATE_LOADED);
    }
  }

  if (state == STATE_LOADED) {
    if (trigger_pressed == true) {
      Serial.println("FIRING");
      delayMicroseconds(DELAY_FROM_BUTTON_TO_LASER_MICROSECONDS);
      digitalWrite(PIN_LASER, HIGH);
      delayMicroseconds(LASER_PULSE_DURATION_MICROSECONDS);
      digitalWrite(PIN_LASER, LOW);
      Serial.println("FIRING_DONE");
      setState(STATE_NOT_LOADED);
    }
  }
  delayMicroseconds(1);
}
