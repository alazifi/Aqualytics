#include <Arduino.h>
#include <Nextion.h>
#include <TDS.h>

TDS tdsSensor(32, 3300, 4095);

String endChar = "\xFF\xFF\xFF";

void bUpdateTemp(float tempVal){
  static char tempValue[6];
  dtostrf(tempVal, 2, 1, tempValue);
  Serial2.print("tTemp.txt=\""+String(tempValue)+"\""+endChar);
}

void bUpdateTDS(int TDSVal){
  static char TDSValue[6];
  //dtostrf(TDSVal, 6, 2, TDSValue);
  itoa(TDSVal, TDSValue, 10);
  Serial2.print("tTDS.txt=\""+String(TDSValue)+"\""+endChar);
}

void bUpdateEC(int ECVal){
  static char ECValue[6];
  //dtostrf(ECVal, 6, 2, ECValue);
  itoa(ECVal, ECValue, 10);
  Serial2.print("tEC.txt=\""+String(ECValue)+"\""+endChar);
}

void bUpdateRes(float ResVal){
  static char ResValue[6];
  dtostrf(ResVal, 2, 1, ResValue);
  Serial2.print("tRes.txt=\""+String(ResValue)+"\""+endChar);
}

void bUpdateSalt(float SaltVal){
  static char SaltValue[6];
  dtostrf(SaltVal, 2, 2, SaltValue);
  Serial2.print("tSalt.txt=\""+String(SaltValue)+"\""+endChar);
}

void bUpdateVpH(float vpHVal){
  static char vpHValue[4];
  itoa(vpHVal, vpHValue, 10);
  Serial2.print("tVpH.txt=\""+String(vpHValue)+"\""+endChar);
}

void bUpdateVTDS(float vTDSVal){
  static char vTDSValue[4];
  itoa(vTDSVal, vTDSValue, 10);
  Serial2.print("tVTDS.txt=\""+String(vTDSValue)+"\""+endChar);
}

void bUpdateK(float kVal){
  static char kValue[4];
  dtostrf(kVal, 2, 2, kValue);
  Serial2.print("tLastk.txt=\""+String(kValue)+"\""+endChar);
}

void bUpdateVDO(float vDOVal){
  static char vDOValue[4];
  itoa(vDOVal, vDOValue, 10);
  Serial2.print("tVDO.txt=\""+String(vDOValue)+"\""+endChar);
}

void setup(){
  Serial.begin(115200);
  Serial2.begin(115200);
  tdsSensor.begin();
}

void loop(){
  tdsSensor.run();
  tdsSensor.setTemperature(27.3);
  tdsSensor.getAllTDSData();
  delay(50);
  bUpdateTemp(tdsSensor.getTemperature());
  bUpdateTDS(tdsSensor.getTDS());
  bUpdateEC(tdsSensor.getEC());
  bUpdateRes(tdsSensor.getResistivity());
  bUpdateSalt(tdsSensor.getSalinity());
  bUpdateVpH(tdsSensor.voltageTDS());
  bUpdateVTDS(tdsSensor.voltageTDS());
  bUpdateK(tdsSensor.getKvalue());
  bUpdateVDO(tdsSensor.voltageTDS());
}