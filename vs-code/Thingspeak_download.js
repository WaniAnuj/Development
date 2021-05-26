var downloadurl = "https://api.thingspeak.com/channels/1394967/feeds.json?api_key=WSXCBQW7MDOVN72W&results=1"

var XMLHttpRequest = require("xmlhttprequest").XMLHttpRequest;
var xhr = new XMLHttpRequest();
xhr.withCredentials = true;

xhr.onload = function(){
  var resp_jsontext = xhr.responseText;
  var resp_json = JSON.parse(resp_jsontext)
  // console.log(resp_json)
  var longitude = resp_json["feeds"][0]["field1"]
  var latitude = resp_json["feeds"][0]["field2"]
  var altitude = resp_json["feeds"][0]["field3"]
  var humidity = resp_json["feeds"][0]["field4"]
  var temperature = resp_json["feeds"][0]["field5"]
  var co2_conc = resp_json["feeds"][0]["field6"]
  var pir = resp_json["feeds"][0]["field7"]
  var distance = resp_json["feeds"][0]["field8"]
}

xhr.open("GET", downloadurl);
// xhr.responseType = 'text'
xhr.send();