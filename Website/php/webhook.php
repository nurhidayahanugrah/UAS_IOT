<?php
include "data.php";
error_reporting(1);
$webHS = json_decode(file_get_contents('php://input'), true);
$topic = $webHS['topic'];
$payload = $webHS['payload'];

if ($topic == 'ucupp/iot/bed') {
   $sql = "INSERT INTO bed (suhu) VALUES ('$payload')";
}
if ($topic == 'ucupp/iot/living') {
   $sql = "INSERT INTO living (suhu) VALUES ('$payload')";
}
if ($topic == 'ucupp/iot/kitchen') {
   $sql = "INSERT INTO kitchen (suhu) VALUES ('$payload')";
}
if ($topic == 'ucupp/iot/bath') {
   $sql = "INSERT INTO bath (suhu) VALUES ('$payload')";
}
if ($topic == 'ucupp/iot/gaming') {
   $sql = "INSERT INTO gaming (suhu) VALUES ('$payload')";
}
if ($topic == 'ucupp/iot/gym') {
   $sql = "INSERT INTO gym (suhu) VALUES ('$payload')";
}
if ($topic != null) {
   mysqli_query($conn, $sql);

}
?>