<!DOCTYPE html>
<html lang="en">

<head>
  <!-- Required meta tags -->
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <!-- Title -->
  <title>Handy sense</title>
  <!-- logo -->
  <link rel="icon" type="png" href="picture/saming_login.png">
  <!-- Icon -->
  <script src='js/a076d05399.js'></script>
  <!-- JS sse data -->
  <script src='js/sse_alldata.js'></script>
  <!-- Google font -->
  <link rel="stylesheet" href="css/google-font.css">
  <link rel="stylesheet" href="css/font_thai.css">
  <!-- Bootstrap CSS -->
  <link rel="stylesheet" href="css/bootstrap.min.css">
  <!-- Bootstrap JS -->
  <script src="js/bootstrap.min.js"></script>
  <script src="js/bootstrap.bundle.min.js"></script>
  <script src="js/jquery-3.4.1.slim.min.js"></script>
  <script src="js/popper.min.js"></script>
</head>

<body>
  <nav class="navbar navbar-light" style="background-color: #2ECC71;">
    <div class="container-fluid">
      <a class="navbar-brand" href="#" style="color: #FDFEFE;">Open innovation</a>
      <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
    </div>
  </nav>

  <div class="container-fluid">
    <div class="row content">
      <div class="col-sm-3 sidenav">
        <br>
        <h4>Value</h4>
        <hr>
        <ul class="nav nav-pills nav-stacked">
          <div class="container">

            <div class="alert alert-dark">
              <i class='fas fa-temperature-low' style='text-align:left;font-size:30px;color:green'></i> &nbsp;
              <h7 id="Temp_C" class="citythai" style='font-size:20px'></h7>
              <h7 class="citythai" style='font-size:20px'> ํC</h7>
              <label class="citythai" style='font-size:16px'>(อุณหภูมิ)</label>
            </div>

            <div class="alert alert-dark">
              <i class='fas fa-cloud-sun-rain' style='font-size:30px;color:green'></i>&nbsp;
              <h7 id="Hum_RH" class="citythai" style='font-size:20px'></h7>
              <h7 class="citythai" style='font-size:20px'> %RH</h7>
              <label class="citythai" style='font-size:16px'>(ความชื้น)</label>
            </div>

            <div class="alert alert-dark">
              <div class='fas fa-tint' style='font-size:30px;color:green'></div>&nbsp;&nbsp;&nbsp;
              <h7 id="Soil_PC" class="citythai" style='font-size:20px'></h7>
              <h7 class="citythai" style='font-size:20px'> %</h7>
              <label class="citythai" style='font-size:16px'>(ความชื้นดิน)</label>
            </div>

            <div class="alert alert-dark">
              <div class='far fa-sun' style='font-size:30px;color:green'></div>&nbsp;
              <h7 id="Lux" class="citythai" style='font-size:20px'></h7>
              <h7 class="citythai" style='font-size:20px'> LUX</h7>
              <label class="citythai" style='font-size:16px'>(ความสว่าง)</label>
            </div>

          </div>
        </ul><br>
      </div>

      <div class="col-sm-3 sidenav">
        <br>
        <h4>Status</h4>
        <hr>
        <ul class="nav nav-pills nav-stacked">
          <div class="container">

            <div class="alert alert-dark">
              <div class='fas fa-luggage-cart' style='font-size:30px;color:green'></div> &nbsp;
              <label class="citythai" style='text-align: right;font-size:16px'>ปั้มน้ำ :</label> &nbsp;
              <h7 id="pump_status" class="citythai" style='text-align: right; font-size:20px'></h7>

            </div>
            <div class="alert alert-dark">
              <div class='far fa-lightbulb' style='font-size:30px;color:green'></div>&nbsp;&nbsp;
              <label class="citythai" style='font-size:16px'>หลอดไฟ :</label>&nbsp;
              <h7 id="light_status" class="citythai" style='font-size:20px'></h7>
            </div>

          </div>
        </ul>
        <h4>Setting Soil Moisture</h4>
        <hr>
        <ul class="nav nav-pills nav-stacked">
          <div class="container">

            <div class="alert alert-dark">
              <div class='fas fa-angle-up' style='font-size:30px;color:green'></div>
              <label class="citythai" style='font-size:14px'>ความชื้นดินสูงสุด</label>
              <h7 id="Soil_max" class="citythai" style='font-size:18px'></h7> &nbsp;
              <h7 class="citythai" style='font-size:20px'> %</h7>
              <br>

              <div class='fas fa-angle-down' style='font-size:30px;color:green'></div>
              <label class="citythai" style='font-size:14px'>ความชื้นดินต่ำสุด</label>
              <h7 id="Soil_min" class="citythai" style='font-size:18px'> <?php echo  $Soil_Min ?></h7> &nbsp;
              <h7 class="citythai" style='font-size:20px'> %</h7>
            </div>

          </div>
        </ul><br>
      </div>

      <div class="col-sm-6">
        <br>
        <h4><small>Handy sense project</small></h4>
        <hr>
        <h2>Open innovation</h2>
        <h5><span class="glyphicon glyphicon-time"></span> Sep 27, 2020.</h5>
        <h5><span class="label label-danger">Handy Sense</span> <span class="label label-primary">Version 1.0</span></h5><br>
        <p class="citythai2">
          เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT
          เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT
          เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT
          เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT
          เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT
          เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT เป็นโครงการเพื่อพัฒนาเกษตรอัฉริยะให้กับเกตรกรไทยได้ใช้เทคโนโลยี IOT
        </p>
        <br><br>
      </div>
    </div>
  </div>

  <div class="footer1">
    <p></p>
    <p href="https://.../">Version Demo,. Handy Sense</p>
  </div>
</body>

</html>