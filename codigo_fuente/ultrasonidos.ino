const int EchoPin = 13;
const int TriggerPin = 14;
int ledPin = 8; // choose the pin for the LED


int ping(int TriggerPin, int EchoPin) {
    long duration, distanceCm;

    digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
    delayMicroseconds(4);
    digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);

    duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos

    distanceCm = 10* duration * 10 / 292/ 2;   //convertimos a distancia, en mm
    return distanceCm;

}

void setup() {
    Serial.begin(9600);
    pinMode(TriggerPin, OUTPUT);
    pinMode(EchoPin, INPUT);
    pinMode(ledPin, OUTPUT);  // declare LED as output
}
void loop() {
    int mm = ping(TriggerPin, EchoPin);
    Serial.print("Distancia: ");
    Serial.println(mm);
    if (mm<=20) {         // check if the input is HIGH (button released)
        digitalWrite(ledPin, HIGH);  // turn LED OFF
    } else {
        digitalWrite(ledPin, LOW);  // turn LED ON

    }
    delay(1000);

}
