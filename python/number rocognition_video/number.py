import cv2
import time
import sys
img_save_path = "./numbers/" # папка для сохранения изображений автомобилей
cap = cv2.VideoCapture('video.mp4') # путь к видео 
number_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_russian_plate_number.xml')
frame_counter = 0
scale_factor_x = 7
scale_factor_y = 12
prev_number = []
last_name = ''


def find_template(img, template, meth):
    
    method = eval(meth)
 
    w, h = template.shape[::-1]
    res = cv2.matchTemplate(img, template, method)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)

    # в зависимости от метода разные подходы
    if method in [cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]:
        top_left = min_loc
    else:
        top_left = max_loc
    bottom_right = (top_left[0] + w, top_left[1] + h)
    
    return [top_left,bottom_right]

while(True):
    # получаем картинку
    ret, image = cap.read()

    # конвертируем в ч/б
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    number  = number_cascade.detectMultiScale(gray, scaleFactor = 1.8, minNeighbors = 5)
    # ищем все номера    на изображении
    

    for (sx, sy, sw, sh) in number:
        
        if len(prev_number) == 0: # если нет найденных номеров сохраняем первый найденый
            prev_number = gray[sy:sy+sh,sx:sx+sw].copy()
            sw = int(sw * scale_factor_x)
            sh = int(sh * scale_factor_y)
            sx = max(0, sx - int(sw / 2))
            sy = max(0 , sy - int(sh / 2))
            last_name = f'{img_save_path}{frame_counter}_{time.strftime("%Y%m%d_%H_%M_%S")}.jpg'
            cv2.imwrite(last_name, image[sy:sy+sh,sx:sx+sw])
            cv2.imwrite(f'{img_save_path}{frame_counter}.jpg', prev_number)
        else:
            # ищем на картинке уже найденые номера по шаблону
            top_left, bottom_right = find_template(gray, prev_number, 'cv2.TM_CCORR_NORMED')
            # ищем и проверяем координаты старых найденных номеров с новыми чтобы записать только новые
            if abs(top_left[0] - sx) < 20 and abs(top_left[1] - sy) < 20:
                prev_number = gray[sy:sy+sh,sx:sx+sw].copy()
                if (bottom_right[0] - top_left[0])*(bottom_right[1] - top_left[1]) > sh*sw:
                    sw = int(sw * scale_factor_x)
                    sh = int(sh * scale_factor_y)
                    sx = max(0, sx - int(sw / 2))
                    sy = max(0 , sy - int(sh / 2))
                    cv2.imwrite(last_name, image[sy:sy+sh,sx:sx+sw])
                    
                
            else:
                prev_number = gray[sy:sy+sh,sx:sx+sw].copy()
                cv2.imwrite(f'{img_save_path}{frame_counter}.jpg', prev_number)
                cv2.rectangle(gray, top_left, bottom_right, 255, 3)
                sw = int(sw * scale_factor_x)
                sh = int(sh * scale_factor_y)
                sx = max(0, sx - int(sw / 2))
                sy = max(0 , sy - int(sh / 2))
                last_name = f'{img_save_path}{frame_counter}_{time.strftime("%Y%m%d_%H_%M_%S")}.jpg'
                cv2.imwrite(last_name, image[sy:sy+sh,sx:sx+sw])

        
        
        

    frame_counter += 1
    cv2.imshow('frame',gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
