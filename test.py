import time
import cv2
from imutils.video import VideoStream

# 1) 얼굴 검출기 로드 (OpenCV가 제공하는 기본 xml 경로 활용)
face_cascade = cv2.CascadeClassifier(
    cv2.data.haarcascades + "haarcascade_frontalface_default.xml"
)

# 2) 카메라 시작
vs = VideoStream(0).start()
time.sleep(2)

while True:
    frame = vs.read()
    if frame is None:
        continue

    frame = cv2.flip(frame, 1)

    # 3) 그레이스케일로 변환 (HAAR은 그레이스케일에서 동작)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # 4) 얼굴 검출
    faces = face_cascade.detectMultiScale(
        gray,
        scaleFactor=1.1,     # 이미지 스케일을 줄여가며 탐지 (1.05~1.3 사이로 조절)
        minNeighbors=5,      # 사각형 후보가 몇 번 겹치면 진짜라고 볼지
        minSize=(60, 60)     # 최소 얼굴 크기
    )

    # 5) 박스 그리기
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

    cv2.imshow("Frame", frame)
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

# 6) 자원 정리
cv2.destroyAllWindows()
vs.stop()   # imutils VideoStream은 stop()이 정석
