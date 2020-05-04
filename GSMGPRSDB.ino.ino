String latitude = "18.4576928";
String longitude = "73.850779";
//do not use jio sim as it only supports 4G
void setup()
{
  Serial1.begin(9600);   // Setting the baud rate of GSM Module
  delay(1000);
  SendMessage();
  updateThinkspeak();
}
void loop()
{
  SendMessage();
  updateThinkspeak();
}

void SendMessage()      //Function to Send Message
{

  Serial1.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);

  Serial1.println("AT+CMGS=\"+919923255933\"\r"); // Replace x with mobile number
  delay(1000);

  Serial1.println(String("This is a SOS message from the taser gun. Location: http://www.=google.com/maps/place/") + latitude + ",%" + longitude);
  // The SMS text you want to send
  delay(100);

  Serial1.println((char)26);// ASCII code of CTRL+Z
  delay(1000);

  //total delay = 3.1 sec
}
void GPRS_init()
{
  Serial1.println("AT"); // Attention
  delay(500);

  Serial1.println("AT+CPIN?");
  delay(500);

  Serial1.println("AT+CREG?");
  delay(500);

  Serial1.println("AT+CGATT?");
  delay(500);

  Serial1.println("AT+CIPSHUT");
  delay(500);

  Serial1.println("AT+CIPSTATUS");
  delay(1000);

  Serial1.println("AT+CIPMUX=0");//normal mode TCP/IPO application
  delay(1000);

  Serial1.println("AT+CGATT=1"); // attach to GPRS service
  delay(2000);

 // Serial1.println("AT+CSTT=\”airtelgrps.com\”,\”\”,\”\”"); // airtel
  //Serial1.println("AT+CSTT=\”bsnlnet\”,\”\”,\”\”"); // bsnl
  Serial1.println("AT+CSTT=\”portalnmms\”,\”\”,\”\”"); // vodafone
  //Serial1.println("AT+CSTT=\”imis\”,\”\”,\”\”"); // idea
  //Serial1.println("AT+CSTT=\”internet\”,\”\”,\”\”"); //if nothing works
  delay(1000);

   Serial1.println("AT+CIICR");
  delay(1000);

Serial1.println("AT+CIFSR");
  delay(1000);

Serial1.println("AT+CISPRT=0");
  delay(1000);


  Serial1.println("AT+CGATT=1"); // attach to GPRS service
  delay(2000);

  Serial1.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\""); //-start-up TCP connection  
  delay(1000);

  Serial1.println("AT+CIPSEND"/*+(42+latitude.length())*/); //send data through TCP connection
  delay(1000);

  //total delay = 11.5 sec
}
void updateThinkspeak()
{
   Serial1.println(String("GET http://localhost:8080/phpmyadmin/sql.php?server=1&db=location_db&table=tracking_location&pos=0=") + ID + "\r\n\x1A");
  delay(1000);
  Serial1.println("AT+CIPSHUT");//close the connection
  delay(1000);
  
  GPRS_init();
  Serial1.println(String("GET http://localhost:8080/phpmyadmin/sql.php?server=1&db=location_db&table=tracking_location&pos=0=") + LATITUDE + "\r\n\x1A");
  delay(1000);

  Serial1.println("AT+CIPSHUT");//close the connection
  delay(1000);

  GPRS_init();
  Serial1.println(String("GET http://localhost:8080/phpmyadmin/sql.php?server=1&db=location_db&table=tracking_location&pos=0") + LONGITUDE + "\r\n\x1A");
  delay(1000);

  Serial1.println("AT+CIPSHUT");//close the connection
  delay(1000);
}
/*
  void getLocation()
  {
  }*/
void RecieveMessage()         //Function to Receive Message

  {



  Serial1.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS

  delay(1000);
/*
  while(1)
  {
            if(Serial1.available())
            {
              while(!Serial1.available());

               incoming = Serial1.read();
               Serial1.print("Received Message is:");
               Serial1.println(incoming , DEC);
            }
           (if(Serial1.available())
            {
                do

                  {

                     while ( !Serial1.available() );

                  } while ( '"' != Serial1.read() );

               do

                  {

                      while ( !Serial1.available() );

                  } while ( '"' != Serial1.read() );

               do

                 {

                      while ( !Serial1.available() );

                  } while ( '"' != Serial1.read() );

               do

                 {

                    while ( !Serial1.available() );

                 } while ( '"' != Serial1.read() );

                do

                  {

                     while ( !Serial1.available() );


                  } while ( '"' != Serial1.read() );

                do

                 {

                    while ( !Serial1.available() );


                  } while ( '"' != Serial1.read() );

                  while ( !Serial1.available() );

                  receive = Serial1.read();

                  while ( !Serial1.available() );

                  receive = Serial1.read();




    while(1)

    {

        while ( !Serial1.available() );

        receive = Serial1.read();

        if ( receive == '\r' )

              break;

        else

             lcd.write(receive);
     }
  }
  }*/
  }
