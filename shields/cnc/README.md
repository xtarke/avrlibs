# Rolland PNC-2300

New electronics for Rolland PNC-2300.

## Conections

![Board and driver](./figures/connections.svg)

- Enable (inverted):

    - ENA- : GND
    - ENA+ : Arduino GPIO  (driver in Figure)

- Direction:

    - DIR- : Arduino GPIO (driver in Figure)
    - DIR+ : +5V

- Pulses:

    - PUL- : Arduino GPIO (driver in Figure)
    - PUL+ : +5V
    
 - Switches: Habilitado debounce por software em config.h (GRBL).
             Colocado capacitor 22nF no eixo Z
             
 - Fundo de escala eixo Z: 26.65mm

## Software

- Arduino Uno: [grbl](https://github.com/grbl/grbl)

$0 = 10    (step pulse, usec)
$1 = 25    (step idle delay, msec)
$2 = 0    (step port invert mask:00000000)
$3 = 1    (dir port invert mask:00000001)
$4 = 0    (step enable invert, bool)
$5 = 0    (limit pins invert, bool)
$6 = 0    (probe pin invert, bool)
$10 = 31    (status report mask:00011111)
$11 = 0.010    (junction deviation, mm)
$12 = 0.002    (arc tolerance, mm)
$13 = 0    (report inches, bool)
$20 = 0    (soft limits, bool)
$21 = 1    (hard limits, bool)
$22 = 1    (homing cycle, bool)
$23 = 3    (homing dir invert mask:00000011)
$24 = 200.000    (homing feed, mm/min)
$25 = 500.000    (homing seek, mm/min)
$26 = 250    (homing debounce, msec)
$27 = 1.000    (homing pull-off, mm)
$100 = 290.000    (x, step/mm)
$101 = 290.000    (y, step/mm)
$102 = 3209.000    (z, step/mm)
$110 = 500.000    (x max rate, mm/min)
$111 = 500.000    (y max rate, mm/min)
$112 = 500.000    (z max rate, mm/min)
$120 = 10.000    (x accel, mm/sec^2)
$121 = 10.000    (y accel, mm/sec^2)
$122 = 10.000    (z accel, mm/sec^2)
$130 = 200.000    (x max travel, mm)
$131 = 200.000    (y max travel, mm)
$132 = 200.000    (z max travel, mm)
   

- PC:
  - [Universal Gcode Sender](http://winder.github.io/ugs_website/download/) (use Feed rate = 200)
  - Check:
    - https://opensource.com/article/19/1/cnc-milling-open-source-software
    - http://jscut.org/

## Refs:

- Hardware: https://blog.protoneer.co.nz/wp-content/uploads/2013/07/Arduino-CNC-Shield-Schematics.png
