//Step Motors
void oneStep(int BTNONOFF,int IN1,int IN2,int IN3,int IN4) {
  switch (states) {
    case 0:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      if (digitalRead(BTNONOFF) == HIGH) {
        states = 1;
      }
      delay(dT);
      break;
    case 1:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      states = 2;
      delay(dT);
      break;
    case 2:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      states = 3;
      delay(dT);
      break;
    case 3:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      states = 0;
      delay(dT);
      break;
  }
}
void Rotation(int IN1,int IN2,int IN3,int IN4) {
  switch (states) {
    case 0:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      states = 1;
      break;
    case 1:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      states = 2;
      break;

    case 2:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      states = 3;
      break;


    case 3:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      states = 0;
      break;
  }
  delay(dT);
}
void Regulation(int PINPOT,int BTNONOFF,int IN1,int IN2,int IN3,int IN4) {
  pot = analogRead(PINPOT);
  pause = map(pot, 0, 1023, 3, 100);
  if (onClick(BTNONOFF) == HIGH) {
    states++;
    if (states > 7) states = 0;
  }
  switch (states) {
    case 0:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 1:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 2:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 3:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 4:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      break;
    case 5:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case 6:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case 7:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
  }
  delay(pause);
}
void RegulationReverse(int PINPOT,int BTNONOFF,int IN1,int IN2,int IN3,int IN4) {
  pot = analogRead(PINPOT);
  if (onClick(BTNONOFF) == HIGH) {
    if (pot >= 0 && pot <= 511) {
      states++;
      if (states > 3) states = 0;
      pause = map(pot, 0, 512, 2, 100);
    } else if (pot >= 512 && pot <= 1023) {
      states--;
      if (states < 0) states = 3;
      pause = map(pot, 1023, 512, 2, 100);
    }
    switch (states) {
      case 0:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
      case 1:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break;
      case 2:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
        break;
      case 3:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;
    }
    delay(pause);
  }
}
void PotMove(int PINPOT,int IN1,int IN2,int IN3,int IN4) {
  pot = analogRead(PINPOT);
  static int potprev = analogRead(PINPOT);
  if (pot - potprev > -2 && pot - potprev > 2) {
    Serial.println("Left");
    states++;
    if (states > 3) states = 0;
    pause = map(pot, 0, 512, 2, 100);
  } else if (pot - potprev > -2 && pot - potprev > 2) {
    Serial.println("Right");
    states--;
    if (states <= 0) states = 3;
    pause = map(pot, 1023, 512, 2, 100);
  } else {
    {
      Serial.println("None");
    }
  }
  switch (states) {
    case 0:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 1:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 2:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      break;
    case 3:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
  }
  potprev = pot;
  delay(pause);
}
