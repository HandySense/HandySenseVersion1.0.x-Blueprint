<!DOCTYPE html>
<html>

<body>
  <?php

  require_once("setting.php");

  if (isset($_REQUEST["Temperature_C"])) { 
    $Temperature_C = $_REQUEST["Temperature_C"];
  } else {
    $Temperature_C = '99';
  }

  if (isset($_REQUEST["Humidity_RH"])) { 
    $Humidity_RH = $_REQUEST["Humidity_RH"];
  } else {
    $Humidity_RH = '99';
  }

  if (isset($_REQUEST["Soil_moisture_PC"])) { 
    $Soil_moisture_PC = $_REQUEST["Soil_moisture_PC"];
  } else {
    $Soil_moisture_PC = '99';
  }

  if (isset($_REQUEST["Brightness_LUX"])) { 
    $Brightness_LUX = $_REQUEST["Brightness_LUX"];
  } else {
    $Brightness_LUX = '99';
  }

  if (isset($_REQUEST["Soil_Min"])) { 
    $Soil_Min = $_REQUEST["Soil_Min"];
  } else {
    $Soil_Min = '99';
  }

  if (isset($_REQUEST["Soil_Max"])) { 
    $Soil_Max = $_REQUEST["Soil_Max"];
  } else {
    $Soil_Max = '99';
  }

  if (isset($_REQUEST["Pump_status"])) {
    $Pump_status = $_REQUEST["Pump_status"];
  } else {
    $Pump_status = '99';
  }

  if (isset($_REQUEST["Light_status"])) { 
    $Light_status = $_REQUEST["Light_status"];
  } else {
    $Light_status = '99';
  }

  $conn = new PDO(
    "mysql:host=$servername;dbname=$dbname",
    $username,
    $password,
    array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8")
  );
  $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

  try {
    $conn->beginTransaction();

    $sth = $conn->prepare("INSERT INTO sensordata (Temperature_C, Humidity_RH, Soil_moisture_PC, Brightness_LUX, Soil_Min, Soil_Max, Pump_status, Light_status) 
          VALUES (:Temperature_C, :Humidity_RH, :Soil_moisture_PC, :Brightness_LUX, :Soil_Min, :Soil_Max, :Pump_status, :Light_status)");

    $sth->bindParam(':Temperature_C', $Temperature_C);
    $sth->bindParam(':Humidity_RH', $Humidity_RH);
    $sth->bindParam(':Soil_moisture_PC', $Soil_moisture_PC);
    $sth->bindParam(':Brightness_LUX', $Brightness_LUX);

    $sth->bindParam(':Soil_Min', $Soil_Min);
    $sth->bindParam(':Soil_Max', $Soil_Max);
    $sth->bindParam(':Pump_status', $Pump_status);
    $sth->bindParam(':Light_status', $Light_status);
    $sth->execute();

    // commit the transaction
    $conn->commit();
    echo 'Updated';
  } catch (PDOException $e) {
    // roll back the transaction if something failed
    $conn->rollback();
    echo "Error: " . $e->getMessage();
  }
  ?>
  </table>
</body>

</html>