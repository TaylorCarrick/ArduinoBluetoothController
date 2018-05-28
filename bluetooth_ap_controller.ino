char dataIn = 'S';        //Character/Data coming from the phone.
char determinant;         //Used in the check function, stores the character received from the phone.
char det;                 //Used in the loop function, stores the character received from the phone.
int velocity = 0;    //Stores the speed based on the character sent by the phone.

void setup() 
{       
//*************NOTE: If using Bluetooth Mate Silver use 115200 btu
//                   If using MDFLY Bluetooth Module use 9600 btu
Serial.begin(9600);  //Initialize serial communication with Bluetooth module at 115200 btu.
pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
   pinMode(13, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin

}

void loop()
{ 
    det = check();
      while (det == 'F')   //if incoming data is a F, move forward
      {     
             digitalWrite(12, HIGH);  
  digitalWrite(9, LOW);   
  analogWrite(3, 255);    //Spins the motor on Channel A at half speed
  
  //Motor B forward @ full speed
  digitalWrite(13, LOW); 
  digitalWrite(8, LOW);   
  analogWrite(11, 255);   //Spins the motor on Channel B at full speed
          det = check();          
      }  
      while (det == 'B')   //if incoming data is a B, move back
      {    
                  digitalWrite(12, LOW);  
  digitalWrite(9, LOW);   
  analogWrite(3, 255);    //Spins the motor on Channel A at half speed
  
  //Motor B forward @ full speed
  digitalWrite(13, HIGH); 
  digitalWrite(8, LOW);   
  analogWrite(11, 255);   //Spins the motor on Channel B at full speed
          det = check();          
      } 

      while (det == 'L')   //if incoming data is a L, move wheels left
      {     
             //Motor A forward @ full speed
  digitalWrite(12, LOW);  
  digitalWrite(9, HIGH);   
  analogWrite(3, 255);    //Spins the motor on Channel A at full speed
  
  //Motor B forward @ full speed
  digitalWrite(13, LOW); //Establishes forward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);   //Spins the motor on Channel B at full speed
          det = check();          
      }  
      while (det == 'R')   //if incoming data is a R, move wheels right
      {    
                       //Motor A forward @ full speed
  digitalWrite(12, HIGH);  
  digitalWrite(9, LOW);   
  analogWrite(3, 255);    //Spins the motor on Channel A at full speed
  
  //Motor B forward @ full speed
  digitalWrite(13, LOW); 
  digitalWrite(8, HIGH);   
  analogWrite(11, 255);   //Spins the motor on Channel B at full speed
          det = check();          
      }
     
    
      
      while (det == 'S')   //if incoming data is a S, stop
      {
                   //Motor A forward @ full speed
  digitalWrite(12, LOW);  
  digitalWrite(9, HIGH);   
  analogWrite(3, 255);    //Spins the motor on Channel A at half speed
  
  //Motor B forward @ full speed
  digitalWrite(13, LOW); 
  digitalWrite(8, HIGH);   
  analogWrite(11, 255);   //Spins the motor on Channel B at full speed  
          det = check(); 
      }
     
     
     
}

int check()
{
  if (Serial.available() > 0)    //Check for data on the serial lines.
  {   
    dataIn = Serial.read();  //Get the character sent by the phone and store it in 'dataIn'.
        if (dataIn == 'F')
        {     
          determinant = 'F';
        }  
        else if (dataIn == 'B')
        { 
          determinant = 'B'; 
        }
        else if (dataIn == 'L')  
        { 
          determinant = 'L';
        }
        else if (dataIn == 'R')  
        { 
          determinant = 'R';
        } 
        else if (dataIn == 'I')  
        { 
          determinant = 'I'; 
        }  
        else if (dataIn == 'J')  
        {  
          determinant = 'J';
        }          
        else if (dataIn == 'G') 
        {
          determinant = 'G'; 
        }    
        else if (dataIn == 'H')  
        {
          determinant = 'H'; 
        }   
        else if (dataIn == 'S') 
        {
          determinant = 'S';
        }
        else if (dataIn == '0') 
        {
          velocity = 0;    //"velocity" does not need to be returned.
        }
        else if (dataIn == '1') 
        {
          velocity = 25;
        }
        else if (dataIn == '2') 
        {
          velocity = 50;
        }
        else if (dataIn == '3') 
        {
          velocity = 75;
        }
        else if (dataIn == '4') 
        {
          velocity = 100;
        }
        else if (dataIn == '5') 
        {
          velocity = 125;
        }
        else if (dataIn == '6') 
        {
          velocity = 150;
        }
        else if (dataIn == '7') 
        {
          velocity = 175;
        }
        else if (dataIn == '8') 
        {
          velocity = 200;
        }
        else if (dataIn == '9') 
        {
          velocity = 225;
        }
        else if (dataIn == 'q') 
        {
          velocity = 255;
        }
        else if (dataIn == 'U') 
        {
          determinant = 'U';
        }
        else if (dataIn == 'u') 
        {
          determinant = 'u';
        }
        else if (dataIn == 'W') 
        {
          determinant = 'W';
        }
       
        else if (dataIn == 'w') 
        {
          determinant = 'w';
        }
  }
return determinant;
}
