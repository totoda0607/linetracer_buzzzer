// Define pins for motor control
int motor_A1 = 5;
int motor_A2 = 6;
int motor_B1 = 10;
int motor_B2 = 9;

// Define pins for IR sensors
int IR_left = A0;
int IR_left_mid = A1;
int IR_right_mid = A2;
int IR_right = A3;

// Define pins for buzzer
int buzzer_pin = 3;

// Define threshold values for IR sensors
int IR_left_thres = 700;
int IR_left_mid_thres = 700;
int IR_right_mid_thres = 700;
int IR_right_thres = 700;

void setup() {
  // Set motor control pins as output
  pinMode(motor_A1, OUTPUT);
  pinMode(motor_A2, OUTPUT);
  pinMode(motor_B1, OUTPUT);
  pinMode(motor_B2, OUTPUT);
  
  // Set buzzer pin as output
  pinMode(buzzer_pin, OUTPUT);
  
  // Set IR sensor pins as input
  pinMode(IR_left, INPUT);
  pinMode(IR_left_mid, INPUT);
  pinMode(IR_right_mid, INPUT);
  pinMode(IR_right, INPUT);
  Serial.print("Start");
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int sensor_L = analogRead(IR_left);
  int sensor_LM = analogRead(IR_left_mid);
  int sensor_RM = analogRead(IR_right_mid);
  int sensor_R = analogRead(IR_right);

  // Check if there is an obstacle
  if (sensor_L < IR_left_thres || sensor_R < IR_right_thres) {
    stop();
    play_song();
  }
  else {
    // Move the car forward
    digitalWrite(motor_A1, HIGH);
    digitalWrite(motor_A2, LOW);
    digitalWrite(motor_B1, HIGH);
    digitalWrite(motor_B2, LOW);
  }
}

void stop() {
  // Stop the car
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, LOW);
}

void play_song() {
  // Play Elise by Beethoven
  int notes[] = {330, 294, 262, 294, 330, 330, 330, 294, 294, 294, 330, 392, 392, 330, 294, 262, 294, 330, 330, 330, 330, 294, 294, 330, 294, 262};
  int durations[] = {200, 200, 200, 200, 200, 200, 400, 200, 200, 400, 200, 200, 400, 200, 200, 200, 200, 200, 400, 200, 200, 200, 200, 200, 200, 200, 400};
  
  // Play each note for its duration
  for (int i = 0; i < 27; i++) {
    int duration = durations[i];
    tone(buzzer_pin, notes[i], duration);
    delay(duration);
  }
  
  // Stop playing the song
  noTone;
}
