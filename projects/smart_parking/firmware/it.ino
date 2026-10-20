
#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

// ===== WIFI =====
const char* ssid = "TEN_WIFI";
const char* password = "MAT_KHAU";

WebServer server(80);

// ===== LCD =====
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ===== CAM BIEN =====
// 4 cam bien bai do
int parkingPins[4] = {32, 33, 25, 26};

// 2 cam bien cong
#define S1 27  // Phia ngoai
#define S2 14  // Phia trong

// LOW = co vat can
#define DETECT LOW

// ===== SERVO =====
#define SERVO_PIN 18
Servo gate;

#define GATE_CLOSE 0
#define GATE_OPEN 90

bool gateOpened = false;
bool passedSecondSensor = false;
int direction = 0; // 1: vao, 2: ra

unsigned long openedAt = 0;
unsigned long clearAt = 0;

const unsigned long GATE_TIMEOUT = 15000;
const unsigned long CLEAR_TIME = 1200;

// ===== DU LIEU BAI XE =====
bool slot[4] = {false, false, false, false};

int total = 4;
int used = 0;
int freeSlots = 4;

// ===== THOI GIAN LCD =====
unsigned long lastLCD = 0;
unsigned long lastWiFiTry = 0;
unsigned long wifiConnectedAt = 0;
bool previousWiFi = false;
int lastLCDMode = -1;

bool sensorActive(int pin) {
  return digitalRead(pin) == DETECT;
}

void readParking() {
  used = 0;

  for (int i = 0; i < 4; i++) {
    slot[i] = sensorActive(parkingPins[i]);

    if (slot[i]) {
      used++;
    }
  }

  freeSlots = total - used;
}

// ===== DIEU KHIEN CONG =====
void openGate(int dir) {
  direction = dir;
  gateOpened = true;
  passedSecondSensor = false;
  openedAt = millis();
  clearAt = 0;

  gate.write(GATE_OPEN);
}

void closeGate() {
  gate.write(GATE_CLOSE);
  gateOpened = false;
  direction = 0;
  passedSecondSensor = false;
  clearAt = 0;
}

void controlGate() {
  bool outside = sensorActive(S1);
  bool inside = sensorActive(S2);

  if (!gateOpened) {
    // Xe vao
    if (outside && !inside && freeSlots > 0) {
      openGate(1);
    }
    // Xe ra
    else if (inside && !outside) {
      openGate(2);
    }
    return;
  }

  // Phat hien xe di qua cam bien thu hai
  if (direction == 1 && inside) {
    passedSecondSensor = true;
  }

  if (direction == 2 && outside) {
    passedSecondSensor = true;
  }

  // Chi dong khi ca hai cam bien khong thay xe
  if (!outside && !inside) {
    if (clearAt == 0) {
      clearAt = millis();
    }

    bool timeout = millis() - openedAt > GATE_TIMEOUT;

    if ((passedSecondSensor || timeout) &&
        millis() - clearAt > CLEAR_TIME) {
      closeGate();
    }
  } else {
    clearAt = 0;
  }
}

// ===== HIEN THI LCD =====
void lcdLine(int row, String content) {
  lcd.setCursor(0, row);

  if (content.length() > 16) {
    content = content.substring(0, 16);
  }

  while (content.length() < 16) {
    content += " ";
  }

  lcd.print(content);
}

void updateLCD() {
  if (millis() - lastLCD < 500) return;
  lastLCD = millis();

  bool connected = WiFi.status() == WL_CONNECTED;

  // Neu chua ket noi WiFi
  if (!connected) {
    lcdLine(0, "SMART PARKING");
    lcdLine(1, "Connecting WiFi");
    return;
  }

  unsigned long elapsed = millis() - wifiConnectedAt;

  // 5 giay dau hien IP
  // Sau do moi 10 giay hien IP 3 giay
  bool showIP = elapsed < 5000 ||
                (elapsed % 10000 < 3000);

  if (showIP) {
    lcdLine(0, "WiFi Connected");
    lcdLine(1, WiFi.localIP().toString());
  }
  else if (freeSlots == 0) {
    lcdLine(0, "BAI XE DAY!");
    lcdLine(1, "SO XE: 4/4");
  }
  else {
    lcdLine(0, "XE TRONG BAI: " + String(used));
    lcdLine(1, "CHO CON TRONG: " + String(freeSlots));
  }
}

// ===== WIFI =====
void updateWiFi() {
  bool connected = WiFi.status() == WL_CONNECTED;

  if (connected && !previousWiFi) {
    wifiConnectedAt = millis();

    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  }

  if (!connected && millis() - lastWiFiTry > 10000) {
    lastWiFiTry = millis();
    WiFi.reconnect();
  }

  previousWiFi = connected;
}

// ===== WEB SERVER =====
void handleData() {
  String json = "{";

  json += "\"used\":" + String(used) + ",";
  json += "\"free\":" + String(freeSlots) + ",";
  json += "\"gate\":\"";
  json += gateOpened ? "OPEN" : "CLOSED";
  json += "\",\"slots\":[";

  for (int i = 0; i < 4; i++) {
    json += slot[i] ? "true" : "false";
    if (i < 3) json += ",";
  }

  json += "]}";

  server.send(200, "application/json", json);
}

const char html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="vi">
<head>
<meta charset="UTF-8">
<meta name="viewport"
content="width=device-width,initial-scale=1">
<title>Smart Parking</title>
<style>
body{
 font-family:Arial;
 background:#eef2f8;
 text-align:center;
 padding:20px;
}
h1{color:#172d50}
.grid{
 display:grid;
 grid-template-columns:repeat(2,1fr);
 gap:12px;
 max-width:600px;
 margin:15px auto;
}
.card{
 background:white;
 padding:20px;
 border-radius:12px;
 box-shadow:0 2px 8px #0002;
}
.num{
 font-size:36px;
 font-weight:bold;
 color:#2563eb;
}
.empty{border:2px solid green}
.busy{border:2px solid red}
</style>
</head>
<body>
<h1>SMART PARKING</h1>
<h2>He thong bai do xe thong minh</h2>

<div class="grid">
<div class="card">
Tong vi tri
<div class="num">4</div>
</div>
<div class="card">
Xe trong bai
<div class="num" id="used">0</div>
</div>
<div class="card">
Cho con trong
<div class="num" id="free">4</div>
</div>
<div class="card">
Trang thai cong
<h3 id="gate">CLOSED</h3>
</div>
</div>

<h2>So do bai do xe</h2>
<div class="grid" id="parking"></div>

<script>
async function update() {
 try {
  let response = await fetch('/data');
  let d = await response.json();

  document.getElementById('used').innerText=d.used;
  document.getElementById('free').innerText=d.free;

  document.getElementById('gate').innerText =
  d.gate === 'OPEN' ? 'DANG MO' : 'DANG DONG';

  let output='';

  d.slots.forEach((occupied,i)=>{
   output+=`
    <div class="card ${occupied?'busy':'empty'}">
      <h3>VI TRI ${i+1}</h3>
      <div style="font-size:40px">
        ${occupied?'🚗':'🅿️'}
      </div>
      <p>${occupied?'DA CO XE':'CON TRONG'}</p>
    </div>`;
  });

  document.getElementById('parking').innerHTML=output;
 } catch(e) {
  console.log("Connection error");
 }
}

update();
setInterval(update,1000);
</script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);

  // Cam bien
  for (int i = 0; i < 4; i++) {
    pinMode(parkingPins[i], INPUT_PULLUP);
  }

  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);

  // LCD
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcdLine(0, "SMART PARKING");
  lcdLine(1, "Starting...");

  // Servo
  gate.setPeriodHertz(50);
  gate.attach(SERVO_PIN, 500, 2400);
  gate.write(GATE_CLOSE);

  // WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Web
  server.on("/", []() {
    server.send_P(200, "text/html", html);
  });

  server.on("/data", handleData);
  server.begin();

  readParking();
}

void loop() {
  readParking();
  controlGate();

  updateWiFi();
  updateLCD();

  server.handleClient();

  delay(20);
}
