#/usr/bin/env python

'''
Video capture sample.
Keys:
    ESC    - exit
    SPACE  - save current frame to <shot path> directory
    + change la case afichee

'''

import numpy as np
import cv2

fnt = cv2.FONT_HERSHEY_PLAIN
#--------------------------------------------------------------------
# active la camera

def create_capture(source = 0):
    cap = None
    cap = cv2.VideoCapture(source)
    if cap is None or not cap.isOpened():
        print 'Warning: unable to open video source: ', source

    return cap
#--------------------------------------------------------------------
# decide la couleur

def MycolorByRGB(*args):

    if len(args) == 4:
        (rgb, h, s, v) = args
    elif len(args) == 2:
        (rgb, hsv) = args
        (h, s, v) = hsv
    
    (blue, green, red) = rgb
    
    green = float(max(green, 1))
    red = float(max(red, 1))
    blue = float(max(blue, 1))

    if green>200 and red>200 and blue>200:
        return 'W'

    if blue / red > 1.7 and blue / green > 1.7: 
        return 'B'
    elif green / red > 2:
        return 'G'

    if h > 150 or h < 6:
        return 'R'
    elif h < 20:
        return 'O'
    elif h < 50:
        return 'Y'

    return '?'
#--------------------------------------------------------------------
# couleur moyenne
def averageRGB(img):
    red = 0
    green = 0
    blue = 0
    num = 1
    for y in xrange(len(img)):
        if y%10 == 0:
            a = img[y]
            for x in xrange(len(a)):
                if x%10 == 0:
                    b = img[y][x]
                    num += 1
                    red += b[0]
                    green += b[1]
                    blue += b[2]
    red /= num
    green /= num
    blue /= num
    return (red, green, blue)
#--------------------------------------------------------------------
# maximum de l'histogramme
def histMode(hist, maxAmt):
    bin_count = int(hist.shape[0])
    maxAmount = int(hist[0])
    maxIndex = 0
    numZero = 0
    numTotal = 0
    for i in xrange(bin_count):
        h = int(hist[i])
        if h == 0: numZero += 1
        numTotal += 1
        if h > maxAmount:
            maxIndex = i
            maxAmount = h
    val = int(maxAmt * maxIndex / bin_count)
    return val
#--------------------------------------------------------------------
def click(event, x, y, flags, param):
    global mouse_action
    global imghaut,imglar
    
    if event == cv2.EVENT_LBUTTONDOWN:
        refPt = [(x, y)]
        #print ("clik "+str(refPt))
        if x>5 and x<36 and y>5 and y<36:  mouse_action=1
        if x>5 and x<36 and y>5+40 and y<36+40:  mouse_action=2
        if x>5 and x<36 and y>5+80 and y<36+80:  mouse_action=3
        if x>5 and x<36 and y>imghaut-20 and y<imghaut:  mouse_action=8
        
        if x>imglar-40:mouse_action=4
        if x>50 and x<100:mouse_action=5
        if y<40 and x>50:mouse_action=6
        if y>imghaut-40 and x>50:mouse_action=7

        
#--------------------------------------------------------------------
def savecube(fn,cube):
    
    text_file = open(fn, "w")
    for (f) in cube:
                text_file.write(f+"\n")
    text_file.close()

#--------------------------------------------------------------------
def makezones(x, y, dx, dy, margin):
    regions = [ ]
    for row in xrange(3):
        for col in xrange(3):
                regions.append((x + col * dx + margin,
                                 y + row * dy + margin,
                                 x + (col + 1) * dx - margin,
                                 y + (row + 1) * dy - margin))
    return regions
    
#--------------------------------------------------------------------    
if __name__ == '__main__':
    global mouse_action
    global imghaut,imglar
    
    mouse_action=0
    shotdir = "."

    print "OpenCV "+cv2.__version__
    
    # changer le numero si 1 pas ok, essayer 0
    cap = create_capture(1)
    
    # definir 9 zones carees
    ph=0
    pv=0
    (x, y, dx, dy, margin) = (130+ph, 20+pv, 130, 130, 32) 
    regions = makezones(x, y, dx, dy, margin)

    ret, vis = cap.read()
    print "Image size "+str(vis.shape)
    imghaut=vis.shape[0]
    imglar=vis.shape[1]

    print("ESC to exit")

    # case que l'on affiche pour debug 
    look=1
    #liste des faces
    cube=[]
    clist=""
    cv2.namedWindow('video')
    cv2.setMouseCallback('video', click)
    
    while True:

        texts = []
        
        ret, vis = cap.read()

        hsv = cv2.cvtColor(vis, cv2.COLOR_BGR2HSV)
        #note: en HSV, H va de 0 a 180
        # ce masque elimine le blanc
        mask = cv2.inRange(hsv, np.array((0., 50., 60.)),
                            np.array((180., 255., 255.)))
        # ce masque prends tout
        mask2 = cv2.inRange(hsv, np.array((0., 0., 0.)), 
                             np.array((180., 255., 255.)))
        #cv2.imshow('mask', mask)
        #cv2.imshow('mask2', mask2)

        # pour chaque zone
        numz=0
        for (x0, y0, x1, y1) in regions:
            numz+=1
            (w, h) = (x1 - x0, y1 - y0)
            (x0m, y0m, x1m, y1m) = (x0 + w/5, y0 + h/5, x1 - w/5, y1 - h/5)

            hsv_roi = hsv[y0m:y1m, x0m:x1m]
            mask_roi = mask[y0m:y1m, x0m:x1m]
            mask_roi2 = mask2[y0m:y1m, x0m:x1m]
            #calculer 3 histogrammes
            histHue = cv2.calcHist( [hsv_roi], [0], mask_roi, [50], [0, 180] )
            histSat = cv2.calcHist( [hsv_roi], [1], mask_roi2, [50], [0, 180] )
            histVal = cv2.calcHist( [hsv_roi], [2], mask_roi2, [50], [0, 180] )

            cv2.normalize(histHue, histHue, 0, 255, cv2.NORM_MINMAX);

            histHue = histHue.reshape(-1)
            histSat = histSat.reshape(-1)
            histVal = histVal.reshape(-1)

            hue = histMode(histHue, 180.)
            sat = histMode(histSat, 255.)
            val = histMode(histVal, 255.)

            rgb_inRegion = vis[y0m:y1m, x0m:x1m]

            avghsv = (hue, sat, val)
            avgrgb = averageRGB(rgb_inRegion)

            if numz==look: info="HSV"+str(avghsv)+" BGR"+str(avgrgb)

            #decide la couleur
            color = MycolorByRGB(avgrgb, avghsv)

            #ajoute les infos couleur a la liste
            texts.append((vis.shape[1] - (x0+x1) / 2, (y0 + y1) / 2, str(color)))
            
            # dessine un carre blanc pour montrer la zone dans l'image
            colcadre=(255, 255, 255)
            if color=='W' or color=='Y':colcadre=(0, 0, 0)
            cv2.rectangle(vis, (x0, y0), (x1, y1), colcadre)
            
        #retourne l'image gauche droite
        vis = vis[::,::-1].copy()
        
        # affiche les textes dans un carre noir
        face=[]
        for (x, y, color) in texts:
            fill = (255,255,255) 
            cv2.rectangle(vis, (x-10, y-10), (x+10, y+10), (10,10,10), -1)
            cv2.putText(vis, color, (x-5, y+4), fnt, 1, fill)
            face.append(color)
            
        # infos en bas de l'image
        cv2.rectangle(vis, (0, imghaut-20), (imglar, imghaut), (10,10,10), -1)
        cv2.putText(vis, info , (50, imghaut-5), fnt, 1, fill)
        cv2.putText(vis, "+/- Zoom,  ESC = quitter", (imglar-230, imghaut-5), fnt, 1, fill)
        
        # infos en haut de l'image
        cv2.rectangle(vis, (0, 0), (imglar, 20), (10,10,10), -1)
        done=""
        for (f) in cube:
            fc=f.split(",")
            done+=fc[4]
        cv2.putText(vis,"Faces vues: "+str(len(done))+" "+ done, (60, 15), fnt, 1, fill)


        # menu
        cv2.rectangle(vis, (0, 0), (46,imghaut ), (60,60,60), -1)
        cv2.rectangle(vis, (2, 2), (44,38 ), (160,160,60), 1)
        cv2.putText(vis,"OK", (12, 24), fnt, 1, fill)
        cv2.rectangle(vis, (2, 2+40), (44,38+40 ), (160,160,60), 1)
        cv2.putText(vis,"save", (5, 24+40), fnt, 1, fill)
        cv2.rectangle(vis, (2, 2+80), (44,38+80 ), (160,160,60), 1)
        cv2.putText(vis,"rst", (8, 24+80), fnt, 1, fill)
        cv2.rectangle(vis, (2, imghaut-20), (44,imghaut-2), (160,160,60), 1)
        cv2.putText(vis,str(look), (16,imghaut-5), fnt, 1, fill)
        cv2.imshow('video', vis)
        
        # teste les click menu
        if mouse_action==1:
                mouse_action=0
                clist=""
                for (x,y,color) in texts: clist+=color+","
                clist = clist[:-1]
                print clist
                cube.append(clist)
                
        if mouse_action==2:
                mouse_action=0
                fn = '%s/cube.txt' % (shotdir)
                savecube(fn,cube)
        
        if mouse_action==3:
                mouse_action=0
                cube=[]
                clist=[]
                
        # teste le clavier
        ch = 0xFF & cv2.waitKey(1)
        
        if ch == 27:
            break
        
        if ch == ord('+') or mouse_action==8:
            mouse_action=0
            look+=1
            if look>9: look=1
        
        if ch == ord(' '):
            clist=""
            for (x,y,color) in texts: clist+=color+","
            clist = clist[:-1]
            print clist
            cube.append(clist)
                
        if ch == ord('s'):
            fn = '%s/cube.txt' % (shotdir)
            savecube(fn,cube)
                
        if ch == ord('r'):
                cube=[]
                clist=[]
                
        if ch == ord('+'):
            if margin>4:
                (x, y, dx, dy, margin) = (130+ph, 20+pv, 130, 130, margin-3) 
                regions = makezones(x, y, dx, dy, margin)
             
        if ch == ord('-'):
            if margin<46:
                (x, y, dx, dy, margin) = (130+ph, 20+pv, 130, 130, margin+3) 
                regions = makezones(x, y, dx, dy, margin)

                    
        if ch == ord('e') or mouse_action==5:
                mouse_action=0
                ph+=5
                (x, y, dx, dy, margin) = (130+ph, 20+pv, 130, 130, margin) 
                regions = makezones(x, y, dx, dy, margin)
                
        if ch == ord('r')or mouse_action==4:
                mouse_action=0
                ph-=5
                (x, y, dx, dy, margin) = (130+ph, 20+pv, 130, 130, margin) 
                regions = makezones(x, y, dx, dy, margin)
                
        if ch == ord('t') or mouse_action==7:
                mouse_action=0
                pv+=5
                (x, y, dx, dy, margin) = (130+ph, 20+pv, 130, 130, margin) 
                regions = makezones(x, y, dx, dy, margin)
                
        if ch == ord('y')or mouse_action==6:
                mouse_action=0
                pv-=5
                (x, y, dx, dy, margin) = (130+ph, 20+pv, 130, 130, margin) 
                regions = makezones(x, y, dx, dy, margin)
            
    cv2.destroyAllWindows()
