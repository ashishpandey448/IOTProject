String voice;
int Relay1 = 2;
int Relay2 = 3 ;
int Relay3 = 4;
int Relay4 = 5;
void Relay1On(){
digitalWrite (Relay1, LOW);
}
void Relay1Off(){
digitalWrite (Relay1, HIGH);
}
void Relay2On(){
digitalWrite (Relay2, LOW);
}
void Relay2Off(){
digitalWrite (Relay2, HIGH);
}
void Relay3On(){
digitalWrite (Relay3, LOW);
}
void Relay3Off(){                         
digitalWrite (Relay3, HIGH);
}
void Relay4On(){
digitalWrite (Relay4, LOW);
}
void Relay4Off(){
digitalWrite (Relay4, HIGH);
}
void allon() {
digitalWrite (Relay1, LOW);
digitalWrite (Relay2, LOW);
digitalWrite (Relay3, LOW);
digitalWrite (Relay4, LOW);
}
void alloff() {
digitalWrite (Relay1, HIGH);
digitalWrite (Relay2, HIGH);
digitalWrite (Relay3, HIGH);
digitalWrite (Relay4, HIGH);
}
void setup() {
Serial.begin(9600);
pinMode(Relay1, OUTPUT);
pinMode(Relay2, OUTPUT);
pinMode(Relay3, OUTPUT);
pinMode(Relay4, OUTPUT);
}
void loop() {
while(Serial.available()) {
delay(10);
char c=Serial.read();
if(c=='#')
{break; }
voice += c;
}
if (voice.length() > 0) {
Serial.println(voice);
if (voice == "on" || voice == "Alexa switch on")
{
allon() ;
}
else if (voice == "off" || voice=="Alexa switch off")
{
alloff() ;
}
else if(voice =="charger" || voice =="Alexa charger on"){
Relay1On();
}
else if(voice =="charger off" || voice =="Alexa charger off"){
Relay1Off();
}
else if(voice =="TV" || voice =="Alexa TV on"){
Relay2On();
}
else if( voice =="switch off TV" || voice =="Alexa TV off" ){
Relay2Off();
}
else if(voice =="light" || voice =="Alexa light on"){
Relay3On();
}
else if(voice =="switch off light" || voice =="Alexa light off"){
Relay3Off();
}
else if(voice =="fan" || voice =="Alexa fan on"){
Relay4On();
}
else if(voice =="switch off fan" || voice =="Alexa fan off"){
Relay4Off();
}
voice="";
}
}
