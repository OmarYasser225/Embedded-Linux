import pyautogui
import time


# to comfirm to start
pyautogui.prompt(text="",title="Enter the button to start")

# get the position of chrome on desktop and open it
#chrome_pos = pyautogui.locateCenterOnScreen('edge.png')
chrome_pos = pyautogui.locateCenterOnScreen("chrome.png")
pyautogui.click(chrome_pos , clicks = 2 )
time.sleep(1)

# open the profile
profile_pos = pyautogui.locateCenterOnScreen("profile.png")
pyautogui.click(profile_pos)
time.sleep(1)
pyautogui.hotkey("ctrl","t")
time.sleep(1) 

#open gmail
pyautogui.click(x = 1683 , y = 190)
time.sleep(2) 

#create the email
create_pos = pyautogui.locateCenterOnScreen("create.png")
pyautogui.click(create_pos)
time.sleep(1)

pyautogui.typewrite("omar.yasser.k9@gmail.com")

for i in range(0,1,1):
    pyautogui.hotkey("tab")
    time.sleep(1)

pyautogui.typewrite("finish the require task")

#send the email
send_pos = pyautogui.locateCenterOnScreen("send.png")
pyautogui.click(send_pos)




