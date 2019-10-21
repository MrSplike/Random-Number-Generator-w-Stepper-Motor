int rotationspeed = 7;
int stepperpins[4] = {8, 9, 10, 11};
int clockdegrees[12] = {0, 35, 65, 90, 120, 151, 187, 214, 242, 270, 299, 330};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int i;
  for (i = 0; i <= 3; i++){
    pinMode(stepperpins[i], OUTPUT);
  }
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int orient = digitalRead(12);
  int j;
  int i = 0;
 
  while(orient == 1){
    for (j = 0; j <= 3; j++){
      digitalWrite(stepperpins[j], HIGH);
    }
    
    digitalWrite(stepperpins[i%4], LOW);
    i++;
    
    orient = digitalRead(12);
    delay(rotationspeed);
  }
  
  delay(500);
  
  int degree = 0;
  int ii = 0;
  int previous = 0;
  int clockposition = random(1, 12);
  int rotationdegree = clockdegrees[clockposition];
  float steps = rotationdegree/1.8;
  
  for (ii = steps; ii >= previous; ii--){
    for (j = 0; j <= 3; j++){
      digitalWrite(stepperpins[j], HIGH);
    }
    
    digitalWrite(stepperpins[ii%4], LOW);
    previous = ii%4;
    delay(rotationspeed);
  }
  
  delay(1000);
 
  int button = digitalRead(13);
  while(button == 1){
    button = digitalRead(13);
    Serial.println(button);
  }  
  
}
