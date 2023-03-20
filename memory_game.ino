
int gametime = 0;
int ledNumber = 2;
int ledSequence[15]=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]; //array to store the led sequence
int inputSequence[15]=[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1];//array to store the input sequence from the user 

// if the sequence is correct, the buzzer will sound the all the leds will flash sequencially
void correct(){	
  
  for(int i=0;i<6;i++){
    digitalWrite(A4,HIGH);
    
    for(int j=2;j<8;j++){
      digitalWrite(i,HIGH);}
     
    delay(100);
    
    digitalWrite(A4,LOW);
  	
    for(int j=2;j<8;j++){
    	digitalWrite(i,LOW);}
  	
    delay(100);
  }
}

//if the sequence is incorrect, then the buzzer will sound and all the led will glow together  
  void incorrect(){
    
    digitalWrite(A4,HIGH);
    
    for (int i=8; i<14; i++){
      digitalWrite(i,HIGH);
    }
    
    delay(1500);
    
    for (int i=8; i<14; i++){
      digitalWrite(i,LOW);
    }
    digitalWrite(A4,LOW);
  }




void setup() {
  // decalring the digital pins for the leds
  for (int i=2; i<8; i++){
    pinMode(i, OUTPUT):
  }

  //declaring the digial pins for the pushbuttons
  for (int i=8; i<14; i++){
    pinMode(i, INPUT):
  }

  //declaring the pin for the buzzer
  pinMode(A4, OUTPUT);
   
  Serial.begin(9600);

  //using the ransomseed command to use to generate the ranom led sequnece
  randomSeed(analogRead(A0));

}


void loop() {
    
  int score=0;
  gametime = millis(); //setting the value of gametime using millis() function to determine how 
  //long the led sequence light up for
  
  int temp = 0; //temp variable which will be used to set the led sequence array index
  
 //loop to light up leds randomly 
  while(millis() - gametime <= 4000){    
    ledNumber = random(2,8); //usin the random fucntion tpo choose an led digital pin b/w 2 to 8
    Serial.println(ledNumber); //printing to the console the led that light ups for deugging purpose
    
    digitalWrite(ledNumber, HIGH);
    delay(400);
    digitalWrite(ledNumber, LOW);
    delay(200);
    score++;
    
    ledSequence[temp]=ledNumber-1;//adding the led which was just high to the ledSequence
    temp+=1; // adding ++1 to the led sequence
    
  }
    
  Serial.println("loop end"); //printing the led loop has ended the serial monitor for debugging
  

//printing the led sequence in order the leds were high
  for(int i=0;i<7;i++){
     Serial.print(ledSequence[i]);
  }
  
  delay(3000);
  Serial.println();
  
  

  //loop to check the input from user  
  Serial.println();
  gametime = millis(); //updating the gametime variable to determine time to for input sequence
  
  int k=0; // a temp variale to set the index for the inputSequence array
     
  Serial.println("input enter"); /
  
  //while loop for taking the input from the user
  while(millis()-gametime <= 5000){
    
    //checking dgiital pins from 8 to 13 for input from the user and if one of the button is high, then
    //add it to the inputSequence array, then adding 1 to the k variale to shift the array index
    for(int i=8; i<14; i++){  
      if(digitalRead(i) == HIGH){
        inputSequence[k]=i-6;
          k++;
      }
      
    }
   
  }
  
  Serial.println("input display");
  
  //printing the inputSequence taken from the user
  for (int i=0; i<8; i++){
  	Serial.print(inputSequence[i]);
  }
  
  delay(1000);
  
  Serial.println();
  
  Serial.println("checking input");
    
//integer varialble to check same values of both arrays
  int inputScore=0;
  //loop to compare the same index from the both the array
  for (int i=0; i<16; i++){
    if (ledSequence[i]==inputSequence[i]){
      inputScore++;}
  }
  Serial.println(score);

  //loop to check the score 
  if (score==inputScore){
   correct();
   
  }
  else{
    incorrect();
    
  }
  delay(2000);

}
