 using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;


public class Sensor_api : MonoBehaviour
{
    public Toggle accx;
    public Toggle accy;
    public Toggle accz;
    // public Toggle accavail;
    public Toggle gyx;
    public Toggle gyy;
    public Toggle gyz;
    // public Toggle gyavail;
    public Toggle gtx;
    public Toggle gty;
    public Toggle gtz;
    // public Toggle gvtavail;
    public Toggle magx;
    public Toggle magy;
    public Toggle magz;
    public string fieldch1;
    public string fieldch1_2;
    public string fieldch2;

    public void enable_gyro()
    {
        Input.gyro.enabled = true;
        Debug.Log("Gyro enabled");
    }


    
    //no fuction to check magnetometers availabilty might have to enable at start
    //to make sure it exists
    public void enable_mag()
    {
        Input.compass.enabled = true;
        Debug.Log("Magnet enabled");
    }
    public void Haptics()
    {
        Handheld.Vibrate();
    }
    public void acc_save()
    {
        fieldch1="";
        if(accx.isOn)
        {
            Debug.Log("X chalu hua re");
            fieldch1 = fieldch1+"1, ";
        }
        if(accy.isOn)
        {
            Debug.Log("Y chalu hua re");
            fieldch1 = fieldch1+"2, ";
        }
        if(accz.isOn)
        {
            Debug.Log("Z chalu hua re");
            fieldch1 = fieldch1+"3, ";
        }
    }

    public void acc_clear()
    {
        accx.isOn = false;
        accy.isOn = false;
        accz.isOn = false;
        fieldch1 = "";
    }

    public void gyro_save()
    {;
        fieldch1_2 = "";
        if(gyx.isOn)
        {
            Debug.Log("X chalu hua re");
            fieldch1_2 = fieldch1_2+"4, ";
        }
        if(gyy.isOn)
        {
            Debug.Log("Y chalu hua re");
            fieldch1_2 = fieldch1_2+"5, ";
        }
        if(gyz.isOn)
        {
            Debug.Log("Z chalu hua re");
            fieldch1_2 = fieldch1_2+"6.";
        }
    }

    public void gyro_clear()
    {
        gyx.isOn = false;
        gyy.isOn = false;
        gyz.isOn = false;
        fieldch1_2 = "";
    }

    // public void gvt_save()
    // {
    //     if(gtx.isOn)
    //     {
    //         Debug.Log("X chalu hua re");
    //         grav_x = Input.gyro.gravity.x;
    //         url1 = url1 + "&field3=3";//+acc_z;
    //     }
    //     // else
    //     // {
    //     //     Debug.Log("band hua re");
    //     // }
    //     if(gty.isOn)
    //     {
    //         Debug.Log("Y chalu hua re");
    //         grav_y = Input.gyro.gravity.y;
    //         url1 = url1 + "&field3=3";//+acc_z;
    //     }
    //     // else
    //     // {
    //     //     Debug.Log("band hua re");
    //     // }
    //     if(gtz.isOn)
    //     {
    //         Debug.Log("Z chalu hua re");
    //         grav_z = Input.gyro.gravity.z;
    //         url1 = url1 + "&field3=3";//+acc_z;
    //     }
    //     // else
    //     // {
    //     //     Debug.Log("band hua re");
    //     // }
    // }

    public void mag_save()
    {
        fieldch2="";
        if(magx.isOn)
        {
            Debug.Log("X chalu hua re");
            fieldch2 = fieldch2+"1, ";
        }
        if(magy.isOn)
        {
            Debug.Log("Y chalu hua re");
            fieldch2 = fieldch2+"2, ";
        }
        if(magz.isOn)
        {
            Debug.Log("Z chalu hua re");
            fieldch2 = fieldch2+"3.";
        }
    }

    public void mag_clear()
    {
        magx.isOn = false;
        magy.isOn = false;
        magz.isOn = false;
        fieldch2 = "";
    }

    
}
