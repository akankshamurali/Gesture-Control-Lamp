import cv2
import mediapipe as mp

# Initialize Mediapipe Hands
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=1, min_detection_confidence=0.7)
mp_draw = mp.solutions.drawing_utils

# Webcam
cap = cv2.VideoCapture(0)

lamp_on = False
brightness = 50  # Initial brightness (0-100)

prev_x = None
swipe_threshold = 40  # Pixels

def is_open_palm(landmarks):
    finger_tips = [8, 12, 16, 20]
    for tip in finger_tips:
        if landmarks[tip].y > landmarks[tip - 2].y:
            return False
    return True

def is_fist(landmarks):
    finger_tips = [8, 12, 16, 20]
    for tip in finger_tips:
        if landmarks[tip].y < landmarks[tip - 2].y:
            return False
    return True

while True:
    success, frame = cap.read()
    frame = cv2.flip(frame, 1)
    h, w, _ = frame.shape

    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    result = hands.process(rgb_frame)

    if result.multi_hand_landmarks:
        for handLms in result.multi_hand_landmarks:
            mp_draw.draw_landmarks(frame, handLms, mp_hands.HAND_CONNECTIONS)
            landmarks = handLms.landmark

            # Gesture: ON/OFF
            if is_open_palm(landmarks):
                lamp_on = True
            elif is_fist(landmarks):
                lamp_on = False

            # Gesture: Brightness control based on hand x movement
            cx = int(landmarks[9].x * w)  # Use wrist/center of palm
            if prev_x is not None:
                delta_x = cx - prev_x
                if abs(delta_x) > swipe_threshold:
                    if delta_x > 0:
                        brightness = min(100, brightness + 10)
                    else:
                        brightness = max(0, brightness - 10)
            prev_x = cx
    else:
        prev_x = None

    # Draw lamp status
    status = "LAMP ON" if lamp_on else "LAMP OFF"
    color = (0, 255, 0) if lamp_on else (0, 0, 255)
    cv2.putText(frame, status, (50, 80), cv2.FONT_HERSHEY_SIMPLEX, 1.5, color, 3)

    # Draw brightness bar
    bar_x, bar_y = 50, 120
    bar_width = 200
    filled = int((brightness / 100) * bar_width)
    cv2.rectangle(frame, (bar_x, bar_y), (bar_x + bar_width, bar_y + 30), (255, 255, 255), 2)
    cv2.rectangle(frame, (bar_x, bar_y), (bar_x + filled, bar_y + 30), (0, 255, 255), -1)
    cv2.putText(frame, f'Brightness: {brightness}%', (bar_x, bar_y - 10),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

    cv2.imshow("Gesture-Controlled Lamp", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
