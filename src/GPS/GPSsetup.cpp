#include "GPSsetup.h"
#include <TinyGPS++.h>
#include <HardwareSerial.h>

 // Objek TinyGPS++ untuk membaca data GPS
TinyGPSPlus gps;

// Buat serial baru untuk komunikasi dengan GPS di UART2
HardwareSerial SerialGPS(2);

void setupGPS()
{
    // Inisialisasi UART2 untuk GPS (RX = GPIO 16, TX = GPIO 17)
    SerialGPS.begin(9600, SERIAL_8N1, 16, 17);
}

void handleGPS()
{
    while (SerialGPS.available() > 0) {
    char c = SerialGPS.read();
    
    // Kirim data ke TinyGPS++ untuk diproses
    if (gps.encode(c)) {
      // Jika ada data GPS y ang valid, cetak koordinat
      if (gps.location.isValid()) {
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);
      } else {
        Serial.println("Location: Not available");
      }
      
      // Cek kecepatan (jika tersedia)
      if (gps.speed.isValid()) {
        Serial.print("Speed (km/h): ");
        Serial.println(gps.speed.kmph());
      }

      // Cek waktu (jika tersedia)
      if (gps.time.isValid()) {
        Serial.print("Time (UTC): ");
        Serial.print(gps.time.hour());
        Serial.print(":");
        Serial.print(gps.time.minute());
        Serial.print(":");
        Serial.println(gps.time.second());
      }
      
      // Cek tanggal (jika tersedia)
      if (gps.date.isValid()) {
        Serial.print("Date: ");
        Serial.print(gps.date.day());
        Serial.print("/");
        Serial.print(gps.date.month());
        Serial.print("/");
        Serial.println(gps.date.year());
      }
    }
  }
}