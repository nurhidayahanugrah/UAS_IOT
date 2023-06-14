<?php

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "iot_suhu";

$conn = mysqli_connect($servername, $username, $password, $dbname);

if(!$conn){
    die("Koneksi ke database gagal: ".mysqli_connect_error());
}


?>