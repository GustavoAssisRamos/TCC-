#include <Arduino.h> 
#include <Wire.h>
#include <Adafruit_MPU6050.h> 
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  
Wire.begin(8,9); // Seta os pinos i2c que vamo usar

  if (!mpu.begin()) {
    Serial.println("MPU6050 não encontrado!");
    while (1) {
      delay(10);
    }
  }
//Setar as configurações do sensor, como range do acelerômetro, range do giroscópio e banda de filtro
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

}

void loop() {

  sensors_event_t a, g, temp; //cria memorias especificas do adafruit 
  mpu.getEvent(&a, &g, &temp); // coleta os dados e & armazena em a e g
  
  float angulo_pitch = atan2(a.acceleration.x, a.acceleration.z) * 57.2958;
  float velocidade_angular_y = g.gyro.y * 57.2958;
  delay (100); //delay para não sobrecarregar o loop
  
}