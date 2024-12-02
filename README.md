I have a lot of empty SR-30 spools and i respool them with ABS (its way cheaper than buing original from Makerbot). The one problem with that is, i only have one ABS RFID chip. So i made my own RFID cloner for these chips.

You need the following Library: https://github.com/ATrappmann/PN5180-Library


HOW TO USE THIS PRODUCT_____________________________________________________________________________________________________

The first switch is switching between read and write. (one green LED is a status LED, one is for read and one is for write)

With the second switch you can choose to fill up the spool or not (Yellow LED on = fill spool).

You can start the read and write function with the button. The LED is blinking, when its either reading or writing. 

Green status LED = Success

Red status LED = Something went wrong (You can see what in the serial monitor on your PC)

You can read one RFID tag and copy it as often as you want.

You can not read one RFID tag and write to the same with the same data (you can't "fill" the spool directly)


HARDWARE YOU NEED______________________________________________________________________________________________________________

1X Arduino UNO R3 (https://www.reichelt.de/arduino-uno-rev-3-dip-variante-atmega328-usb-arduino-uno-dip-p154902.html?&trstct=pos_2&nbc=1)

1X Adafruit bidirectional level shifter (https://www.reichelt.de/entwicklerboards-bidirektionaler-logikpegelkonverter-4-kanal--debo-logic-4ch-p235503.html?PROVID=2788&gad_source=1&gclid=CjwKCAiA0rW6BhAcEiwAQH28IkAeBbxkydem947jZAJKp2vnG3u0HDU44NT42CdebqoHi3iF8ZTFbBoCd54QAvD_BwE)

1X PN5180 RFID Reader (I only found them for sale in China ; https://www.ebay.de/itm/162768430788?srsltid=AfmBOop9j9C-VffmtjEJo-Qw5yhp8ghc4ka8X3xlJzSkLfzv2_8m_6zh)

1X Button (https://www.reichelt.de/miniatur-drucktaster-0-5a-24vac-1x-ein-sw-t-113a-sw-p45167.html?&trstct=vrt_pdn&nbc=1)

2X Switch (https://www.reichelt.de/kippschalter-6a-125vac-1x-ein-ein-ms-500a-p13150.html?&trstct=pol_0&nbc=1)

3X LED Green (https://www.reichelt.de/led-5mm-bedrahtet-gruen-2000-mcd-60--5034g3d-esa-a-p361637.html?&trstct=pos_7&nbc=1)

1X LED Yellow (https://www.reichelt.de/led-5mm-bedrahtet-gelb-130-mcd-60--5003y1d-ehb-a-p361633.html?&trstct=pos_5&nbc=1)

1X LED Red (https://www.reichelt.de/led-5-mm-bedrahtet-rot-fr-led-5-rd-dif-p230933.html?&trstct=pos_1&nbc=1)

5X 220Ohm Resistor (https://www.reichelt.de/widerstand-metallschicht-220-ohm-0207-0-6-0-1--mpr-220-p12875.html?&trstct=pos_0&nbc=1)

4X 10KOhm Resistor (https://www.reichelt.de/widerstand-metallschicht-10-kohm-axial-1-w-5--vis-pr0100010105-p237110.html?&trstct=pos_6&nbc=1)

Soldering iron and wires to connect it

3D Printer for the case


RFID TAGS________________________________________________________________________________________________________________
I use the old SR-30 RFID tags.

If you need new RFID tags, you can buy them easily (https://www.ebay.de/itm/364655662869?_skw=iso+15693&itmmeta=01JE3AMX6FMD4FZ348DKF9A4XN&hash=item54e72bd715:g:gB4AAOSwMKNlw~Vw&itmprp=enc%3AAQAJAAAA0HoV3kP08IDx%2BKZ9MfhVJKm4HNlsBZ7eKHAijT%2FPY0JAVfoXb2ZGtaMjs3CBv5SdTnZiQGq3%2Flrnm2FsDOtRHo2Ga1wn6SE6RR8K%2F%2BhD2UxB1BhdQtotgygYN2boV%2Fd3ArwA7K0NmbxbA6IIxaGS46IZnDWxzUzFM%2BJTaC%2FR8lONevazQb1DAW5gpIfILcorGATyS0ZGjA0DqFYP3Z9Mk2LpadfuxZzlLVJw5Unfkn%2F7U%2BqX%2BixDYyXX9ACW%2Fl%2FRVG906PzGiFlcRsRW5qgILDA%3D%7Ctkp%3ABk9SR7LT0-rwZA)

