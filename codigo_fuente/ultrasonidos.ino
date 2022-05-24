int ping(int TriggerPin, int EchoPin) {
    long duration, distanceCm;

    digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
    delayMicroseconds(4);
    digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);

    duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos

    distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
    return distanceCm;

}

void setup() {
    Serial.begin(9600);
    pinMode(TriggerPin, OUTPUT);
    pinMode(EchoPin, INPUT);
    pinMode(ledPin, OUTPUT);  // declare LED as output
}
void loop() {

}
