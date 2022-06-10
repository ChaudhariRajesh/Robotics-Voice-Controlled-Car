int flag1;
String voice;
int dis;
int dis1;

int cm;
int cm1;
int inl = 7;
int led1;
int tri = A2;
int echo = A1;
int tri1 = A5;
int echo1 = A4;
int led2;
int inr = 8;
int buz = 12;
int l1 = 6;
int l2 = 11;
int r1 = 3;
int r2 = 5;
int Speed = 100;
bool fora;
bool back;
int input1, input2;
int flag = 0;

void setup()
{
  digitalWrite(inl, HIGH);
  digitalWrite(inr, HIGH);
  input1 = digitalRead(A0);
  input2 = digitalRead(A1);
  //digitalWrite(8, HIGH);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(13,OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  pinMode(inl, OUTPUT);
  pinMode(inr, OUTPUT);

  pinMode(buz, OUTPUT);
  pinMode(13, OUTPUT);

  
  pinMode(tri, OUTPUT);
  pinMode(echo, INPUT);
   pinMode(4, OUTPUT);
  pinMode(tri1, OUTPUT);
  pinMode(echo1, INPUT);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(4,HIGH);
  
 
}
//int f = 0, f1 = 0;
bool f;
void loop()
{
  
  digitalWrite(tri1, LOW);
  //digitalWrite(tri, LOW);
  delayMicroseconds(2);
  digitalWrite(tri1, HIGH);
  //digitalWrite(tri, HIGH);
  delayMicroseconds(2);
  digitalWrite(tri1, LOW);
  //digitalWrite(tri, LOW);
  delayMicroseconds(2);
  dis = pulseIn(echo1, HIGH);
  //dis1 = pulseIn(echo, HIGH);
  cm = (dis / 29 / 2);
  //cm1 = (dis1 / 29 / 2);

  delay(100);

  //Serial.print("hiii");
  // input1 = digitalRead(A0);
  // input2 = digitalRead(A1);
  if (cm <= 40 && fora == true && !Serial.available() )
  {
    
    goto st;
    //sen:
  }
  else if (fora == true && !Serial.available())
  {
    goto fo;
  }


  /* while (true)
    {
     dis = pulseIn(echo, HIGH);
     cm = (dis / 29 / 2);
     //input1 = digitalRead(A0);
     if (cm > 25)
     {
       goto fo;
       break;
     }
    }
    }*/
  digitalWrite(tri, LOW);
  delayMicroseconds(2);
  digitalWrite(tri, HIGH);
  delayMicroseconds(2);
  digitalWrite(tri, LOW);
  delayMicroseconds(2);

  dis = pulseIn(echo, HIGH);
  cm = (dis / 29 / 2);
  if (cm <= 60 && back == true && !Serial.available() )
  {
    //Serial.print("hello");
    
    goto st;
    //sen1:
  }
  else if (back == true && !Serial.available())
  {
    while (!Serial.available() && back == true && flag1 == 1)
    {
      Serial.print("hiiiii");
      bu();
      digitalWrite(8, LOW);
      delay(200);
      digitalWrite(8, HIGH);
      delay(200);
      goto bk;

    }


  }

  /* while (true)
    {
     dis1 = pulseIn(echo1, HIGH);
     cm1 = (dis1 / 29 / 2);
     //input2 = digitalRead(A1);
     if (cm1 > 25)
     {
       goto bk;
       break;
     }
    }
    }*/
  /*while (!Serial.available() && back == true)
    {
    Serial.print("hiiiii");
    bu();

    }*/



  //  Serial.print("hello");
 /* while(!Serial.available() && voice=="break")
  {
    digitalWrite(inl,LOW);
    digitalWrite(10,LOW);
    delay(200);
    digitalWrite(inl,HIGH);
    digitalWri+te(10,HIGH);
    delay(200);+
    
  }*/
  

  
  while (Serial.available())
  {
    delay(10);
    char c = Serial.read();
    if (c == '#')
    {
      break;
    }
    voice += c;
    //digitalWrite(8,HIGH);
  }
  if (voice == "Galaxy")
  {
    flag1 = 1;
    digitalWrite(buz, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
    digitalWrite(13,LOW);
    delay(400);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(buz, LOW);
    delay(200);
    digitalWrite(buz, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
    digitalWrite(13,LOW);
    delay(400);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(buz, LOW);
    delay(200);

  }
  if (flag1 != 1)
  {
    voice = "";
  }
  else if (flag1 == 1)
  {
    Serial.println(voice);
    if (voice.length() > 0)
    {
      //Serial.println(voice);
      if (voice == "slow" && back != true)
      {
        goto st;
sp:
        Speed = 125;
        if (fora == true)
        {
          goto fo;
        }
      }

      else if (voice == "medium" && back != true)
      {
        goto st;
sp1:
        Speed = 175;
        if (fora == true)
        {
          goto fo;
        }
      }

      else if (voice == "fast" && back != true)
      {
        goto st;
sp2:
        Speed = 255;
        if (fora == true)
        {
          goto fo;
        }
      }

      if (voice == "forward")
      {
        fora = true;
        back = false;
fo:



        analogWrite(l1, Speed);
        analogWrite(l2, 0);

        analogWrite(r1, 0);
        analogWrite(r2, Speed);

        //delay(5000);

        /*analogWrite(l1, 0);
          analogWrite(r1, 0);
          analogWrite(l2, 0);
          analogWrite(r2, 0);*/
      }

      else if (voice == "backward")
      {
        fora = false;
        back = true;
bk:
        analogWrite(l1, 0);
        analogWrite(l2, 120);

        analogWrite(r1, 120);
        analogWrite(r2, 0);

        //delay(5000);

        /*analogWrite(l1, 0);
          analogWrite(r1, 0);
          analogWrite(l2, 0);
          analogWrite(r2  1, 0);*/
      }

      else if (voice == "right")
      {
        digitalWrite(10, LOW);
        analogWrite(l1, 0);
        analogWrite(l2, 255);

        analogWrite(r1, 0);
        analogWrite(r2, 255);

        delay(850);

        analogWrite(l1, 0);
        analogWrite(r1, 0);
        analogWrite(l2, 0);
        analogWrite(r2, 0);
        digitalWrite(10, HIGH);
      }
      else if (voice == "turn on inner lights" || voice == "Inna lights on")
      {
        digitalWrite(4, LOW);
      }
      else if (voice == "turn off inner lights" || voice == "Inna lights off")
      {
        digitalWrite(4, HIGH);
      }
      else if(voice=="turn on wheel lights" || voice == "wheel lights on")
      {
        digitalWrite(13,LOW);
      }
      else if(voice=="turn off wheel lights" || voice == "wheel lights off")
      {
        digitalWrite(13,HIGH);
      }
      else if (voice == "left")
      {
        digitalWrite(inl, LOW);
        //digitalWrite(10,LOW);
        delay(200);
        // digitalWrite(10, HIGH);
       
       // digitalWrite(10, LOW);
        analogWrite(l1, 255);
        analogWrite(l2, 0);

        analogWrite(r1, 255);
        analogWrite(r2, 0);

        delay(850);
       // digitalWrite(10, HIGH);

        analogWrite(l1, 0);
        analogWrite(r1, 0);
        analogWrite(l2, 0);
        analogWrite(r2, 0);
        digitalWrite(inl, HIGH);
      }

      else if (voice == "turn on light" || voice == "light on")
      {
        digitalWrite(9, LOW);
        // digitalWrite(led2, HIGH);
      }

      else if (voice == "turn off light" || voice == "light off")
      {
        digitalWrite(9, HIGH);
        digitalWrite(led2, LOW);
      }

      else if (voice == "peep")
      {
        digitalWrite(buz, HIGH);
        delay(400);
        digitalWrite(buz, LOW);
        delay(200);
        digitalWrite(buz, HIGH);
        delay(400);
        digitalWrite(buz, LOW);
      }
      else if (voice == "rotate")
      {
        analogWrite(l1, 255);
        analogWrite(l2, 0);

        analogWrite(r1, 255);
        analogWrite(r2, 0);

        delay(1750);

        analogWrite(l1, 0);
        analogWrite(r1, 0);
        analogWrite(l2, 0);
        analogWrite(r2, 0);
      }

      else if (voice == "break")
      {
        back = false;
        fora = false;
        st:
        analogWrite(r1, 0);
        analogWrite(l1, 0);
        analogWrite(l2, 0);
       
        analogWrite(r2, 0);
      
       

        if (voice == "slow")
        {
          goto sp;
        }
        else if (voice == "medium")
        {
          goto sp1;
        }
        else if (voice == "fast")
        {
          goto sp2;
        }

        if (flag1 == 0)
        {
          back = false;
          goto sen;
        }
        if (input2 == HIGH)
        {
          //        goto sen1;
        }

      }
      else if (voice == "turn on all lights")
      {
       
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
        digitalWrite(13,LOW);
        

      }
      else if (voice == "turn off all lights")
      {
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(13,HIGH);
      }

      else if (voice == "left forward")
      {
        back = false;
        fora = true;
        analogWrite(l1, 255);
        analogWrite(l2, 0);

        analogWrite(r1, 255);
        analogWrite(r2, 0);

        delay(900);

        analogWrite(l1, Speed);
        analogWrite(l2, 0);

        analogWrite(r1, 0);
        analogWrite(r2, Speed);
      }
      else if (voice == "stop")
      {
        flag1 = 0;
        goto st;
        sen:
        back == false;
        fora = false;
        Serial.print("Paliwal");
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
         digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(13,HIGH);
        bu();
      }

      else if (voice == "right forward")
      {
        back = false;
        fora = true;
        analogWrite(l1, 0);
        analogWrite(l2, 255);

        analogWrite(r1, 0);
        analogWrite(r2, 255);

        delay(850);

        analogWrite(l1, Speed);
        analogWrite(l2, 0);

        analogWrite(r1, 0);
        analogWrite(r2, Speed);
      }
      voice = "";
    }
    
  }
}
void bu()
{
  digitalWrite(buz, HIGH);
  delay(400);
  digitalWrite(buz, LOW);
  delay(200);
}
void bu1()
{
  digitalWrite(buz, HIGH);
  delay(400);
  digitalWrite(buz, LOW);
  delay(600);
}

