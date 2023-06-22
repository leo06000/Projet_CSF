const byte TRIG = 2;
const byte ECHO = 3;
const unsigned long tps_mesure = 25000UL; //25msx10¨3= 25000 us 
const float vts_son_ms = 340.0 / 1000;
void setup() {
  //Initialisation du système 
  pinMode(4, OUTPUT); // Led rouge
  digitalWrite(4, LOW); // Led rouge éteinte en état de base
  pinMode(5, OUTPUT); // Led verte
  digitalWrite(5, HIGH);// Led verte allumé en état de base
  pinMode(TRIG, OUTPUT); // Pin d'émission du signal
  digitalWrite(TRIG, LOW); // Aucun signal émit dans l'état de base
  pinMode(ECHO, INPUT);// Pin de réception du signal
}void loop() {
  // On crée une émission de 10us qui partira du pin TRIG
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Mesure reçoit le temps qui s'est écoulé entre l'émission et réception du signal
  long mesure = pulseIn(ECHO, HIGH, tps_mesure);
  
  float distance_mm = mesure / 2.0 * vts_son_ms;// Calcul de la distance entre l'objet et l'émetteur
  if (distance_mm > 100) // objet est assez loin donc on allume led Verte
  {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  else if (distance_mm < 1)// objet trop proche pour être détecté , on éteint les LED
  {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else // l'object est détecté  dans la zone prédéfinit grâce a la ligne 24
  {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
}
