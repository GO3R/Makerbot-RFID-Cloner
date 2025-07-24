Two versions available! 

I have a lot of empty SR-30 spools and i respool them with ABS (its way cheaper than buing original from Makerbot). The one problem with that is, i only have one ABS RFID chip. So i made my own RFID cloner for these chips.

You can only duplicate existing RFID tags from your spools. You can not use this product to make a new material. 

I "reverse engeneered" the original RFID tag contents for you, but i will not share that. Makerbot please do not sue me :) 

You need the following Library: https://github.com/ATrappmann/PN5180-Library



3D-Model and circuit board (both not necessary for the function, but it looks nicer) is attached. Hard wiring is possible, but extremely difficult, because you dont have much space in the enclosure. 

Version 2.0 of my Makerbot Method X RFID Coil Cloner is finally finished. Unfortunately, I had to remove the clone function, but you can still select all 16 materials and 16 different colors and read the tag in the serial monitor. Plus, you can now use the device from anywhere thanks to the integrated 9V battery.

I removed four LEDs because I needed the pins from the Arduino, so only one 220 ohm resistor is needed. A switch (previously used to fill the coil) was repurposed. This switches the battery supply to the Arduino. Pull-up resistors are now used for the switches and buttons, making the 10k ohm resistors unnecessary. The circuit board has been completely redesigned. Two OTAX KMR162s were added to allow material and color selection.

Unfortunately, I don't have all the materials, so the machine can't create them all. I have ABS, ASA, Nylon, NylonCF, PC-ABS, PETG, PLA, Tough, PVA, and SR-30. I don't have the MakerBot hex code for any other materials. If you have these materials, please send me the hex code (the output from the serial monitor). I will then expand the code a little bit until it's complete.

V2.1: I have addet two more Materials NylonCF and Tough (that is the special more tough PLA). To update from V2 to V2.1, you only need to flash the new Makerbot_RFIDV2.1.ino on your RFID Cloner.


![IMG_20250312_114832706](https://github.com/user-attachments/assets/55a54733-811a-4344-b1e5-6f94e4012ad8)



HOW TO USE THIS PRODUCT IN V1________________________________________________________________________________________

The first switch is switching between read and write. (one green LED is a status LED, one is for read and one is for write)

With the second switch you can choose to fill up the spool or not (Yellow LED on = fill spool).

You can start the read and write function with the button. The LED is blinking, when its either reading or writing. 

Green status LED = Success

Red status LED = Something went wrong (You can see what in the serial monitor on your PC)

You can read one RFID tag and copy it as often as you want.

You can not read one RFID tag and write to the same with the same data (you can't "fill" the spool directly)



HOW TO USE THIS PRODUCT IN V2________________________________________________________________________________________

One switch ist an OnOff switch, the other is the Read-Write selector switch. 

Select read and connect the device to your computer with a serial monitor. add an RFID Tag and read it.

Select write, a material and a colour, add the RFID Tag and write the material. 



HARDWARE YOU NEED V1________________________________________________________________________________________

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

JST XH connectors, i buy them in a set (https://www.ebay.de/itm/175923966477?_skw=jst+xh&itmmeta=01JF7RE7BS6BCZPJXQEYGT0QK3&hash=item28f5e2b20d:g:k~QAAOSwrwBlEuX9&itmprp=enc%3AAQAJAAAAwHoV3kP08IDx%2BKZ9MfhVJKnbRvawEu%2B8LMwjy22IyXHMFGQoypK%2BP99wUpl74c3Shsb5031voZ7Elp2Y5rr1cnSrt%2FH1HYbOoYFthzPSpJzHo%2FDVP57WFXn93Xlbfuq22HPrJMpSqqaMV%2ByNIzVOWLdVqVBmzq4O7NO%2BiFERnPkYlSbWIv%2BWIPW0ks2SB8gBeqDLTAxMF2xIVMGQURE8srL3bIoqH0XsqCWC5MZrvEYBQVrweXD9M4PPJjd0NEWSRA%3D%3D%7Ctkp%3ABk9SR4z2uPj5ZA)
(7X 2Pin, 1X 3Pin, 1X 4Pin, 1X5Pin)

2X female headers 6 pin (https://www.reichelt.de/buchsenleisten-2-54-mm-1x06-gerade-mpe-094-1-006-p119915.html?&trstct=pol_7&nbc=1) (you don't need them, if you solder the level shifter in place)

1X male headers (https://www.reichelt.de/stiftleisten-2-54-mm-1x24-gerade-mpe-087-1-024-p119889.html?&trstct=pol_11&nbc=1) (you need at least 19 Pins for the Arduino and 12 for the level shifter)

8X M3x5 screw (https://www.ebay.de/itm/371713576275?_skw=m3x5&itmmeta=01JF7XCENQA1R7PBYJD1W71DF9&hash=item568bdb0d53%3Ag%3AwDQAAOSw8thZnFHJ&itmprp=enc%3AAQAJAAAAwHoV3kP08IDx%2BKZ9MfhVJKkly9PinaU0nvnuiB6hH%2FWr7o1ZXoZsEApFP5SxZfG9Kuy8sq0PJFaigqiJTBfd7ERH0SAIsUPBXh1QsEzAxBPMdhcxEDbBqu7g%2FLz3d5MrcnwDAE0Q3%2FgWUyzbJJD%2BTL7VSRrIHwcSoE%2Bq1uMfaM4c23357kkW7G54Xxxxh0N4LYaHsmDUQteNc501i1DJewiW3Hiii46r9IrMN00bEjqv3yQl6nD53qCPN4QVQ0cu7g%3D%3D%7Ctkp%3ABlBMUIzrsf35ZA&var=640692312773) (for fixing the RFID reader and the Arduino)

4X M3x10 screw (https://www.ebay.de/itm/371713576275?_skw=m3x5&itmmeta=01JF7XCENQA1R7PBYJD1W71DF9&hash=item568bdb0d53%3Ag%3AwDQAAOSw8thZnFHJ&itmprp=enc%3AAQAJAAAAwHoV3kP08IDx%2BKZ9MfhVJKkly9PinaU0nvnuiB6hH%2FWr7o1ZXoZsEApFP5SxZfG9Kuy8sq0PJFaigqiJTBfd7ERH0SAIsUPBXh1QsEzAxBPMdhcxEDbBqu7g%2FLz3d5MrcnwDAE0Q3%2FgWUyzbJJD%2BTL7VSRrIHwcSoE%2Bq1uMfaM4c23357kkW7G54Xxxxh0N4LYaHsmDUQteNc501i1DJewiW3Hiii46r9IrMN00bEjqv3yQl6nD53qCPN4QVQ0cu7g%3D%3D%7Ctkp%3ABlBMUIzrsf35ZA&var=640692312785) (for closing the enclosure)

12X M3x4 Heat set insert (https://www.ebay.de/itm/365099517164?_skw=m3+heat+set+insert&itmmeta=01JF7X515R4HQZA5W9H7KC739H&hash=item5501a084ec:g:~2cAAOSw5dRm-uM4&itmprp=enc%3AAQAJAAAA8HoV3kP08IDx%2BKZ9MfhVJKnlBm8j0I69Sj1BbFbPdS8nYluoulM0gPdxg3o6He4ZQ%2B2inAb%2Fx1iL%2B5nDg87jp2D8cdYijXuN6lU3qulGXgiR8%2Br0VKpuOzf6F%2Fhq1xBEKgG0P5IoC8KRwZCPXckpipD3NUH02bmZMbyxsJG%2Bi5I59XkpH7Pn3vsHFkcPHAH25VEDUF9Wv%2Bdrpj6%2B85e6i1u1xg8hfjn0DY%2B7clZgKeuuznTwwYOFkSU74EX7Zxjyo8OfMmh20J6cD32%2FzyEcwYKqwihJjIxv2SPWmv7jqdCKNBd6dod1XYUgBPgH9D7xMQ%3D%3D%7Ctkp%3ABk9SR4qTlP35ZA) (Optional)

Soldering iron and wires to connect it

3D Printer for the case



HARDWARE YOU NEED V2________________________________________________________________________________________

1X Arduino UNO R3 (https://www.reichelt.de/arduino-uno-rev-3-dip-variante-atmega328-usb-arduino-uno-dip-p154902.html?&trstct=pos_2&nbc=1)

1X Adafruit bidirectional level shifter (https://www.reichelt.de/entwicklerboards-bidirektionaler-logikpegelkonverter-4-kanal--debo-logic-4ch-p235503.html?PROVID=2788&gad_source=1&gclid=CjwKCAiA0rW6BhAcEiwAQH28IkAeBbxkydem947jZAJKp2vnG3u0HDU44NT42CdebqoHi3iF8ZTFbBoCd54QAvD_BwE)

1X PN5180 RFID Reader (I only found them for sale in China ; https://www.ebay.de/itm/162768430788?srsltid=AfmBOop9j9C-VffmtjEJo-Qw5yhp8ghc4ka8X3xlJzSkLfzv2_8m_6zh)

1X Button (https://www.reichelt.de/miniatur-drucktaster-0-5a-24vac-1x-ein-sw-t-113a-sw-p45167.html?&trstct=vrt_pdn&nbc=1)

2X Switch (https://www.reichelt.de/kippschalter-6a-125vac-1x-ein-ein-ms-500a-p13150.html?&trstct=pol_0&nbc=1)

1X LED Red (https://www.reichelt.de/led-5-mm-bedrahtet-rot-fr-led-5-rd-dif-p230933.html?&trstct=pos_1&nbc=1)

1X 220Ohm Resistor (https://www.reichelt.de/widerstand-metallschicht-220-ohm-0207-0-6-0-1--mpr-220-p12875.html?&trstct=pos_0&nbc=1)

JST XH connectors, i buy them in a set (https://www.ebay.de/itm/175923966477?_skw=jst+xh&itmmeta=01JF7RE7BS6BCZPJXQEYGT0QK3&hash=item28f5e2b20d:g:k~QAAOSwrwBlEuX9&itmprp=enc%3AAQAJAAAAwHoV3kP08IDx%2BKZ9MfhVJKnbRvawEu%2B8LMwjy22IyXHMFGQoypK%2BP99wUpl74c3Shsb5031voZ7Elp2Y5rr1cnSrt%2FH1HYbOoYFthzPSpJzHo%2FDVP57WFXn93Xlbfuq22HPrJMpSqqaMV%2ByNIzVOWLdVqVBmzq4O7NO%2BiFERnPkYlSbWIv%2BWIPW0ks2SB8gBeqDLTAxMF2xIVMGQURE8srL3bIoqH0XsqCWC5MZrvEYBQVrweXD9M4PPJjd0NEWSRA%3D%3D%7Ctkp%3ABk9SR4z2uPj5ZA)
(7X 2Pin, 1X 3Pin, 1X 4Pin, 1X5Pin)

2X female headers 6 pin (https://www.reichelt.de/buchsenleisten-2-54-mm-1x06-gerade-mpe-094-1-006-p119915.html?&trstct=pol_7&nbc=1) (you don't need them, if you solder the level shifter in place)

1X male headers (https://www.reichelt.de/stiftleisten-2-54-mm-1x24-gerade-mpe-087-1-024-p119889.html?&trstct=pol_11&nbc=1) (you need at least 19 Pins for the Arduino and 12 for the level shifter)

8X M3x5 screw (https://www.ebay.de/itm/371713576275?_skw=m3x5&itmmeta=01JF7XCENQA1R7PBYJD1W71DF9&hash=item568bdb0d53%3Ag%3AwDQAAOSw8thZnFHJ&itmprp=enc%3AAQAJAAAAwHoV3kP08IDx%2BKZ9MfhVJKkly9PinaU0nvnuiB6hH%2FWr7o1ZXoZsEApFP5SxZfG9Kuy8sq0PJFaigqiJTBfd7ERH0SAIsUPBXh1QsEzAxBPMdhcxEDbBqu7g%2FLz3d5MrcnwDAE0Q3%2FgWUyzbJJD%2BTL7VSRrIHwcSoE%2Bq1uMfaM4c23357kkW7G54Xxxxh0N4LYaHsmDUQteNc501i1DJewiW3Hiii46r9IrMN00bEjqv3yQl6nD53qCPN4QVQ0cu7g%3D%3D%7Ctkp%3ABlBMUIzrsf35ZA&var=640692312773) (for fixing the RFID reader and the Arduino)

2X M3x10 screw (https://www.ebay.de/itm/371713576275?_skw=m3x5&itmmeta=01JF7XCENQA1R7PBYJD1W71DF9&hash=item568bdb0d53%3Ag%3AwDQAAOSw8thZnFHJ&itmprp=enc%3AAQAJAAAAwHoV3kP08IDx%2BKZ9MfhVJKkly9PinaU0nvnuiB6hH%2FWr7o1ZXoZsEApFP5SxZfG9Kuy8sq0PJFaigqiJTBfd7ERH0SAIsUPBXh1QsEzAxBPMdhcxEDbBqu7g%2FLz3d5MrcnwDAE0Q3%2FgWUyzbJJD%2BTL7VSRrIHwcSoE%2Bq1uMfaM4c23357kkW7G54Xxxxh0N4LYaHsmDUQteNc501i1DJewiW3Hiii46r9IrMN00bEjqv3yQl6nD53qCPN4QVQ0cu7g%3D%3D%7Ctkp%3ABlBMUIzrsf35ZA&var=640692312785) (for closing the enclosure)

10X M3x4 Heat set insert (https://www.ebay.de/itm/365099517164?_skw=m3+heat+set+insert&itmmeta=01JF7X515R4HQZA5W9H7KC739H&hash=item5501a084ec:g:~2cAAOSw5dRm-uM4&itmprp=enc%3AAQAJAAAA8HoV3kP08IDx%2BKZ9MfhVJKnlBm8j0I69Sj1BbFbPdS8nYluoulM0gPdxg3o6He4ZQ%2B2inAb%2Fx1iL%2B5nDg87jp2D8cdYijXuN6lU3qulGXgiR8%2Br0VKpuOzf6F%2Fhq1xBEKgG0P5IoC8KRwZCPXckpipD3NUH02bmZMbyxsJG%2Bi5I59XkpH7Pn3vsHFkcPHAH25VEDUF9Wv%2Bdrpj6%2B85e6i1u1xg8hfjn0DY%2B7clZgKeuuznTwwYOFkSU74EX7Zxjyo8OfMmh20J6cD32%2FzyEcwYKqwihJjIxv2SPWmv7jqdCKNBd6dod1XYUgBPgH9D7xMQ%3D%3D%7Ctkp%3ABk9SR4qTlP35ZA) (Optional)

2X OTAX KMR162 Switch (https://www.reichelt.de/de/de/shop/produkt/dreh-codierschalter_16-polig_mit_vertikal_achse-9434)

1X 9V Battery + Batteryclip (https://www.reichelt.de/de/de/shop/produkt/batterieclip_fuer_9-volt-block_vertikal-6665)

Soldering iron and wires to connect it

3D Printer for the case



RFID TAGS________________________________________________________________________________________

I use the old SR-30 RFID tags.

If you need new RFID tags, you can buy them easily (https://www.ebay.de/itm/364655662869?_skw=iso+15693&itmmeta=01JE3AMX6FMD4FZ348DKF9A4XN&hash=item54e72bd715:g:gB4AAOSwMKNlw~Vw&itmprp=enc%3AAQAJAAAA0HoV3kP08IDx%2BKZ9MfhVJKm4HNlsBZ7eKHAijT%2FPY0JAVfoXb2ZGtaMjs3CBv5SdTnZiQGq3%2Flrnm2FsDOtRHo2Ga1wn6SE6RR8K%2F%2BhD2UxB1BhdQtotgygYN2boV%2Fd3ArwA7K0NmbxbA6IIxaGS46IZnDWxzUzFM%2BJTaC%2FR8lONevazQb1DAW5gpIfILcorGATyS0ZGjA0DqFYP3Z9Mk2LpadfuxZzlLVJw5Unfkn%2F7U%2BqX%2BixDYyXX9ACW%2Fl%2FRVG906PzGiFlcRsRW5qgILDA%3D%7Ctkp%3ABk9SR7LT0-rwZA)

HOW TO CONNECT V1________________________________________________________________________________________

![PN5180connection](https://github.com/user-attachments/assets/2afcb0cf-af08-4ba9-9a9a-0d3039215cec)

HOW TO CONNECT V2________________________________________________________________________________________

![PN5180connectionV2](https://github.com/user-attachments/assets/02b10d63-5c87-4d55-b448-3e94b0a4e9ae)

