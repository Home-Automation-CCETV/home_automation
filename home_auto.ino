#define CMDBUFFER_SIZE 32

void setup()
{
  
  Serial.begin(9600);
  Serial.println("Power On");
  
  for(int i=22;i<=53;i++)
  {
    pinMode(i, OUTPUT);
    Serial.println("Output Pin : "+String(i));
    digitalWrite(i, HIGH);
  }
    
}

void loop()
{

}

void serialEvent()
{
 static char cmdBuffer[CMDBUFFER_SIZE] = "";
 char c;
 while(Serial.available()) 
 {
   c = processCharInput(cmdBuffer, Serial.read());
   Serial.print(c);
   if (c == '\n') 
   {
     Serial.println();
     //Full command received. Do your stuff here!

    if(strcmp("Check Output Pins", cmdBuffer) == 0)
    {
      Serial.println("Operation is : Check Output Pins");
      
      for(int i=22;i<=53;i++)
      {
  
        int val = digitalRead(i);
        Serial.println("Pin is : "+String(i));
        Serial.println("The State of Pin is : "+String(val));
      }
      
    }
    
    if(strcmp("Shut on", cmdBuffer) == 0)
    {
      Serial.println("Operation is : Shut on");
      
      for(int i=22;i<=53;i++)
      {
  
          digitalWrite(i,LOW);
      }
      
    }
  
    if(strcmp("Shut down", cmdBuffer) == 0)
    {
      Serial.println("Operation is : Shut down");
      
      for(int i=22;i<=53;i++)
      {
  
          digitalWrite(i,HIGH);
      }
      
    }
      
    if(strcmp("Off Bulb 1", cmdBuffer) == 0)
    {
      Serial.println("Operation is : Off Bulb 1");
      digitalWrite(22,HIGH);
      
    }
    
    if(strcmp("On Bulb 1", cmdBuffer) == 0)
    {
      Serial.println("Operation is : On Bulb 1");
      digitalWrite(22,LOW);
    }
  
    if(strcmp("Off Bulb 2", cmdBuffer) == 0)
    {
      Serial.println("Operation is : Off Bulb 2");
      digitalWrite(23,HIGH);
      
    }
    
    if(strcmp("On Bulb 2", cmdBuffer) == 0)
    {
      Serial.println("Operation is : Off Bulb n");
      digitalWrite(23,LOW);
      
    }
  
    if(strcmp("Off Bulb 3", cmdBuffer) == 0)
    {
      Serial.println("Operation is : Off Bulb 3");
      digitalWrite(24,HIGH);
    }
    
    if(strcmp("On Bulb 3", cmdBuffer) == 0)
    {
      Serial.println("Operation is : On Bulb 3");
      digitalWrite(24,LOW);
      
    }
  
    if(strcmp("Off Bulb 4", cmdBuffer) == 0)
    {
      Serial.println("Operation is : Off Bulb 4");
      digitalWrite(25,HIGH);
      
    }
    
    if(strcmp("On Bulb 4", cmdBuffer) == 0)
    {
      Serial.println("Operation is : On Bulb 4");
      digitalWrite(25,LOW);
    }
  
    if(strcmp("Off Bulb 5", cmdBuffer) == 0)
    {
      Serial.println("Operation is : Off Bulb 5");
      digitalWrite(26,HIGH);
      
    }
    
    if(strcmp("On Bulb 5", cmdBuffer) == 0)
    {
      Serial.println("Operation is : On Bulb 5");
      digitalWrite(26,LOW);
      
    }

     if (strcmp("HELLO", cmdBuffer) == 0)
     {
        Serial.println("\r\nYou typed hello!"); 
     }

     
     cmdBuffer[0] = 0;
   }
 }
 delay(1);
}

char processCharInput(char* cmdBuffer, const char c)
{
 //Store the character in the input buffer
 if (c >= 32 && c <= 126) //Ignore control characters and special ascii characters
 {
   if (strlen(cmdBuffer) < CMDBUFFER_SIZE) 
   { 
     strncat(cmdBuffer, &c, 1);   //Add it to the buffer
   }
   else  
   {   
     return '\n';
   }
 }
 else if ((c == 8 || c == 127) && cmdBuffer[0] != 0) //Backspace
 {

   cmdBuffer[strlen(cmdBuffer)-1] = 0;
 }

 return c;
}
