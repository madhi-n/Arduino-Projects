
 const int row[8] = {
   2, 7, 19, 5, 13, 18, 12, 16
};

 const int col[8] = {
   6, 11, 10, 3, 17, 4, 8, 9
};
bool right = true;

void setup() {
  
    Serial.begin(9600);
    for(int i = 0;i<8;i++){
      pinMode(col[i], OUTPUT);
      pinMode(row[i], OUTPUT);
    }
}

void loop() {
  for(){
    for (int i = 0; i <= 7;i++){
      digitalWrite(col[i],HIGH);
      for(int x = 1;x<=7;x++){
        digitalWrite(row[x],HIGH);
      }
      delay(200);
      digitalWrite(col[i],LOW);
    }
    
    clear();
    
    digitalWrite(col[7],HIGH);
    for(int i = 0;i <= 7;i++){
      digitalWrite(row[i],HIGH);
    }
    for(int i = 1;i <= 7;i++){
      digitalWrite(row[i],LOW);
      delay(200);
      digitalWrite(row[i],HIGH);
    }
    
    clear();
    
    for (int i = 6; i >=1;i--){
      digitalWrite(col[i],HIGH);
      for(int x = 0;x<=6;x++){
        digitalWrite(row[x],HIGH);
      }
      delay(200);
      digitalWrite(col[i],LOW);
    }
    
    clear();
    
    digitalWrite(col[0],HIGH);
    for(int i = 0;i <= 7;i++){
      digitalWrite(row[i],HIGH);
    }
    for(int i = 7;i >= 1;i--){
      digitalWrite(row[i],LOW);
      delay(200);
      digitalWrite(row[i],HIGH);
    }
  }
}




void clear(){
  for(int i = 0;i<8;i++){
    digitalWrite(col[i],LOW);
    digitalWrite(row[i],LOW);
  }
}