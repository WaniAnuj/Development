using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Communication : MonoBehaviour
{
    // Start is called before the first frame update
    public Text console_scrn;
    public Button wifibtn;
    public Button gsmbtn;
    public Text wifibtn_connect;
    public Text gsmbtn_connect;
    public Text nonetxt;
    public RawImage wifiimg;
    public RawImage gsmimg;
    public bool commstatus;
    public bool wifi;
    public bool gsm;
    private bool wbtn;
    private bool gbtn;
    private string m_ReachabilityText;


    void Update()
    {
        if(wifi == false && gsm ==false)
        {
            nonetxt.gameObject.SetActive(true);
            commstatus = false;
        }
        else
        {
            commstatus = true;    
        }

        // console_scrn.text = "Internet : " + m_ReachabilityText;
        //Check if the device cannot reach the internet
        if (Application.internetReachability == NetworkReachability.NotReachable)
        {
            //Change the Text
            // m_ReachabilityText = "Not Reachable.";
            wifibtn.interactable = false;
            gsmbtn.interactable = false;
        }
        //Check if the device can reach the internet via a carrier data network
        else if (Application.internetReachability == NetworkReachability.ReachableViaCarrierDataNetwork)
        {
            // m_ReachabilityText = "Reachable via carrier data network.";
            gsmbtn.interactable = true;
        }
        //Check if the device can reach the internet via a LAN/ wifi
        else if (Application.internetReachability == NetworkReachability.ReachableViaLocalAreaNetwork)
        {
            // m_ReachabilityText = "Reachable via Local Area Network.";
            wifibtn.interactable =  true;
        }
    }
    public void wifi_on()
    {
        wbtn = !wbtn;
        if(wbtn == true)
        {
        wifiimg.gameObject.SetActive(true);
        // wifibtn_connect.GetComponent<Text>().text = "Connected";
        // wifibtn_connect.GetComponent<Image>().color = Color.green;
        wifibtn_connect.text = "Connected";
        wifi =true;
        nonetxt.gameObject.SetActive(false);   
        }
        else
        {
        wifiimg.gameObject.SetActive(false);
        // wifibtn_connect.GetComponent<Text>().text = "Connected";
        // wifibtn_connect.GetComponent<Image>().color = Color.green;
        wifibtn_connect.text = "Connect";
        wifi =  false;
        }
    }

    public void gsm_on()
    {
        gbtn = !gbtn;
        if(gbtn == true)
        {
        gsmimg.gameObject.SetActive(true);
        // gsmbtn_connect.GetComponent<Text>().text = "Connected";
        // gsmbtn_connect.GetComponent<Image>().color = Color.green;
        gsmbtn_connect.text = "Connected";
        gsm=true;
        nonetxt.gameObject.SetActive(false);
        }
        else
        {
        gsmimg.gameObject.SetActive(false);
        // gsmbtn_connect.GetComponent<Text>().text = "Connected";
        // gsmbtn_connect.GetComponent<Image>().color = Color.green;
        gsmbtn_connect.text = "Connect";
        gsm = false;
        }
    }

    public void clear_comms_imgs()
    {
        wbtn = false;
        wifiimg.gameObject.SetActive(false);
        wifibtn_connect.text = "Connect";
        wifi = false;
        gbtn = false;

        gsm = false;
        gsmimg.gameObject.SetActive(false);
        gsmbtn_connect.text = "Connect";
        wifiimg.gameObject.SetActive(false);
        gsmimg.gameObject.SetActive(false);
    }
}
