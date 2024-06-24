import pyautogui
import time


# to comfirm to start
pyautogui.prompt(text="",title="Enter the button to start")

# get the position of chrome on desktop and open it
chrome_pos = pyautogui.locateCenterOnScreen("chrome.png",confidence=0.9)
pyautogui.click(chrome_pos , clicks = 2 )
time.sleep(1)

# open the profile
profile_pos = pyautogui.locateCenterOnScreen("profile.png",confidence=0.9)
pyautogui.click(profile_pos)
time.sleep(1)
pyautogui.hotkey("ctrl","t")
time.sleep(1) 

#open gmail
pyautogui.click(x = 1683 , y = 190)
time.sleep(2) 

#select
select_pos = pyautogui.locateCenterOnScreen("select.png",confidence=0.9)
pyautogui.click(select_pos)
time.sleep(1)

#select all
select_all_pos = pyautogui.locateCenterOnScreen("select_all.png",confidence=0.9)
pyautogui.click(select_all_pos)

#select read 
read_pos = pyautogui.locateCenterOnScreen("read.png",confidence=0.9)
pyautogui.click(read_pos)

#select done
time.sleep(1)
pyautogui.click(x = 723 , y = 610)




