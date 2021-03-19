if (typeof(EventSource) !== "undefined") {
    var source = new EventSource("sse_data.php");
    source.onmessage = function(event) {
      var data = JSON.parse(event.data);
      document.getElementById("Temp_C").innerHTML = data.temp_c;
      document.getElementById("Hum_RH").innerHTML = data.hum_rh;
      document.getElementById("Soil_PC").innerHTML = data.soil_pc;
      document.getElementById("Lux").innerHTML = data.lux;
      document.getElementById("pump_status").innerHTML = data.pump_status;
      document.getElementById("light_status").innerHTML = data.light_status;
      document.getElementById("Soil_max").innerHTML = data.max_soil;
      document.getElementById("Soil_min").innerHTML = data.min_soil;
      
      // console.log(JSON.parse(event.data));
    };
  } else {
    document.getElementById("result").innerHTML = "Sorry, your browser does not support server-sent events...";
  }