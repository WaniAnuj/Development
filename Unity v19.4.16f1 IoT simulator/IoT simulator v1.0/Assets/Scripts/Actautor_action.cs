using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Actautor_action : MonoBehaviour
{
    public AudioSource alert;
    public GameObject popup_panel;
    private bool hapticstatus;
    private bool audiostatus;
    private bool popupstatus;
    private bool actuator_run;
    // private bool okstatus;

void Start()
{
     audiostatus = false;
}
    public void haptic_select()
    {
        hapticstatus = true;
        audiostatus = false;
        popupstatus = false;
        Debug.Log("haptic selected");
    }

    public void audio_select()
    {
        audiostatus = true;
        hapticstatus = false;
        popupstatus = false;
    }

    public void popup_select()
    {
        popupstatus = true;
        audiostatus = false;
        hapticstatus = false;
    }

    public void run()
    {
        actuator_run = true;
    }

    public void stop()
    {
        actuator_run = false;
    }

    public void actuate()
    {
        StartCoroutine(feedback());
    }

    public void okbtn()
    {
        popup_panel.SetActive(false);
    }

    IEnumerator feedback()
    {
        while(actuator_run)
        {
        Debug.Log("actuate entered");
        Debug.Log ("actuationstatus: "+ GameObject.Find("Sensor Enable").GetComponent<Thingspeak>().actuation);
        if(GameObject.Find("Sensor Enable").GetComponent<Thingspeak>().actuation)
        {
            Debug.Log("actuate true");
            if(hapticstatus)
            {
                Debug.Log("vibrate on");
                Handheld.Vibrate();
                yield return new WaitForSeconds(1);
                Handheld.Vibrate();
                yield return new WaitForSeconds(1);
                Handheld.Vibrate();
            }

            if(audiostatus)
            {
                Debug.Log("Audio on");
                alert.Play();
                if(alert.isPlaying != true)
                {
                    alert.Stop();
                }
            }

            if(popupstatus)
            {
                Debug.Log("pop up");
                popup_panel.SetActive(true);
            }
        }
        yield return new WaitForSeconds(GameObject.Find("Sensor Enable").GetComponent<Thingspeak>().download_wait_time);
        }
    }
}
