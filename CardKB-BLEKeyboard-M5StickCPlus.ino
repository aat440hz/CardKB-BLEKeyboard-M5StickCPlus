#include <M5StickCPlus.h>
#include <Wire.h>
#include <BleKeyboard.h>

#define CARDKB_ADDR 0x5F

BleKeyboard bleKeyboard;
bool isConnected = false;  // Current connection status
bool wasConnected = false; // Last known connection status

void setup() {
    Serial.begin(115200);
    M5.begin();
    Wire.begin(32, 33); // SDA, SCL pins as in your example
    M5.Lcd.setRotation(1);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(1, 10);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(2);
    bleKeyboard.begin();
    Serial.println("Starting BLE work!");
    M5.Lcd.println("BLE Keyboard Ready");
}

void loop() {
    // Check the current connection status
    isConnected = bleKeyboard.isConnected();

    // Update the display only when connection status changes
    if (isConnected != wasConnected) {
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setCursor(1, 10);
        if (isConnected) {
            M5.Lcd.println("BLE Connected!");
            Serial.println("BLE Connected!");
        } else {
            M5.Lcd.println("BLE Disconnected!");
            Serial.println("BLE Disconnected!");
        }
        wasConnected = isConnected;  // Update the remembered status
    }

    // Handling of key presses when BLE is connected
    if (isConnected) {
        Wire.requestFrom(CARDKB_ADDR, 1);
        while (Wire.available()) {
            char c = Wire.read();  // receive a byte as character
            if (c != 0) {
                switch (c) {
                    case 27:  // ASCII for ESC is 27
                        bleKeyboard.write(KEY_ESC);  // Send ESC keypress via BLE Keyboard
                        Serial.println("Sending ESC Key");  // Debugging
                        break;
                    case '\r':  // If Enter key (or the correct character for your CARDKB)
                        bleKeyboard.write(KEY_RETURN);  // Send Enter keypress via BLE Keyboard
                        Serial.println("Sending Enter Key");  // Debugging
                        break;
                    case 0xB5:  // Hexadecimal code for Up Arrow
                        bleKeyboard.write(KEY_UP_ARROW);
                        Serial.println("Sending Up Arrow Key");  // Debugging
                        break;
                    case 0xB6:  // Hexadecimal code for Down Arrow
                        bleKeyboard.write(KEY_DOWN_ARROW);
                        Serial.println("Sending Down Arrow Key");  // Debugging
                        break;
                    default:
                        bleKeyboard.print(c);  // Send character as BLE Keyboard
                        Serial.print("Sending: ");  // Debugging
                        Serial.println(c, HEX);
                        break;
                }
            }
        }
    }
    delay(200); // Debounce delay
}
