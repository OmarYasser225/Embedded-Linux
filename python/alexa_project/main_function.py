""" Modules """
from wikipedia.exceptions import PageError, DisambiguationError
from googletrans import Translator
from termcolor  import colored
from time import sleep
from gtts import gTTS

import speech_recognition as sr

import subprocess
import webbrowser
import pyautogui
import pywhatkit
import wikipedia
import pyjokes
import pygame
import os


agree_words        = ["yes" , "of course" , "sure" , "please"]
opened_website_name = ["facebook" , "github" , "linkedin"]

user_name = ""

def get_name(text):
    if "i am" in text.lower:
        index = text.find("i am")
        text = text[index+len("i am"):]
        user_name = text
        return
    else:
        text = set(text)
        user_name = str(text)

def check_agree_or_not(text):
    
    for word in agree_words:
        if word.lower() in text.lower():  # Handle case sensitivity
            return 1
    
    return 0    


""" This function to recognize the voice of user and convert it to text """
def listen():
    text = ""
    print("Listening...")
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        recognizer.adjust_for_ambient_noise(source)
        audio = recognizer.listen(source)

    try:
        print("Recognizing...")
        #text = recognizer.recognize_google(audio,language='en-US', show_all=True).lower()
        text = recognizer.recognize_google(audio,language='en-US').lower()
        print(colored("You said: ","red"),colored(text,"light_blue"))
        return text       
                
    except sr.UnknownValueError:
        if text == "":
             return 0
        speak("Sorry I couldn't understand")


""" This function to convert text to speech """
def speak(output,langauge="en"):
    try:
        file_name = "audio.mp3"

        # Convert text to speech
        voice = gTTS(text=output, lang=langauge, slow=False)
        voice.save(file_name)

        # Initialize the mixer
        pygame.mixer.init()

        # Load the audio file
        pygame.mixer.music.load(file_name)

        # Play the audio file
        pygame.mixer.music.play()

        # Keep the program running to allow the music to play
        while pygame.mixer.music.get_busy():
            pygame.time.Clock().tick(10)

        # Stop audio file and close the mixer
        pygame.mixer.music.stop()
        sleep(0.2)  # this delay to make the sound smooth
        pygame.mixer.quit()

        os.remove(file_name)

    except Exception as e:
        print(f"An error occurred: {e}")

      

def get_weather(city):
    webbrowser.open(f"https://www.google.com/search?q=weather+in+{city}")


def  web_search(text):
    index = text.find("about")
    search = text[index+len("about"):]
   
    if "in" in text:
        if "youtube" in text:
            webbrowser.open(f"https://www.youtube.com/results?search_query={search}")

        elif "wikipedia" in text:
            webbrowser.open(f"https://en.wikipedia.org/wiki/{search}")
        
        else:
             webbrowser.open(f"https://www.google.com/search?q={search}")
    
    elif "about" in text:
        webbrowser.open(f"https://www.google.com/search?q={search}")
    
    else:
        for word in opened_website_name:
            if word in text:
                webbrowser.open(f"www.{word}.com")
                return


        
    

def open_app(app_name):
    dir = {
            "chrome"         :"C:\Program Files\Google\Chrome\Application\chrome.exe",
            "microsoft edge" :"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe",
            "atmel studio"   :"C:\Program Files (x86)\Atmel\Studio\7.0\AtmelStudio.exe"
          }
    for key in dir.keys():
        if key in app_name:
            subprocess.Popen(dir[key])
            speak("The application was opened")
            return 1

    speak("The application is not exist")
    return 0
        


def translate_text(language,text):
    if language == 0:
            speak("Sorry I don't this language")
            return
    
    while True:
        language_key = ""
        languages = {
                    "arabic":"ar",
                    "french":"fr"
                    }
        index = text.find("translate")
        text = text[index+len("translate"):]
        
        if text:
            for key in languages.keys():
                if key in language:
                    language_key = key
            
            if language_key not in languages.keys():
                speak("Sorry I don't this language")
                return 

            translator = Translator()
            translated = translator.translate(text, dest=languages[language_key])
            speak(translated.text,languages[language_key])
        else:
            speak("Sorry I can't determine the senstence")
            return 
        
        speak("Do you want to translate this sentence in another langauge")
        rx = str(listen())
        check = check_agree_or_not(rx)

        if check == 1:
             speak("tell me the desire language...")
             language = str(listen())
             print(colored("langauge: ","red"),colored(language,"light_blue"))
            
        else:
            return
       

        
        
    
def send_whatsapp_message(phone_number,message):
    
    if not isinstance(message, str):
         message= str(message)

    pywhatkit.sendwhatmsg_instantly(
        phone_no = phone_number, 
        message  = message
    )
    sleep(5)
    pyautogui.hotkey("enter")

def get_summary(text):
    index = text.find("about")
    text = text[index+len("about")+1:]
    try:
        # Attempt to get the summary with auto-suggest enabled
        summary = wikipedia.summary(text, sentences=2, auto_suggest=True)
        print(colored("wikipedia inforamation: ","light_green"),colored(summary,"cyan"))
        speak(summary)
    except PageError:
        speak("The page does not exist on Wikipedia. Please try another query.")
    except DisambiguationError as e:
        speak(f"The query is ambiguous. Possible options include: {e.options}")
    except Exception as e:
        return f"An error occurred: {e}"
    


""" This function detect the text and take an action """
def text_recognation(text):

    if not isinstance(text, str):
        speak("i can't understand")
        return 0
    
    if "translate" in text:
        speak("tell me the desire language...")
        language = listen()
        print(colored("language: ","red"),colored(language,"light_blue"))
        translate_text(language,text)
    
    elif "weather" in text:
        speak("tell me name of your city...")
        city = listen()
        print(colored("City: ","red"),colored(city,"light_blue"))
        get_weather(city)


    elif "whatsapp" in text:
            speak("Kindly Enter the phone number")
            phone_num = input(colored("phone number: ","red"))
            sleep(0.2)
            speak("Kindly Enter your message...")
            message = listen()
            send_whatsapp_message(phone_num,message)

    elif "open" in text:
        for word in opened_website_name:
            if word in text:
                web_search(text)
                return
        
        open_app(text)

    elif "joke" in text:
        joke = pyjokes.get_joke()
        print(colored("joke: ","light_green"),colored(joke,"light_cyan")) 
        speak(joke)

    elif "summary" in text:
        get_summary(text)

    elif "i love you" in text:
        speak("i love you too , but unfortunatly i am program")
    
    elif "goodbye" in text:
        speak("Good bye every one and see you in another project")
    
    elif "thank you" in text:
        speak("You are welcome")
    
    elif "hi" in text:
        speak("Hi, how are you")
    
    elif "i am fine and you" in text:
        speak("i am ok")

    elif "i am ok" in text:
        speak("that is good to hear")

    elif "how are you" in text:
        speak("I am fine and you")

    elif "how old are you" in text:
        speak("i do not know because i am a program")
    
    elif "what is your name" in text:
        speak("i am alexa and you")

    elif "what is my name" in text:
        speak(f"you are {user_name}")

    elif "who i am" in text:
        speak(f"you are {user_name}")

    else:
        web_search(text)
    
    

