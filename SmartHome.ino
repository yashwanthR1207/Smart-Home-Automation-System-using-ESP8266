#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* ---------------- PIN DEFINITIONS ---------------- */
#define DHTPIN D4
#define DHTTYPE DHT11

#define FIRE_SENSOR D6
#define IR_SENSOR   D5
#define BUZZER      D7

#define LED1 D8
#define LED2 D6
#define LED3 D3

#define RED   D2
#define GREEN D1
#define BLUE  D0

/* ---------------- OBJECTS ---------------- */
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
ESP8266WebServer server(80);

/* ---------------- WIFI ---------------- */
const char* ssid = "Esp";
const char* password = "123456789";

/* ---------------- VARIABLES ---------------- */
unsigned long lastBuzzerToggle = 0;
bool buzzerState = false;

unsigned long lastIRTime = 0;

float temperature = 0.0;
float humidity = 0.0;
bool fireDetected = false;
bool irDetected = false;

/* ---------------- SETUP ---------------- */
void setup() {
  Serial.begin(9600);

  pinMode(FIRE_SENSOR, INPUT);
  pinMode(IR_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  lcd.init();
  lcd.backlight();
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("Smart Home Sys");
  delay(2000);
  lcd.clear();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/data", handleData);
  server.begin();
}

/* ---------------- LOOP ---------------- */
void loop() {
  server.handleClient();

  /* ---- FIRE SENSOR ---- */
  fireDetected = (digitalRead(FIRE_SENSOR) == LOW);

  if (fireDetected) {
    lcd.setCursor(0, 0);
    lcd.print(" FIRE ALERT!    ");

    if (millis() - lastBuzzerToggle > 80) {
      buzzerState = !buzzerState;
      digitalWrite(BUZZER, buzzerState);
      lastBuzzerToggle = millis();
    }
  } else {
    digitalWrite(BUZZER, LOW);
    lcd.setCursor(0, 0);
    lcd.print("                ");
  }

  /* ---- DHT SENSOR ---- */
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (!isnan(h) && !isnan(t)) {
    humidity = h;
    temperature = t;
  }

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C H:");
  lcd.print(humidity);
  lcd.print("% ");

  /* ---- IR SENSOR ---- */
  irDetected = (digitalRead(IR_SENSOR) == LOW);

  if (millis() - lastIRTime > 300) {
    lastIRTime = millis();

    if (irDetected) {
      digitalWrite(LED1, !digitalRead(LED1));
      digitalWrite(LED2, !digitalRead(LED2));
      digitalWrite(LED3, !digitalRead(LED3));
    } else {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }
  }

  /* ---- RGB SERIAL CONTROL ---- */
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'r') setColor(255, 0, 0);
    else if (cmd == 'g') setColor(0, 255, 0);
    else if (cmd == 'b') setColor(0, 0, 255);
    else if (cmd == 'w') setColor(255, 255, 255);
    else if (cmd == 'o') setColor(0, 0, 0);
  }
}

/* ---------------- FUNCTIONS ---------------- */
void setColor(int red, int green, int blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}

/* ---------------- WEB PAGE ---------------- */
void handleRoot() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>Smart Home Dashboard</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body{font-family:Arial;background:#f4f4f4;text-align:center}
.card{background:white;padding:15px;margin:10px;border-radius:8px;display:inline-block;width:200px}
.warning{color:red}
.safe{color:green}
</style>
</head>
<body>
<h1>Smart Home Dashboard</h1>
<div class="card"><h3>Temperature</h3><p id="t">--</p></div>
<div class="card"><h3>Humidity</h3><p id="h">--</p></div>
<div class="card"><h3>Fire</h3><p id="f" class="safe">Safe</p></div>
<div class="card"><h3>Motion</h3><p id="m">None</p></div>

<script>
function load(){
fetch('/data').then(r=>r.json()).then(d=>{
document.getElementById('t').innerHTML=d.temperature+' °C';
document.getElementById('h').innerHTML=d.humidity+' %';
document.getElementById('f').innerHTML=d.fire?'FIRE!':'Safe';
document.getElementById('f').className=d.fire?'warning':'safe';
document.getElementById('m').innerHTML=d.motion?'Detected':'None';
});
}
setInterval(load,5000); load();
</script>
</body>
</html>
)rawliteral";

  server.send(200, "text/html", html);
}

/* ---------------- JSON API ---------------- */
void handleData() {
  String json = "{";
  json += "\"temperature\":" + String(temperature, 1) + ",";
  json += "\"humidity\":" + String(humidity, 1) + ",";
  json += "\"fire\":" + String(fireDetected ? "true" : "false") + ",";
  json += "\"motion\":" + String(irDetected ? "true" : "false");
  json += "}";

  server.send(200, "application/json", json);
}
