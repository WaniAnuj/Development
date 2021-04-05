using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;

public class Panel_switching : MonoBehaviour
{
    public Button sensorbtn;
    public Button commsbtn;
    public Button actuatorbtn;
    public GameObject Landing_panel;
    public GameObject Home_panel;
    public GameObject Sensor_panel;
    public GameObject Controller_panel;
    public GameObject Actuator_panel;
    public GameObject Comms_panel;
    public GameObject txupload_panel;
    public GameObject rxdownload_panel;
    public GameObject Console_panel;
    public GameObject mobnet_panel;
    public GameObject wifi_panel;
    public GameObject acc_panel;
    public GameObject gyro_panel;
    public GameObject mag_panel;
    public GameObject test_panel;
    public GameObject console_upload_panel;
    public GameObject console_download_panel;
    public GameObject threshold_panel;

    private bool tx;


    // Start is called before the first frame update
    void Start()
    {
        // if(Home_panel != null)
        // {
        //     Home_panel.SetActive(false);
        // }
        // if(Landing_panel != null)
        // {
        //     Landing_panel.SetActive(true);
        // }
        // if(Sensor_panel != null)
        // {
        //     Sensor_panel.SetActive(false);
        // }
        // if(Controller_panel != null)
        // {
        //     Controller_panel.SetActive(false);
        // }
        // if(Actuator_panel != null)
        // {
        //     Actuator_panel.SetActive(false);
        // }
        // if(Comms_panel != null)
        // {
        //     Comms_panel.SetActive(false);
        // }
        // if(txupload_panel != null)
        // {
        //     txupload_panel.SetActive(false);
        // }
        // if(rxdownload_panel != null)
        // {
        //     rxdownload_panel.SetActive(false);
        // }
        // if(mobnet_panel != null)
        // {
        //     mobnet_panel.SetActive(false);
        // }
        // if(wifi_panel != null)
        // {
        //     wifi_panel.SetActive(false);
        // }
        // if(Console_panel != null)
        // {
        //     Console_panel.SetActive(false);
        // }
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void txmode()
    {
        tx = true;
        Debug.Log(tx);
    }
    
    public void rxmode()
    {
        tx = false;
    }
    public void console_panel_switch()
    {
       if(tx == true)
       {
          console_upload_panel.SetActive(true);
          console_download_panel.SetActive(false);
       }
       else
       {
          console_download_panel.SetActive(true);
          console_upload_panel.SetActive(false);
       }
    }

    public void Close_Home_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(true);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
        if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_Home_panel()
    {
        if(tx == true)
        {
            
            actuatorbtn.interactable = false;
            sensorbtn.interactable = true;
            // commsbtn.interactable = false;
        }
        else if(tx == false)
        {
            
            sensorbtn.interactable = false;
            actuatorbtn.interactable = true;
            // commsbtn.interactable = false;
        }
        if(Home_panel != null)
        {
            Home_panel.SetActive(true);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_Sensor_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(true);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_Controller_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(true);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_Actuator_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(true);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_Comms_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(true);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

     public void Open_txrx_panel()
    { 
        if(tx == true)
        {
            Debug.Log(tx);
            if(Home_panel != null)
            {
                Home_panel.SetActive(false);
            }
            if(Landing_panel != null)
            {
                Landing_panel.SetActive(false);
            }
            if(Sensor_panel != null)
            {
                Sensor_panel.SetActive(false);
            }
            if(Controller_panel != null)
            {
                Controller_panel.SetActive(false);
            }
            if(Actuator_panel != null)
            {
                Actuator_panel.SetActive(false);
            }
            if(Comms_panel != null)
            {
                Comms_panel.SetActive(false);
            }
            if(txupload_panel != null)
            {
                txupload_panel.SetActive(true);
            }
            if(rxdownload_panel != null)
            {
                rxdownload_panel.SetActive(false);
            }
            if(mobnet_panel != null)
            {
                mobnet_panel.SetActive(false);
            }
            if(wifi_panel != null)
            {
                wifi_panel.SetActive(false);
            }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
        }
    else{
        Debug.Log(tx);
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(true);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }
    }

    public void Open_console_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(true);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_mobnet_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(true);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_wifi_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(true);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_acc_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(true);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_gyro_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(true);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Open_mag_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(true);
        }
        if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Close_sensor_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(true);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Close_controller_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(true);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

     public void Close_actuator_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(true);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

     public void Close_comms_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(true);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

     public void Close_console_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(true);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

     public void Close_wifi_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(true);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

     public void Close_mobnet_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(true);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

     public void Close_txupload_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(true);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Close_rxdownload_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(true);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Close_acc_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Close_gyro_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void Close_mag_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
    }

    public void open_test_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(false);
        }
        if(test_panel != null)
        {
            test_panel.SetActive(true);
        }
    }

    public void Open_threshold_panel()
    {
        if(Home_panel != null)
        {
            Home_panel.SetActive(false);
        }
        if(Landing_panel != null)
        {
            Landing_panel.SetActive(false);
        }
        if(Sensor_panel != null)
        {
            Sensor_panel.SetActive(false);
        }
        if(Controller_panel != null)
        {
            Controller_panel.SetActive(false);
        }
        if(Actuator_panel != null)
        {
            Actuator_panel.SetActive(false);
        }
        if(Comms_panel != null)
        {
            Comms_panel.SetActive(false);
        }
        if(txupload_panel != null)
        {
            txupload_panel.SetActive(false);
        }
        if(rxdownload_panel != null)
        {
            rxdownload_panel.SetActive(false);
        }
        if(mobnet_panel != null)
        {
            mobnet_panel.SetActive(false);
        }
        if(wifi_panel != null)
        {
            wifi_panel.SetActive(false);
        }
        if(Console_panel != null)
        {
            Console_panel.SetActive(false);
        }
        if(acc_panel != null)
        {
            acc_panel.SetActive(false);
        }
        if(gyro_panel != null)
        {
            gyro_panel.SetActive(false);
        }
        if(mag_panel != null)
        {
            mag_panel.SetActive(false);
        }
if(threshold_panel != null)
        {
            threshold_panel.SetActive(true);
        }
    }
}
