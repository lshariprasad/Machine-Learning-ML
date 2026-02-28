import cv2
import mediapipe as mp
import serial
import time
from collections import deque, Counter

# ESP32 serial

ser = serial.Serial('COM5',115200)
time.sleep(2)

BaseOptions = mp.tasks.BaseOptions
FaceLandmarker = mp.tasks.vision.FaceLandmarker
FaceLandmarkerOptions = mp.tasks.vision.FaceLandmarkerOptions
VisionRunningMode = mp.tasks.vision.RunningMode

options = FaceLandmarkerOptions(
base_options=BaseOptions(model_asset_path="face_landmarker.task"),
running_mode=VisionRunningMode.IMAGE,
num_faces=1
)

landmarker = FaceLandmarker.create_from_options(options)

cap = cv2.VideoCapture(0)

emotion_buffer = deque(maxlen=10)
last_send = time.time()

while True:


    ret, frame = cap.read()

    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb)

    result = landmarker.detect(mp_image)

    emotion = "SEARCHING"

    if result.face_landmarks:

        face = result.face_landmarks[0]

        top_lip = face[13].y
        bottom_lip = face[14].y

        left_eye = face[159].y
        right_eye = face[386].y

        mouth_open = abs(top_lip - bottom_lip)

        if mouth_open > 0.035:
            emotion = "SURPRISED"

        elif abs(left_eye - right_eye) < 0.002:
            emotion = "SLEEPING"

        elif mouth_open > 0.015:
            emotion = "SMILING"

        else:
            emotion = "NEUTRAL"

    emotion_buffer.append(emotion)

    stable = Counter(emotion_buffer).most_common(1)[0][0]

    if time.time() - last_send > 2:
        ser.write((stable+"\n").encode())
        last_send = time.time()

    cv2.putText(frame, stable, (30,40),
                cv2.FONT_HERSHEY_SIMPLEX,1,(0,255,0),2)

    cv2.imshow("AI Emotion Detection",frame)

    if cv2.waitKey(1)==27:
        break


cap.release()
cv2.destroyAllWindows()
