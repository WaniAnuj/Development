using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using SimpleJSON;

public class Thingspeak : MonoBehaviour
{
   public Text threshch1_fielddisplay;
   public Text threshch2_fielddisplay;
   public InputField threshch1_fieldno;
   public InputField threshch2_fieldno;
   public InputField threshold_value;
   public bool actuation;
   public float download_wait_time;
   
   public Text time_txt;
   public Text sensor_txt;
   public Text axis_txt;
   public Text sensorvalue_txt;
   public Text units_txt;
    public RawImage contimg;
    public RawImage accimg;
    public RawImage gyroimg;
    public RawImage magimg;
    public Text contnonetxt;
    public Text senonetxt;
    public Text consolemsg;
    public InputField tx_api1;
    public InputField tx_api2;
    public Text tx_fieldnoch1;
    public Text tx_fieldnoch2;
    public InputField tx_timer;
    public InputField rx_chid1;
    public InputField rx_chid2;
    public InputField rx_api1;
    public InputField rx_api2;
    public InputField rx_fieldno1;
    public InputField rx_fieldno2;
    public InputField rx_timer;
    public Button runbtn;


    private string sensor_urlch1;
    private string sensor_urlch2;
    private string sensor_gyurl;
    private string upload_urlch1;
    private string upload_urlch2;
    private string download_urlch1_1;
    private string download_urlch1_2;
    private string download_urlch1_3;
    private string download_urlch1_4;
    private string download_urlch1_5;
    private string download_urlch1_6;
    private string download_urlch2_1;
    private string download_urlch2_2;
    private string download_urlch2_3;
    private bool status;
    private bool updownexecuetion;
    private string[] fieldno1;
    private string[] fieldno2;
    private int i;
    private JSONNode jsonData;
    private UnityWebRequest thingspeak_upload;

    private float acc_x;
    private float acc_y;
    private float acc_z;
    private float gyro_x;
    private float gyro_y;
    private float gyro_z;
    private float grav_x;
    private float grav_y;
    private float grav_z;
    private float mag_x;
    private float mag_y;
    private float mag_z;

    private string url1;
    private string url2;
    private string gyurl;
    private bool upstatus;
    private bool downstatus;
    
    private bool accimgstatus;
    private bool gyroimgstatus;
    private bool magimgstatus;
    private bool senstatus;
    private bool contstatus;
    private bool txclearstatus;
    private bool rxclearstatus;

    private string time_lastupdate;
    private string[] split_time_lastupdate;
    private string fieldvalue;
    public void tx_status()
    {
        status = true;
    }

    public void rx_status()
    {
       status = false;
    }
    void Update()
    {
       if(upstatus ==true || downstatus ==true)
       {
          Debug.Log("Image hai");
          contimg.gameObject.SetActive(true);
          contnonetxt.gameObject.SetActive(false);
          contstatus = true;
       }

       else if(txclearstatus)
       {
          Debug.Log("image nahi hai");
          contstatus = false;
          contnonetxt.gameObject.SetActive(true);
          contimg.gameObject.SetActive(false);
       }
       else if(rxclearstatus)
       {
          Debug.Log("Idhar gaya re image");
          contstatus = false;
          contnonetxt.gameObject.SetActive(true);
          contimg.gameObject.SetActive(false);
       }

       if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().accx.isOn==true || GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().accy.isOn==true || GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().accz.isOn)
       {
          accimg.gameObject.SetActive(true);
          senonetxt.gameObject.SetActive(false);
          accimgstatus = true;
       }
       else
       {
          accimg.gameObject.SetActive(false);
          accimgstatus = false;
       }
       if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().gyx.isOn==true || GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().gyy.isOn==true || GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().gyz.isOn)
       {
          gyroimg.gameObject.SetActive(true);
          senonetxt.gameObject.SetActive(false);
          gyroimgstatus = true;
       }
       else
       {
          gyroimg.gameObject.SetActive(false);
          gyroimgstatus = false;
       }
       if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().magx.isOn==true || GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().magy.isOn==true || GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().magz.isOn)
       {
          magimg.gameObject.SetActive(true);
          senonetxt.gameObject.SetActive(false);
          magimgstatus = true;
       }
       else
       {
          magimg.gameObject.SetActive(false);
          magimgstatus = false;
       }
       if(accimgstatus != true && gyroimgstatus != true && magimgstatus != true)
       {
          senonetxt.gameObject.SetActive(true);
          senstatus = false;
       }
       else
       {
          senonetxt.gameObject.SetActive(false);
          senstatus = true;
       }


      if(status == true)
      {
         if(contstatus == false || senstatus == false || GameObject.Find("Sensor Enable").GetComponent<Communication>().commstatus == false)
         {
            runbtn.interactable = false;
         }
         else
         {
            runbtn.interactable = true;
         }
      }
       else
       {
         if(contstatus == false || GameObject.Find("Sensor Enable").GetComponent<Communication>().commstatus == false)
         {
            runbtn.interactable = false;
         }
         else
         {
            runbtn.interactable = true;
         }
       }
    }

    public void clear_threshold()
    {
       threshch1_fielddisplay.text = "";
       threshch2_fielddisplay.text = "";
       threshch2_fieldno.text = "";
       threshch1_fieldno.text = "";
       threshold_value.text = "";
    }

    public void clear_tx()
    {
       tx_api1.text = "";
       tx_api2.text = "";
       tx_fieldnoch1.text = "";
       tx_fieldnoch2.text = "";
       tx_timer.text = "";
       txclearstatus = true;
       upstatus = false;
    }

    public void clear_rx()
    {
       rx_api1.text = "";
       rx_api2.text = "";
       rx_chid1.text = "";
       rx_chid2.text = "";
       rx_fieldno1.text = "";
       rx_fieldno2.text = "";
       rx_timer.text = "";
       rxclearstatus =true;
       downstatus = false;
    }

    public void stop_upndown()
       {
          updownexecuetion = false;
          Debug.Log("Stopped execuetion");
          if(status == true)
          {
             consolemsg.text = consolemsg.text + "Stopped Uploading. \n";
          }
          else
          {
             consolemsg.text = consolemsg.text + "Stopped Downloading. \n";
          }
          
       }
    public void tx_save()
    {
        tx_fieldnoch1.text = GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().fieldch1 + GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().fieldch1_2; 
        Debug.Log("field ch1:"+tx_fieldnoch1.text);

        tx_fieldnoch2.text = GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().fieldch2;
        Debug.Log("field ch2:"+tx_fieldnoch2);

        if(tx_fieldnoch1.text != "" || tx_fieldnoch2.text != "")
        {
           Debug.Log("fields filled");
           upstatus = true;
           txclearstatus = false;
        }
        else
        {
           upstatus= false;
        }
    }

    public void rx_save()
    {
       threshch1_fielddisplay.text = rx_fieldno1.text;
       threshch2_fielddisplay.text = rx_fieldno2.text;
       rxclearstatus = false;
        var field1 = rx_fieldno1.text;
        var field2 =  rx_fieldno2.text;
        fieldno1 = field1.Split(',');
        fieldno2 = field2.Split(',');
        if(field1 != "" || field2 != "")
        {
           downstatus = true;
        }
        else
        {
           downstatus = false;
        }
        for(i = 0; i < fieldno1.Length; i++)
        {
            //  Debug.Log(fieldno1[i]); //each split
             if(fieldno1[i]=="1")
             {
                download_urlch1_1 = "https://api.thingspeak.com/channels/"+rx_chid1.text+"/fields/1/last.json?api_key="+rx_api1.text;
             }
             else if(fieldno1[i]=="2")
             {
                download_urlch1_2 = "https://api.thingspeak.com/channels/"+rx_chid1.text+"/fields/2/last.json?api_key="+rx_api1.text;
             }
             else if(fieldno1[i]=="3")
             {
                download_urlch1_3 = "https://api.thingspeak.com/channels/"+rx_chid1.text+"/fields/3/last.json?api_key="+rx_api1.text;
             }
             else if(fieldno1[i]=="4")
             {
                download_urlch1_4 = "https://api.thingspeak.com/channels/"+rx_chid1.text+"/fields/4/last.json?api_key="+rx_api1.text;
             }
             else if(fieldno1[i]=="5")
             {
                download_urlch1_5 = "https://api.thingspeak.com/channels/"+rx_chid1.text+"/fields/5/last.json?api_key="+rx_api1.text;
             }
             else if(fieldno1[i]=="6")
             {
                download_urlch1_6 = "https://api.thingspeak.com/channels/"+rx_chid1.text+"/fields/6/last.json?api_key="+rx_api1.text;
             }
        }

             for(int i = 0; i < fieldno2.Length; i++)
        {
            //  Debug.Log(fieldno2[i]); //each split
             if(fieldno2[i]=="1")
             {
                download_urlch2_1 = "https://api.thingspeak.com/channels/"+rx_chid2.text+"/fields/1/last.json?api_key="+rx_api2.text;
             }
             else if(fieldno2[i]=="2")
             {
                download_urlch2_2 = "https://api.thingspeak.com/channels/"+rx_chid2.text+"/fields/2/last.json?api_key="+rx_api2.text;
             }
             else if(fieldno2[i]=="3")
             {
                download_urlch2_3 = "https://api.thingspeak.com/channels/"+rx_chid2.text+"/fields/3/last.json?api_key="+rx_api2.text;
             }
             
        }
        // download_url1 = "https://api.thingspeak.com/channels/"+rx_chid1.text+"/feeds.json?api_key="+rx_api1.text+"&results=1";
        // Debug.Log(download_url1);
    }
    public void thingspeak_start()
    {
       updownexecuetion = true;
        if (status == true)
        {
                StartCoroutine(Uploading(GetFloat(tx_timer.text,0.0f)));
        }
        else
        {
                  StartCoroutine(Download(GetFloat(rx_timer.text,0.0f)));
        }
    }

    private float GetFloat(string stringValue, float defaultValue)
{
    float result = defaultValue;
    float.TryParse(stringValue, out result);
    return result;
}

    IEnumerator Uploading(float time)
    {
       while(updownexecuetion)
       {

          url1="";
         if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().accx.isOn)
         {
               Debug.Log("X chalu hua re");
               acc_x = Input.acceleration.x;
               url1 = url1 + "&field1="+ acc_x;
         }
         if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().accy.isOn)
         {
               Debug.Log("Y chalu hua re");
               acc_y = Input.acceleration.y;
               url1 = url1 + "&field2="+acc_y;
         }
         if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().accz.isOn)
         {
               Debug.Log("Z chalu hua re");
               acc_z = Input.acceleration.z;
               url1 = url1 + "&field3="+acc_z;
         }

         gyurl="";
        if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().gyx.isOn)
        {
            Debug.Log("X chalu hua re");
            gyro_x = Input.gyro.attitude.eulerAngles.x;
            gyurl = gyurl + "&field4="+gyro_x;
        }
        if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().gyy.isOn)
        {
            Debug.Log("Y chalu hua re");
            gyro_y = Input.gyro.attitude.eulerAngles.y;
            gyurl = gyurl + "&field5="+gyro_y;
        }
        if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().gyz.isOn)
        {
            Debug.Log("Z chalu hua re");
            gyro_z = Input.gyro.attitude.eulerAngles.z;
            gyurl = gyurl + "&field6="+gyro_z;
        }

        url2 = "";
        if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().magx.isOn)
        {
            Debug.Log("X chalu hua re");
            mag_x = Input.compass.rawVector.x;
            url2 = url2 + "&field1="+mag_x;
        }
        if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().magy.isOn)
        {
            Debug.Log("Y chalu hua re");
            mag_y = Input.compass.rawVector.y;
            url2 = url2 + "&field2="+mag_y;
        }
        if(GameObject.Find("Sensor Enable").GetComponent<Sensor_api>().magz.isOn)
        {
            Debug.Log("Z chalu hua re");
            mag_z = Input.compass.rawVector.z;
            url2 = url2 + "&field3="+mag_z;
        }

        sensor_urlch1 = "";
        sensor_gyurl="";
        sensor_urlch2="";
        sensor_urlch1 = url1;
        sensor_gyurl = gyurl;
        upload_urlch1 = "https://api.thingspeak.com/update?api_key="+tx_api1.text;
        upload_urlch1 = upload_urlch1 + sensor_urlch1 + sensor_gyurl;

        sensor_urlch2 = url2;
        Debug.Log("url 2 status:"+sensor_urlch2);
        upload_urlch2 = "https://api.thingspeak.com/update?api_key="+tx_api2.text;
        upload_urlch2 = upload_urlch2 + sensor_urlch2;

         if(sensor_urlch1 != "" || sensor_gyurl != "")
            {
               UnityWebRequest thingspeak_upload = new UnityWebRequest(upload_urlch1, "POST");
               yield return thingspeak_upload.SendWebRequest();
               if(thingspeak_upload.isNetworkError)
               {
                     Debug.Log("Network error");
               }
               else if(thingspeak_upload.isHttpError)
               {
                     Debug.Log("HTTP error");
                     Debug.Log(thingspeak_upload.responseCode);
               } 
               else
               {
                     Debug.Log("Uploaded1");
                     consolemsg.text = consolemsg.text + "The channel 1, field number "+tx_fieldnoch1.text+"updated \n";
                     consolemsg.text = consolemsg.text + upload_urlch1 + "\n";
               }
            }
         if(sensor_urlch2 != "")
            {
               UnityWebRequest thingspeak_upload = new UnityWebRequest(upload_urlch2, "POST");
               yield return thingspeak_upload.SendWebRequest();
               if(thingspeak_upload.isNetworkError)
               {
                     Debug.Log("Network error");
               }
               else if(thingspeak_upload.isHttpError)
               {
                     Debug.Log("HTTP error");
                     Debug.Log(thingspeak_upload.responseCode);
               } 
               else
               {
                     Debug.Log("Uploaded2");
                     consolemsg.text = consolemsg.text + "The channel 2, field number "+tx_fieldnoch2.text+"updated \n";
                     consolemsg.text = consolemsg.text + upload_urlch2 + "\n";
               }
            }        
        consolemsg.text = consolemsg.text + "\n";
        yield return new WaitForSeconds(time);
       }
    }

     IEnumerator Download(float time)
   {
    while(updownexecuetion)
      { 
      if(rx_api1.text != "" && rx_chid1.text != "")
        {
        for(i = 0; i < fieldno1.Length; i++)
            {
             Debug.Log(fieldno1[i]); //each split
             if(fieldno1[i]=="1")
             {
                using(UnityWebRequest thingspeak_download = UnityWebRequest.Get(download_urlch1_1))
                  {
                        // Request and wait for the desired page.
                        yield return thingspeak_download.SendWebRequest();
                        if (thingspeak_download.isNetworkError || thingspeak_download.isHttpError)
                        {
                           Debug.Log( "Error: " + thingspeak_download.error);
                           Debug.Log("HTTP response code:" + thingspeak_download.responseCode);
                        }
                        else
                        {
                           Debug.Log("data: " + thingspeak_download.downloadHandler.text);
                           jsonData = JSON.Parse(System.Text.Encoding.UTF8.GetString(thingspeak_download.downloadHandler.data));
                           string fnmber = "field1";
                           // Debug.Log(jsonData);
                           // Debug.Log("jsonnode data: " + jsonData["feeds"][0]["field2"]); for feeds downlaod url
                           Debug.Log(jsonData[fnmber]);
                           // consolemsg.text = consolemsg.text + "The Accelerometer X-axis value is "+jsonData[fnmber]+" meter per second squared \n";
                           // consolemsg.text =  consolemsg.text + Time.time + "   Accelerometer   " + "  X-axis  " + jsonData[fnmber] + "  m/s^2 \n";
                           time_lastupdate = jsonData["created_at"];
                           split_time_lastupdate = time_lastupdate.Split(new char[] { 'T','Z' }, System.StringSplitOptions.RemoveEmptyEntries);
                           for(int j = 0; j < split_time_lastupdate.Length; j++)
                              {
                                 Debug.Log("split"+j+": "+split_time_lastupdate[j]);

                              }
                           time_txt.text = time_txt.text + split_time_lastupdate[0] + "," + split_time_lastupdate[1]  + "\n";
                           sensor_txt.text = sensor_txt.text + "Accelerometer \n";
                           axis_txt.text =  axis_txt.text + "X-axis \n";
                           sensorvalue_txt.text =  sensorvalue_txt.text + jsonData[fnmber] + "\n";
                           units_txt.text = units_txt.text + "m/s^2 \n";
                           if(threshch1_fieldno.text == "1")
                           {
                           fieldvalue = jsonData[fnmber];
                           if(GetFloat(fieldvalue,0.0f) > GetFloat(threshold_value.text,0.0f))
                           {
                              Debug.Log("greater then 30 which is " + GetFloat(fieldvalue,0.0f));
                              actuation =  true;
                           }
                           else
                           {
                              Debug.Log("not great bruh");
                              actuation = false;
                           }
                           }
                        }
               }
                Debug.Log("field1 it is");
             }
             else if(fieldno1[i]=="2")
             {
                using(UnityWebRequest thingspeak_download = UnityWebRequest.Get(download_urlch1_2))
                  {
                        // Request and wait for the desired page.
                        yield return thingspeak_download.SendWebRequest();
                        if (thingspeak_download.isNetworkError || thingspeak_download.isHttpError)
                        {
                           Debug.Log( "Error: " + thingspeak_download.error);
                           Debug.Log("HTTP response code:" + thingspeak_download.responseCode);
                        }
                        else
                        {
                           Debug.Log("data: " + thingspeak_download.downloadHandler.text);
                           jsonData = JSON.Parse(System.Text.Encoding.UTF8.GetString(thingspeak_download.downloadHandler.data));
                           string fnmber = "field2";
                           // Debug.Log(jsonData);
                           // Debug.Log("jsonnode data: " + jsonData["feeds"][0]["field2"]); for feeds downlaod url
                           Debug.Log(jsonData[fnmber]);
                           // consolemsg.text = consolemsg.text + "The Accelerometer Y-axis value is "+jsonData[fnmber]+" meter per second squared \n";
                           time_lastupdate = jsonData["created_at"];
                           split_time_lastupdate = time_lastupdate.Split(new char[] { 'T','Z' }, System.StringSplitOptions.RemoveEmptyEntries);
                           time_txt.text = time_txt.text + split_time_lastupdate[0] + "," + split_time_lastupdate[1]  + "\n";
                           sensor_txt.text = sensor_txt.text + "Accelerometer \n";
                           axis_txt.text =  axis_txt.text + "Y-axis \n";
                           sensorvalue_txt.text =  sensorvalue_txt.text + jsonData[fnmber] + "\n";
                           units_txt.text = units_txt.text + "m/s^2 \n";
                           if(threshch1_fieldno.text == "2")
                           {
                           fieldvalue = jsonData[fnmber];
                           if(GetFloat(fieldvalue,0.0f) > GetFloat(threshold_value.text,0.0f))
                           {
                              Debug.Log("greater then 30 which is " + GetFloat(fieldvalue,0.0f));
                              actuation =  true;
                           }
                           else
                           {
                              Debug.Log("not great bruh");
                              actuation = false;
                           }
                           }
                        }
               }
                Debug.Log("field2 it is");
             }
             else if(fieldno1[i]=="3")
             {
                using(UnityWebRequest thingspeak_download = UnityWebRequest.Get(download_urlch1_3))
                  {
                        // Request and wait for the desired page.
                        yield return thingspeak_download.SendWebRequest();
                        if (thingspeak_download.isNetworkError || thingspeak_download.isHttpError)
                        {
                           Debug.Log( "Error: " + thingspeak_download.error);
                           Debug.Log("HTTP response code:" + thingspeak_download.responseCode);
                        }
                        else
                        {
                           Debug.Log("data: " + thingspeak_download.downloadHandler.text);
                           jsonData = JSON.Parse(System.Text.Encoding.UTF8.GetString(thingspeak_download.downloadHandler.data));
                           string fnmber = "field3";
                           // Debug.Log(jsonData);
                           // Debug.Log("jsonnode data: " + jsonData["feeds"][0]["field2"]); for feeds downlaod url
                           Debug.Log(jsonData[fnmber]);
                           // consolemsg.text = consolemsg.text + "The Accelerometer Z-axis value is "+jsonData[fnmber]+" meter per second squared \n";
                           time_lastupdate = jsonData["created_at"];
                           split_time_lastupdate = time_lastupdate.Split(new char[] { 'T','Z' }, System.StringSplitOptions.RemoveEmptyEntries);
                           time_txt.text = time_txt.text + split_time_lastupdate[0] + "," + split_time_lastupdate[1]  + "\n";
                           sensor_txt.text = sensor_txt.text + "Accelerometer \n";
                           axis_txt.text =  axis_txt.text + "Z-axis \n";
                           sensorvalue_txt.text =  sensorvalue_txt.text + jsonData[fnmber] + "\n";
                           units_txt.text = units_txt.text + "m/s^2 \n";
                           if(threshch1_fieldno.text == "3")
                           {
                           fieldvalue = jsonData[fnmber];
                           if(GetFloat(fieldvalue,0.0f) > GetFloat(threshold_value.text,0.0f))
                           {
                              Debug.Log("greater then 30 which is " + GetFloat(fieldvalue,0.0f));
                              actuation =  true;
                           }
                           else
                           {
                              Debug.Log("not great bruh");
                              actuation = false;
                           }
                           }
                        }
                  }
                Debug.Log("field3 it is");
               }
             else if(fieldno1[i]=="4")
             {
                using(UnityWebRequest thingspeak_download = UnityWebRequest.Get(download_urlch1_4))
                  {
                        // Request and wait for the desired page.
                        yield return thingspeak_download.SendWebRequest();
                        if (thingspeak_download.isNetworkError || thingspeak_download.isHttpError)
                        {
                           Debug.Log( "Error: " + thingspeak_download.error);
                           Debug.Log("HTTP response code:" + thingspeak_download.responseCode);
                        }
                        else
                        {
                           Debug.Log("data: " + thingspeak_download.downloadHandler.text);
                           jsonData = JSON.Parse(System.Text.Encoding.UTF8.GetString(thingspeak_download.downloadHandler.data));
                           string fnmber = "field4";
                           // Debug.Log(jsonData);
                           // Debug.Log("jsonnode data: " + jsonData["feeds"][0]["field2"]); for feeds downlaod url
                           Debug.Log(jsonData[fnmber]);
                           // consolemsg.text = consolemsg.text + "The Gyroscope X-axis value is "+jsonData[fnmber]+" degrees \n";
                           time_lastupdate = jsonData["created_at"];
                           split_time_lastupdate = time_lastupdate.Split(new char[] { 'T','Z' }, System.StringSplitOptions.RemoveEmptyEntries);
                           time_txt.text = time_txt.text + split_time_lastupdate[0] + "," + split_time_lastupdate[1]  + "\n";
                           sensor_txt.text = sensor_txt.text + "Gyroscope \n";
                           axis_txt.text =  axis_txt.text + "Pitch \n";
                           sensorvalue_txt.text =  sensorvalue_txt.text + jsonData[fnmber] + "\n";
                           units_txt.text = units_txt.text + "degrees \n";
                           if(threshch1_fieldno.text == "4")
                           {
                           fieldvalue = jsonData[fnmber];
                           if(GetFloat(fieldvalue,0.0f) > GetFloat(threshold_value.text,0.0f))
                           {
                              Debug.Log("greater then 30 which is " + GetFloat(fieldvalue,0.0f));
                              actuation =  true;
                           }
                           else
                           {
                              Debug.Log("not great bruh");
                              actuation = false;
                           }
                           }
                        }
                  }
                Debug.Log("field4 it is");
               }
             if(fieldno1[i]=="5")
             {
                using(UnityWebRequest thingspeak_download = UnityWebRequest.Get(download_urlch1_5))
                  {
                        // Request and wait for the desired page.
                        yield return thingspeak_download.SendWebRequest();
                        if (thingspeak_download.isNetworkError || thingspeak_download.isHttpError)
                        {
                           Debug.Log( "Error: " + thingspeak_download.error);
                           Debug.Log("HTTP response code:" + thingspeak_download.responseCode);
                        }
                        else
                        {
                           Debug.Log("data: " + thingspeak_download.downloadHandler.text);
                           jsonData = JSON.Parse(System.Text.Encoding.UTF8.GetString(thingspeak_download.downloadHandler.data));
                           string fnmber = "field5";
                           // Debug.Log(jsonData);
                           // Debug.Log("jsonnode data: " + jsonData["feeds"][0]["field2"]); for feeds downlaod url
                           Debug.Log(jsonData[fnmber]);
                           // consolemsg.text = consolemsg.text + "The Gyroscope Y-axis value is "+jsonData[fnmber]+" degrees \n";
                           time_lastupdate = jsonData["created_at"];
                           split_time_lastupdate = time_lastupdate.Split(new char[] { 'T','Z' }, System.StringSplitOptions.RemoveEmptyEntries);
                           time_txt.text = time_txt.text + split_time_lastupdate[0] + "," + split_time_lastupdate[1]  + "\n";
                           sensor_txt.text = sensor_txt.text + "Gyroscope \n";
                           axis_txt.text =  axis_txt.text + "Roll \n";
                           sensorvalue_txt.text =  sensorvalue_txt.text + jsonData[fnmber] + "\n";
                           units_txt.text = units_txt.text + "degrees \n";
                           if(threshch1_fieldno.text == "5")
                           {
                           fieldvalue = jsonData[fnmber];
                           if(GetFloat(fieldvalue,0.0f) > GetFloat(threshold_value.text,0.0f))
                           {
                              Debug.Log("greater then 30 which is " + GetFloat(fieldvalue,0.0f));
                              actuation =  true;
                           }
                           else
                           {
                              Debug.Log("not great bruh");
                              actuation = false;
                           }
                           }
                        }
                  }
                  Debug.Log("field5 it is");
               }
             else if(fieldno1[i]=="6")
             {
                using(UnityWebRequest thingspeak_download = UnityWebRequest.Get(download_urlch1_6))
                  {
                        // Request and wait for the desired page.
                        yield return thingspeak_download.SendWebRequest();
                        if (thingspeak_download.isNetworkError || thingspeak_download.isHttpError)
                        {
                           Debug.Log( "Error: " + thingspeak_download.error);
                           Debug.Log("HTTP response code:" + thingspeak_download.responseCode);
                        }
                        else
                        {
                           Debug.Log("data: " + thingspeak_download.downloadHandler.text);
                           jsonData = JSON.Parse(System.Text.Encoding.UTF8.GetString(thingspeak_download.downloadHandler.data));
                           string fnmber = "field6";
                           // Debug.Log(jsonData);
                           // Debug.Log("jsonnode data: " + jsonData["feeds"][0]["field2"]); for feeds downlaod url
                           Debug.Log(jsonData[fnmber]);
                           // consolemsg.text = consolemsg.text + "The Gyroscope Z-axis value is "+jsonData[fnmber]+" degrees \n";
                           time_lastupdate = jsonData["created_at"];
                           split_time_lastupdate = time_lastupdate.Split(new char[] { 'T','Z' }, System.StringSplitOptions.RemoveEmptyEntries);
                           time_txt.text = time_txt.text + split_time_lastupdate[0] + "," + split_time_lastupdate[1]  + "\n";
                           sensor_txt.text = sensor_txt.text + "Gyroscope \n";
                           axis_txt.text =  axis_txt.text + "Yaw \n";
                           sensorvalue_txt.text =  sensorvalue_txt.text + jsonData[fnmber] + "\n";
                           units_txt.text = units_txt.text + "degrees \n";
                           if(threshch1_fieldno.text == "6")
                           {
                           fieldvalue = jsonData[fnmber];
                           if(GetFloat(fieldvalue,0.0f) > GetFloat(threshold_value.text,0.0f))
                           {
                              Debug.Log("greater then 30 which is " + GetFloat(fieldvalue,0.0f));
                              actuation =  true;
                           }
                           else
                           {
                              Debug.Log("not great bruh");
                              actuation = false;
                           }
                           }
                        }
                  }
                  Debug.Log("field6 it is");
               }
            }
         }
        if(rx_api2.text != "" && rx_chid2.text != "")
         {

             for(int i = 0; i < fieldno2.Length; i++)
            {
             Debug.Log(fieldno2[i]); //each split
             if(fieldno2[i]=="1")
             {
                using(UnityWebRequest thingspeak_download = UnityWebRequest.Get(download_urlch2_1))
                  {
                        // Request and wait for the desired page.
                        yield return thingspeak_download.SendWebRequest();
                        if (thingspeak_download.isNetworkError || thingspeak_download.isHttpError)
                        {
                           Debug.Log( "Error: " + thingspeak_download.error);
                           Debug.Log("HTTP response code:" + thingspeak_download.responseCode);
                        }
                        else
                        {
                           Debug.Log("data: " + thingspeak_download.downloadHandler.text);
                           jsonData = JSON.Parse(System.Text.Encoding.UTF8.GetString(thingspeak_download.downloadHandler.data));
                           string fnmber = "field1";
                           // Debug.Log(jsonData);
                           // Debug.Log("jsonnode data: " + jsonData["feeds"][0]["field2"]); for feeds downlaod url
                           Debug.Log(jsonData[fnmber]);
                           // consolemsg.text = consolemsg.text + "The Magnetometer X-axis value is "+jsonData[fnmber]+" microtesla \n";
                           time_lastupdate = jsonData["created_at"];
                           split_time_lastupdate = time_lastupdate.Split(new char[] { 'T','Z' }, System.StringSplitOptions.RemoveEmptyEntries);
                           time_txt.text = time_txt.text + split_time_lastupdate[0] + "," + split_time_lastupdate[1]  + "\n";
                           sensor_txt.text = sensor_txt.text + "Magnetometer \n";
                           axis_txt.text =  axis_txt.text + "X-axis \n";
                           sensorvalue_txt.text =  sensorvalue_txt.text + jsonData[fnmber] + "\n";
                           units_txt.text = units_txt.text + "microTesla \n";
                           if(threshch2_fieldno.text == "1")
                           {
                           fieldvalue = jsonData[fnmber];
                           if(GetFloat(fieldvalue,0.0f) > GetFloat(threshold_value.text,0.0f))
                           {
                              Debug.Log("greater then 30 which is " + GetFloat(fieldvalue,0.0f));
                              actuation =  true;
                           }
                           else
                           {
                              Debug.Log("not great bruh");
                              actuation = false;
                           }
                           }
                        }
                  }
                Debug.Log("ch2 field1 it is");
             }
             else if(fieldno2[i]=="2")
             {
                using(UnityWebRequest thingspeak_download = UnityWebRequest.Get(download_urlch2_2))
                  {
                        // Request and wait for the desired page.
                        yield return thingspeak_download.SendWebRequest();
                        if (thingspeak_download.isNetworkError || thingspeak_download.isHttpError)
                        {
                           Debug.Log( "Error: " + thingspeak_download.error);
                           Debug.Log("HTTP response code:" + thingspeak_download.responseCode);
                        }
                        else
                        {
                           Debug.Log("data: " + thingspeak_download.downloadHandler.text);
                           jsonData = JSON.Parse(System.Text.Encoding.UTF8.GetString(thingspeak_download.downloadHandler.data));
                           string fnmber = "field2";
                           // Debug.Log(jsonData);
                           // Debug.Log("jsonnode data: " + jsonData["feeds"][0]["field2"]); for feeds downlaod url
                           Debug.Log(jsonData[fnmber]);
                           // consolemsg.text = consolemsg.text + "The Magnetometer Y-axis value is "+jsonData[fnmber]+" microtesla \n";
                           time_lastupdate = jsonData["created_at"];
                           split_time_lastupdate = time_lastupdate.Split(new char[] { 'T','Z' }, System.StringSplitOptions.RemoveEmptyEntries);
                           time_txt.text = time_txt.text + split_time_lastupdate[0] + "," + split_time_lastupdate[1]  + "\n";
                           sensor_txt.text = sensor_txt.text + "Magnetometer \n";
                           axis_txt.text =  axis_txt.text + "Y-axis \n";
                           sensorvalue_txt.text =  sensorvalue_txt.text + jsonData[fnmber] + "\n";
                           units_txt.text = units_txt.text + "microTesla \n";
                           if(threshch2_fieldno.text == "2")
                           {
                           fieldvalue = jsonData[fnmber];
                           if(GetFloat(fieldvalue,0.0f) > GetFloat(threshold_value.text,0.0f))
                           {
                              Debug.Log("greater then 30 which is " + GetFloat(fieldvalue,0.0f));
                              actuation =  true;
                           }
                           else
                           {
                              Debug.Log("not great bruh");
                              actuation = false;
                           }
                           }
                        }
                  }
                Debug.Log("ch2 field2 it is");
             }
             else if(fieldno2[i]=="3")
             {
                using(UnityWebRequest thingspeak_download = UnityWebRequest.Get(download_urlch2_3))
                  {
                        // Request and wait for the desired page.
                        yield return thingspeak_download.SendWebRequest();
                        if (thingspeak_download.isNetworkError || thingspeak_download.isHttpError)
                        {
                           Debug.Log( "Error: " + thingspeak_download.error);
                           Debug.Log("HTTP response code:" + thingspeak_download.responseCode);
                        }
                        else
                        {
                           Debug.Log("data: " + thingspeak_download.downloadHandler.text);
                           jsonData = JSON.Parse(System.Text.Encoding.UTF8.GetString(thingspeak_download.downloadHandler.data));
                           string fnmber = "field3";
                           // Debug.Log(jsonData);
                           // Debug.Log("jsonnode data: " + jsonData["feeds"][0]["field2"]); for feeds downlaod url
                           Debug.Log(jsonData[fnmber]);
                           // consolemsg.text = consolemsg.text + "The Magnetometer Z-axis value is "+jsonData[fnmber]+" microtesla \n";
                           time_lastupdate = jsonData["created_at"];
                           split_time_lastupdate = time_lastupdate.Split(new char[] { 'T','Z' }, System.StringSplitOptions.RemoveEmptyEntries);
                           time_txt.text = time_txt.text + split_time_lastupdate[0] + "," + split_time_lastupdate[1]  + "\n";
                           sensor_txt.text = sensor_txt.text + "Magnetometer \n";
                           axis_txt.text =  axis_txt.text + "Z-axis \n";
                           sensorvalue_txt.text =  sensorvalue_txt.text + jsonData[fnmber] + "\n";
                           units_txt.text = units_txt.text + "microTesla \n";
                           if(threshch2_fieldno.text == "3")
                           {
                           fieldvalue = jsonData[fnmber];
                           if(GetFloat(fieldvalue,0.0f) > GetFloat(threshold_value.text,0.0f))
                           {
                              Debug.Log("greater then 30 which is " + GetFloat(fieldvalue,0.0f));
                              actuation =  true;
                           }
                           else
                           {
                              Debug.Log("not great bruh");
                              actuation = false;
                           }
                           }
                        }
                  }
                Debug.Log("ch2 field3 it is");
               }
            }
         }
         consolemsg.text = consolemsg.text + "\n";
         download_wait_time = time;
         yield return new WaitForSeconds(download_wait_time);
      }
   } 

   public void clear_console()
   {
      consolemsg.text = "";
      time_txt.text = "";
      sensor_txt.text = "";
      axis_txt.text = "";
      sensorvalue_txt.text = "";
      units_txt.text = "";
   }        
}
