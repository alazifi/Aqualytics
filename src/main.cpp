#include <Arduino.h>
#include <Nextion.h>
#include <TDS.h>

TDS tdsSensor(32, 3300, 4095);

String endChar = "\xFF\xFF\xFF";

// bool start = false;
// bool save = false;

// NexText tTemp = NexText(1, 2, "tTemp");
// NexText tTDS = NexText(1, 4, "tTDS");
// NexText tEC = NexText(1, 5, "tEC");
// NexText tRes = NexText(1, 6, "tRes");
// NexText tSalt = NexText(1, 7, "tSalt");
// NexText tVpH = NexText(3, 6, "tVpH");
// NexText tVTDS = NexText(3, 7, "tVTDS");
// NexText tLastk = NexText(3, 8, "tLastk");
// NexText tVDO = NexText(3, 9, "tVDO");
// // NexButton bCalTDS = NexButton(2, 7, "bCalTDS");
// // NexButton bStartTDS = NexButton(3, 6, "bStartTDS");
// // NexButton bInputTDS = NexButton(3, 7, "bInputTDS");
// // NexButton bSaveTDS = NexButton(3, 8, "bSaveTDS");
// NexTouch *nex_listen_list[] ={
//     &tTemp,
//     &tTDS,
//     &tEC,
//     &tRes,
//     &tSalt,
//     &tVpH,
//     &tVTDS,
//     &tLastk,
//     &tVDO,
//     // &bCalTDS,
//     // &bStartTDS,
//     // &bInputTDS,
//     // &bSaveTDS,
//     NULL
// };

// void bUpdateTemp(int tempVal){
//   static char tempValue[6];
//   dtostrf(tempVal, 2, 1, tempValue);
//   tTemp.setText(tempValue);
// }

void bUpdateTemp(float tempVal){
  static char tempValue[6];
  dtostrf(tempVal, 2, 1, tempValue);
  Serial2.print("tTemp.txt=\""+String(tempValue)+"\""+endChar);
}

// void bUpdateTDS(int TDSVal){
//   static char TDSValue[6];
//   //dtostrf(TDSVal, 6, 2, TDSValue);
//   itoa(TDSVal, TDSValue, 10);
//   tTDS.setText(TDSValue);
// }

// void bUpdateEC(int ECVal){
//   static char ECValue[6];
//   //dtostrf(ECVal, 6, 2, ECValue);
//   itoa(ECVal, ECValue, 10);
//   tEC.setText(ECValue);
// }

// void bUpdateRes(float ResVal){
//   static char ResValue[6];
//   dtostrf(ResVal, 2, 1, ResValue);
//   tRes.setText(ResValue);
// }

// void bUpdateSalt(float SaltVal){
//   static char SaltValue[6];
//   dtostrf(SaltVal, 2, 2, SaltValue);
//   tSalt.setText(SaltValue);
// }

// void bUpdateVpH(float vpHVal){
//   static char vpHValue[4];
//   itoa(vpHVal, vpHValue, 10);
//   tVpH.setText(vpHValue);
// }

// void bUpdateVTDS(float vTDSVal){
//   static char vTDSValue[4];
//   itoa(vTDSVal, vTDSValue, 10);
//   tVTDS.setText(vTDSValue);
// }

// void bUpdateK(float kVal){
//   static char kValue[4];
//   dtostrf(kVal, 2, 2, kValue);
//   tLastk.setText(kValue);
// }

// void bUpdateVDO(float vDOVal){
//   static char vDOValue[4];
//   itoa(vDOVal, vDOValue, 10);
//   tVDO.setText(vDOValue);
// }

void setup(){
  //nexInit();
  Serial.begin(115200);
  Serial2.begin(115200);
  tdsSensor.begin();
}

void loop(){
  tdsSensor.run();
  tdsSensor.setTemperature(27.3);
  tdsSensor.getAllTDSData();
  bUpdateTemp(tdsSensor.getTemperature());
  delay(1000);
  // bUpdateTemp(tdsSensor.getTemperature());
  // bUpdateTDS(tdsSensor.getTDS());
  // bUpdateEC(tdsSensor.getEC());
  // bUpdateRes(tdsSensor.getResistivity());
  // bUpdateSalt(tdsSensor.getSalinity());
  // bUpdateVpH(tdsSensor.voltageTDS());
  // bUpdateVTDS(tdsSensor.voltageTDS());
  // bUpdateK(tdsSensor.getKvalue());
  // bUpdateVDO(tdsSensor.voltageTDS());
  // nexLoop(nex_listen_list);
}