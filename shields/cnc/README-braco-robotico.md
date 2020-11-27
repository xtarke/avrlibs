# grbl para o braço robótico

- Eixo Z: Rotate
- Eixo X: Lower
- Eixo Y: Higher

- Hardlimits: X+,Y+, Z+ (Vermelho e branco (Normalmente aberto))

- Arduino Uno: [grbl](https://github.com/grbl/grbl)

```
$0 = 10    (step pulse, usec)
$1 = 255    (step idle delay, msec)
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
$21 = 0    (hard limits, bool)
$22 = 1    (homing cycle, bool)
$23 = 4    (homing dir invert mask:00000100)
$24 = 25.000    (homing feed, mm/min)
$25 = 50.000    (homing seek, mm/min)
$26 = 250    (homing debounce, msec)
$27 = 1.000    (homing pull-off, mm)
$100 = 250.000    (x, step/mm)
$101 = 250.000    (y, step/mm)
$102 = 250.000    (z, step/mm)
$110 = 500.000    (x max rate, mm/min)
$111 = 500.000    (y max rate, mm/min)
$112 = 500.000    (z max rate, mm/min)
$120 = 10.000    (x accel, mm/sec^2)
$121 = 10.000    (y accel, mm/sec^2)
$122 = 10.000    (z accel, mm/sec^2)
$130 = 200.000    (x max travel, mm)
$131 = 200.000    (y max travel, mm)
$132 = 200.000    (z max travel, mm)
```
