# Alexa Project

### Voice Assistant
The Voice Assistant project is a Python-based application designed to provide interactive voice-controlled functionalities. Using various APIs and libraries, it enables voice recognition, text-to-speech conversion, web browsing, application launching, and more. Users can interact with the assistant through voice commands to perform tasks such as searching the web, retrieving weather information, sending WhatsApp messages, fetching summaries from Wikipedia, and even enjoying a few jokes. This project leverages Python libraries such as SpeechRecognition, gTTS, pygame, pyautogui, pywhatkit, and Wikipedia to deliver a versatile and engaging voice assistant experience.

# Important note
You need first to install the requirements.txt file by the following line
```bash
pip install -r requirements.txt 
```
# Files description
there are 2 file with extension (.py)
### 1-alexa_project.py (excutable)
- contain the main project
### 2-main_function.py (module)
- contain the main functions of alexa like listen , speak , and etc...

# Additional note
- the file called __`effect.mp3`__ this  music file i added to make me an indication to speak
- you can also  make it by add the following function in **`__init__.py`** file for __speech recognition__ module 
```python
def music_open(audio_file):
     # Initialize the mixer
        pygame.mixer.init()

        # Load the audio file
        pygame.mixer.music.load(audio_file)

        # Play the audio file
        pygame.mixer.music.play()

        # Keep the program running to allow the music to play
        while pygame.mixer.music.get_busy():
            pygame.time.Clock().tick(10)

        # Stop audio file and close the mixer
        pygame.mixer.music.stop()
```
- then call this function in **`class Recognizer`** like the following

```python
class Recognizer(AudioSource):
    def __init__(self):
        """
        Creates a new ``Recognizer`` instance, which represents a collection of speech recognition functionality.
        """
        music_open("effect.mp3") #`this is the function that i added in __init.py__ file`
        self.energy_threshold = 300  
        self.dynamic_energy_threshold = True
        self.dynamic_energy_adjustment_damping = 0.15
        self.dynamic_energy_ratio = 1.5
        self.pause_threshold = 0.8  
        self.operation_timeout = None 

        self.phrase_threshold = 0.3 
        self.non_speaking_duration = 0.5
```




