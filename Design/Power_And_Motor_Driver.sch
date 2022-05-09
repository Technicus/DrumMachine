EESchema Schematic File Version 4
LIBS:Drum_Machine_V00-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 6 7
Title "Drum Machine"
Date "2018-06-15"
Rev "V00"
Comp "Prototype Engineering Studio LLC"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Drum_Machine_V00-rescue:AC_DC_Power_Supply-Drum_Machine_V01 U8
U 1 1 671790AB
P 3150 2300
F 0 "U8" H 3150 2592 39  0000 C CNN
F 1 "AC_DC_Power_Supply" H 3150 2517 39  0000 C CNN
F 2 "" H 3150 2500 39  0001 C CNN
F 3 "" H 3150 2500 39  0001 C CNN
	1    3150 2300
	-1   0    0    -1  
$EndComp
$Comp
L Drum_Machine_V00-rescue:AC_Wall_Plug_Earth-Drum_Machine_V01 P3
U 1 1 6717917F
P 2350 2350
F 0 "P3" H 2619 2253 39  0000 L CNN
F 1 "AC_Wall_Plug_Earth" H 2619 2178 39  0000 L CNN
F 2 "" H 2350 2600 39  0001 C CNN
F 3 "" H 2350 2600 39  0001 C CNN
	1    2350 2350
	-1   0    0    -1  
$EndComp
$Comp
L Drum_Machine_V00-rescue:Regulator-Drum_Machine_V01 U10
U 1 1 67179246
P 4600 2300
F 0 "U10" H 4600 2568 39  0000 C CNN
F 1 "Regulator" H 4600 2493 39  0000 C CNN
F 2 "" H 4600 2500 39  0001 C CNN
F 3 "" H 4600 2500 39  0001 C CNN
	1    4600 2300
	1    0    0    -1  
$EndComp
$Comp
L Drum_Machine_V00-rescue:CP-device C1
U 1 1 671793C3
P 4050 2450
F 0 "C1" H 4168 2496 50  0000 L CNN
F 1 "0.1μF" H 4168 2405 50  0000 L CNN
F 2 "" H 4088 2300 50  0001 C CNN
F 3 "" H 4050 2450 50  0001 C CNN
	1    4050 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2300 4050 2250
Wire Wire Line
	4050 2250 4300 2250
$Comp
L Drum_Machine_V00-rescue:CP-device C3
U 1 1 67179619
P 5200 2450
F 0 "C3" H 5318 2496 50  0000 L CNN
F 1 "22μF" H 5318 2405 50  0000 L CNN
F 2 "" H 5238 2300 50  0001 C CNN
F 3 "" H 5200 2450 50  0001 C CNN
	1    5200 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2250 5200 2250
Wire Wire Line
	5200 2300 5200 2250
Connection ~ 5200 2250
Wire Wire Line
	5200 2250 5450 2250
Wire Wire Line
	4050 2600 4050 2650
Wire Wire Line
	4050 2650 4600 2650
Wire Wire Line
	5200 2650 5200 2600
Wire Wire Line
	4600 2550 4600 2650
Connection ~ 4600 2650
Wire Wire Line
	4600 2650 5200 2650
$Comp
L Drum_Machine_V00-rescue:Regulator-Drum_Machine_V01 U11
U 1 1 67179A82
P 4600 3050
F 0 "U11" H 4600 3318 39  0000 C CNN
F 1 "Regulator" H 4600 3243 39  0000 C CNN
F 2 "" H 4600 3250 39  0001 C CNN
F 3 "" H 4600 3250 39  0001 C CNN
	1    4600 3050
	1    0    0    -1  
$EndComp
$Comp
L Drum_Machine_V00-rescue:CP-device C2
U 1 1 67179A89
P 4050 3200
F 0 "C2" H 4168 3246 50  0000 L CNN
F 1 "0.4μF" H 4168 3155 50  0000 L CNN
F 2 "" H 4088 3050 50  0001 C CNN
F 3 "" H 4050 3200 50  0001 C CNN
	1    4050 3200
	1    0    0    -1  
$EndComp
$Comp
L Drum_Machine_V00-rescue:GND #PWR0124
U 1 1 67179A90
P 4600 3450
F 0 "#PWR0124" H 4600 3200 50  0001 C CNN
F 1 "GND" H 4605 3277 50  0000 C CNN
F 2 "" H 4600 3450 50  0001 C CNN
F 3 "" H 4600 3450 50  0001 C CNN
	1    4600 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 3000 4050 3000
Wire Wire Line
	4050 3050 4050 3000
Connection ~ 4050 3000
Wire Wire Line
	4050 3000 4300 3000
$Comp
L Drum_Machine_V00-rescue:CP-device C4
U 1 1 67179A9A
P 5200 3200
F 0 "C4" H 5318 3246 50  0000 L CNN
F 1 "33μF" H 5318 3155 50  0000 L CNN
F 2 "" H 5238 3050 50  0001 C CNN
F 3 "" H 5200 3200 50  0001 C CNN
	1    5200 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3000 5200 3000
Wire Wire Line
	5200 3050 5200 3000
Connection ~ 5200 3000
Wire Wire Line
	5200 3000 5450 3000
Wire Wire Line
	4050 3350 4050 3400
Wire Wire Line
	4050 3400 4600 3400
Wire Wire Line
	5200 3400 5200 3350
Wire Wire Line
	4600 3300 4600 3400
Connection ~ 4600 3400
Wire Wire Line
	4600 3400 5200 3400
Wire Wire Line
	4600 3400 4600 3450
Wire Wire Line
	2800 2250 2600 2250
Wire Wire Line
	2800 2350 2700 2350
Wire Wire Line
	2700 2350 2700 2450
Wire Wire Line
	2700 2450 2600 2450
Wire Wire Line
	3850 5300 3450 5300
Wire Wire Line
	3850 5450 3450 5450
Wire Wire Line
	3850 5600 3550 5600
Wire Wire Line
	3550 5600 3550 4800
Wire Wire Line
	3850 5150 3850 4800
Wire Wire Line
	4850 5150 5000 5150
Wire Wire Line
	4850 5300 5000 5300
Wire Wire Line
	3850 5750 3850 5950
$Comp
L Drum_Machine_V00-rescue:Motor_Driver-Drum_Machine_V01 U9
U 1 1 6717DADA
P 4350 5450
F 0 "U9" H 4350 5992 39  0000 C CNN
F 1 "Motor_Driver" H 4350 5917 39  0000 C CNN
F 2 "" H 4350 5900 39  0001 C CNN
F 3 "" H 4350 5900 39  0001 C CNN
	1    4350 5450
	1    0    0    -1  
$EndComp
$Comp
L Drum_Machine_V00-rescue:GND #PWR0125
U 1 1 6717FAFA
P 3850 5950
F 0 "#PWR0125" H 3850 5700 50  0001 C CNN
F 1 "GND" H 3855 5777 50  0000 C CNN
F 2 "" H 3850 5950 50  0001 C CNN
F 3 "" H 3850 5950 50  0001 C CNN
	1    3850 5950
	1    0    0    -1  
$EndComp
NoConn ~ 4850 5450
Wire Wire Line
	4850 5600 5000 5600
Text GLabel 3450 5300 0    39   Output ~ 0
Motor_1
Text GLabel 3450 5450 0    39   Output ~ 0
Motor_2
Text GLabel 5000 5150 2    39   Input ~ 0
Motor_PWM
Text GLabel 5000 5300 2    39   Input ~ 0
Motor_Dir
Text GLabel 5000 5600 2    39   Input ~ 0
Motor_En
$Comp
L power:+5V #PWR0126
U 1 1 67181C25
P 3850 4800
F 0 "#PWR0126" H 3850 4650 50  0001 C CNN
F 1 "+5V" H 3865 4973 50  0000 C CNN
F 2 "" H 3850 4800 50  0001 C CNN
F 3 "" H 3850 4800 50  0001 C CNN
	1    3850 4800
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0127
U 1 1 67181C69
P 3550 4800
F 0 "#PWR0127" H 3550 4650 50  0001 C CNN
F 1 "+3V3" H 3565 4973 50  0000 C CNN
F 2 "" H 3550 4800 50  0001 C CNN
F 3 "" H 3550 4800 50  0001 C CNN
	1    3550 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2250 5450 2150
Wire Wire Line
	5450 3000 5450 2900
Wire Wire Line
	3500 2350 3600 2350
$Comp
L power:+12V #PWR0128
U 1 1 67186DB4
P 3750 2150
F 0 "#PWR0128" H 3750 2000 50  0001 C CNN
F 1 "+12V" H 3765 2323 50  0000 C CNN
F 2 "" H 3750 2150 50  0001 C CNN
F 3 "" H 3750 2150 50  0001 C CNN
	1    3750 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2250 4050 2250
Wire Wire Line
	3750 2150 3750 2250
Connection ~ 3750 2250
Wire Wire Line
	3750 2250 3750 3000
Connection ~ 4050 2250
$Comp
L power:+5V #PWR0129
U 1 1 67188994
P 5450 2150
F 0 "#PWR0129" H 5450 2000 50  0001 C CNN
F 1 "+5V" H 5465 2323 50  0000 C CNN
F 2 "" H 5450 2150 50  0001 C CNN
F 3 "" H 5450 2150 50  0001 C CNN
	1    5450 2150
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0130
U 1 1 671889D8
P 5450 2900
F 0 "#PWR0130" H 5450 2750 50  0001 C CNN
F 1 "+3V3" H 5465 3073 50  0000 C CNN
F 2 "" H 5450 2900 50  0001 C CNN
F 3 "" H 5450 2900 50  0001 C CNN
	1    5450 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2250 3750 2250
Wire Wire Line
	3600 2350 3600 2650
Wire Wire Line
	3600 3400 4050 3400
Connection ~ 4050 3400
Wire Wire Line
	4050 2650 3600 2650
Connection ~ 4050 2650
Connection ~ 3600 2650
Wire Wire Line
	3600 2650 3600 3400
$Comp
L Drum_Machine_V00-rescue:S_Tac-Drum_Machine_V01 SW36
U 1 1 67226ABF
P 8350 3650
F 0 "SW36" H 8350 3941 39  0000 C CNN
F 1 "S_Tac" H 8350 3866 39  0000 C CNN
F 2 "" H 8350 3850 39  0001 C CNN
F 3 "" H 8350 3850 39  0001 C CNN
	1    8350 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0131
U 1 1 67226BEB
P 8600 3850
F 0 "#PWR0131" H 8600 3600 50  0001 C CNN
F 1 "GND" H 8605 3677 50  0000 C CNN
F 2 "" H 8600 3850 50  0001 C CNN
F 3 "" H 8600 3850 50  0001 C CNN
	1    8600 3850
	1    0    0    -1  
$EndComp
Text GLabel 7950 3600 0    39   Output ~ 0
Soft_Power_Button
Wire Wire Line
	7950 3600 8100 3600
Wire Wire Line
	8550 3600 8600 3600
Wire Wire Line
	8600 3600 8600 3700
Wire Wire Line
	8550 3700 8600 3700
Connection ~ 8600 3700
Wire Wire Line
	8600 3700 8600 3850
Wire Wire Line
	8150 3700 8100 3700
Wire Wire Line
	8100 3700 8100 3600
Connection ~ 8100 3600
Wire Wire Line
	8100 3600 8150 3600
$Comp
L Drum_Machine_V00-rescue:S_Tac-Drum_Machine_V01 SW37
U 1 1 6722A0D1
P 8350 4550
F 0 "SW37" H 8350 4841 39  0000 C CNN
F 1 "S_Tac" H 8350 4766 39  0000 C CNN
F 2 "" H 8350 4750 39  0001 C CNN
F 3 "" H 8350 4750 39  0001 C CNN
	1    8350 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0132
U 1 1 6722A0D8
P 8600 4750
F 0 "#PWR0132" H 8600 4500 50  0001 C CNN
F 1 "GND" H 8605 4577 50  0000 C CNN
F 2 "" H 8600 4750 50  0001 C CNN
F 3 "" H 8600 4750 50  0001 C CNN
	1    8600 4750
	1    0    0    -1  
$EndComp
Text GLabel 7950 4500 0    39   Output ~ 0
Soft_Reset_Button
Wire Wire Line
	7950 4500 8100 4500
Wire Wire Line
	8550 4500 8600 4500
Wire Wire Line
	8600 4500 8600 4600
Wire Wire Line
	8550 4600 8600 4600
Connection ~ 8600 4600
Wire Wire Line
	8600 4600 8600 4750
Wire Wire Line
	8150 4600 8100 4600
Wire Wire Line
	8100 4600 8100 4500
Connection ~ 8100 4500
Wire Wire Line
	8100 4500 8150 4500
Wire Wire Line
	2600 2650 2700 2650
Wire Wire Line
	2700 2650 2700 2700
$Comp
L Drum_Machine_V00-rescue:GNDPWR-power #PWR0133
U 1 1 6722EE88
P 2700 2700
F 0 "#PWR0133" H 2700 2500 50  0001 C CNN
F 1 "GNDPWR" H 2700 2800 50  0001 C CNN
F 2 "" H 2700 2650 50  0001 C CNN
F 3 "" H 2700 2650 50  0001 C CNN
	1    2700 2700
	1    0    0    -1  
$EndComp
$EndSCHEMATC