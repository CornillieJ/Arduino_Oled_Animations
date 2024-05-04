# Arduino OLED Display Animation Project

Welcome to my Arduino OLED Display Animation project! This project utilizes an SSD1306 OLED display along with buttons to showcase various animations.

## Introduction

The purpose of this project is to display small animations on an OLED display controlled by an Arduino. Users can interact with the animations using buttons to navigate through a menu and select different options.

## ShowCase Videos
- **Hardware showCase**: 
[![Hardware showCase](https://img.youtube.com/vi/mcY3DI6WkEM0.jpg)](https://youtu.be/mcY3DI6WkEM)
- **Features showCase**:
[![Features showCase](https://img.youtube.com/vi/frrQctzdX90/0.jpg)](https://youtu.be/frrQctzdX90)

## Features

- **Main Menu**: Upon starting the program, users are presented with a main menu where they can choose from a selection of animations or turn off the display.
- **Animations**: Currently available animations include:
  - **Bongocat**: Reacts to left and right button presses to display different frames of the animation.
  - **Kirby**: Sucks in an object upon pressing one button, grows larger, and eats it upon pressing another button, returning to normal size.
  - **Navi**: Displays a floating animation.
- **Navigation**: Users can navigate the menu using left and right buttons and select options using the select button.
- **Button Configuration**:
  - Left Button: Connected to pin 9.
  - Right Button: Connected to pin 2.
  - Select Button: Connected to pin 3.
- **Display Connection**: OLED display connected to pins A4 (serial data) and A5 (serial clock), as well as VCC and GND.
- **Arduino version**: I believe this will work on most Arduino's, I used both arduino NANO and arduino UNO.

## Usage

1. Connect the buttons and OLED display to the specified pins.
2. Upload the provided Arduino sketch to your Arduino board.
3. Interact with the animations using the buttons as described above.

## Contribution

Contributions to this project are welcome! Feel free to use the provided code and modify it to suit your needs. If you make improvements or add new features, consider submitting a pull request.

## License

This project is open-source and available under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code as you see fit.

## Acknowledgements

Special thanks to Lizz for contributing the idea of this project.

## Support

If you encounter any issues or have any questions, feel free to [contact me](mailto:jeffrey.cornillie@hotmail.com) or open an issue.

