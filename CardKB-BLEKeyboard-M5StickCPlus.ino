#include <M5StickCPlus.h>
#include <Wire.h>
#include <BleKeyboard.h>

#define CARDKB_ADDR 0x5F

BleKeyboard bleKeyboard;
bool isConnected = false; // Global variable to track connection status

void setup() {
    Serial.begin(115200);
    M5.begin();
    Wire.begin(32, 33); // SDA, SCL pins as in your example
    M5.Lcd.setRotation(3);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(1, 10);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(2);
    bleKeyboard.begin();
    Serial.println("Starting BLE work!");
    M5.Lcd.println("BLE Keyboard Ready");
}

void loop() {
    // Check and update the connection status
    if (bleKeyboard.isConnected() && !isConnected) {
        isConnected = true;
        Serial.println("BLE Connected!");
    } else if (!bleKeyboard.isConnected() && isConnected) {
        isConnected = false;
        Serial.println("BLE Disconnected!");
    }

    // Update the display with the accurate BLE connection status
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(1, 10);
    if (isConnected) {
        M5.Lcd.println("BLE Connected!");
        Wire.requestFrom(CARDKB_ADDR, 1);
        while (Wire.available()) {
            char c = Wire.read();  // receive a byte as character
            if (c != 0) {
                if (c == '\r') {  // If Enter key (or the correct character for your CARDKB)
                    bleKeyboard.write(KEY_RETURN);  // Send Enter keypress via BLE Keyboard
                    Serial.println("Sending Enter Key");  // Debugging
                } else {
                    bleKeyboard.print(c);  // Send character as BLE Keyboard
                    Serial.print("Sending: ");  // Debugging
                    Serial.println(c, HEX);
                }
            }
        }
    } else {
        M5.Lcd.println("BLE Disconnected!");
    }
    delay(200); // Debounce delay
}
