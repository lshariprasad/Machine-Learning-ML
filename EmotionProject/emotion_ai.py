import cv2
import serial
import time
from deepface import DeepFace

ser = serial.Serial('COM5',115200)
time.sleep(2)

cap = cv2.VideoCapture(0)

while True:

    ret, frame = cap.read()

    try:
        result = DeepFace.analyze(frame, actions=['emotion'], enforce_detection=False)

        emotion = result[0]['dominant_emotion']

        emotion_map = {
            "happy":"SMILING",
            "sad":"SAD",
            "angry":"ANGER",
            "surprise":"SURPRISED",
            "fear":"CRYING",
            "neutral":"NEUTRAL",
            "disgust":"ANGER"
        }

        emotion_text = emotion_map.get(emotion,"NEUTRAL")

        ser.write((emotion_text+"\n").encode())

        cv2.putText(frame,emotion_text,(30,40),
                    cv2.FONT_HERSHEY_SIMPLEX,1,(0,255,0),2)

    except:
        pass

    cv2.imshow("AI Emotion Detection",frame)

    if cv2.waitKey(1)==27:
        break

cap.release()
cv2.destroyAllWindows()