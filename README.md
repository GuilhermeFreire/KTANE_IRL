# Keep Talking and Nobody Explodes - In Real Life

This project's objective is to bring the amazing [Keep Talking and Nobody Explodes](http://www.keeptalkinggame.com/) game to **REAL LIFE**!

## The Plan

Starting simple, the idea is to recreate each of the modules using Arduinos (or equivalent microcontrollers).
A roadmap will soon be uploaded to this section so as to see what's coming up.

## The Modules

At first, the original modules from the game will be built.
But there's nothing stopping anyone from creating new modules, feel free to submit a pull request if you're so inclined.

### Wires

The first module I'm attempting to recreate is _Wires_.

So far, the module supports 2 wires. The code has the correct wire to cut hardcoded (it's the blue one).
If you're trying to reproduce it at home, here are the schematics.

![BLUE_and_RED_schematics](https://raw.githubusercontent.com/GuilhermeFreire/KTANE_IRL/master/schematics/blue_red_detector.png)

Thinking of the future, the code is setup so as to identify the colors of the wires according to the voltage passing through them.
Each color has an associated resistance, this way it's possible to detect the color of the wire electronically - independently of
the order the wires are setup.

In this example, we can clearly see the distinction between the **BLUE** and **RED** wires. The blue wire is associated with **two** 330Ω
resistors in series, while the red one is associated with only **one** 330Ω resistor.

![BLUE_and_RED_voltage](https://raw.githubusercontent.com/GuilhermeFreire/KTANE_IRL/master/images/blue_and_red.png)

The blue line correspond to the BLUE wire and the orange one to the RED wire (sorry for the lack of labels on the graph). The Y axis
represents Voltage on a scale from 0 to 1023 - where 0 represents 0V and 1023 represents 5V. The X axis represents time - it was recorded continuously at a rate of 9600Bd.
