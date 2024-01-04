# CardKB-BLEKeyboard-M5StickCPlus

This repository contains Arduino code to turn an M5StickCPlus with a CARDKB I2C Mini Keyboard into a Bluetooth keyboard. The project uses the M5StickCPlus's built-in BLE functionality to communicate as a keyboard device with different operating systems.

## Features

- **Bluetooth Keyboard**: Emulates a Bluetooth keyboard with the M5StickCPlus.
- **CARDKB Support**: Utilizes the CARDKB I2C Mini Keyboard for text input.
- **Connection Status Display**: Displays BLE connection status on the M5StickCPlus's screen.
- **Customizable**: Easy to modify and extend the functionality.

## Hardware Requirements

- M5StickCPlus
- CARDKB I2C Mini Keyboard

## Software Requirements

- Arduino IDE
- M5StickCPlus Library
- Wire Library (for I2C communication)
- BleKeyboard Library
- Correct Board Configuration:
    - For Windows: M5StickC board from [Espressif's package](https://dl.espressif.com/dl/package_esp32_index.json)
    - For Android: M5StickCPlus board from [M5Stack's package](https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json)

## Setup

1. **Hardware Connection**: Connect your CARDKB to the M5StickCPlus according to the standard connection procedure.
2. **Environment Setup**: Ensure the Arduino IDE is installed with the necessary libraries.
3. **Board Manager Configuration**:
    - Open Arduino IDE, go to `File > Preferences`, and under "Additional Board Manager URLs" add:
        - For Windows: `https://dl.espressif.com/dl/package_esp32_index.json`
        - For Android: `https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json`
    - Go to `Tools > Board > Boards Manager`, search for the respective packages, and install them.
    - Select the correct board from `Tools > Board`:
        - For Windows: Choose "M5StickC"
        - For Android: Choose "M5StickCPlus"
4. **Load and Modify Code**: Open the provided code in Arduino IDE. Modify the pin configuration if necessary, depending on your M5StickCPlus model.
5. **Upload Code**: Compile and upload the code to your M5StickCPlus.

## Usage

Once the device is powered and the code is uploaded:

1. **Turn on Bluetooth**: Ensure the Bluetooth on your target device (computer, phone, etc.) is turned on.
2. **Pair Device**: In your Bluetooth settings, pair with the device named "M5StickCPlus Keyboard" (or the name you set).
3. **Start Typing**: Once connected, you can start typing using the CARDKB. The text will be sent to the connected device as if from a standard Bluetooth keyboard.

## Customization

You can customize the behavior of the keyboard by modifying the Arduino code. This might include changing the Bluetooth device name, adjusting key mappings, or adding functionality for additional keys.

## Troubleshooting

If you encounter issues, ensure that:

- The M5StickCPlus is adequately powered.
- The CARDKB is correctly connected and recognized by the M5StickCPlus.
- The Bluetooth device is in range and not already connected to a different device.
- You have selected the correct board configuration for your target operating system.

## Contributing

Feel free to fork this project and submit your contributions via pull requests.

## Acknowledgments

- M5StickCPlus community for the helpful resources.
- [BleKeyboard Library](https://github.com/T-vK/ESP32-BLE-Keyboard) for the BLE keyboard functionality.
