<h1>Arduino Memory Game</h1>
<h2>Game Objective</h2>

<P>The objective of this memory game is to repeat a sequence of LED lights shown by the game. The sequence starts with a set lenght of LED, and each level adds an additional LED to the sequence. The game continues until the player makes a mistake.</p>

<h2>Gameplay</h2>

<p>The game is played using six pushbuttons and six LEDs. When the game starts, a sequence of LEDs will light up one by one, and the player must repeat the sequence by pressing the corresponding buttons in the correct order. If the player gets the sequence correct, the game will move on to the next level, which will have one more LED in the sequence. If the player makes a mistake, the game will end, and the player will have to start over.</p>

<h2>Hardware Requirements</h2>

<h3>To play this game, you will need:</h3>

    An Arduino Uno or Nano board
    Six LEDs (any color)
    Six pushbuttons
    Six 10k ohm resistors
    Six 330 ohm resistors
    Breadboard
    Jumper wires

<h2>Software Requirements</h2>

<h3>To program the Arduino, you will need:</h3>

    <p>Arduino IDE software (version 1.8 or later)</p>

<h2>Installation</h2>

<h3>To install and run this game on your Arduino board, follow these steps:</h3>

    Connect the six LEDs to digital pins 2 to 7 on the Arduino board, and connect the six 330 ohm resistors in series with each LED.
    Connect the six pushbuttons to digital pins 8 to 13 on the Arduino board, and connect the six 10k ohm resistors in series with each button.
    Connect the power and ground rails of the breadboard to the corresponding pins on the Arduino board.
    Download the .ino file from this repository.
    Open the .ino file in the Arduino IDE software.
    Upload the code to the Arduino board.




<p>To start the game, press the reset button on the Arduino board. The first LED will light up, and then turn off. The sequence of LEDs will then begin, with one LED lighting up at a time. After the sequence ends, the player must press the corresponding buttons in the same order as the LED sequence. If the player gets the sequence correct, the game will move on to the next level. If the player makes a mistake, the game will end, and the player will have to start over.</p>

<h2>Circuit</h2>
<img src="https://user-images.githubusercontent.com/110321699/226264859-08312a46-4504-4bff-b7fd-3cc83179ecc5.png">
