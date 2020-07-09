# CAN_Dumper
Arduino MCP2515 CAN Dumper

A simple CAN_Dumper, I used this code doing the CID_Faker project (which now is ended since its working ^^)
You can use the exact same board / connections as in the CID_Faker project (check the other project on my repositories).
This Dumper is to be connected to a computer, or even a phone with a serial terminal App on it (tons of them in Android).
Once connected to the car CAN Bus, connect it to your device of choice, and open the serial, then type 'd' or 'D' on the keyboard to start dump.
Type any other character to stop the dumping.
The Dumper dumps one line per packet, indicating a timestamp per each packet, followed by the hexadecimal value of each byte of the CAN packet.
