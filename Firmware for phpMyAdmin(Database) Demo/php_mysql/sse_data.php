<?php
header('Content-Type: text/event-stream');
header('Cache-Control: no-cache');

require_once("setting.php");

$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
   die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT ID, Temperature_C, Humidity_RH, Soil_moisture_PC, Brightness_LUX, Soil_Min, Soil_Max, Pump_status, Light_status, DATE_TIME FROM sensordata ORDER BY id DESC LIMIT 1";
if ($result = $conn->query($sql)) {
   while ($row = $result->fetch_assoc()) {
      $row_ID = $row["ID"];
      $row_Temperature_C = $row["Temperature_C"];
      $row_Humidity_RH = $row["Humidity_RH"];
      $row_Soil_moisture_PC = $row["Soil_moisture_PC"];
      $row_Brightness_LUX = $row["Brightness_LUX"];
      $Soil_Min = $row["Soil_Min"];
      $Soil_Max = $row["Soil_Max"];
      $Pump_status = $row["Pump_status"];
      $Light_status = $row["Light_status"];
      $row_DATE_TIME = $row["DATE_TIME"];
   }
   $result->free();
}
$all = json_encode(array("temp_c"=>$row_Temperature_C, "hum_rh"=>$row_Humidity_RH, "soil_pc"=>$row_Soil_moisture_PC, "lux"=>$row_Brightness_LUX, "min_soil"=>$Soil_Min, "max_soil"=>$Soil_Max, "pump_status"=>$Pump_status, "light_status"=>$Light_status));
echo "data: {$all}\n\n";

flush();
$conn->close();
?>