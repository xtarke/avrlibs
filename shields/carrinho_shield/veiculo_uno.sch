EESchema Schematic File Version 4
LIBS:veiculo_uno-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "lun. 30 mars 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 8950 1450 1    60   ~ 0
Vin
Text Label 9350 1450 1    60   ~ 0
IOREF
Text Label 8900 2500 0    60   ~ 0
A0
Text Label 8900 2600 0    60   ~ 0
A1
Text Label 8900 2700 0    60   ~ 0
A2
Text Label 8900 2800 0    60   ~ 0
A3
Text Label 8900 2900 0    60   ~ 0
A4(SDA)
Text Label 8900 3000 0    60   ~ 0
A5(SCL)
Text Label 10550 3000 0    60   ~ 0
0(Rx)
Text Label 10550 2800 0    60   ~ 0
2
Text Label 10550 2900 0    60   ~ 0
1(Tx)
Text Label 10550 2700 0    60   ~ 0
3(**)
Text Label 10550 2600 0    60   ~ 0
4
Text Label 10550 2500 0    60   ~ 0
5(**)
Text Label 10550 2400 0    60   ~ 0
6(**)
Text Label 10550 2300 0    60   ~ 0
7
Text Label 10550 2100 0    60   ~ 0
8
Text Label 10550 2000 0    60   ~ 0
9(**)
Text Label 10550 1900 0    60   ~ 0
10(**/SS)
Text Label 10550 1800 0    60   ~ 0
11(**/MOSI)
Text Label 10550 1700 0    60   ~ 0
12(MISO)
Text Label 10550 1600 0    60   ~ 0
13(SCK)
Text Label 10550 1400 0    60   ~ 0
AREF
NoConn ~ 9400 1600
Text Label 10550 1300 0    60   ~ 0
A4(SDA)
Text Label 10550 1200 0    60   ~ 0
A5(SCL)
Text Notes 10850 1000 0    60   ~ 0
Holes
Text Notes 8550 750  0    60   ~ 0
Shield for Arduino that uses\nthe same pin disposition\nlike "Uno" board Rev 3.
$Comp
L Connector_Generic:Conn_01x08 P1
U 1 1 56D70129
P 9600 1900
F 0 "P1" H 9600 2350 50  0000 C CNN
F 1 "Power" V 9700 1900 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 9750 1900 20  0000 C CNN
F 3 "" H 9600 1900 50  0000 C CNN
	1    9600 1900
	1    0    0    -1  
$EndComp
Text Label 8650 1800 0    60   ~ 0
Reset
$Comp
L power:+3.3V #PWR03
U 1 1 56D70538
P 9150 1450
F 0 "#PWR03" H 9150 1300 50  0001 C CNN
F 1 "+3.3V" V 9150 1700 50  0000 C CNN
F 2 "" H 9150 1450 50  0000 C CNN
F 3 "" H 9150 1450 50  0000 C CNN
	1    9150 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 56D707BB
P 9050 1350
F 0 "#PWR02" H 9050 1200 50  0001 C CNN
F 1 "+5V" V 9050 1550 50  0000 C CNN
F 2 "" H 9050 1350 50  0000 C CNN
F 3 "" H 9050 1350 50  0000 C CNN
	1    9050 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 56D70CC2
P 9300 3150
F 0 "#PWR04" H 9300 2900 50  0001 C CNN
F 1 "GND" H 9300 3000 50  0000 C CNN
F 2 "" H 9300 3150 50  0000 C CNN
F 3 "" H 9300 3150 50  0000 C CNN
	1    9300 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 56D70CFF
P 10300 3150
F 0 "#PWR05" H 10300 2900 50  0001 C CNN
F 1 "GND" H 10300 3000 50  0000 C CNN
F 2 "" H 10300 3150 50  0000 C CNN
F 3 "" H 10300 3150 50  0000 C CNN
	1    10300 3150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 P2
U 1 1 56D70DD8
P 9600 2700
F 0 "P2" H 9600 2300 50  0000 C CNN
F 1 "Analog" V 9700 2700 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x06" V 9750 2750 20  0000 C CNN
F 3 "" H 9600 2700 50  0000 C CNN
	1    9600 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P5
U 1 1 56D71177
P 10800 650
F 0 "P5" V 10900 650 50  0000 C CNN
F 1 "CONN_01X01" V 10900 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 10721 724 20  0000 C CNN
F 3 "" H 10800 650 50  0000 C CNN
	1    10800 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P6
U 1 1 56D71274
P 10900 650
F 0 "P6" V 11000 650 50  0000 C CNN
F 1 "CONN_01X01" V 11000 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 10900 650 20  0001 C CNN
F 3 "" H 10900 650 50  0000 C CNN
	1    10900 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P7
U 1 1 56D712A8
P 11000 650
F 0 "P7" V 11100 650 50  0000 C CNN
F 1 "CONN_01X01" V 11100 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" V 11000 650 20  0001 C CNN
F 3 "" H 11000 650 50  0000 C CNN
	1    11000 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P8
U 1 1 56D712DB
P 11100 650
F 0 "P8" V 11200 650 50  0000 C CNN
F 1 "CONN_01X01" V 11200 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 11024 572 20  0000 C CNN
F 3 "" H 11100 650 50  0000 C CNN
	1    11100 650 
	0    -1   -1   0   
$EndComp
NoConn ~ 10800 850 
NoConn ~ 10900 850 
NoConn ~ 11000 850 
NoConn ~ 11100 850 
$Comp
L Connector_Generic:Conn_01x08 P4
U 1 1 56D7164F
P 10000 2600
F 0 "P4" H 10000 2100 50  0000 C CNN
F 1 "Digital" V 10100 2600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 10150 2550 20  0000 C CNN
F 3 "" H 10000 2600 50  0000 C CNN
	1    10000 2600
	-1   0    0    -1  
$EndComp
Wire Notes Line
	8525 825  9925 825 
Wire Notes Line
	9925 825  9925 475 
Wire Wire Line
	9350 1450 9350 1700
Wire Wire Line
	9350 1700 9400 1700
Wire Wire Line
	9400 1900 9150 1900
Wire Wire Line
	9400 2000 9050 2000
Wire Wire Line
	9400 2300 8950 2300
Wire Wire Line
	9400 2100 9300 2100
Wire Wire Line
	9400 2200 9300 2200
Connection ~ 9300 2200
Wire Wire Line
	8950 2300 8950 1450
Wire Wire Line
	9050 2000 9050 1350
Wire Wire Line
	9150 1900 9150 1450
Wire Wire Line
	9400 2900 8900 2900
Wire Wire Line
	9400 3000 8900 3000
$Comp
L Connector_Generic:Conn_01x10 P3
U 1 1 56D721E0
P 10000 1600
F 0 "P3" H 10000 2150 50  0000 C CNN
F 1 "Digital" V 10100 1600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x10" V 10150 1600 20  0000 C CNN
F 3 "" H 10000 1600 50  0000 C CNN
	1    10000 1600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10200 1400 10550 1400
Wire Wire Line
	10200 1300 10550 1300
Wire Wire Line
	10200 1200 10550 1200
Wire Wire Line
	10200 1500 10300 1500
Wire Wire Line
	10300 1500 10300 3150
Wire Wire Line
	9300 2100 9300 2200
Wire Notes Line
	8500 500  8500 3450
Wire Notes Line
	8500 3450 11200 3450
Wire Wire Line
	9400 1800 8650 1800
Text Notes 9700 1600 0    60   ~ 0
1
Wire Notes Line
	11200 1000 10700 1000
Wire Notes Line
	10700 1000 10700 500 
$Comp
L Connector:Conn_01x26_Male J1
U 1 1 5E6B62DC
P 1850 2500
F 0 "J1" H 1956 3878 50  0000 C CNN
F 1 "Conn_01x26_Male" H 1956 3787 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x13_P2.54mm_Vertical" H 1850 2500 50  0001 C CNN
F 3 "~" H 1850 2500 50  0001 C CNN
	1    1850 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J6
U 1 1 5E6BC9D5
P 7750 1150
F 0 "J6" H 7856 1328 50  0000 C CNN
F 1 "Conn_01x02_Male" V 8250 1100 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7750 1150 50  0001 C CNN
F 3 "~" H 7750 1150 50  0001 C CNN
	1    7750 1150
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5E6C3DB8
P 6500 1150
F 0 "J2" V 6653 963 50  0000 R CNN
F 1 "Conn_01x02_Male" V 6562 963 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6500 1150 50  0001 C CNN
F 3 "~" H 6500 1150 50  0001 C CNN
	1    6500 1150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9300 2200 9300 3150
$Comp
L power:GND #PWR01
U 1 1 5E6CC8B6
P 2500 1400
F 0 "#PWR01" H 2500 1150 50  0001 C CNN
F 1 "GND" H 2500 1250 50  0000 C CNN
F 2 "" H 2500 1400 50  0000 C CNN
F 3 "" H 2500 1400 50  0000 C CNN
	1    2500 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 1300 2500 1300
Wire Wire Line
	2500 1300 2500 1400
Text GLabel 7600 800  0    50   Input ~ 0
ADC3
Text GLabel 8750 2800 0    50   Input ~ 0
A3
Wire Wire Line
	8750 2800 9400 2800
Text GLabel 7950 800  2    50   Input ~ 0
A3
Wire Wire Line
	7950 800  7850 800 
Wire Wire Line
	7850 800  7850 950 
Wire Wire Line
	7600 800  7750 800 
Wire Wire Line
	7750 800  7750 950 
Text GLabel 2300 1700 2    50   Input ~ 0
ADC3
Wire Wire Line
	2050 1700 2300 1700
Text GLabel 10850 2600 2    50   Input ~ 0
4
Text GLabel 6700 800  2    50   Input ~ 0
4
Wire Wire Line
	6700 800  6600 800 
Wire Wire Line
	6600 800  6600 950 
Text GLabel 6400 800  0    50   Input ~ 0
Echo1
Wire Wire Line
	6500 950  6500 800 
Wire Wire Line
	6500 800  6400 800 
$Comp
L Connector:Conn_01x02_Male J9
U 1 1 5E6D99F8
P 5600 1150
F 0 "J9" V 5753 963 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5662 963 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5600 1150 50  0001 C CNN
F 3 "~" H 5600 1150 50  0001 C CNN
	1    5600 1150
	0    -1   -1   0   
$EndComp
Text GLabel 11050 1900 2    50   Input ~ 0
10
Text GLabel 10900 2300 2    50   Input ~ 0
7
$Comp
L Connector:Conn_01x02_Male J3
U 1 1 5E6DCAD9
P 4650 1150
F 0 "J3" V 4803 963 50  0000 R CNN
F 1 "Conn_01x02_Male" V 4712 963 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4650 1150 50  0001 C CNN
F 3 "~" H 4650 1150 50  0001 C CNN
	1    4650 1150
	0    -1   -1   0   
$EndComp
Text GLabel 5800 800  2    50   Input ~ 0
7
Text GLabel 4850 800  2    50   Input ~ 0
10
Wire Wire Line
	5800 800  5700 800 
Wire Wire Line
	5700 800  5700 950 
Wire Wire Line
	4750 800  4750 950 
Wire Wire Line
	4750 800  4850 800 
Text GLabel 4550 800  0    50   Input ~ 0
R_TCRT
Wire Wire Line
	4550 800  4650 800 
Wire Wire Line
	4650 800  4650 950 
Text GLabel 5550 800  0    50   Input ~ 0
L_TCRT
Wire Wire Line
	5550 800  5600 800 
Wire Wire Line
	5600 800  5600 950 
$Comp
L Connector:Conn_01x02_Male J18
U 1 1 5E6E73BA
P 7750 2050
F 0 "J18" V 7903 1863 50  0000 R CNN
F 1 "Conn_01x02_Male" V 7812 1863 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7750 2050 50  0001 C CNN
F 3 "~" H 7750 2050 50  0001 C CNN
	1    7750 2050
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J14
U 1 1 5E6E742E
P 6650 2050
F 0 "J14" V 6803 1863 50  0000 R CNN
F 1 "Conn_01x02_Male" V 6712 1863 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6650 2050 50  0001 C CNN
F 3 "~" H 6650 2050 50  0001 C CNN
	1    6650 2050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10200 2600 10850 2600
Wire Wire Line
	10200 1900 11050 1900
Wire Wire Line
	10200 2300 10900 2300
Text GLabel 11050 1600 2    50   Input ~ 0
13
Wire Wire Line
	10200 1600 11050 1600
Text GLabel 7900 1700 2    50   Input ~ 0
13
Wire Wire Line
	7900 1700 7850 1700
Wire Wire Line
	7850 1700 7850 1850
Text GLabel 7700 1700 0    50   Input ~ 0
D0
Wire Wire Line
	7700 1700 7750 1700
Wire Wire Line
	7750 1700 7750 1850
Text GLabel 10850 2800 2    50   Input ~ 0
2
Wire Wire Line
	10200 2800 10850 2800
Text GLabel 6800 1700 2    50   Input ~ 0
2
Text GLabel 6600 1700 0    50   Input ~ 0
Trig1
Wire Wire Line
	6800 1700 6750 1700
Wire Wire Line
	6750 1700 6750 1850
Wire Wire Line
	6600 1700 6650 1700
Wire Wire Line
	6650 1700 6650 1850
$Comp
L Connector:Conn_01x02_Male J10
U 1 1 5E6FE4FA
P 5600 2050
F 0 "J10" V 5753 1863 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5662 1863 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5600 2050 50  0001 C CNN
F 3 "~" H 5600 2050 50  0001 C CNN
	1    5600 2050
	0    -1   -1   0   
$EndComp
Text GLabel 11050 2000 2    50   Input ~ 0
9
Wire Wire Line
	10200 2000 11050 2000
Text GLabel 5750 1700 2    50   Input ~ 0
9
Text GLabel 5550 1700 0    50   Input ~ 0
Trig0
Wire Wire Line
	5550 1700 5600 1700
Wire Wire Line
	5600 1700 5600 1850
Wire Wire Line
	5700 1850 5700 1700
Wire Wire Line
	5700 1700 5750 1700
$Comp
L Connector:Conn_01x02_Male J4
U 1 1 5E70305F
P 4650 2050
F 0 "J4" V 4803 1863 50  0000 R CNN
F 1 "Conn_01x02_Male" V 4712 1863 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4650 2050 50  0001 C CNN
F 3 "~" H 4650 2050 50  0001 C CNN
	1    4650 2050
	0    -1   -1   0   
$EndComp
Text GLabel 4600 1700 0    50   Input ~ 0
Echo0
Wire Wire Line
	4600 1700 4650 1700
Wire Wire Line
	4650 1700 4650 1850
Text GLabel 4800 1700 2    50   Input ~ 0
8
Wire Wire Line
	4750 1850 4750 1700
Wire Wire Line
	4750 1700 4800 1700
Text GLabel 11050 2100 2    50   Input ~ 0
8
Wire Wire Line
	10200 2100 11050 2100
Text GLabel 7900 2400 2    50   Input ~ 0
12
Text GLabel 6800 2400 2    50   Input ~ 0
3
$Comp
L Connector:Conn_01x02_Male J19
U 1 1 5E7089E9
P 7750 2750
F 0 "J19" V 7903 2563 50  0000 R CNN
F 1 "Conn_01x02_Male" V 7812 2563 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7750 2750 50  0001 C CNN
F 3 "~" H 7750 2750 50  0001 C CNN
	1    7750 2750
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J15
U 1 1 5E708A39
P 6650 2750
F 0 "J15" V 6803 2563 50  0000 R CNN
F 1 "Conn_01x02_Male" V 6712 2563 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6650 2750 50  0001 C CNN
F 3 "~" H 6650 2750 50  0001 C CNN
	1    6650 2750
	0    -1   -1   0   
$EndComp
Text GLabel 7700 2400 0    50   Input ~ 0
D1
Wire Wire Line
	7700 2400 7750 2400
Wire Wire Line
	7750 2400 7750 2550
Wire Wire Line
	7900 2400 7850 2400
Wire Wire Line
	7850 2400 7850 2550
Wire Wire Line
	6800 2400 6750 2400
Wire Wire Line
	6750 2400 6750 2550
Text GLabel 6600 2400 0    50   Input ~ 0
PWM2N
Wire Wire Line
	6600 2400 6650 2400
Wire Wire Line
	6650 2400 6650 2550
Text GLabel 11050 1700 2    50   Input ~ 0
12
Wire Wire Line
	10200 1700 11050 1700
Text GLabel 10850 2700 2    50   Input ~ 0
3
Wire Wire Line
	10200 2500 10850 2500
Text GLabel 5550 2400 0    50   Input ~ 0
ADC0
$Comp
L Connector:Conn_01x02_Male J11
U 1 1 5E718E4F
P 5600 2750
F 0 "J11" V 5753 2563 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5662 2563 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5600 2750 50  0001 C CNN
F 3 "~" H 5600 2750 50  0001 C CNN
	1    5600 2750
	0    -1   -1   0   
$EndComp
Text GLabel 5750 2400 2    50   Input ~ 0
A0
Wire Wire Line
	5750 2400 5700 2400
Wire Wire Line
	5700 2400 5700 2550
Wire Wire Line
	5550 2400 5600 2400
Wire Wire Line
	5600 2400 5600 2550
Text GLabel 8750 2500 0    50   Input ~ 0
A0
Wire Wire Line
	8750 2500 9400 2500
Text GLabel 4600 2400 0    50   Input ~ 0
ADC1
$Comp
L Connector:Conn_01x02_Male J5
U 1 1 5E722316
P 4650 2750
F 0 "J5" V 4803 2563 50  0000 R CNN
F 1 "Conn_01x02_Male" V 4712 2563 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4650 2750 50  0001 C CNN
F 3 "~" H 4650 2750 50  0001 C CNN
	1    4650 2750
	0    -1   -1   0   
$EndComp
Text GLabel 4800 2400 2    50   Input ~ 0
A1
Wire Wire Line
	4800 2400 4750 2400
Wire Wire Line
	4750 2400 4750 2550
Wire Wire Line
	4600 2400 4650 2400
Wire Wire Line
	4650 2400 4650 2550
$Comp
L Connector:Conn_01x02_Male J20
U 1 1 5E7298F1
P 7750 3300
F 0 "J20" V 7903 3113 50  0000 R CNN
F 1 "Conn_01x02_Male" V 7812 3113 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7750 3300 50  0001 C CNN
F 3 "~" H 7750 3300 50  0001 C CNN
	1    7750 3300
	0    -1   -1   0   
$EndComp
Text GLabel 7700 3000 0    50   Input ~ 0
ADC2
Text GLabel 7900 3000 2    50   Input ~ 0
A2
Wire Wire Line
	7700 3000 7750 3000
Wire Wire Line
	7750 3000 7750 3100
Wire Wire Line
	7900 3000 7850 3000
Wire Wire Line
	7850 3000 7850 3100
Text GLabel 8750 2600 0    50   Input ~ 0
A1
Text GLabel 8750 2700 0    50   Input ~ 0
A2
Wire Wire Line
	8750 2600 9400 2600
Wire Wire Line
	8750 2700 9400 2700
Text GLabel 4600 3000 0    50   Input ~ 0
A2'
Text GLabel 4600 3400 0    50   Input ~ 0
A1'
$Comp
L Connector:Conn_01x02_Male J7
U 1 1 5E735226
P 4650 3300
F 0 "J7" V 4803 3113 50  0000 R CNN
F 1 "Conn_01x02_Male" V 4712 3113 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4650 3300 50  0001 C CNN
F 3 "~" H 4650 3300 50  0001 C CNN
	1    4650 3300
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J8
U 1 1 5E735276
P 4650 3700
F 0 "J8" V 4803 3513 50  0000 R CNN
F 1 "Conn_01x02_Male" V 4712 3513 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4650 3700 50  0001 C CNN
F 3 "~" H 4650 3700 50  0001 C CNN
	1    4650 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4600 3400 4650 3400
Wire Wire Line
	4650 3400 4650 3500
Wire Wire Line
	4600 3000 4650 3000
Wire Wire Line
	4650 3000 4650 3100
Text GLabel 4800 3000 2    50   Input ~ 0
Conector
Text GLabel 4800 3400 2    50   Input ~ 0
Conector'
Wire Wire Line
	4800 3000 4750 3000
Wire Wire Line
	4750 3000 4750 3100
Wire Wire Line
	4800 3400 4750 3400
Wire Wire Line
	4750 3400 4750 3500
Text GLabel 10850 3000 2    50   Input ~ 0
Rx
Text GLabel 10850 2900 2    50   Input ~ 0
Tx
Wire Wire Line
	10200 2900 10850 2900
Wire Wire Line
	10200 3000 10850 3000
$Comp
L Connector:Conn_01x02_Male J16
U 1 1 5E74836B
P 6850 3300
F 0 "J16" V 7003 3113 50  0000 R CNN
F 1 "Conn_01x02_Male" V 6912 3113 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6850 3300 50  0001 C CNN
F 3 "~" H 6850 3300 50  0001 C CNN
	1    6850 3300
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J12
U 1 1 5E7483D7
P 5900 3300
F 0 "J12" V 6053 3113 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5962 3113 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5900 3300 50  0001 C CNN
F 3 "~" H 5900 3300 50  0001 C CNN
	1    5900 3300
	0    -1   -1   0   
$EndComp
Text GLabel 7000 3000 2    50   Input ~ 0
Rx
Text GLabel 6050 3000 2    50   Input ~ 0
Tx
Text GLabel 5850 3000 0    50   Input ~ 0
RXB
Text GLabel 6800 3000 0    50   Input ~ 0
TXB
Wire Wire Line
	7000 3000 6950 3000
Wire Wire Line
	6950 3000 6950 3100
Wire Wire Line
	6800 3000 6850 3000
Wire Wire Line
	6850 3000 6850 3100
Wire Wire Line
	6050 3000 6000 3000
Wire Wire Line
	6000 3000 6000 3100
Wire Wire Line
	5850 3000 5900 3000
Wire Wire Line
	5900 3000 5900 3100
$Comp
L Connector:Conn_01x02_Male J21
U 1 1 5E76127F
P 7750 3750
F 0 "J21" V 7903 3563 50  0000 R CNN
F 1 "Conn_01x02_Male" V 7812 3563 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7750 3750 50  0001 C CNN
F 3 "~" H 7750 3750 50  0001 C CNN
	1    7750 3750
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J17
U 1 1 5E7612D7
P 6850 3750
F 0 "J17" V 7003 3563 50  0000 R CNN
F 1 "Conn_01x02_Male" V 6912 3563 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6850 3750 50  0001 C CNN
F 3 "~" H 6850 3750 50  0001 C CNN
	1    6850 3750
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J13
U 1 1 5E761337
P 5900 3750
F 0 "J13" V 6053 3563 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5962 3563 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5900 3750 50  0001 C CNN
F 3 "~" H 5900 3750 50  0001 C CNN
	1    5900 3750
	0    -1   -1   0   
$EndComp
Text GLabel 7700 3450 0    50   Input ~ 0
PWM1
Text GLabel 6800 3450 0    50   Input ~ 0
PWM1N
Text GLabel 5850 3450 0    50   Input ~ 0
PWM2
Wire Wire Line
	7700 3450 7750 3450
Wire Wire Line
	7750 3450 7750 3550
Wire Wire Line
	6800 3450 6850 3450
Wire Wire Line
	6850 3450 6850 3550
Wire Wire Line
	5850 3450 5900 3450
Wire Wire Line
	5900 3450 5900 3550
Text GLabel 7900 3450 2    50   Input ~ 0
6
Wire Wire Line
	7900 3450 7850 3450
Wire Wire Line
	7850 3450 7850 3550
Text GLabel 7000 3450 2    50   Input ~ 0
5
Text GLabel 6050 3450 2    50   Input ~ 0
11
Wire Wire Line
	6050 3450 6000 3450
Wire Wire Line
	6000 3450 6000 3550
Wire Wire Line
	7000 3450 6950 3450
Wire Wire Line
	6950 3450 6950 3550
Text GLabel 10850 2500 2    50   Input ~ 0
5
Wire Wire Line
	10200 2700 10850 2700
Text GLabel 10850 2400 2    50   Input ~ 0
6
Wire Wire Line
	10200 2400 10850 2400
Text GLabel 11050 1800 2    50   Input ~ 0
11
Wire Wire Line
	10200 1800 11050 1800
$EndSCHEMATC
