void setup()
{
  
  Serial.begin(9600);
  Serial.println("Power On");
  
  for(int i=2;i<=13;i++)
  {
    pinMode(i, OUTPUT);
    Serial.println("Output Pin : "+String(i));
    digitalWrite(i, HIGH);
//    digitalWrite(i, LOW);
  }
    
}

void loop()
{
  String input_string;
  
  while(Serial.available()) {

    //Read the incoming data as string
    input_string= Serial.readString();
    Serial.println("Input is : "+input_string);

    if(input_string=="Check Output Pins")
    {
      Serial.println("Operation is : Check Output Pins");
    
      for(int i=2;i<=13;i++)
      {
        int val = digitalRead(i);
        Serial.println("Pin is : "+String(i));
        Serial.println("The State of Pin is : "+String(val));
      }
    
    }
  
    if(input_string=="Shut on")
    {
      Serial.println("Operation is : Shut on");
    
      for(int i=2;i<=13;i++)
      {

        digitalWrite(i,LOW);
      }
    
    }

    if(input_string=="Shut down")
    {
      Serial.println("Operation is : Shut down");
    
      for(int i=2;i<=13;i++)
      {

        digitalWrite(i,HIGH);
      }
    
    }
  
    if(input_string=="Off Bulb 1")
    {
      Serial.println("Operation is : Off Bulb 1");
      digitalWrite(2,HIGH);
    
    }
  
    if(input_string=="On Bulb 1")
    {
      Serial.println("Operation is : On Bulb 1");
      digitalWrite(2,LOW);
    }

    if(input_string=="Off Bulb 2")
    {
      Serial.println("Operation is : Off Bulb 2");
      digitalWrite(3,HIGH);
    
    }
  
    if(input_string=="On Bulb 2")
    {
      Serial.println("Operation is : Off Bulb n");
      digitalWrite(3,LOW);
    
    }

    if(input_string=="Off Bulb 3")
    {
      Serial.println("Operation is : Off Bulb 3");
      digitalWrite(4,HIGH);
    }
  
    if(input_string=="On Bulb 3")
    {
      Serial.println("Operation is : On Bulb 3");
      digitalWrite(4,LOW);
    
    }

    if(input_string=="Off Bulb 4")
    {
      Serial.println("Operation is : Off Bulb 4");
      digitalWrite(5,HIGH);
    
    }
  
    if(input_string=="On Bulb 4")
    {
      Serial.println("Operation is : On Bulb 4");
      digitalWrite(5,LOW);
    }

    if(input_string=="Off Bulb 5")
    {
      Serial.println("Operation is : Off Bulb 5");
      digitalWrite(6,HIGH);
    
    }
  
    if(input_string=="On Bulb 5")
    {
      Serial.println("Operation is : On Bulb 5");
      digitalWrite(6,LOW);
    
    }
  
  }
  
  
  
}
