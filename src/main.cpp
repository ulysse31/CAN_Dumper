#include <Arduino.h>
#include <SPI.h>
#include <mcp2515.h>

struct can_frame  canMsg;
MCP2515           mcp2515(5);
bool              showDump;



void dumpPacket()
{
   Serial.print(millis());
    Serial.print(",0x");
    Serial.print(canMsg.can_id, HEX);
    Serial.print(",0x");
    Serial.print(canMsg.can_dlc, HEX);
    for (int i = 0; i<canMsg.can_dlc; i++)
    {
      Serial.print(",0x");
      Serial.print(canMsg.data[i],HEX);
    }
   Serial.println();
}

void getInput()
{
  char c;

  c = Serial.read();
  if (c == 'd' || c == 'D')
    {
      showDump = (showDump == true ? false : true);
      if (showDump == true)
        {
          Serial.println("");
          Serial.println("------------- Dump Start -------------");
          Serial.println("TIME:,ID:,DLC:,DATA:");
        }
        else
        {
          Serial.println("");
          Serial.println("------------- Dump Stop -------------");          
        }
    }
}

void setup()
{
  showDump = false;
  Serial.begin(115200);
  SPI.begin();
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_100KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
  Serial.println("------------- Nix CAN Dumper v0.1 -------------");
}

void loop()
{
  if (Serial.available())
    getInput();
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK && showDump == true)
    dumpPacket();
}
