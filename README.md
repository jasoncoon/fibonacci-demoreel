Fibonacci Demo Reel
=========

A simple Demo Reel for Fibonacci boards for any Arduino-compatible microcontroller.

Source code: https://github.com/jasoncoon/fibonacci-demoreel

More information on Fibonacci64: https://www.evilgeniuslabs.org/fibonacci64

[![Image of Yaktocat](https://i.imgur.com/rzZu48F.gif)](https://www.evilgeniuslabs.org/fibonacci64)

Hook LED data in to pin 4, or change `DATA_PIN`.

Autoplay is enabled by default, and set to cycle to the next pattern every 10 seconds.  These can be changed with the `autoplay` and `autoplayDuration` variables.

The code supports two buttons, on pins 2 and 3 by default, to change brightness and pattern.

Buttons should be connected between the data pins and ground.

Press button 2 to cycle between brightness levels 16, 32, 64, 128, 255, then back to 16.

Press button 3 to cycle between patterns.  Pressing it the first time disables autoplay.  Press the reset button to re-enable autoplay.