import serial
import requests
devicecode = ""  # INSERT HERE YOUR DEVICEcode thing
arduino = serial.Serial(, 9600, timeout=.1)
apikey = ""  # INSERT HERE YOUR THINGSPEAK APICODE
url = "http://api.thingspeak.com/update?key="+apikey


def sendToSite(tmp):
    completeurl = url+"&field1="+tmp
    r = requests.get(completeurl)
    print(r.status_code)

while True:
    data = arduino.readline()[:-2]
    if data:
        # tempTmp = data.split(,)[1]
        stringTmp = data.decode("utf-8").split(",")[1]
        sendToSite(stringTmp)
