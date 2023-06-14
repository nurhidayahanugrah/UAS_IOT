# Ujian Akhir Semester
## Mata Kuliah Internet of Things (IoT)

## Anggota Kelompok
* 2009106010 Muhammad Akmal Rifad
* 2009106102 Olivia Oktavi Utami
* 2009106112 Adrian Tasmin
* 2009106121 Nurhidayah Anugrah
* 2009106148 Yusuf Adhy Iswanto

## Deskripsi Projek
Projek ini merupakan smarthome berbasis Internet of Things (IoT) yang dimana dapat memonitoring suhu di tiap-tiap ruangan. Untuk memonitoring suhu tersebut dapat melalui aplikasi maupun website yang telah dibuat.

## Penjelasan
### Wokwi
* Sensor suhu pada rangkaian Wokwi membaca nilai suhu.
* Perangkat ESP8266 atau NodeMCU yang terhubung ke Wokwi memperoleh nilai suhu tersebut.
* Perangkat terhubung ke broker MQTT menggunakan koneksi Wi-Fi.
* Perangkat menerbitkan data suhu ke broker MQTT dengan menggunakan topik yang ditentukan dan payload berisi nilai suhu tersebut.

### Broker
* Broker yang digunakan adalah shiftr.io dengan alamat "https://uas-iot.cloud.shiftr.io/" yang berfungsi mengambil data dari sensor di wokwi kemudian mengirimkan ke database.
* Setelah Kodular menerima pesan dengan data suhu dari broker MQTT, Kodular mengirimkan data suhu tersebut ke server menggunakan webhook.
* Data suhu yang diterima oleh server dikirimkan ke database website yang sesuai.
* Data suhu disimpan dalam database website dengan nama database "id20859976_suhuruanganku"

### Database
Untuk penyimpanan database kami menggunakan 000webhost karena menyediakan webhook. Database dibuat di phpmyadmin. Untuk tabel database terdiri dari 6 tabel sesuai dengan kamar yang dibuat yaitu gaming, kitchen, gym, bed, bath, dan living. Tiap tabel memiliki 3 atribut yang sama yaitu ID, Suhu, dan Waktu. Tiap kamar memiliki 1 topik.

### Kodular
* Pada proyek Kodular, komponen MQTT dikonfigurasi dengan menggunakan alamat broker "https://uas-iot.cloud.shiftr.io/" dan informasi kredensial yang sama dengan broker yang digunakan seperti username dan password.
* Kodular menetapkan subscription (langganan) pada topik yang sama dengan yang digunakan oleh perangkat Wokwi.
* Saat ada pesan baru pada topik yang di-subscribe, Kodular menerima pesan tersebut dari broker MQTT.
* Data suhu yang diterima oleh Kodular dapat diolah atau ditampilkan ke pengguna melalui aplikasi.

### Tampilan
1. Android
Untuk desain aplikasi menggunakan website kodular. Berikut tampilan dari aplikasinya:
![WhatsApp Image 2023-06-14 at 14 13 55](https://github.com/nurhidayahanugrah/UAS_IOT/assets/102194104/5d6a9431-3935-4e77-953b-9cea1280b307)
![WhatsApp Image 2023-06-14 at 14 14 28](https://github.com/nurhidayahanugrah/UAS_IOT/assets/102194104/80cd39fc-60ef-4972-a139-fcd44b14a1df)

2. Website
url: https://iotsuhuucuppp.000webhostapp.com/index.html
