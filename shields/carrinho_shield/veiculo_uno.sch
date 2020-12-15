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
L power:+3.3V #PWR04
U 1 1 56D70538
P 9150 1450
F 0 "#PWR04" H 9150 1300 50  0001 C CNN
F 1 "+3.3V" V 9150 1700 50  0000 C CNN
F 2 "" H 9150 1450 50  0000 C CNN
F 3 "" H 9150 1450 50  0000 C CNN
	1    9150 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 56D707BB
P 9050 1350
F 0 "#PWR01" H 9050 1200 50  0001 C CNN
F 1 "+5V" V 9050 1550 50  0000 C CNN
F 2 "" H 9050 1350 50  0000 C CNN
F 3 "" H 9050 1350 50  0000 C CNN
	1    9050 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 56D70CC2
P 9300 3150
F 0 "#PWR09" H 9300 2900 50  0001 C CNN
F 1 "GND" H 9300 3000 50  0000 C CNN
F 2 "" H 9300 3150 50  0000 C CNN
F 3 "" H 9300 3150 50  0000 C CNN
	1    9300 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 56D70CFF
P 10300 3150
F 0 "#PWR010" H 10300 2900 50  0001 C CNN
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
L Connector:Conn_01x02_Male J4
U 1 1 5E6BC9D5
P 5300 1650
F 0 "J4" H 5406 1828 50  0000 C CNN
F 1 "Conn_01x02_Male" V 5800 1600 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5300 1650 50  0001 C CNN
F 3 "~" H 5300 1650 50  0001 C CNN
	1    5300 1650
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J10
U 1 1 5E6C3DB8
P 5200 3650
F 0 "J10" V 5353 3463 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5262 3463 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5200 3650 50  0001 C CNN
F 3 "~" H 5200 3650 50  0001 C CNN
	1    5200 3650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9300 2200 9300 3150
Text GLabel 5150 1300 0    50   Input ~ 0
ADC3
Text GLabel 8750 2800 0    50   Input ~ 0
A3
Wire Wire Line
	8750 2800 9400 2800
Text GLabel 5500 1300 2    50   Input ~ 0
A3
Wire Wire Line
	5500 1300 5400 1300
Wire Wire Line
	5400 1300 5400 1450
Wire Wire Line
	5150 1300 5300 1300
Wire Wire Line
	5300 1300 5300 1450
Text GLabel 10850 2600 2    50   Input ~ 0
4
Text GLabel 5400 3300 2    50   Input ~ 0
2
Wire Wire Line
	5400 3300 5300 3300
Wire Wire Line
	5300 3300 5300 3450
Text GLabel 5100 3300 0    50   Input ~ 0
Echo1
Wire Wire Line
	5200 3450 5200 3300
Wire Wire Line
	5200 3300 5100 3300
$Comp
L Connector:Conn_01x02_Male J9
U 1 1 5E6D99F8
P 2550 5600
F 0 "J9" V 2703 5413 50  0000 R CNN
F 1 "Conn_01x02_Male" V 2612 5413 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2550 5600 50  0001 C CNN
F 3 "~" H 2550 5600 50  0001 C CNN
	1    2550 5600
	0    -1   -1   0   
$EndComp
Text GLabel 11050 1900 2    50   Input ~ 0
10
Text GLabel 10900 2300 2    50   Input ~ 0
7
$Comp
L Connector:Conn_01x02_Male J8
U 1 1 5E6DCAD9
P 1300 5600
F 0 "J8" V 1453 5413 50  0000 R CNN
F 1 "Conn_01x02_Male" V 1362 5413 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1300 5600 50  0001 C CNN
F 3 "~" H 1300 5600 50  0001 C CNN
	1    1300 5600
	0    -1   -1   0   
$EndComp
Text GLabel 2750 5250 2    50   Input ~ 0
A5(SCL)
Text GLabel 1500 5250 2    50   Input ~ 0
A4(SDA)
Wire Wire Line
	2750 5250 2650 5250
Wire Wire Line
	2650 5250 2650 5400
Wire Wire Line
	1400 5250 1400 5400
Wire Wire Line
	1400 5250 1500 5250
Text GLabel 1200 5250 0    50   Input ~ 0
R_TCRT
Wire Wire Line
	1200 5250 1300 5250
Wire Wire Line
	1300 5250 1300 5400
Text GLabel 2500 5250 0    50   Input ~ 0
L_TCRT
Wire Wire Line
	2500 5250 2550 5250
Wire Wire Line
	2550 5250 2550 5400
$Comp
L Connector:Conn_01x02_Male J14
U 1 1 5E6E73BA
P 5200 5100
F 0 "J14" V 5353 4913 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5262 4913 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5200 5100 50  0001 C CNN
F 3 "~" H 5200 5100 50  0001 C CNN
	1    5200 5100
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J13
U 1 1 5E6E742E
P 6500 3650
F 0 "J13" V 6653 3463 50  0000 R CNN
F 1 "Conn_01x02_Male" V 6562 3463 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6500 3650 50  0001 C CNN
F 3 "~" H 6500 3650 50  0001 C CNN
	1    6500 3650
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
Text GLabel 5350 4750 2    50   Input ~ 0
13
Wire Wire Line
	5350 4750 5300 4750
Wire Wire Line
	5300 4750 5300 4900
Text GLabel 5150 4750 0    50   Input ~ 0
D0
Wire Wire Line
	5150 4750 5200 4750
Wire Wire Line
	5200 4750 5200 4900
Text GLabel 10850 2800 2    50   Input ~ 0
2
Wire Wire Line
	10200 2800 10850 2800
Text GLabel 6650 3300 2    50   Input ~ 0
4
Text GLabel 6450 3300 0    50   Input ~ 0
Trig1
Wire Wire Line
	6650 3300 6600 3300
Wire Wire Line
	6600 3300 6600 3450
Wire Wire Line
	6450 3300 6500 3300
Wire Wire Line
	6500 3300 6500 3450
$Comp
L Connector:Conn_01x02_Male J12
U 1 1 5E6FE4FA
P 6500 3150
F 0 "J12" V 6653 2963 50  0000 R CNN
F 1 "Conn_01x02_Male" V 6562 2963 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6500 3150 50  0001 C CNN
F 3 "~" H 6500 3150 50  0001 C CNN
	1    6500 3150
	0    -1   -1   0   
$EndComp
Text GLabel 11050 2000 2    50   Input ~ 0
9
Wire Wire Line
	10200 2000 11050 2000
Text GLabel 6650 2800 2    50   Input ~ 0
7
Text GLabel 6450 2800 0    50   Input ~ 0
Trig0
Wire Wire Line
	6450 2800 6500 2800
Wire Wire Line
	6500 2800 6500 2950
Wire Wire Line
	6600 2950 6600 2800
Wire Wire Line
	6600 2800 6650 2800
$Comp
L Connector:Conn_01x02_Male J11
U 1 1 5E70305F
P 5200 3150
F 0 "J11" V 5353 2963 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5262 2963 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5200 3150 50  0001 C CNN
F 3 "~" H 5200 3150 50  0001 C CNN
	1    5200 3150
	0    -1   -1   0   
$EndComp
Text GLabel 5150 2800 0    50   Input ~ 0
Echo0
Wire Wire Line
	5150 2800 5200 2800
Wire Wire Line
	5200 2800 5200 2950
Text GLabel 5350 2800 2    50   Input ~ 0
8
Wire Wire Line
	5300 2950 5300 2800
Wire Wire Line
	5300 2800 5350 2800
Text GLabel 11050 2100 2    50   Input ~ 0
8
Wire Wire Line
	10200 2100 11050 2100
Text GLabel 5350 5200 2    50   Input ~ 0
12
Text GLabel 10050 4200 2    50   Input ~ 0
3
$Comp
L Connector:Conn_01x02_Male J16
U 1 1 5E7089E9
P 5200 5550
F 0 "J16" V 5353 5363 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5262 5363 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5200 5550 50  0001 C CNN
F 3 "~" H 5200 5550 50  0001 C CNN
	1    5200 5550
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J15
U 1 1 5E708A39
P 9900 4550
F 0 "J15" V 10053 4363 50  0000 R CNN
F 1 "Conn_01x02_Male" V 9962 4363 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9900 4550 50  0001 C CNN
F 3 "~" H 9900 4550 50  0001 C CNN
	1    9900 4550
	0    -1   -1   0   
$EndComp
Text GLabel 5150 5200 0    50   Input ~ 0
D1
Wire Wire Line
	5150 5200 5200 5200
Wire Wire Line
	5200 5200 5200 5350
Wire Wire Line
	5350 5200 5300 5200
Wire Wire Line
	5300 5200 5300 5350
Wire Wire Line
	10050 4200 10000 4200
Wire Wire Line
	10000 4200 10000 4350
Text GLabel 9850 4200 0    50   Input ~ 0
PWM2N
Wire Wire Line
	9850 4200 9900 4200
Wire Wire Line
	9900 4200 9900 4350
Text GLabel 11050 1700 2    50   Input ~ 0
12
Wire Wire Line
	10200 1700 11050 1700
Text GLabel 10850 2700 2    50   Input ~ 0
3
Wire Wire Line
	10200 2500 10850 2500
Text GLabel 5100 650  0    50   Input ~ 0
ADC0
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 5E718E4F
P 5150 1000
F 0 "J1" V 5303 813 50  0000 R CNN
F 1 "Conn_01x02_Male" V 5212 813 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5150 1000 50  0001 C CNN
F 3 "~" H 5150 1000 50  0001 C CNN
	1    5150 1000
	0    -1   -1   0   
$EndComp
Text GLabel 5300 650  2    50   Input ~ 0
A2
Wire Wire Line
	5300 650  5250 650 
Wire Wire Line
	5250 650  5250 800 
Wire Wire Line
	5100 650  5150 650 
Wire Wire Line
	5150 650  5150 800 
Text GLabel 8750 2500 0    50   Input ~ 0
A0
Wire Wire Line
	8750 2500 9400 2500
Text GLabel 6050 650  0    50   Input ~ 0
ADC1
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5E722316
P 6100 1000
F 0 "J2" V 6253 813 50  0000 R CNN
F 1 "Conn_01x02_Male" V 6162 813 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6100 1000 50  0001 C CNN
F 3 "~" H 6100 1000 50  0001 C CNN
	1    6100 1000
	0    -1   -1   0   
$EndComp
Text GLabel 6250 650  2    50   Input ~ 0
A1
Wire Wire Line
	6250 650  6200 650 
Wire Wire Line
	6200 650  6200 800 
Wire Wire Line
	6050 650  6100 650 
Wire Wire Line
	6100 650  6100 800 
$Comp
L Connector:Conn_01x02_Male J3
U 1 1 5E7298F1
P 7050 1000
F 0 "J3" V 7203 813 50  0000 R CNN
F 1 "Conn_01x02_Male" V 7112 813 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7050 1000 50  0001 C CNN
F 3 "~" H 7050 1000 50  0001 C CNN
	1    7050 1000
	0    -1   -1   0   
$EndComp
Text GLabel 7000 700  0    50   Input ~ 0
ADC2
Text GLabel 7200 700  2    50   Input ~ 0
A0
Wire Wire Line
	7000 700  7050 700 
Wire Wire Line
	7050 700  7050 800 
Wire Wire Line
	7200 700  7150 700 
Wire Wire Line
	7150 700  7150 800 
Text GLabel 8750 2600 0    50   Input ~ 0
A1
Text GLabel 8750 2700 0    50   Input ~ 0
A2
Wire Wire Line
	8750 2600 9400 2600
Wire Wire Line
	8750 2700 9400 2700
Text GLabel 6150 1300 0    50   Input ~ 0
AMP1
$Comp
L Connector:Conn_01x02_Male J5
U 1 1 5E735276
P 6550 1400
F 0 "J5" V 6703 1213 50  0000 R CNN
F 1 "Conn_01x02_Male" H 7150 1700 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6550 1400 50  0001 C CNN
F 3 "~" H 6550 1400 50  0001 C CNN
	1    6550 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	6250 1450 6250 1400
Wire Wire Line
	6250 1400 6350 1400
Text GLabel 10850 3000 2    50   Input ~ 0
Rx
Text GLabel 10850 2900 2    50   Input ~ 0
Tx
Wire Wire Line
	10200 2900 10850 2900
Wire Wire Line
	10200 3000 10850 3000
$Comp
L Connector:Conn_01x02_Male J18
U 1 1 5E74836B
P 4250 7450
F 0 "J18" V 4403 7263 50  0000 R CNN
F 1 "Conn_01x02_Male" V 4300 8150 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4250 7450 50  0001 C CNN
F 3 "~" H 4250 7450 50  0001 C CNN
	1    4250 7450
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J17
U 1 1 5E7483D7
P 1650 7400
F 0 "J17" V 1803 7213 50  0000 R CNN
F 1 "Conn_01x02_Male" V 1700 8100 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1650 7400 50  0001 C CNN
F 3 "~" H 1650 7400 50  0001 C CNN
	1    1650 7400
	0    -1   -1   0   
$EndComp
Text GLabel 1600 7100 0    50   Input ~ 0
RXB
Text GLabel 4200 7150 0    50   Input ~ 0
TXB
Wire Wire Line
	4350 7150 4350 7250
Wire Wire Line
	4200 7150 4250 7150
Wire Wire Line
	4250 7150 4250 7250
Wire Wire Line
	1750 7100 1750 7200
Wire Wire Line
	1600 7100 1650 7100
Wire Wire Line
	1650 7100 1650 7200
$Comp
L Connector:Conn_01x02_Male J21
U 1 1 5E76127F
P 8900 4050
F 0 "J21" V 9053 3863 50  0000 R CNN
F 1 "Conn_01x02_Male" V 8962 3863 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8900 4050 50  0001 C CNN
F 3 "~" H 8900 4050 50  0001 C CNN
	1    8900 4050
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J20
U 1 1 5E7612D7
P 9900 4050
F 0 "J20" V 10053 3863 50  0000 R CNN
F 1 "Conn_01x02_Male" V 9962 3863 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9900 4050 50  0001 C CNN
F 3 "~" H 9900 4050 50  0001 C CNN
	1    9900 4050
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Male J19
U 1 1 5E761337
P 8900 4550
F 0 "J19" V 9053 4363 50  0000 R CNN
F 1 "Conn_01x02_Male" V 8962 4363 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8900 4550 50  0001 C CNN
F 3 "~" H 8900 4550 50  0001 C CNN
	1    8900 4550
	0    -1   -1   0   
$EndComp
Text GLabel 8850 3750 0    50   Input ~ 0
PWM1
Text GLabel 9850 3750 0    50   Input ~ 0
PWM1N
Text GLabel 8850 4250 0    50   Input ~ 0
PWM2
Wire Wire Line
	8850 3750 8900 3750
Wire Wire Line
	8900 3750 8900 3850
Wire Wire Line
	9850 3750 9900 3750
Wire Wire Line
	9900 3750 9900 3850
Wire Wire Line
	8850 4250 8900 4250
Wire Wire Line
	8900 4250 8900 4350
Text GLabel 9050 3750 2    50   Input ~ 0
6
Wire Wire Line
	9050 3750 9000 3750
Wire Wire Line
	9000 3750 9000 3850
Text GLabel 10050 3750 2    50   Input ~ 0
5
Text GLabel 9050 4250 2    50   Input ~ 0
11
Wire Wire Line
	9050 4250 9000 4250
Wire Wire Line
	9000 4250 9000 4350
Wire Wire Line
	10050 3750 10000 3750
Wire Wire Line
	10000 3750 10000 3850
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
$Comp
L Connector_Generic:Conn_02x13_Odd_Even J7
U 1 1 5EE18C86
P 1900 2350
F 0 "J7" H 1950 3167 50  0000 C CNN
F 1 "Conn_02x13_Odd_Even" H 1950 3076 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x13_P2.54mm_Vertical" H 1900 2350 50  0001 C CNN
F 3 "~" H 1900 2350 50  0001 C CNN
	1    1900 2350
	-1   0    0    -1  
$EndComp
Text GLabel 2550 1750 2    50   Input ~ 0
D0
Wire Wire Line
	2550 1750 2100 1750
$Comp
L power:GND #PWR08
U 1 1 5EE1DC02
P 2250 3050
F 0 "#PWR08" H 2250 2800 50  0001 C CNN
F 1 "GND" H 2250 2900 50  0000 C CNN
F 2 "" H 2250 3050 50  0000 C CNN
F 3 "" H 2250 3050 50  0000 C CNN
	1    2250 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1850 2250 1850
Wire Wire Line
	2250 1850 2250 2550
Wire Wire Line
	2100 2450 2400 2450
Wire Wire Line
	2400 2450 2400 1650
Wire Wire Line
	1400 2450 1400 1650
$Comp
L power:GND #PWR07
U 1 1 5EE2BB45
P 1500 3050
F 0 "#PWR07" H 1500 2800 50  0001 C CNN
F 1 "GND" H 1500 2900 50  0000 C CNN
F 2 "" H 1500 3050 50  0000 C CNN
F 3 "" H 1500 3050 50  0000 C CNN
	1    1500 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 3050 1500 1750
Wire Wire Line
	1500 1750 1600 1750
Wire Wire Line
	1600 2450 1400 2450
Text GLabel 2550 1950 2    50   Input ~ 0
Echo1
Text GLabel 2550 2050 2    50   Input ~ 0
Trig1
Text GLabel 2550 2250 2    50   Input ~ 0
R_TCRT
Text GLabel 2550 2350 2    50   Input ~ 0
L_TCRT
Text GLabel 2550 2650 2    50   Input ~ 0
Trig0
Text GLabel 2550 2750 2    50   Input ~ 0
Echo0
Text GLabel 2550 2850 2    50   Input ~ 0
D1
Text GLabel 2550 2950 2    50   Input ~ 0
PWM2N
Text GLabel 1300 2950 0    50   Input ~ 0
PWM2
Text GLabel 1300 2850 0    50   Input ~ 0
PWM1N
Text GLabel 1300 2750 0    50   Input ~ 0
PWM1
Text GLabel 1300 2650 0    50   Input ~ 0
RXB
Text GLabel 1300 2550 0    50   Input ~ 0
TXB
Text GLabel 1300 2350 0    50   Input ~ 0
AMP2
Text GLabel 1300 2250 0    50   Input ~ 0
ADC2
Text GLabel 1300 1850 0    50   Input ~ 0
AMP1
Text GLabel 1300 2150 0    50   Input ~ 0
ADC1
Text GLabel 1300 2050 0    50   Input ~ 0
ADC0
Text GLabel 1300 1950 0    50   Input ~ 0
ADC3
Wire Wire Line
	1300 2950 1600 2950
Wire Wire Line
	1600 2850 1300 2850
Wire Wire Line
	1300 2750 1600 2750
Wire Wire Line
	1300 2650 1600 2650
Wire Wire Line
	1600 2550 1300 2550
Wire Wire Line
	1300 2350 1600 2350
Wire Wire Line
	1600 2250 1300 2250
Wire Wire Line
	1300 2150 1600 2150
Wire Wire Line
	1300 2050 1600 2050
Wire Wire Line
	1300 1950 1600 1950
Wire Wire Line
	1300 1850 1600 1850
Wire Wire Line
	2100 2950 2550 2950
Wire Wire Line
	2550 2850 2100 2850
Wire Wire Line
	2100 2750 2550 2750
Wire Wire Line
	2550 2650 2100 2650
Wire Wire Line
	2100 2350 2550 2350
Wire Wire Line
	2100 2250 2550 2250
Wire Wire Line
	2100 2050 2550 2050
Wire Wire Line
	2550 1950 2100 1950
$Comp
L power:GND #PWR02
U 1 1 5EEDDC4D
P 6250 1450
F 0 "#PWR02" H 6250 1200 50  0001 C CNN
F 1 "GND" H 6250 1300 50  0000 C CNN
F 2 "" H 6250 1450 50  0000 C CNN
F 3 "" H 6250 1450 50  0000 C CNN
	1    6250 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1300 6350 1300
Text GLabel 7150 1300 0    50   Input ~ 0
AMP2
$Comp
L Connector:Conn_01x02_Male J6
U 1 1 5EEF3F3C
P 7550 1400
F 0 "J6" V 7703 1213 50  0000 R CNN
F 1 "Conn_01x02_Male" H 8150 1700 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7550 1400 50  0001 C CNN
F 3 "~" H 7550 1400 50  0001 C CNN
	1    7550 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	7250 1450 7250 1400
Wire Wire Line
	7250 1400 7350 1400
$Comp
L power:GND #PWR03
U 1 1 5EEF3F45
P 7250 1450
F 0 "#PWR03" H 7250 1200 50  0001 C CNN
F 1 "GND" H 7250 1300 50  0000 C CNN
F 2 "" H 7250 1450 50  0000 C CNN
F 3 "" H 7250 1450 50  0000 C CNN
	1    7250 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 1300 7350 1300
Text Notes 8750 5100 0    50   ~ 0
11 - OC2A\n3 - OC2B\n\n6 - OC0A\n5- OC0B
Text Notes 5150 4150 0    50   ~ 0
2 - int0 (ext. event)\n8 - ICP1 (capture)\n\n4 - GPIO\n7 - GPIO 
$Comp
L pspice:CAP C1
U 1 1 5EFE9E76
P 1500 4000
F 0 "C1" H 1678 4046 50  0000 L CNN
F 1 "100n" H 1678 3955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1500 4000 50  0001 C CNN
F 3 "~" H 1500 4000 50  0001 C CNN
	1    1500 4000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5EFE9F72
P 1500 3700
F 0 "#PWR0101" H 1500 3550 50  0001 C CNN
F 1 "+5V" V 1500 3900 50  0000 C CNN
F 2 "" H 1500 3700 50  0000 C CNN
F 3 "" H 1500 3700 50  0000 C CNN
	1    1500 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5EFEA0B3
P 1500 4350
F 0 "#PWR0102" H 1500 4100 50  0001 C CNN
F 1 "GND" H 1500 4200 50  0000 C CNN
F 2 "" H 1500 4350 50  0000 C CNN
F 3 "" H 1500 4350 50  0000 C CNN
	1    1500 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 3700 1500 3750
Wire Wire Line
	1500 4250 1500 4350
$Comp
L pspice:CAP C2
U 1 1 5F00DDFD
P 2100 4000
F 0 "C2" H 2278 4046 50  0000 L CNN
F 1 "100n" H 2278 3955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2100 4000 50  0001 C CNN
F 3 "~" H 2100 4000 50  0001 C CNN
	1    2100 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5F00DE0A
P 2100 4350
F 0 "#PWR0103" H 2100 4100 50  0001 C CNN
F 1 "GND" H 2100 4200 50  0000 C CNN
F 2 "" H 2100 4350 50  0000 C CNN
F 3 "" H 2100 4350 50  0000 C CNN
	1    2100 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 3700 2100 3750
Wire Wire Line
	2100 4250 2100 4350
$Comp
L power:+3.3V #PWR0104
U 1 1 5F015339
P 2100 3700
F 0 "#PWR0104" H 2100 3550 50  0001 C CNN
F 1 "+3.3V" V 2100 3950 50  0000 C CNN
F 2 "" H 2100 3700 50  0000 C CNN
F 3 "" H 2100 3700 50  0000 C CNN
	1    2100 3700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J23
U 1 1 5F015F8B
P 2800 4050
F 0 "J23" H 2906 4328 50  0000 C CNN
F 1 "Conn_01x04_Male" H 2906 4237 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2800 4050 50  0001 C CNN
F 3 "~" H 2800 4050 50  0001 C CNN
	1    2800 4050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 5F0162BF
P 3300 3700
F 0 "#PWR0105" H 3300 3550 50  0001 C CNN
F 1 "+5V" V 3300 3900 50  0000 C CNN
F 2 "" H 3300 3700 50  0000 C CNN
F 3 "" H 3300 3700 50  0000 C CNN
	1    3300 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0106
U 1 1 5F016456
P 3200 3700
F 0 "#PWR0106" H 3200 3550 50  0001 C CNN
F 1 "+3.3V" V 3200 3950 50  0000 C CNN
F 2 "" H 3200 3700 50  0000 C CNN
F 3 "" H 3200 3700 50  0000 C CNN
	1    3200 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5F02C3E1
P 3200 4350
F 0 "#PWR0107" H 3200 4100 50  0001 C CNN
F 1 "GND" H 3200 4200 50  0000 C CNN
F 2 "" H 3200 4350 50  0000 C CNN
F 3 "" H 3200 4350 50  0000 C CNN
	1    3200 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 4250 3200 4350
Wire Wire Line
	3300 4150 3300 3950
Wire Wire Line
	3200 4050 3200 3700
Wire Wire Line
	3000 4250 3200 4250
Wire Wire Line
	3000 4150 3300 4150
Wire Wire Line
	3000 4050 3200 4050
Wire Wire Line
	3000 3950 3300 3950
Connection ~ 3300 3950
Wire Wire Line
	3300 3950 3300 3700
Text Notes 6150 4800 0    50   ~ 0
Encoder
Text Notes 950  5100 0    50   ~ 0
Sensor optico
Wire Wire Line
	2100 2550 2250 2550
Connection ~ 2250 2550
Wire Wire Line
	2250 2550 2250 3050
$Comp
L Device:R R1
U 1 1 5EE3A0BC
P 3900 4250
F 0 "R1" H 3970 4296 50  0000 L CNN
F 1 "R" H 3970 4205 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3830 4250 50  0001 C CNN
F 3 "~" H 3900 4250 50  0001 C CNN
	1    3900 4250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5EE3A180
P 3900 4500
F 0 "#PWR0108" H 3900 4250 50  0001 C CNN
F 1 "GND" H 3900 4350 50  0000 C CNN
F 2 "" H 3900 4500 50  0000 C CNN
F 3 "" H 3900 4500 50  0000 C CNN
	1    3900 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5EE3A374
P 3900 3850
F 0 "D1" V 3938 3733 50  0000 R CNN
F 1 "LED" V 3847 3733 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 3900 3850 50  0001 C CNN
F 3 "~" H 3900 3850 50  0001 C CNN
	1    3900 3850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3900 3550 3900 3700
Wire Wire Line
	3900 4000 3900 4100
Wire Wire Line
	3900 4400 3900 4500
$Comp
L power:+5V #PWR0109
U 1 1 5EE64533
P 3900 3550
F 0 "#PWR0109" H 3900 3400 50  0001 C CNN
F 1 "+5V" V 3900 3750 50  0000 C CNN
F 2 "" H 3900 3550 50  0000 C CNN
F 3 "" H 3900 3550 50  0000 C CNN
	1    3900 3550
	1    0    0    -1  
$EndComp
Text Notes 7850 6900 0    50   ~ 0
SHIELD ARDUINO PARA CARRINHO AUTÔNOMO\nLIGAÇÃO CONFORME PLACA DE POTÊNCIA
$Comp
L Transistor_FET:2N7002 Q1
U 1 1 5F7DA52B
P 2600 7000
F 0 "Q1" V 2850 7000 50  0000 C CNN
F 1 "2N7002" V 2941 7000 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2800 6925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 2600 7000 50  0001 L CNN
	1    2600 7000
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:2N7002 Q2
U 1 1 5F7DA64F
P 5300 7050
F 0 "Q2" V 5550 7050 50  0000 C CNN
F 1 "2N7002" V 5641 7050 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5500 6975 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 5300 7050 50  0001 L CNN
	1    5300 7050
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5F7EB1DB
P 2250 6800
F 0 "R2" H 2320 6846 50  0000 L CNN
F 1 "2k2" H 2320 6755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2180 6800 50  0001 C CNN
F 3 "~" H 2250 6800 50  0001 C CNN
	1    2250 6800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5F7EB2EF
P 2900 6800
F 0 "R3" H 2970 6846 50  0000 L CNN
F 1 "2k2" H 2970 6755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2830 6800 50  0001 C CNN
F 3 "~" H 2900 6800 50  0001 C CNN
	1    2900 6800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5F7EB396
P 4800 6850
F 0 "R4" H 4870 6896 50  0000 L CNN
F 1 "2k2" H 4870 6805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4730 6850 50  0001 C CNN
F 3 "~" H 4800 6850 50  0001 C CNN
	1    4800 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5F7EB472
P 5750 6850
F 0 "R5" H 5820 6896 50  0000 L CNN
F 1 "2k2" H 5820 6805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5680 6850 50  0001 C CNN
F 3 "~" H 5750 6850 50  0001 C CNN
	1    5750 6850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR012
U 1 1 5F7EB9CA
P 2250 6550
F 0 "#PWR012" H 2250 6400 50  0001 C CNN
F 1 "+3.3V" V 2250 6800 50  0000 C CNN
F 2 "" H 2250 6550 50  0000 C CNN
F 3 "" H 2250 6550 50  0000 C CNN
	1    2250 6550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 5F7EBD2F
P 2900 6500
F 0 "#PWR011" H 2900 6350 50  0001 C CNN
F 1 "+5V" V 2900 6700 50  0000 C CNN
F 2 "" H 2900 6500 50  0000 C CNN
F 3 "" H 2900 6500 50  0000 C CNN
	1    2900 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 7100 2900 7100
Wire Wire Line
	2900 7100 2900 6950
Wire Wire Line
	2900 6650 2900 6500
Wire Wire Line
	2400 7100 2250 7100
Wire Wire Line
	2250 7100 2250 6950
Wire Wire Line
	2250 6650 2250 6600
$Comp
L power:+5V #PWR014
U 1 1 5F818006
P 5750 6550
F 0 "#PWR014" H 5750 6400 50  0001 C CNN
F 1 "+5V" V 5750 6750 50  0000 C CNN
F 2 "" H 5750 6550 50  0000 C CNN
F 3 "" H 5750 6550 50  0000 C CNN
	1    5750 6550
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR013
U 1 1 5F81805F
P 4800 6550
F 0 "#PWR013" H 4800 6400 50  0001 C CNN
F 1 "+3.3V" V 4800 6800 50  0000 C CNN
F 2 "" H 4800 6550 50  0000 C CNN
F 3 "" H 4800 6550 50  0000 C CNN
	1    4800 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 6600 2600 6600
Wire Wire Line
	2600 6600 2600 6800
Connection ~ 2250 6600
Wire Wire Line
	2250 6600 2250 6550
Wire Wire Line
	4800 6550 4800 6600
Wire Wire Line
	5100 7150 4800 7150
Wire Wire Line
	4800 7000 4800 7150
Wire Wire Line
	5500 7150 5750 7150
Wire Wire Line
	5750 6550 5750 6700
Wire Wire Line
	5750 7150 5750 7000
Wire Wire Line
	4800 6600 5300 6600
Wire Wire Line
	5300 6600 5300 6850
Connection ~ 4800 6600
Wire Wire Line
	4800 6600 4800 6700
Text GLabel 3050 7100 2    50   Input ~ 0
Tx
Wire Wire Line
	2900 7100 3050 7100
Connection ~ 2900 7100
Text GLabel 5850 7150 2    50   Input ~ 0
Rx
Wire Wire Line
	5750 7150 5850 7150
Connection ~ 5750 7150
Wire Wire Line
	1750 7100 2250 7100
Connection ~ 2250 7100
Connection ~ 4800 7150
Wire Wire Line
	4350 7150 4800 7150
Text Notes 2750 7700 0    50   ~ 0
Módulo Bluetooth HC05\nI/O em 3V3
$Comp
L power:+5VP #PWR06
U 1 1 5F931DB6
P 2400 1650
F 0 "#PWR06" H 2400 1500 50  0001 C CNN
F 1 "+5VP" H 2415 1823 50  0000 C CNN
F 2 "" H 2400 1650 50  0001 C CNN
F 3 "" H 2400 1650 50  0001 C CNN
	1    2400 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+5VP #PWR05
U 1 1 5F931E0F
P 1400 1650
F 0 "#PWR05" H 1400 1500 50  0001 C CNN
F 1 "+5VP" H 1415 1823 50  0000 C CNN
F 2 "" H 1400 1650 50  0001 C CNN
F 3 "" H 1400 1650 50  0001 C CNN
	1    1400 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+5VP #PWR015
U 1 1 5F9467DA
P 2950 1500
F 0 "#PWR015" H 2950 1350 50  0001 C CNN
F 1 "+5VP" H 2965 1673 50  0000 C CNN
F 2 "" H 2950 1500 50  0001 C CNN
F 3 "" H 2950 1500 50  0001 C CNN
	1    2950 1500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR016
U 1 1 5F946885
P 3800 1650
F 0 "#PWR016" H 3800 1500 50  0001 C CNN
F 1 "+5V" V 3800 1850 50  0000 C CNN
F 2 "" H 3800 1650 50  0000 C CNN
F 3 "" H 3800 1650 50  0000 C CNN
	1    3800 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D2
U 1 1 5F967836
P 3250 1650
F 0 "D2" H 3250 1434 50  0000 C CNN
F 1 "D_Schottky" H 3250 1525 50  0000 C CNN
F 2 "Diode_SMD:D_SMB" H 3250 1650 50  0001 C CNN
F 3 "~" H 3250 1650 50  0001 C CNN
	1    3250 1650
	-1   0    0    1   
$EndComp
Wire Wire Line
	3100 1650 2950 1650
Wire Wire Line
	2950 1650 2950 1500
Wire Wire Line
	3400 1650 3800 1650
$EndSCHEMATC
